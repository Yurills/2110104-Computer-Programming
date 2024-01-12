//05_String_Add_Numbers
#include <iostream>
#include <math.h>
using namespace std;

string addZero (string inputLow, string inputHigh)
{
    int length = inputHigh.length();
    string temp = "";
    for (int i=0;i<length;i++)
    {
        temp += '0';
    }

    for (int i=0;i<inputLow.length();i++){
        temp[length-1-i] = inputLow[inputLow.length()-1-i];
    }
    return temp;
}

string addition (string input1, string input2)
{
    int length = input1.length();
    int temp = 0;
    int tod = 0;
    string output = "";
    for (int i=0;i<length;i++){
        output += '0';
    }

    for (int i=length-1;i>=1;i--){
        temp = (input1[i] - '0') + (input2[i] - '0');
        if (tod){
            temp++;
        }
        tod = 0;
        if (temp >= 10){
            temp %= 10;
            tod++;
        }

        output[i] = (char) (temp + '0');
    }

    temp = (input1[0] - '0') + (input2[0] - '0');
    if (tod){
        temp++;
    }
    tod = 0;
    if (temp >= 10){
        temp%=10;
        tod++;
    }
    output[0] = (char) (temp + '0');
    if (tod) {
        output = '1' + output;
    }

    return output;

}


int main(){
    string input1 = "";
    string input2 = "";
    cin >> input1;
    while (cin>>input2){
        if (input2 == "END"){break;}
        
        if (input1.length() > input2.length()){
            string temp = input1;
            input1 = input2;
            input2 = temp;
        }

        input1 = addZero(input1,input2);


        input1 = addition(input1,input2);


    }
    cout << input1;
}