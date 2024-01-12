#include <iostream>
#include <math.h>

using namespace std;

long gcd(long a, long b) {
 if (b == 0) return a;
 return gcd(b, a%b);
}



int main(){
    string a,b,c;cin>>a>>b>>c;
    string full = a + b + c;
    string main = a + b;

    int nfull = stoi(full);
    int nmain = stoi(main);

    int numer = nfull-nmain;

    int denom = 1;
    denom *= pow(10,b.length()+c.length());
    denom -= pow(10,b.length());

    int ans_denom,ans_numer;
    ans_denom = denom/gcd(numer,denom);
    ans_numer = numer/gcd(numer,denom);

    cout << ans_numer << " / " << ans_denom;   

    

}