#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int d, need, have;
        cin >> d >> need >> have;

        if (need <= have) {
            cout << "0" << endl;
            continue;
        }
        
        bool found = false;

        
        for (int trial = 1; trial <= have; trial++) {
          
            double discount = (d * trial * need)/100.0;
            double final_price = need - discount;
            
            if (final_price + trial <= have) {
                cout << trial << endl;
                found = true;
                break;
            }
        }

       
        if (!found) {
            cout << -1 << endl;
        }
    }

    return 0;
}