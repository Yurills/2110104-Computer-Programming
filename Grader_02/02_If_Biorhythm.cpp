#include <iostream>
#include <math.h>
using namespace std;

int findRed(int d,int m,int y) {
    int months[]= {31,28,31,30,31,30,31,31,30,31,30,31};
    int day=0;
    if (y%4==0 && m<=2){
        day=1;
        if (y%100==0){
            day=0;
            if (y%400==0){
                day=1;
            }
        }
    }
    for (int i=m;i<13;i++){
        day+=months[i-1];
    }
    day -= d-1;
    return day;
    }

int findBlue(int d,int m,int y) {
    int months[]= {31,28,31,30,31,30,31,31,30,31,30,31};
    int day=0;
    if (y%4==0 && m>2){
        day=1;
        if (y%100==0){
            day=0;
            if (y%400==0){
                day=1;
            }
        }
    }
    for (int i=0;i<m;i++){
        day+=months[i-1];
    }
    day += d-1;
    return day;
    }

int findBlack(int y,int by){
    int day=0;
    day = 365 * (by-y-1);
    return day;

}

double findPhy(int day){
    double answer = sin(2*M_PI*day/23);
    return round(answer*100.0)/100.0;
}
double findEmo(int day){
    double answer = sin(2*M_PI*day/28);
    return round(answer*100.0)/100.0;
}
double findInt(int day){
    double answer = sin(2*M_PI*day/33);
    return round(answer*100.0)/100.0;
}


int main() {
    int d,m,y; cin>>d>>m>>y;
    int bd,bm,by; cin>>bd>>bm>>by;
    y -= 543;
    by -= 543;

    int sumDay = findRed(d,m,y)+findBlack(y,by)+findBlue(bd,bm,by);



    //cout << findRed(d,m,y) << " " << findBlack(y,by) << " " << findBlue(bd,bm,by);

    cout << sumDay << " " << findPhy(sumDay) << " " << findEmo(sumDay) << " " << findInt(sumDay);
}