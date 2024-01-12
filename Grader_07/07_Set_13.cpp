#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
    set<string> winners;
    set<string> losers;
    string winner;
    string loser;

    while (cin >> winner){
        cin >> loser;
        winners.insert(winner);
        losers.insert(loser);

    }

    bool found = false;
    vector<string> realWinner;
    for (auto a=winners.begin(); a!=winners.end();a++){
        if (losers.find(*a) == losers.end()) {
            realWinner.push_back(*a);
            found = true;
        }
    }

    if (found){
        for (auto e:realWinner){
            cout << e << " ";
        }
    }
    else {
        cout << "None";
    }
}