#include <iostream>
#include <math.h>
using namespace std;

bool checkPrime(long long int number){
    long long int divide = 3;
    long long int stopPoint = number;
    if (number%2==0){return false;}
    while (true){
        if (divide == stopPoint){
            return true;
        }
        if (number%divide==0){
            return false;
        }
        divide+=2;
    }
}


long long int createNumber (int input[]){
    string str_answer = "";
    for (int i=1;i<=input[1];i++){
        str_answer += to_string(input[0]);
    }
    for (int i=1;i<=input[3];i++){
        str_answer += to_string(input[2]);
    }
    long long int answer = stoi(str_answer);
    return answer;
    
}



int main(){
    int n;cin>>n;
    int input[4];
    for (int i=0;i<n;i++){ //each loop per request
        for (int j=0;j<4;j++){
            cin >> input[j];
        }
        if (checkPrime(createNumber(input))){
                cout << "YES";
            }
        else { cout << "NO";}
        cout << "\n";

    }
}