//06_Vector_★_Back_n_Front
#include <iostream>
#include <vector>
using namespace std;

void push_front (int input , vector<int> &v){
    v.insert(v.begin(),input);
}


int main() {
    vector<int> v;
    int n;cin>>n;
    int input;
    int i=1;
    while (n--){
        cin >> input;
        if (i%2){
            v.push_back(input);
        }
        else {
           
            push_front(input ,v);
        }
        i++;
    }
    while (cin >> input){
        if (input == -1){break;}
        else {
            if (i%2){
                v.push_back(input);
        }   
            else {
                push_front(input ,v);
        }
            i++;
        }

    }
    cout << "[";
    for (int j=0;j<i-2;j++){
        cout << v[j] << ", ";
    }
    cout << v[i-2];
    cout << "]";
}