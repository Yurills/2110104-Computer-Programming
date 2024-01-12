//06_Vector_★★★_FirstFit_BestFit
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
    string operate; cin >> operate;
    int input; vector<int> vInput;
    while(cin>>input) {vInput.push_back(input);}

    pair<int, int> container; //groupNumber , item
    vector<pair<int ,int>> itemGroup;
    int groupNumber = 0;

    if (operate == "first") {
        container.first = groupNumber;
        container.second = vInput[0];
        vInput.erase(vInput.begin());
        itemGroup.push_back(container);

        int GroupSum = 0;
        for (auto e : vInput);




    }

}