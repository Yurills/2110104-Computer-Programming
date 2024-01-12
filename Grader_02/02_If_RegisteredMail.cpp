#include <iostream>

using namespace std;

int main() {
    int a;cin>>a;
    string p;
    if (a <= 100){
        p = "18";}
    else if (a<=250){
        p = "22";}
    else if (a<=500){
        p = "28";}
    else if (a<=1000){
        p = "38";}
    else if (a<=2000){
            p = "58";
        }
    else {p="Reject";}  
    cout << p;
}