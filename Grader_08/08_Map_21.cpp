#include <iostream>
#include <map>
#include <vector>
#include <utility>
using namespace std;

int main() {
    string name,animal;
    vector<pair<string, string>> atlas; //name : animal
    pair<string, string> atlas_container;
    map<string, int> order;
    
    int count = 0;
    while (cin >> name){
        cin >> animal;
        atlas_container = make_pair(name,animal);
        atlas.push_back(atlas_container);
        
        if (order.find(animal) == order.end()){
            order[animal]=count;
            count++;
        }
    }

    map<int ,string> sOrder;
    for ( auto e:order ){
        sOrder[e.second] = e.first;
    }

    for (auto e:sOrder){
        cout << e.second << ": ";
        for (auto i:atlas){
            if ( e.second == i.second) {
                cout << i.first << " ";
            }
        }
        cout << endl;
    }
    
}