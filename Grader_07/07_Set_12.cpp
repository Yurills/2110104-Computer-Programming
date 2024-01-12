#include <iostream>
#include <set>
using namespace std;

int main() {
    int input;
    set<int> setInput;
    int count = 0;
    int answer = -1;
    while (cin >> input) {
        ++count;
        if (setInput.find(input) == setInput.end()) {
            setInput.insert(input);
        }
        else {
            answer = count;
            break;
        }

    }
    cout << answer;


}