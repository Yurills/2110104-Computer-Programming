#include <iostream>
#include <math.h>
using namespace std;
int main(){
    int inp,temp,ans;cin>>inp;
    inp = (inp-543)%100;
    temp = (inp + floor((inp/4))+11);
    ans = temp%7;
    cout << ans;

    return 0;
}