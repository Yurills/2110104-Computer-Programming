#include <iostream>

using namespace std;

int main(){
    int d,m,y; cin >> d >> m >> y;
    y-=543;
    int months[]={31,28,31,30,31,30,31,31,30,31,30,31};
    bool leap = false;
    if (y%4==0){
        leap =true;
        if (y%100==0){
            leap= false;
            if (y%400==0){
                 leap = true;
            }
        }
    }

    if (leap==true && m > 1){
        d += 1;
    }
    for (int i=0;i<m-1;i++ ){
        d += months[i];
    }
    cout << d;


}