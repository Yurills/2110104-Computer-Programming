//05_String_Global-String-Alignmer

#include <iostream>

using namespace std;

int iterateFromAtoB (string a, string b){
    int answer = 0;
    int count = 0;

    for (int i=0;i<b.length();i++){
        count = 0;
        for (int j=0;j<a.length();j++){
            if (i+j>b.length()-1){break;}
            if (a[j] == b[j+i]){
                count++;
            }

        }
        if (count > answer){
            answer = count;
        }
    }
    return answer;
}

int getIndex_iterateFromAtoB (string a, string b){
    int answer = 0;
    int count = 0;
    int index = 0;

    for (int i=0;i<b.length();i++){
        count = 0;
        for (int j=0;j<a.length();j++){
            if (i+j>b.length()-1){break;}
            if (a[j] == b[j+i]){
                count++;
            }

        }
        if (count > answer){
            answer = count;
            index = i;
        }
    }
    return index;
}

string printWhitespace (int index , string a){
    string answer = "";
    while (index--){
        answer+="-";
    }
    answer+=a;

    return answer;
}




int main() {
    string X,Y;
    cin>>X>>Y;
    int index;
    int nX = iterateFromAtoB(X,Y);
    int nY = iterateFromAtoB(Y,X);

    if (nX > nY){
        index = getIndex_iterateFromAtoB(X,Y);
        cout << printWhitespace(index,X);
        cout << endl << Y;
        cout << endl << nX;

    }
    else { 
        index = getIndex_iterateFromAtoB(Y,X);
        cout << endl << X;
        cout << endl << printWhitespace(index,Y);
        cout << endl << nY;
    }
    
}