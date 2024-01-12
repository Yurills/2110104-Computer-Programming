#include <iostream>
#include <math.h>
using namespace std;

bool checkIfLiftPassed (int index ,int liftStart[], int liftEnd[], int personStart){
    //check go-up or go-down
    if (liftStart[index]<liftEnd[index]){
        for (int i=liftStart[index];i<=liftEnd[index];i++){
            if (personStart == i){return true;}
    }
    }
    else {
        for (int i=liftStart[index];i>=liftEnd[index];i--){
            if (personStart == i){return true;}
        }
    }
    return false;
}

int calculateFloorIfLiftPassed (int index, int liftStart[], int liftEnd[], int personStart, int personEnd ){
    bool GoSameWay;
    int directionLift = liftEnd[index] - liftStart[index];
    int directionPerson = personEnd - personStart;

    if (directionLift*directionPerson >= 0){
        GoSameWay = true;
    }
    else {
        GoSameWay = false;
    }

    int burden = 0;
    if (GoSameWay){
        burden += abs(personEnd - liftEnd[index]);
    }
    else {
        burden += abs(personStart - liftEnd[index]) + abs(personEnd - personStart);
    }
    return burden;
}

int calculateFloorIfNotPassed (int index, int liftStart[],int liftEnd[], int personStart, int personEnd){
        int burden = 0;
    burden += abs(personStart - liftEnd[index]) + abs(personEnd - personStart);
    return burden;
}



int main(){
    int liftAmount; cin >> liftAmount;
    int liftIndex[liftAmount], liftStart[liftAmount], liftEnd[liftAmount];
    for (int i=0;i<liftAmount;i++){
        cin >> liftIndex[i] >> liftStart[i] >> liftEnd[i];
    }

    int caseAmount; cin >> caseAmount;
    int personStart,personEnd;
    for (int i=0;i<caseAmount;i++){
        cin >> personStart >> personEnd;


        int min = 100;
        int burden;
        int indexLowestburden = 0;
        for (int j=0;j<liftAmount;j++){
            if (checkIfLiftPassed(j, liftStart, liftEnd, personStart)){
                burden = calculateFloorIfLiftPassed(j, liftStart, liftEnd, personStart, personEnd);
            }
            else  {
                burden = calculateFloorIfNotPassed(j, liftStart, liftEnd, personStart, personEnd);
            }

            if (burden < min){
                min = burden;
                indexLowestburden = j;
            }
            else if (burden == min){
                if (liftIndex[indexLowestburden] > liftIndex[j]){
                    indexLowestburden = j;
                }
            }
        }
        cout << ">> " << liftIndex[indexLowestburden] << "\n";
        
    }

}