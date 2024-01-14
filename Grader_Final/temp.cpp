#include <iostream>
#include <map>
#include <vector>
#include <set>
using namespace std;

int main() {
    map<int, set<string>, greater<int>> scores;
    int n; cin >> n;
    while (n--){
        string student; int score;
        cin >> student >> score;
        auto itr = scores.find(score);
        if (itr == scores.end()){
            set<string> temp = {};
            temp.insert(student);
            scores[score] = temp;
        }
        else {
            ((*itr).second).insert(student);
        }
    }

    int output; cin >> output;
    set<string> shown;
    for (auto itr = scores.begin(), end = next((scores.begin()),output ); itr != end ;itr++){
        cout << (*itr).first << " ";
        for (auto e : (*itr).second){
            if (shown.find(e) == shown.end()){
                cout << e << " ";
            }
            shown.insert(e);
            
        }
        cout << endl;
    }
}