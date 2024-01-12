#include <iostream>
#include <string>

using namespace std;

int findIndexfromContries(string input, string countries[],int n){
    for (int i=0;i<n;i++){
        if (input == countries[i]){
            return i;
        }
    }
    return 0;
}


int main() {
    int n;cin>>n;
    string countries[n];
    int fees[n];
    for (int i=0;i<n;i++){
        cin >> countries[i] >> fees[i];
    }
    cin.ignore(256,'\n');

    string input;
    getline(cin,input);
    
    int destination_size = (input.length()+1)/7;
    string destination[destination_size];
    for (int i=0;i<destination_size;i++){
        destination[i] = input.substr(4+(7*i),2);
    }

    int answer = 0;
    for (int i=1;i<destination_size;i++){
        if (destination[i]!=destination[i-1]){
            answer+= fees[findIndexfromContries(destination[i],countries,n)];
        }
    }
    cout << answer;
}