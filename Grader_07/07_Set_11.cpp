//07_
#include <iostream>
#include <set>
using namespace std;

char lower( char i) {
    if (isupper(i)){
        i += 32;
    }
    return i;
}

int main() {
    multiset<char> letter1, letter2;
    string input;getline(cin, input);

    for (auto e : input){
        if (e != ' '){
        letter1.insert(lower(e));
        }
    }
    getline(cin,input);
    for (auto e : input) {
        if (e != ' ')
        letter2.insert(lower(e));
    }

    auto itr1 = letter1.begin();
    auto itr2 = letter2.begin();
    string answer = "YES";
    if (letter1.size() != letter2.size()) {
        answer = "NO";
    }
    while (itr1 != letter1.end()){
        if (*itr1 != *itr2){
            answer = "NO";
        }
        itr1++;
        itr2++;
    }
    cout << answer << endl;

    


}