
#include <iostream>
#include <vector>

using namespace std;

int main()  
{
    string a;cin>>a;

    string month;
    string months[]={"JAN","FEB","MAR","APR","MAY","JUN","JUL","AUG","SEP","OCT","NOV","DEC"};
    int temp2; temp2 = stoi(a.substr(3,2));
    month = months[temp2-1];
    
    string day;
    if (a[0]=='0'){day = a.substr(1,1);}
    else {day = a.substr(0,2);}
    
    string year;
    temp2 = stoi(a.substr(6,4))-543;
    year = to_string(temp2);

    cout<<month<<" "<<day<<", "<<year;
}