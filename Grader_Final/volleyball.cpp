#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int main() {
    int n; cin >>n;
    
    
    while (n--) { //per game
        pair<string, vector<int>> infoA;
        pair<string, vector<int>> infoB;
        string winner = "";
        string teamA, teamB;
        cin >> teamA >> teamB;
        string currentScore;
        cin >> currentScore;
        while (currentScore != "*"){ // per score
            //check NUM
            int scoreA,scoreB;
            string container = "";
            
            for (auto e:currentScore){
                if (e == '-'){
                    scoreA = stoi(container);
                    container = "";
                }
                else {
                    container += e;
                }
                
                
            }
            scoreB = stoi(container);

            infoA.first = teamA;
            infoB.first = teamB;
            (infoA.second).push_back(scoreA);
            (infoB.second).push_back(scoreB);

            cin >> currentScore;

        }


        vector<int> pointA = infoA.second;
        vector<int> pointB = infoB.second;
        int sumA=0,sumB=0;
        for (int i=0;i<(pointA).size();i++){
            if (pointA[i]>pointB[i]){
                sumA++;
            }
            else {
                sumB++; 
            }
        }
    
        if (sumA > sumB){
            infoA.first = "*"+infoA.first;
        }
        else {
            infoB.first = "*"+infoB.first;
        }

        cout << infoA.first << " " << sumA << " [ ";
        for (auto e:pointA){
            cout << e << " ";
        }
        cout << "]" << endl;    

        cout << infoB.first << " " << sumB << " [ ";
        for (auto e:pointB){
            cout << e << " ";
        }
        cout << "]" << endl;    
    

    }
}