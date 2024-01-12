#include <iostream>
#include <math.h>

using namespace std;

int main() {
    double sub;cin>>sub;
    if (sub > 1000 && sub < 1000000){
        sub /= 1000;
        if (sub > 10){
            sub = round(sub);
        }
        else if (sub > 1){
            sub = round(sub*10)/10;
        }
        cout << sub <<"K";
        
    }
    else if (sub > 1000000 && sub < 1000000000){
        sub /= 1000000;
        if (sub > 10){
            sub = round(sub);}
        else if (sub > 1){
            sub = round(sub*10)/10;
        }
        
        cout << sub << "M";
    }
    else if (sub > 1000000000){
        sub /= 1000000000;
        if (sub > 10){
            sub = round(sub);}
        else if (sub > 1){
            sub = round(sub*10)/10;
        }
        
        cout << sub << "B";}
    else {cout << sub;}



    return 0;
}