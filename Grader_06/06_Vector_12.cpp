//06_Vector_★_Collatz
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> numbers;
    int input;
    cin >> input;
    numbers.push_back(input);
    int n = numbers.back();
    while (n != 1){
        if (n%2){
            n = 3*n+1;
        }
        else {
            n = n/2;
        }

        numbers.push_back(n);
        n = numbers.back();
    
    }

    if (numbers.size() <= 15){
        for (int i=0;i<numbers.size()-1;i++){
            cout << numbers[i] << "->";
        }
        cout << numbers[numbers.size()-1];
    }
    else {
        for (int i=numbers.size()-15;i<numbers.size()-1;i++){
            cout << numbers[i] << "->";
        }
        cout << numbers[numbers.size()-1];
    }
    
}