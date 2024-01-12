    #include <iostream>
    #include <string>

    using namespace std;

    void pancakeSwap(int index,int pancakes[]){
        for (int i=0;i<=index/2;i++){
            swap(pancakes[i],pancakes[index-i]);
        }
    }

    int checkHigh (int pancakes[],int n){
        int max=pancakes[0];
        int imax=0;
        for (int i=0;i<n;i++){
            if (pancakes[i]>max){
                max = pancakes[i];
                imax = i;
            }
        }
        return imax;
    }

    int checkLow (int pancakes[],int n){
        int min=pancakes[0];
        int imin=0;
        for (int i=0;i<n;i++){
            if (pancakes[i]<min){
                min = pancakes[i];
                imin = i;
            }
        }
        return imin;
    }

    void printChanges(int n, int pancakes[]) {
        for (int i=0;i<n-1;i++){
                cout << pancakes[i] << " ";
            }
            cout << pancakes[n-1] << "\n";
    }


    int main() {
        int n;cin>>n;
        int pancakes[n];
        for (int i=0;i<n;i++){
            cin >> pancakes[i];
        }

        int ipancake = n;
        printChanges(n,pancakes);
        while (ipancake-1){


            if (checkHigh(pancakes,ipancake)==0){
                pancakeSwap(ipancake-1,pancakes);
                printChanges(n,pancakes);
                ipancake--;
            }
            else if (checkHigh(pancakes,ipancake)==ipancake-1){

                ipancake--;
            }
            else {
                pancakeSwap(checkHigh(pancakes,ipancake),pancakes);
                printChanges(n,pancakes);
                
                pancakeSwap(ipancake-1,pancakes);
                printChanges(n,pancakes);
                ipancake--;

            }

        }



    }