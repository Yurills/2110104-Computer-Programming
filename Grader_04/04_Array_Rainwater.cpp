#include <iostream>
using namespace std;

int findIndexLeftSize(int roads[] , int start , int finish){
    int max = start;
    for (int i=start;i>=finish;i--){
        if (roads[i] > roads[max]){
            max = i;
        }
    }
    return max;
}

int findIndexRightSize(int roads[] , int start , int finish){
    int max = start;
    for (int i=start;i<finish;i++){
        if(roads[i]>roads[max]){
            max = i;
        }
    }
    return max;
}

int checkMin(int a, int b){
    if (a>b)return b;
    else return a;
}



int main() {
    int n; cin>>n;
    int roads[n];
    int rainwater[n] = {};
    for (int i=0;i<n;i++)cin>>roads[i];

    int leftSize,rightSize;
    for (int i=1;i<n;i++){
        leftSize = roads[findIndexLeftSize(roads,i,0)];
        rightSize = roads[findIndexRightSize(roads,i,n)];
        rainwater[i] = checkMin(leftSize,rightSize) - roads[i];
    }

    int answer=0;
    for (int i=0;i<n;i++){
        answer += rainwater[i];
    }

    cout << answer;

}