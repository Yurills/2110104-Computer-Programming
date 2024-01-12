#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    string fac[] = {"01","02","20","21","22","23","24","25","26","27","28","29","30","31","32","33","34","35","36","37","38","39","40","51","53","55","58"};
    string c;cin>>c;

    for (int i=0;i<28;i++){
        if (fac[i]==c){
            cout << "OK";
            break;
        }
        if (i==27){
            cout << "Error";
        }
        }
}
