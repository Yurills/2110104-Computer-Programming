#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

double Mosteller(double Weight ,double Height) {
    double results;
    results = (sqrt(Weight*Height))/60;
    return results;
}

double Haycock(double Weight ,double Height) {
    double results;
    results = 0.024265 * pow(Weight,0.5378) * pow(Height,0.3964);
    return results;
}

double Boyd(double Weight ,double Height) {
    double results;
    results = 0.0333 * pow(Weight,0.6157-0.0188*log10 (Weight)) * pow(Height,0.3);
    return results;
}

int main(){
    double W,H; cin>>W>>H;
    cout <<setprecision(15) << Mosteller(W,H) << "\n" << Haycock(W,H) << "\n" <<Boyd(W,H);
}