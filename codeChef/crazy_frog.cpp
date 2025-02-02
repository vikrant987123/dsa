#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

// Ordered Set Definitions
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
const int N = 1e6 + 5;

int fact[N];

// **Precompute Factorials Modulo `Mod`**
void precompute_factorial() {
    fact[0] = 1;
    rep(i, 1, N - 1) {
        fact[i] = (fact[i - 1] * i) % Mod;
    }
}

// **Modular Exponentiation**
int binexp(int a, int b, int m) {
    int ans = 1;
    while (b > 0) {
        if (b & 1)
            ans = (ans * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return ans;
}

// **Modular Inverse using Fermat’s Theorem**
int modinv(int a, int m) {
    return binexp(a, m - 2, m);
}

// **nCr Modulo `Mod`**
int nCr(int n, int r) {
    if (r > n) return 0;
    return (fact[n] * modinv(fact[r], Mod) % Mod * modinv(fact[n - r], Mod) % Mod) % Mod;
}

// **Check if a number is prime**
bool prime(int x) {
    if (x <= 1) return false;
    if (x == 2 || x == 3) return true;
    if (x % 2 == 0 || x % 3 == 0) return false;
    for (int i = 5; i * i <= x; i += 6) {
        if (x % i == 0 || x % (i + 2) == 0)
            return false;
    }
    return true;
}

// **Sieve of Eratosthenes**
bool checksieve(int n) {
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));

    for (int p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    return prime[n];
}

// **Get Factors of a Number**
vector<int> getfactors(int n) {
    vector<int> ans;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            if (n / i != i) {
                ans.push_back(n / i);
                ans.push_back(i);
            } else
                ans.push_back(i);
        }
    }
    sort(all(ans));
    return ans;
}

// **Calculate Distance Between Two Points**
double getdist(int ax, int ay, int bx, int by) {
    return sqrt((ax - bx) * (ax - bx) + (ay - by) * (ay - by));
}

// **Check if (r, c) is within Matrix Bounds**
bool isvalid(int r, int c, int n, int m) {
    return r >= 0 && r < n && c >= 0 && c < m;
}

// **Check Parity (Odd or Even)**
int checkparity(int n) {
    return (n & 1) ? 1 : 0;
}

// **Core Function to Process Test Cases**
void helper() {
    int n;
    cin >> n;

    vi frogLoc(n);
    rep(i, 0, n - 1) cin >> frogLoc[i];

    int odd = 0, even = 0;
    rep(i, 0, n - 1) {
        if (frogLoc[i] % 2 == 0)
            even++;
        else
            odd++;
    }

    int maxi = max(even, odd);
    cout << maxi << endl;
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    precompute_factorial();  // Precompute factorials for `nCr()`

    int t;
    cin >> t;

    while (t--) {
        helper();
    }

    return 0;
}
