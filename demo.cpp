// #include <bits/stdc++.h>
// using namespace std;

// int main(){
//     int n;
//     cin>>n;
//     cout<<"hey "<<n<<endl;
// }

#include <bits/stdc++.h>
using namespace std;

void print_str(int n){
    //int c=0;
    if(n>4){
        return;
    }

    cout<<"Raj"<<endl;
    n++;
    print_str(n);
}

int main(){
    int n;
    cin>>n;

    print_str(n);

    return 0;
}