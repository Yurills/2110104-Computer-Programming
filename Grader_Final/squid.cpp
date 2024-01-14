#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;cin >> n;
    while (n--){ //per game
        int g; cin >> g;
        vector<long long int> players;
        while (g--) { //per round
            long long int player; cin >> player;
            players.push_back(player);
        }

        sort(players.begin(),players.end());
        
        long long int sum = 0;
        for (auto e: players){
            sum += e;
        }
        cout << (sum - players[0]) << endl;

    }
}