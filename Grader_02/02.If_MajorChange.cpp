#include <iostream>
#include <string>
#include <math.h>

using namespace std;

bool PassCheck(string Comp,string Cal1,string Cal2){
    if (Comp != "A"){
        return false;
    }
    else if(Cal1 == "D" || Cal1 =="F"){
        return false;
    }
    else if(Cal2 == "D" || Cal2=="F"){
        return false;
    }
    else return true;
}

int main() {
    string studentA,studentB;
    double scoreA,scoreB;
    string CompA,CompB,Cal1A,Cal1B,Cal2A,Cal2B;
    cin >> studentA >> scoreA >> CompA >> Cal1A >> Cal2A;
    cin >> studentB >> scoreB >> CompB >> Cal1B >> Cal2B;
    
    bool passA = PassCheck(CompA,Cal1A,Cal2A);
    bool passB = PassCheck(CompB,Cal1B,Cal2B);


    if (passA==false && passB==false){
        cout << "None";
    }
    else if (passA==true && passB==true){
        if (scoreA > scoreB){
            cout << studentA;
        }
        else if (scoreB > scoreA){
            cout << studentB;
        }
        else if (Cal1A < Cal1B){
            cout << studentA;
        }
        else if (Cal1B < Cal1A){
            cout << studentB;
        }
        else if (Cal2A < Cal2B){
            cout << studentA;
        }
        else if (Cal2B < Cal2A){
            cout << studentB;
        }
        else {cout << "Both";}
    }
    else if (passA==true && passB==false){
        cout << studentA;
    }
    else if (passA==false && passB==true){
        cout << studentB;
    }

}

