 #include <iostream>

 using namespace std;
    
    bool CheckLeap(int y){
        bool leap = false;
        if (y%4==0){
            leap = true;
            if (y%100 == 100){
                leap = false;
                if (y%400==0){
                    leap = true;
                }
            }
        }
        return leap;
    }


int months[] = {31,28,31,30,31,30,31,31,30,31,30,31};

int main(){
    int d,m,y; cin>>d>>m>>y;
    y -= 543;
    int n = 31;
    
    if (months[m-1]%30==0){
        n=30;
    }
    else {
        if (m==2){
            n=28;
            if (y%400==0){
                n=29;
            }
            if (y%4==0&&y%100!=0){
                n=29;
            }
        }
    }
    d=d+15;
    if (d>n){
        d -= n;
        m += 1;
    }
    if (m>12){
        m -= 12;
        y += 1;
    }
    y += 543;

    cout << d <<"/" << m << "/" <<y;

    return 0;
 }