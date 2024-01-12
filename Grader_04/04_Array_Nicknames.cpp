#include <iostream>
#include <string>

using namespace std;

int main() {
    string names[] = {"Robert","William","James","John","Margaret","Edward","Sarah","Andrew","Anthony","Deborah"};
    string nicks[] = {"Dick","Bill","Jim","Jack","Peggy","Ed","Sally","Andy","Tony","Debbie"};
    int n;cin>>n;

    for (int i=0;i<n;i++){
        string name; cin >> name;
        string ans = "Not found";
        for (int i=0;i<10;i++){
            if (name == names[i]){
                ans = nicks[i];
            }
            else if (name == nicks[i]){
                ans = names[i];
            }
        }
        cout << ans << endl;

    }
}