//06_Vector_★_Split
#include <iostream>
#include <vector>

using namespace std;

vector<string> split(string line, char delimiter) {
    line += delimiter;
    string words ="";
    vector<string> str;
    for (int i=0;i<line.length();i++){
        if (line[i]!=delimiter){
            words += line[i];
        }
        else {
            if (words != ""){
                str.push_back(words);
                words = "";
            }
        }
    }
    return str;


}
int main() {
 string line;
 getline(cin, line);
 string delim;
 getline(cin, delim);
 for (string e : split(line, delim[0])) {
 cout << '(' << e << ')';
 }
}