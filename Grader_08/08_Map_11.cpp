#include <iostream>
#include <map>
using namespace std;

int main() {
    int map_amount; cin>>map_amount;
    map<string,string> names;

    string name,nickname;
    for (int i=0;i<map_amount;i++){
        cin >> name >> nickname;
        names[name] = nickname;
        names[nickname] = name;
    }

    int output_amount; cin>>output_amount;
    string output;
    for (int i=0;i<output_amount;i++) {
        cin>>output;
        string answer = "Not found";
        if (names.find(output) != names.end()){
            answer = (*(names.find(output))).second;
            

        }
        cout << answer << endl;

    }
}