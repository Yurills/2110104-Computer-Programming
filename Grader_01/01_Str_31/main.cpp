#include <bits/stdc++.h>
using namespace std;
long gcd(long a, long b) {
    if (b == 0) 
        return a;
    return gcd(b, a%b);
}

int main(){
    string a, b, c;
    cin >> a >> b >> c;
    
    string temp = a + b + c;
    string temp2 = a+b;
    int xminus = stoi(temp2);
    int x = stoi(temp);
    int xmulti = 1;

    // x*= b.length();
    // x*= c.length();

    xmulti *= pow(10, b.length() + c.length());
    xmulti -= pow(10, b.length());
    
    int ans = gcd(x - xminus, xmulti);

    cout << (x - xminus)/ans << " / " << xmulti/ans;

    return 0;
}