#include <iostream>
#include <map>
#include <utility>
using namespace std;

int main() {
    int n;cin>>n;
    map<string, float> table;

    while(n--){
        string input1; cin>>input1;
        float input2; cin>>input2;
        table[input1] = input2;
    }

    pair<int, string> current;
    string currency; int value;
    cin >> value >> currency;
    current = make_pair(value,currency);

    cout << current.first << " " << current.second;

    string convert;
    while (cin>>convert){
            auto itr = table.find(current.second);
        
        if (current.second == "THB" && convert != "THB"){ //fromTHB
            itr = table.find(convert);
            value = (current.first/((*itr).second));
            current.first = value;
            current.second = convert;
        }
        else if (current.second != "THB" && convert == "THB"){ //toTHB
            value = (current.first * ((*itr).second));
            current.first = value;
            current.second = convert;
        }
        else {
            itr = table.find(convert);
            value = (current.first*(*table.find(current.second)).second)/(*itr).second;
            current.first = value;
            current.second = convert;
        }

        cout << " -> " << current.first << " " << current.second;


    }

}   