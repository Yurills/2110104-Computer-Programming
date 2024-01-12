//05_String_License_Plate
#include <iostream>
#include <math.h>
#include <string>
using namespace std;

string alphab = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

string toBackPlateNumber (int number ){
    if (number > 999){
        number %= 1000;
    }
    string plate = "000";
    string str_number = to_string(number);
    int n= str_number.length();

    for (int i=0;i<n;i++){
        plate[2-i] = str_number[n-1-i];
    }
    return plate;
}

int searchIndexAlphabet (char a ,string alpha){
    for (int i=0;i<26;i++){
        if (a == alpha[i]){
            return i;
            break;
        }
    }
    return 0;
}

int AlphatToInt (string input){
    int temp = 0;
    for (int i=2;i>0;i--){
        temp += searchIndexAlphabet(input[i], alphab)*(pow(26,2-i));
    }
    temp += (input[0] - '0')*(26*26); 
    return temp;
}

string toFrontPlateNumber (int number) {
    int temp[3] = {};
    temp[2] = number%26;
    if (number/26 > 0){
    temp[1] = (number/26)%26;
    temp[0] = number/(26*26); 
    }
    string answer = "0AA";
    answer[1] = alphab[temp[1]];
    answer[2] = alphab[temp[2]];
    answer[0] = (char)temp[0] + '0';

    return answer;
    
}

int main() {
    string input; cin >> input;
    int addIn; cin >> addIn;

    string back = input.substr(4,3);
    int iback = stoi(back);
    iback += addIn;
    int addFront = (iback/1000);
    iback %= 1000;

    string front = input.substr(0,3);
    int ifont = AlphatToInt(front);
    ifont += addFront;

    string temp = "";
    temp += toFrontPlateNumber(ifont)+"-"+toBackPlateNumber(iback);

    cout << temp;

}