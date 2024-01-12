//05_String_25

#include <iostream>
#include <math.h>
using namespace std;

string getfirstDigit (string A , string N) {
    int iA = A[A.length()-1] - '0';
    int iN;
    if (N.length() > 1){
        iN = stoi(N.substr(N.length()-2,2));
        if (N.substr(N.length()-2,N.length()-1) == "00"){
        iN = 4;
    }
    }
    else {iN= N[N.length()-1] - '0';}
    
   


    
    if (iN>4)iN = iN%4;
    if (iN == 0){
        iN = 4;
    }

    if (N == "0"){
        iN = 0;
    }

    int answer;
    answer = pow(iA,iN);

    string str_answer = to_string(answer);
    string temp = "";
    temp += str_answer[str_answer.length()-1];

    return temp;

}



int main() {
    string A,N;

    while (cin >> A) {
        cin >> N;
        cout << ">> " << getfirstDigit(A,N) << "\n";

    }
}