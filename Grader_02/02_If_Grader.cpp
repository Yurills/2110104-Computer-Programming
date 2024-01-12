#include <iostream>

using namespace std;

int main(){
    int grade;cin>>grade;
    string result;
    if (grade <80){
        result = "B";
        if (grade <70){
            result = "C";
            if (grade <60){
                result ="D";
                if (grade <50){
                    result = "F";
                }
            }
        }
    }
    else result = 'A';

    cout << result;
}