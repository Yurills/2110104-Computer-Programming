#include <iostream>
#include <math.h>

using namespace std;

int main(){
    double Xm,Ym,Xe,Ye,Re,Rp,Rm; cin>>Xe>>Ye>>Re>>Rp>>Xm>>Ym;
    Rm = sqrt(pow(Xm-Xe,2)+(pow(Ym-Ye,2)));
    
    double Xp,Yp;
    Yp=(Re-Rp)/Rm*(Ym-Ye);
    Xp=(Re-Rp)/Rm*(Xm-Xe);

    cout << round(Xp+Xe)<< " " << round(Yp+Ye);

    
}