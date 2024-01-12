//06_Vector_★_UniqueCount
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int o;
    vector<int> input;
    vector<int> output;
    while (cin>>o){
        input.push_back(o);
    }
    
    sort(input.begin(),input.end());
    int temp = input[0];
    int count = 1;
    for (int i=1;i<input.size();i++){
        if (temp!=input[i]){
            output.push_back(temp);
            count++;
        }
        temp = input[i];
    }
    output.push_back(temp);
    

    cout << count << "\n";
    if (count < 10){
        for (int i=0;i<count-1;i++){
            cout << output[i] << " ";
        }
        cout << output[count-1];
    }
    else {
        for (int i=0;i<9;i++){
            cout << output[i] << " ";
        }
        cout << output[9];
    }
    

}