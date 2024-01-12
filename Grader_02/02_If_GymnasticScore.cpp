#include <iostream>
#include <math.h>

using namespace std;


int main(){
double scores[4];
for (int i=0;i<4;i++){
    cin>>scores[i];
}

double min = scores[0];
double max = scores[0];
for (int i=0;i<4;i++){
    if (scores[i]>max){
        max=scores[i];
    }
    if (scores[i]<min){
        min=scores[i];
    }

}
bool atMax = false,atMin = false;
for (int i=0; i<4; i++){
    if (scores[i]==max && atMax == false){
        scores[i]=0;
        atMax=true;
    }
    if (scores[i]==min && atMin == false){
        scores[i]=0;
        atMin=true;
    }
}
double avg = (scores[0]+scores[1]+scores[2]+scores[3])/2;

cout<< round(avg*100.0)/100.0 ;
}