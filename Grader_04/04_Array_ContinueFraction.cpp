#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

int main() {
    int n; cin>>n;
    double numbers[n];
    for (int i=0;i<n;i++){
        cin >> numbers[i];
    }

    double fraction_numbers[n];
    double temp = 0;
    for (int i=0;i<n;i++){
        temp = numbers[i];
        for (int j=i-1;j>=0;j--){
            temp = numbers[j] + (1/temp) ;

        }
        cout << setprecision(10) << temp << endl;
    }
}