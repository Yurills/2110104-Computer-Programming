#include <iostream>
using namespace std;

int main() {
    int input;cin>>input;
    if (input>0){
        cout << "positive\n";
    }
    else if (input == 0 ){
        cout << "zero\n";
    }
    else {cout << "negative\n";}

    if (input %2 == 0){
        cout << "even";
    }
    else {cout << "odd";}
}