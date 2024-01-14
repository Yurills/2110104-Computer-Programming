#include <iostream>
#include <map>
using namespace std;

int main() {
    int n;cin >> n;
    map<string, float> order;
    while (n--){
        string item;cin >> item;
        float price;cin >> price;
        order[item] = price;
    }

    map<string, float> sales;
    cin >> n;
    while(n--){
        string item;cin>>item;
        float amount;cin>>amount;;

        if(order.find(item) != order.end()){
            auto itr = sales.find(item);
            if (itr == sales.end()){
                sales[item] = ((*(order.find(item))).second) * amount;
            }
            else {
                sales[item] += ((*(order.find(item))).second) * amount;
            }
        }
    }

    if (!sales.empty()){
        float total = 0;
        float max = 0;
        for (auto e : sales){
            total += e.second;
            if (e.second > max){
                max = e.second;
            }
        }

        cout << "Total ice cream sales: " << total << endl << "Top sales: ";
        for (auto e: sales){
            if (e.second == max){
                cout << e.first << " ";
            }
        }

    }
    else {
        cout << "No ice cream sales";
    }

    

}