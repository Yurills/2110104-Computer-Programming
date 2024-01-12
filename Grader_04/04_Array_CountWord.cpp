#include <iostream>

using namespace std;

char turnLow (char a){
    if (a >=65 && a<=90){
        return a += 32;
    }
    else {return a;}
    
}

int findIndex (char a){
    return a - 'a';
}


int main() {
    string input;
    getline(cin,input);

    string alpha[26];
    int alpha_count[26] = {};
    
    for (int i=0;i<26;i++){
        alpha[i] = 'a'+i;
    }

    for (int i=0;i<input.length();i++){
        if (isalpha(input[i])){
        input[i] = turnLow(input[i]);
        alpha_count[findIndex(input[i])]++;
        }
    }

    for (int i=0;i<26;i++){
        if (alpha_count[i] != 0) {
            cout << alpha[i] << " -> " << alpha_count[i] << endl;
        }
    }

}
