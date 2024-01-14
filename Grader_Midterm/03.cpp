#include <iostream>
#include <math.h>
using namespace std;

float TurnGrade(string grade, string gradesNum[], float grades[]){
    int answer = 0;
    int index = 0;
    for (int i=0;i<8;i++){
        if (grade == gradesNum[i]){
            index = i;
        }
    }
    return grades[index];

}



int main() {
    float grades[] ={0.0, 1.0, 1.5, 2.0, 2.5, 3.0, 3.5, 4.0};
    string gradesNum[] = {"F","D","D+","C","C+","B","B+","A"};

    int n;cin>>n;
    string grade;
    float multiply;
    float sum = 0;
    float divide = 0;
    for (int i=0;i<n;i++){
        cin >> grade >> multiply;
        sum += TurnGrade(grade,gradesNum,grades)*(multiply);
        divide += multiply;
    }

    float answer = sum/divide;
    cout << round(answer*100)/100;

}