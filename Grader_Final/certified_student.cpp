#include <iostream>
#include <map>
#include <vector>
#include <set>
using namespace std;

int main() {
    map<string, int> scores;
    set<int, greater<int>> score_order;
    int n; cin >> n;
    while (n--){
        string student; int score;
        cin >> student >> score;
        score_order.insert(score);
        auto itr = scores.find(student);
        if (itr != scores.end()){
            if (score > (*itr).second){
                (*itr).second = score;
            }
        }
        else {
            scores[student] = score;
        }

    }
    int output; cin >> output;
    if (output > score_order.size()){
        output = score_order.size();
    }

    int count = 1;
    for (auto itr = score_order.begin(), end = next(itr, output);itr!=end;itr++){
        
        if (count > output){
            break;
        }
        
        cout << (*itr) << " ";
        
        for (auto e : scores){
            if (e.second == (*itr)){
                count++;
                cout << e.first << " ";
            }
        }
        
        cout << endl;


    }
    
    
}