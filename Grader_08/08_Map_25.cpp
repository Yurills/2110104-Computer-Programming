#include <iostream>
#include <map>
#include <vector>
#include <set>
using namespace std;

int main() {
    int n;cin >> n;
    map<string, vector<string>> placeVisit;
    map<string, vector<string>> userInfo;
    vector<string> orders;
    
    while (n--) {
        string city;
        vector<string> cities;
        vector<string> visits;
        string userID; cin>>userID;
        orders.push_back(userID);
        
       

        while (cin >> city){
            if (city == "*"){
                break;
            }
            cities.push_back(city);

            auto itr = placeVisit.find(city);
            if (itr != placeVisit.end()){
                ((*itr).second).push_back(userID);
            }
            else {
                visits.clear();
                visits.push_back(userID);
                placeVisit[city] = visits;
            }

        }

        userInfo[userID] = cities ;
        cities.clear();
        
    }

    string userInput; cin >> userInput;
    vector<string> userVisits = (*(userInfo.find(userInput))).second;
    set<string> answer;

    for (auto e : userVisits){
        for (auto i : (*(placeVisit.find(e))).second){
            if (i != userInput){
            answer.insert(i);
            }
        }
    }

    for (auto e: orders){
        if (answer.find(e) != answer.end()){
            cout << ">> " << e << endl;
        }
    }

    if (answer.empty()){
        cout << ">> Not Found";
    }

}