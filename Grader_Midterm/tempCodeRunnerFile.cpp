#include <iostream>
#include <math.h>
using namespace std;

const double g = 10;
const double PI = 3.14;


double findH(double u, double angle, double t){
    double sinAngle = sin(angle);
    double block1 = (t - (u*sinAngle)/g);
    double block2 = ((u*sinAngle)) + (0.5*g*(t-(3*(u*sinAngle/g))));
    return block1*block2;
}

double findR(double u, double angle, double t){
    return u*(cos(angle)*t);
}



int main() {
    double u,angle,t;
    cin >> u >> angle >> t;
    angle = angle*PI/180;
    cout << round(findH(u,angle,t)*10)/10 << " " << round(findR(u,angle,t)*10)/10;
    



}