#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long  n, x;
        cin >> n >> x;

        vector<int> a(n), b(n);
        vector<int>final;
        vector<pair<int, int>> arr(n);
        long long  total = 0;
        long long  p=0;
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];

        for (int i = 0; i < n; i++) {
            arr[i] = {a[i], b[i]};
            total+=arr[i].first * arr[i].second;
            final.push_back(arr[i].first*arr[i].second);
        }

        if (total < x) {
            cout << "-1" << endl;
            continue;
        }
        reverse(final.begin(),final.end());
        
        for(int i=0;i<n;i++){
            p+=final[i];
            if(p>=x){
                cout<< (i+1)<<endl;
                break;
            }
        }
    }

    return 0;
}