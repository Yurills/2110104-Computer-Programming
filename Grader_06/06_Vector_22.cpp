    //06_Vector_★★_Max-Dup-Range
    #include <iostream>
    #include <vector>
    #include <tuple>
    #include <algorithm>
    using namespace std;

    vector<int> turnStrToInt (string input){
        vector<int> output;
        input += " ";
        string temp = "";
        for (int i=0;i<input.length();i++){
            if (input[i]!=' '){
                temp += input[i];
            }
            else if (temp != "") {
                output.push_back(stoi(temp));
                temp = "";
            }
        }
        return output;
    }

    vector<int> checkNumb (vector<int> number){
        vector<int> output = {0};
        int count=0;
        for (int i=1;i<number.size();i++){
            if (number[i-1] == number[i]){
                count++;
            }
            else {
                count=0;
            }
            output.push_back(count);
        }
        return output;
    }


    int main() {
        string input; getline(cin,input);
        vector<int> number = turnStrToInt(input);
        vector<int> index = checkNumb(number);

        vector<tuple<int,int,int>> rangeVector;
        int max = 0;
        for (int i=0;i<index.size();i++){
            if (index[i]>max){
                max = index[i];
            }
        }

        tuple<int,int,int> range;
        for (int i=0;i<index.size();i++){
            if (index[i] == max){
                get<0>(range) = number[i];
                get<1>(range) = i-max;
                get<2>(range) = i+1;
                rangeVector.push_back(range);
            }

        }
        sort(rangeVector.begin(),rangeVector.end());

        for (int i=0;i<rangeVector.size();i++){
            cout << get<0>(rangeVector[i]) << " --> x[ " << get<1>(rangeVector[i]) << " : " << get<2>(rangeVector[i]) << " ]\n";
        }

    }