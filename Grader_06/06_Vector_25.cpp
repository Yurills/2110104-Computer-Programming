//06_Vector_★★_Upgrade
#include <iostream>
#include <vector>
#include <utility>
using namespace std;

string upgrade (string a){
    string grade_list[] = {"A","A","B+","B","C+","C","D+","D","F"};
    for (int i=1;i<9;i++){
        if (a == grade_list[i]){
            string b = grade_list[i-1];
            //cout << b;
            return b;
        }
    }
    return "A";
}



int main() {
    vector<pair<string, string>> container;
    pair<string, string> content;

    string studentID,studentGrade;
    cin >> studentID;
    while (studentID != "q"){
        content.first = studentID;
        cin >> studentGrade;
        content.second = studentGrade;

        container.push_back(content);
        
        cin >> studentID;
    }
    string inputID;
    while (cin >> inputID){
        for ( auto &i : container){
            if (i.first == inputID){
                i.second = upgrade(i.second);
            }
        }
    }

    for (auto i : container){
        cout << i.first << ' ' << i.second << endl;

    }
}