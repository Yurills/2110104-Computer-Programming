#include <iostream>
#include <set>
using namespace std;

int main() {
    int num; cin >> num;
    int input;

    set<int> numbers;
    while (cin >> input){
        if (input <= num && input != num/2) {
            numbers.insert(input);
            
        }
    }
    int count = 0;
    int k;
    for (auto i = numbers.begin(); i != numbers.end() ; i++) {
        auto a = numbers.find(abs(num - (*i)));
        if (a != numbers.end()) {
            ++count;
            numbers.erase(a);
        }
    }

    cout << count;

}