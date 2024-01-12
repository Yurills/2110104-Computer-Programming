//06_Vector_★★_Top3Sales
#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

bool searchItemNames (vector<pair<string,float>> &item_list, string itemInput){
    for (auto i : item_list){
        if (itemInput == i.first){
            return true;
        }
    }
    return false;
}

float findPrice (vector<pair<string, float>> &item_list, string itemInput) {
    for (auto i : item_list){
        if (itemInput == i.first){
            return i.second;
        }
    }
    return 0;
}



int main() {
    vector<pair<string, float>> item_list;
    pair<string, float> item_price;

    string item;float price;
    cin >> item;
    while (item!="END"){
        item_price.first = item;
        cin >> price;
        item_price.second = price;
        item_list.push_back(item_price);
        cin >> item;
       
    }


    string itemInput;
    vector<pair<float, string>> itemSold;
    pair<float,string> itemContainer;
    while (cin >> itemInput){
        if (searchItemNames(item_list,itemInput)){
            itemContainer.second = itemInput;
            itemContainer.first = findPrice(item_list, itemInput);
            itemSold.push_back(itemContainer);
        }
    }

    sort(itemSold.begin(),itemSold.end());
    vector<pair<float,string>> newItemSold;
    pair<float,string> newContainer;
    int count = 1;
    for (auto itr = itemSold.begin(), end = itemSold.end(); itr!=end; ++itr){
        if (*itr == *(itr+1)){
            count++;
        }
        else {
            newContainer.second = (*itr).second;
            newContainer.first = ((*itr).first)*-count;
            count = 1;
            newItemSold.push_back(newContainer);
        }
    }
    sort(newItemSold.begin(),newItemSold.end());
    for (auto &e : newItemSold){
        e.first *= -1;
    }

    if (newItemSold.size()==0){
        cout<<"No Sales";
    }

    for (int i=0;i<newItemSold.size();i++){
        if (i>2)break;
        cout << newItemSold[i].second << " " << newItemSold[i].first << "\n";
    }
    




}