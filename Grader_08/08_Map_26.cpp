#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

bool containsSpace (string line){
    for (auto e:line){
        if (e == ' '){
            return true;
        }
    }
    return false;
}



int main() {
    map<string, set<string>> stations;
    set<string> temp;
    
    string input;
    while(getline(cin, input)){
        if (containsSpace(input) == false){
            break;
        }
        string input1 = "",input2 = "";
        bool front = true;
        for ( auto e : input){
            if (e != ' ' && front){
                input1 += e;
            }
            else if (e != ' ' && !front){
                input2 += e;
            }
            else {
                front = false;
            }
        }

        if (stations.find(input1)==stations.end()){
            temp.clear();
            temp.insert(input2);
            stations[input1] = temp;
        }
        else {
            ((*(stations.find(input1))).second).insert(input2);
        }

        if (stations.find(input2)==stations.end()){
            temp.clear();
            temp.insert(input1);
            stations[input2] = temp;
        }
        else {
            ((*(stations.find(input2))).second).insert(input1);
        }

       
    }

    string output = input;
    set<string> answer;
    auto itr = stations.find(output);
    if (itr == stations.end()){
        cout << output;
    }
    else {
        for (auto e : (*itr).second){
            answer.insert(e);
            
            auto itr2 = stations.find(e);
            for (auto i : (*itr2).second){
                answer.insert(i);
            }
        }
        
        for (auto e : answer) {
            cout << e << endl;
        }
    }
}