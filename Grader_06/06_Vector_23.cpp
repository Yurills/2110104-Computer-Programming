//06_Vector_★★_Third_Closest
#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <math.h>
using namespace std;

int main() {
    int n;cin>>n;
    vector<tuple<double,int,double,double>> output;
    tuple<double, int, double, double> input;
    double x,y;
    for (int i=0;i<n;i++){
        cin >> x >> y;
        get<1>(input) = i+1;
        get<2>(input) = x;
        get<3>(input) = y;
        get<0>(input) = sqrt(x*x+y*y);
        output.push_back(input);
    }

    sort(output.begin(), output.end());
    cout << "#" << get<1>(output[2]) << ": (" << get<2>(output[2]) << ", " << get<3>(output[2]) << ")";
    


}