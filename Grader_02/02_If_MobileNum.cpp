#include <iostream>
#include <string>

using namespace std;

int main() {
    string str;cin>>str;

    if (str[0]=='0'){
        if (str[1]=='6'||str[1]=='8'||str[1]=='9'){
            if (str.size()==10){
                {cout << "Mobile number";}
            }
            else {cout<<"Not a mobile number";}
        }
        else {cout<<"Not a mobile number";}
    }
    else {cout<<"Not a mobile number";}
}