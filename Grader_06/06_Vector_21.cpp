//06_Vector_★★_BWT
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<string> word;
    string input;cin >> input;

    string mod = input + "$";
    for (int i=0;i<mod.length();i++){
        string temp = mod.substr(i,mod.length()-i);
        temp += mod.substr(0,i);
        word.push_back(temp);
    }
    sort(word.begin(),word.end());

    string cipher = "";
    string vec;
    for (int i=0;i<word.size();i++){
        // vec = word[i];
        // cipher += vec[vec.length()-1];


        cipher += (word[i])[word[i].length()-1];
        //cout << word[i] << endl;
    }
    cout << cipher;

    


}