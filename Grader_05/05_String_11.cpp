//05_String_Decode_Secret
#include <iostream>
#include <string>
using namespace std;

string decodeString (string input , char symbol){
    string temp = "" , output = "";
    for (int i=0;i<input.length();i++){
        if (temp == ""){
            if (input[i] == symbol){
                temp += input[i];
            }
        }
        else {
            if (input[i] == symbol){
                output  += temp.substr(1,temp.length()-1);
                temp = "";
            }
            else {
                temp += input[i];
            }
        }
    }
    return output;
}

int main() {
    string input;
    string decode = "";
    char symbol;
    while (getline(cin,input)){
        symbol = input[input.length()-1];
        cout << decodeString (input, symbol) << "\n";

        if (input == ""){
            break;
        }
    }
}

