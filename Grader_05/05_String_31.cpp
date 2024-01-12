//05_String_Baconian
#include <iostream>
#include <string>
using namespace std;

int findIndexArray (string want , string array[] , int n){  
    for (int i=0;i<n;i++){
        if (want == array[i]){
            return i;
        }
    }
    return 0;
}

string getFirstLetter (string a){
    string temp = "";
    temp += a[0];
    return temp;
}

string decodeString (string input){
    string cipher[12] = {"UUUU" , "UUUL" , "UULU" , "UULL" , "ULUU" , "ULUL" , "ULLU" , "ULLL" , "LUUU" , "LUUL" , "LULU" , "LULL"};
    string strAlpha = "";
    for (int i=0;i<input.length();i++){
        if (isalpha(input[i])){
            if (isupper(input[i]))strAlpha += "U";
            else strAlpha += "L";
        }
    }

    string tempHolder = "";
    int tempNumforDecode[strAlpha.length()/4];
    int count = 0;
    for (int i=0;i<strAlpha.length();i++){
        tempHolder += strAlpha[i];
        if (tempHolder.length() == 4){
            tempNumforDecode[count++] = findIndexArray(tempHolder,cipher,12);
            tempHolder = "";
        }
    }
    string decoded = "";
    for (int i=0;i<strAlpha.length()/4;i++){
        if ((tempNumforDecode[i]) < 10){
             decoded += tempNumforDecode[i] + '0';
        }
        else {
            if (tempNumforDecode[i] == 10){
                decoded += "-";
            }
            else if (tempNumforDecode[i] == 11){
                decoded += ",";
            }
        }
    }
    return decoded;
}

string turnUpper (string a){
    string b = "";
    for (int i=0;i<a.length();i++){
        if (isalpha(a[i])){
            if (isupper(a[i])){
                b += a[i];
            }
            else {
                a[i] -=32;
                b += a[i];
            }
        }
        else {
            b += a[i];
            }
    }
    return b;
}

string turnLower (string a){
    string b = "";
    for (int i=0;i<a.length();i++){
        if (isalpha(a[i])){
            if (islower(a[i])){
                b += a[i];
            }
            else {
                a[i] +=32;
                b += a[i];
            }
        }
        else {
            b += a[i];
            }
    }
    return b;
}

string encodeString(string fakeWord ,string input){
    string cipher[12] = {"UUUU" , "UUUL" , "UULU" , "UULL" , "ULUU" , "ULUL" , "ULLU" , "ULLL" , "LUUU" , "LUUL" , "LULU" , "LULL"};
    string cipherSet = "";
    for (int i=0;i<input.length();i++){
        if (input[i] != '-' && input[i] != ','){
            cipherSet += cipher[input[i]-'0'];
        }
        else if (input[i] == '-'){
            cipherSet += cipher[10];
        }
        else if (input[i] == ','){
            cipherSet += cipher[11];
        }
    }
    int n=0;
    for (int i=0;i<fakeWord.length();i++){
        if (isalpha(fakeWord[i]))n++;
    }
    string iFakeWord[n];
    string FakeWordTemp = ""; int c = 0;
    for (int i=0;i<fakeWord.length();i++){
        FakeWordTemp += fakeWord[i];
        if (isalpha(fakeWord[i+1]) || i == fakeWord.length()-1){
            iFakeWord[c++] = FakeWordTemp;
            FakeWordTemp = "";
        }
    }




    string Encoded = "";
    for (int i=0;i<cipherSet.length()-1;i++){
        if (cipherSet[i] == 'U'){
            Encoded += turnUpper(iFakeWord[i%n]);
        }
        else {
            Encoded += turnLower(iFakeWord[i%n]);
        }
    }
    if (cipherSet[cipherSet.length()-1] == 'U'){
            Encoded += turnUpper(getFirstLetter(iFakeWord[(cipherSet.length()-1)%n]));
        }
    else {
            Encoded += turnLower(getFirstLetter(iFakeWord[(cipherSet.length()-1)%n]));
        }


    return Encoded;
}



int main() {
    string cipher; getline(cin,cipher);
    string input;
    while (getline(cin,input)){
        char command = input[0];
        input = input.substr(2,input.length()-2);

        if (command == 'D'){cout << decodeString(input) << endl;}
        else if (command == 'E') {cout << encodeString(cipher,input) << endl;}
    }
}
