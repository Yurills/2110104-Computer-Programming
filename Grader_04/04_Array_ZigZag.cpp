#include <iostream>
using namespace std;

int findMax(int A[], int B[], int n){
    int max = B[0];
    for (int i=0;i<n;i++){
        if (i%2==0){
            if(B[i]>max){
                max = B[i];
            }
            
        }
        else {
            if (A[i]>max){
                max = A[i];
            }
        }
    }
    return max;
}

int findMin(int A[], int B[], int n){
    int min = A[0];
    for (int i=0;i<n;i++){
        if (i%2==0){
            if(A[i]<min){
                min = A[i];
            }
            
        }
        else {
            if (B[i]<min){
                min = B[i];
            }
        }
    }
    return min;
}





int main() {
    int n;cin>>n;
    int X[n];
    int Y[n];
    int min[n];
    int max[n];
    for (int i=0;i<n;i++){
        cin >> X[i] >> Y[i];
    }
    string input;cin>>input;
    if (input=="Zig-Zag"){
        cout << findMin(X,Y,n) << " ";
        cout << findMax(X,Y,n);
    }
    else{
        cout << findMin(Y,X,n) << " ";
        cout << findMax(Y,X,n);
    }



}