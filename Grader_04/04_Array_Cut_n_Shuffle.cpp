#include <iostream>
#include <string>


using namespace std;

void Cut(string cards[], int n){
    for (int i=0;i<n/2;i++){
        swap(cards[i],cards[i+n/2]);
    }
}

void Shuffle (string cards[], int n) {
    string temp[n];
    string cardcopy[n];
    for (int i=0;i<n/2;i++){
        cardcopy[i] = cards[i];
    }
    for (int i=0;i<n/2;i++){
        temp[i]=cards[i+n/2];
    }
    for (int i=0;i<n/2;i++){
            cards[2*i+1] = temp[i];
            cards[2*i] = cardcopy[i];
    }

}




int main() {
    int n; cin>>n;
    string cards[n];
    
    for (int i=0;i<n;i++){
        cin >> cards[i];
    }
    cin.ignore(1024,'\n');
    string input;
    getline(cin,input);
    for (int i =0;i<input.length();i++){
        if (input[i]=='C'){
            Cut(cards,n);
        }
        else if (input[i]=='S'){
            Shuffle(cards,n);
        }
    }
    for (int i=0;i<n-1;i++){
        cout << cards[i] << " ";
    }
    cout << cards[n-1];
}

