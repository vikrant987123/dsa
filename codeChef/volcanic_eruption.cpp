#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

// In addition to normal set operations, the ordered set supports:

// order_of_key(k) : Gives the count of elements smaller than k. — O(log n)
// find_by_order(k): Returns the iterator for the kth element (use k = 0 for the first element). — O(log n)

template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <class T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define int long long
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define rev(i, a, b) for (int i = a; i >= b; i--)
#define vi vector<int>
#define vs vector<string>
#define umap unordered_map<int, int>
#define omap map<int, int>
#define pii pair<int, int>
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define all(x) (x).begin(), (x).end()
#define setit(a, b) memset(a, b, sizeof(a))
#define mp make_pair
#define ff first
#define ss second
#define least INT_MIN
#define great INT_MAX
#define get(arr, n) \
    vi arr(n);      \
    rep(i, 0, n - 1) { cin >> arr[i]; }
#define c(x) cout << ((x) ? "YES" : "NO") << endl;
#define debug(x, n) \
    rep(i, 0, n - 1) { cout << #x << i << " is " << arr[i] << endl; }
#define outarr(arr, n)                          \
    rep(i, 0, n - 1) { cout << arr[i] << " "; } \
    cout << endl;
#define maxe *max_element
#define mine *min_element

const int mod = 998244353;
const int inf = 1e18;
const int Mod = 1000000007;

/*--------------------------FUNCTIONS----------------------------------*/
int fact[10000000];
int factorial(int x)
{
    // int fact[x + 1];
    fact[0] = 1;
    rep(i, 1, x)
    {
        fact[i] = (fact[i - 1] % Mod * i % Mod) % Mod;
    }
    return fact[x] % Mod;
}

bool prime(int x)
{
    int i = 2;
    while (i <= sqrt(x))
    {
        if (x % i == 0)
        {
            return false;
        }
        i++;
    }
    return true;
}

bool checksieve(int n)
{
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));

    for (int p = 2; p * p <= n; p++)
    {
        if (prime[p] == true)
        {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    return prime[n];
}

vector<int> getfactors(int n)
{
    vector<int> ans;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            if (n / i != i)
            {
                ans.push_back(n / i);
                ans.push_back(i);
            }
            else
                ans.push_back(i);
        }
    }

    sort(all(ans));
    return ans;
}

int binexp(int a, int b, int m)
{
    int ans = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            ans = (ans % m * a % m) % m;
        }
        a = (a % m * a % m) % m;
        b >>= 1;
    }
    return ans;
}

int modinv(int a, int m)
{
    return binexp(a, m - 2, m);
}

int nCr(int n, int r)
{
    return fact[n] / (fact[r] * fact[n - r]);
}

double getdist(int ax, int ay, int bx, int by)
{

    return sqrt((ax - bx) * (ax - bx) + (ay - by) * (ay - by));
}

// code to check that the rows and col are valid in a matrix
bool isvalid(int r, int c, int n, int m)
{
    return r >= 0 && r < n && c >= 0 && c < m;
}

int checkparity(int n)
{
    if (n & 1)
        return 1;
    else
        return 0;
}





/*--------------------------MAIN CODE----------------------------------*/

void helper()
{

int n,p;
cin>>n>>p;

vector<int> ht(n);
for(int i=0;i<n;i++){
    cin>>ht[i];
}

vector<int> mL(n),mR(n);

int h = INT_MAX;
for(int i=0;i<n;i++){
    if(ht[i]==0){// volcano encountered
        mL[i] = 0;
        h=0;
    }

    if(ht[i]<h){ //when ith building has some building (int left) greater than that
        mL[i] = h;
    }else{//if ith is itself the greater from its left
        mL[i] = ht[i];
        h = ht[i];
    }
}
h = INT_MAX;
for(int i=n-1;i>=0;i--){
    if(ht[i]==0){
        mR[i] = 0;
        h=0;
    }

    if(ht[i]<h){
        mR[i] = h;
    }
    else{
        mR[i] = ht[i];
        h = ht[i];
    }
}

for(int i=0;i<n;i++){
    int mini = min(mL[i],mR[i]);
    cout<< (mini+p-1)/p <<" ";
}
cout<<endl;
   
}

int32_t main()
{

    // // std::setprecision(10);
    int t;
    cin >> t;

    while (t--)
    {
        helper();
    }

    return 0;
}