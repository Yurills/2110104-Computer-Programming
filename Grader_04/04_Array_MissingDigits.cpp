#include <iostream>
#include <string>

using namespace std;

int main() {
    string nums = "0123456789";
    string str;cin>>str;
    int count = 0;
    for (int i=0;i<str.length();i++){
        if (str[i]-'0' < 10 && str[i]-'0' >= 0){
            nums[str[i]-'0'] = 'x';
            count++;
        }

    }
    string ans = "";
    for (int i=0;i<10;i++){
        if (nums[i]!='x'){
            ans = ans+nums[i]+",";
        }
    }
    ans.pop_back();
    if (nums == "xxxxxxxxxx"){
        ans="None";
    }
    cout << ans;

    
    


}