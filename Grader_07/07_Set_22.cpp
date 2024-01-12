#include <iostream>
#include <set>
using namespace std;

set<int> turnLineToSet(string line){
    set<int> setInt;
    line += " ";
    string container = "";
    for (auto e:line){
        if (e!=' '){
            container += e;
        }
        else {
            setInt.insert(stoi(container));
            container = "";
        }
    }
    return setInt;
}
void showSet(set<int> input){
    if (input.size() == 0){
        cout << "empty set";
    }
    else {
        for (auto e:input){
            cout << e << " ";
        }
    }
    cout<<endl;
}

int main() {
    string line;
    set<int> current_set;

    set<int> unions, intersects, diffs;
    
    getline(cin,line);
    set<int> first_set;
    first_set = turnLineToSet(line);
    
    //set up
    for (auto e:first_set){
            unions.insert(e);
            intersects.insert(e);
            diffs.insert(e);
    }

    while(getline(cin, line)) {
        current_set = turnLineToSet(line);

        //unions
        for (auto e:current_set){
            unions.insert(e);
        }

        //intersects
        set<int> temp;
        for (auto e:current_set){
            if (intersects.find(e) != intersects.end()){
                temp.insert(e);
            }
        }
        intersects = temp;

        //diffs 
        for (auto e:current_set) {
            if (diffs.find(e) != diffs.end()){
                diffs.erase(diffs.find(e));
            }
        }
    }

    cout << "U: "; showSet(unions);
    cout << "I: "; showSet(intersects);
    cout << "D: "; showSet(diffs);
}