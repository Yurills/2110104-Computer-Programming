#include <iostream>
#include <math.h>
using namespace std;

int main(){
    string user;cin>>user;
    int sum=0,n13;
    for (int i=0;i<12;i++){
        sum+=(13-i)*(int(user[i]-'0'));
    }   
    n13 = (11-(sum%11))%10;
    string answer;
    answer = user.substr(0,1)+"-"+user.substr(1,4)+"-"+user.substr(5     ,5)+"-"+user.substr(10,2)+"-"+to_string(n13);
    cout<<answer;
}
