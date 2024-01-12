#include <iostream>
#include <string>
using namespace std;

string readNum (int number){
    switch (number)
    {
    case 1: return "one";
    case 2: return "two";
    case 3: return "three";
    case 4: return "four";
    case 5: return "five";
    case 6: return "six";
    case 7: return "seven";
    case 8: return "eight";
    case 9: return "nine";
    default: return "";
    }}

string readTen (int ten , int one){
    int number1 = ten*10;
    int number = number1 + one;
    string answer ="";
    if (number1 == 10){
        switch (number){
            case 10: answer += "ten";break;
            case 11: answer += "eleven";break;
            case 12: answer += "twelve";break;
            case 13: answer += "thirteen";break;
            case 14: answer += "fourteen";break;
            case 15: answer += "fifteen";break;
            case 16: answer += "sixteen";break;
            case 17: answer += "seventeen";break;
            case 18: answer += "eighteen";break;
            case 19: answer += "nineteen";break;
            default: answer += "";break;
        }
    }
    else{
        switch (number1){
        case 20: answer += "twenty";break;
        case 30: answer += "thirty";break;
        case 40: answer += "forty";break;
        case 50: answer += "fifty";break;
        case 60: answer += "sixty";break;
        case 70: answer += "seventy";break;
        case 80: answer += "eighty";break;
        case 90: answer += "ninety";break;
        default: answer += "";
        }
        if (one){
            answer += " " + readNum(one);
        }
    }
    return answer;
}

string readPrefix(int digit , string number){
    if (number != ""){
    switch (digit){
        case 3: return "hundred ";
        case 4: return "thousand ";
        case 6: return "hundred ";
        case 7: return "million ";
        case 9: return "hundred ";
        case 10: return "billion ";
        case 12: return "hundred ";
        case 13: return "trillion ";
        case 15: return "hundred ";
        default: return "";
        }
    }
    else return "";
}



;
int main() {
    string input; cin>>input;
    int n = input.length();
    int number[n];
    for (int i=0;i<n;i++){
        number[i] = input[i] - '0';
    }

    string digit_name[n] = {};
    string answer = "";
    if (input == "0") answer = "zero";
    
    for (int i=0;i<n;i++){
        if (number[i]){
            if ((n-i)%3==2 || (n-i) == 2){
                digit_name[i] = readTen(number[i],number[i+1]);
                digit_name[i+1] = "read";
                i++;
            }
            else {
                digit_name[i] = readNum(number[i]);
            }
        }
    }

    for (int i=0;i<n;i++){
        if (digit_name[i]!="" && digit_name[i]!="read" ){
            answer += digit_name[i] + " ";
        }
        answer += readPrefix((n-i),digit_name[i]);

    }
    
    if (answer[n-1] == ' '){
        answer.pop_back();
    }
    cout << answer;
}