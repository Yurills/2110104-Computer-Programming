#include <iostream>
#include <math.h>

using namespace std;

int main(){
    double a,b,c;cin>>a>>b>>c;
    double x1,x2;
    x1 =  sqrt(pow(b,2)-(4*a*c));
    
    x2 = (-1*b+x1)/(2*a);
    x1 = (-1*b-x1)/(2*a);

    x1 = round(x1*1000)/1000;
    x2 = round(x2*1000)/1000;

    cout << x1 <<" "<< x2;

}