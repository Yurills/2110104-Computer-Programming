#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;cin>>n;
    int graph[n];
    int count = 0;
    for (int i=0;i<n;i++){
        cin >> graph[i];
    }

    for (int i=1;i<n-1;i++) {
        if (graph[i]>graph[i-1] && graph[i]>graph[i+1]){
            count++;
        }
    }
    cout << count;
}