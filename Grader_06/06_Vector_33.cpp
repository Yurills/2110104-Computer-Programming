//06_Vector_★★★_PartyList
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <tuple>
using namespace std;

int main() {
    vector<string> reps;
    vector<double> scores;

    string rep;
    int score;
    cin >> rep;
    while (rep!="END"){
        cin >> score;
        reps.push_back(rep);
        scores.push_back(score);
        cin >> rep;
    }

    long double avg_score = 0;
    for (auto e : scores) {
        avg_score += e;
    }
    avg_score /= 100;

    vector<double> relScores;
    vector<double> relScoreFLOOR;
    vector<double> relScoreREMAINDER;
    for (auto e : scores){
        relScoreFLOOR.push_back(floor(e/avg_score));
        relScoreREMAINDER.push_back(e/avg_score - (floor(e/avg_score)));
    }

    int sumPeople = 0;
    for (auto e : relScoreFLOOR){
        sumPeople += e;
    }

    auto maxITR = max_element(relScoreREMAINDER.begin(),relScoreREMAINDER.end());
    int maxindex = maxITR - relScoreREMAINDER.begin(); 
    for (int i=sumPeople-1; i<99;i++){
        relScoreFLOOR[maxindex]++;
        relScoreREMAINDER[maxindex] = 0;
        maxITR = max_element(relScoreREMAINDER.begin(),relScoreREMAINDER.end());
        maxindex = maxITR - relScoreREMAINDER.begin(); 

    }

    tuple <int, double, string> results;
    vector <tuple<int, double, string>> answer;

    for (int i=0;i<relScoreFLOOR.size();i++){
        if (relScoreFLOOR[i] > 0) {
            results = make_tuple(relScoreFLOOR[i], scores[i], reps[i]);
            answer.push_back(results);
        }
    }

    sort(answer.begin(), answer.end(), greater<tuple<int ,double ,string>>());

    for (auto e:answer){
        cout << get<2>(e) << " " << get<0>(e) << " " << get<1>(e) << endl;
    }

}