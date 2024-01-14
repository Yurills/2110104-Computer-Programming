#include <iostream>
#include <map>
using namespace std;

int convertTime (string time){
    int answer = 0;
    time += " ";
    string container = "";
    for ( auto e : time) {
        if (e == ' '){
            answer += stoi(container);
            container = "";
        }
        else if (e == ':'){
            answer += stoi(container)*60;
            container = "";
        }
        else {
            container += e;
        }
    }
    return answer;
}

string convertTimeBack (int time){
    string front = to_string(time/60);
    string back = to_string(time%60);
    return front+":"+back;
}

int main() {
    string genre; string time;
    int nTime;

    map<string, int> chart;
    while (cin>>genre){
        cin>>genre>>genre>>time;
        nTime = convertTime(time);

        auto a = chart.find(genre);
        if (a == chart.end()){
            chart[genre] = nTime;
        }
        else {
            (*a).second += nTime;
        }
    }

    map<int, string, greater<int>> swappy;
    for (auto e : chart){
        swappy[e.second] = e.first;
    }
    
    int i=3;
    for (auto e:swappy){
        cout << e.second << " --> " << convertTimeBack(e.first) << endl;
        i--;
        if (i==0){
            break;
        }
    }

    
}