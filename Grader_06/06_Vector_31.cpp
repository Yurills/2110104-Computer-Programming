//06_Vector_★★★_Bingo
#include <iostream>
#include <vector>
#include <utility>
using namespace std;

void checkBall (vector<pair<bool, string>> &row, string input) {
    for (auto &e : row){
        if (e.second == input){
            e.first = true;
            break;
        }
    }
}

bool bingoACROSS (vector<pair<bool, string>> &rowB, vector<pair<bool, string>> &rowI, vector<pair<bool, string>> &rowN, vector<pair<bool, string>> &rowG, vector<pair<bool, string>> &rowO) {
    for (int i=0;i<5;i++){
        if (rowB[i].first && rowI[i].first && rowN[i].first && rowG[i].first && rowO[i].first){return true;}
    }
    return false;
}

bool bingoDOWN (vector<pair<bool, string>> &rowB, vector<pair<bool, string>> &rowI, vector<pair<bool, string>> &rowN, vector<pair<bool, string>> &rowG, vector<pair<bool, string>> &rowO, string input) {
    char key = input[0];
    if (key == 'B'){for (auto e : rowB){if (!e.first){return false;}}}
    else if (key == 'I'){for (auto e : rowI){if (!e.first){return false;}}}
    else if (key == 'N'){for (auto e : rowN){if (!e.first){return false;}}}
    else if (key == 'G'){for (auto e : rowG){if (!e.first){return false;}}}
    else if (key == 'O'){for (auto e : rowO){if (!e.first){return false;}}}
    return true;
}

bool bingoANGLEtopLeft (vector<pair<bool, string>> &rowB, vector<pair<bool, string>> &rowI, vector<pair<bool, string>> &rowN, vector<pair<bool, string>> &rowG, vector<pair<bool, string>> &rowO) {
    if (rowB[0].first && rowI[1].first && rowG[3].first && rowO[4].first){return true;}
    return false;
}

bool bingoANGLEtopRight (vector<pair<bool, string>> &rowB, vector<pair<bool, string>> &rowI, vector<pair<bool, string>> &rowN, vector<pair<bool, string>> &rowG, vector<pair<bool, string>> &rowO) {
    if (rowB[4].first && rowI[3].first && rowG[1].first && rowO[0].first){return true;}
    return false;
}

int main() {
    string bingo;getline(cin,bingo);
    

    vector<pair<bool, string>> rowB;
    vector<pair<bool, string>> rowI;
    vector<pair<bool, string>> rowN;
    vector<pair<bool, string>> rowG;
    vector<pair<bool, string>> rowO;
    pair<bool, string> container = make_pair(false,"");

    string input;
    for (int i=0;i<5;i++){
        cin >> input;container.second = "B" + input;
        rowB.push_back(container);
        cin >> input;container.second = "I" + input;
        rowI.push_back(container);
        cin >> input;container.second = "N" + input;
        rowN.push_back(container);
        cin >> input;container.second = "G" + input;
        rowG.push_back(container);
        cin >> input;container.second = "O" + input;
        rowO.push_back(container);
    }
    rowN[2].first = true;
    bool across,down,topleft,topright = false;
    vector<string> balls;
    int posx; char posy;
    while (cin>>input){
        balls.push_back(input);
        posy = input[0];
        checkBall(rowB,input);
        checkBall(rowI,input);
        checkBall(rowN,input);
        checkBall(rowG,input);
        checkBall(rowO,input);

        across = bingoACROSS(rowB,rowI,rowN,rowG,rowO);
        down = bingoDOWN(rowB,rowI,rowN,rowG,rowO,input);
        topleft = bingoANGLEtopLeft(rowB,rowI,rowN,rowG,rowO);
        topright = bingoANGLEtopRight(rowB,rowI,rowN,rowG,rowO);

        int index;
        if (across || down || topleft || topright){
            cout << balls.size() << "\n";}
        if (across){
            for (int i=0;i<5;i++){
                if (rowB[i].second == input || rowI[i].second == input || rowN[i].second == input|| rowG[i].second == input || rowO[i].second == input){
                    index = i; 
                    break;
                }  
        
                }
            if (index != 2) {            
            cout << rowB[index].second << ", " << rowI[index].second << ", " << rowN[index].second << ", " << rowG[index].second << ", " << rowO[index].second << endl;
            }
            else {
            cout << rowB[index].second << ", " << rowI[index].second << ", " << rowG[index].second << ", " << rowO[index].second << endl;
            }
        }
        
        if (down){
            char key = input[0];
            if (key == 'B'){
                cout << rowB[0].second << ", " << rowB[1].second << ", " << rowB[2].second << ", " << rowB[3].second << ", " << rowB[4].second << endl;}
            else if (key == 'I'){
                cout << rowI[0].second << ", " << rowI[1].second << ", " << rowI[2].second << ", " << rowI[3].second << ", " << rowI[4].second << endl;}
            else if (key == 'G'){
                cout << rowG[0].second << ", " << rowG[1].second << ", " << rowG[2].second << ", " << rowG[3].second << ", " << rowG[4].second << endl;}
            else if (key == 'O'){
                cout << rowO[0].second << ", " << rowO[1].second << ", " << rowO[2].second << ", " << rowO[3].second << ", " << rowO[4].second << endl;}
            else {
                cout << rowN[0].second << ", " << rowN[1].second << ", " << rowN[3].second << ", " << rowN[4].second << endl;}
        }
        
        if (topleft){
            cout << rowB[0].second << ", " << rowI[1].second << ", " << rowG[3].second << ", " << rowO[4].second << endl;
        }

        if (topright){
            cout << rowB[4].second << ", " << rowI[3].second << ", " << rowG[1].second << ", " << rowO[0].second << endl;
        }

        if (across || down || topleft || topright){
            break;}

    }
        
}

    

    

