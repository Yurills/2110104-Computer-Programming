//06_Vector_★★★_QueueTicket
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;








int main() {
    string operate;int params = 0;;
    int n; cin>>n;
    int ticketID = 0;
    int time = 0,startTime,deltaTime;float avg = 0;

    vector<pair<int ,int>> QueueTable;
    pair<int, int> timeAndTicket = make_pair(0,0);
    QueueTable.push_back(timeAndTicket); //create first element (not used)
    vector<int> addingQueueTime;
    int currentINDEX = 0;
    
    while (n--){
        cin >> operate;
        if (operate == "reset" || operate == "new" || operate == "order") {cin >> params;}

        if (operate == "reset") {
            ticketID = params;
        }

        if (operate == "new") { //make new ticket starting from "reset" ticket
            timeAndTicket.first = params;
            timeAndTicket.second = ticketID;
            QueueTable.push_back(timeAndTicket);
            cout << ">> ticket " << ticketID << endl;
            ticketID++;
        }

        if (operate == "next") { //increment to next INDEX 
            currentINDEX++;
            cout << ">> call " << QueueTable[currentINDEX].second << endl;
        }

        if (operate == "order") { 
            deltaTime = params - QueueTable[currentINDEX].first;
            addingQueueTime.push_back(deltaTime);
            cout << ">> qtime " << QueueTable[currentINDEX].second << " " << deltaTime << endl;
        }

        if (operate == "avg_qtime"){
            for (auto e:addingQueueTime){
                avg += e;
            }
            avg /= addingQueueTime.size();
            cout << ">> avg_qtime " << round(avg*100.0)/100.0 << endl;
            avg = 0;
        }

    }
}