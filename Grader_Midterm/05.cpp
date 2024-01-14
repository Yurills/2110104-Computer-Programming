#include <iostream>
using namespace std;

int min_start (int start[], int n){
    int min = start[0];
    for (int i=1;i<n;i++){
        if (start[i] < min){
            min = start[i];
        }
    }
    return min;
}

int max_stop (int stop[], int n){
    int max = stop[0];
    for (int i=1;i<n;i++){
        if (stop[i] > max){
            max = stop[i];
        }
    }
    return max;
}


int main() {
    int n;cin>>n;
    int start[n],stop[n];
    for (int i=0;i<n;i++){
        cin >> start[i] >> stop[i];
    }
    
    int max_count = 0;
    for (int i=0 ;i<n;i++){
        int count=1;
        for (int j=i+1;j<n;j++){
            if (start[i] < stop[j] && stop[i] > start[j] ){
                count++;
            }
        }

        if (count > max_count){
            max_count = count;
        }

    }

    cout << max_count;


    
    


}