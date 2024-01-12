#include <iostream>
using namespace std;



int findInversion(int line[] , int n) {
    int inv = 0;
    int line_length = (n*n)-1;
    for (int i=0;i<line_length;i++){
        for (int j=i+1;j<line_length;j++){
            if (line[i]>line[j]){
                inv++;
            }
        }
    }
    return inv;
}

int main() {
    
    int n;cin >> n;
    int tiles[n][n];
    for (int i=0;i<n;i++){
       for (int j=0;j<n;j++){
        cin >> tiles[i][j];
       } 
    }

    int line[n*n-1];
    int count = 0;
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            if (tiles[i][j]){
                line[count] = tiles[i][j];
                count++;
            }
        }
    }

    //check zero position
    bool Zero_is_Odd;
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            if (tiles[i][j]==0){
                if (i%2){
                    Zero_is_Odd = true;
                }
                else {Zero_is_Odd = false;}
                break;
            }
        }
    }

    //check for answer
    string answer = "NO";

    if (n%2){ //Odd Row
        if (findInversion(line,n)%2 == 0){ //Even Inversion  
            answer = "YES";
        }
    }   
    else { //Even Row
        if (findInversion(line,n)%2 && Zero_is_Odd == false) { //Odd Inversion Even Zero
            answer = "YES";
        }
        else if (findInversion(line,n)%2 == 0 && Zero_is_Odd) { //Even Inversion Odd Zero
            answer = "YES";
        }
    }

    cout << answer;






}