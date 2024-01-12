//05_String_Camel_Split
#include <iostream>
#include <string>
using namespace std;

string CamelSplit(string input) {
    string temp = ""; temp += input[0];
    string answer = "";
    for (int i=1;i<input.length();i++){
        if (isupper(input[i])){
            answer += temp + ", ";
            temp = input[i];
        }
        else if (isdigit(input[i])){
            if (isdigit(input[i-1])){
                temp += input[i];
            }
            else {
                answer += temp + ", ";
                temp = input[i];
            }
        }
        else {
            if (isdigit(input[i-1])){
                answer += temp + ", ";
                temp = input[i];
            }
            else {
                temp += input[i];
            }
        }
    }
    answer += temp;
    return answer;
}


int main() {
    string input;
    getline(cin,input);
    cout << CamelSplit(input);
    
}