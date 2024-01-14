#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

    map<string, vector<string>> department; // department: vector of employee
    int n,m; cin>> n >> m;
    while (n--) { //init 
        string emp, dept;
        cin >> emp >> dept;
        vector<string> employee = {};

        auto itr = department.find(dept);
        if (itr == department.end()){
            employee.push_back(emp);
            department[dept] = employee;
        }
        else {
            ((*itr).second).push_back(emp);
        }
    }

    while (m--){ //moving
        int operation; cin >> operation;
        string emp, dept; cin >> emp >> dept;
        vector<string> employee = {};

        if (operation == 1){ //move department
            
            for (auto e : department){
                for (auto r : e.second){
                    if (r != emp){
                        employee.push_back(r);
                    }
                }
                
                department[e.first] = employee;
                employee.clear();
            }

            auto deptItr = department.find(dept); //add on new department
            if (deptItr == department.end()){
                employee.push_back(emp);
                department[dept] = employee;
            }
            else {
                ((*deptItr).second).push_back(emp);
            }
        }

        else if (operation == 2){ //merge dept but emp = dept1 dept = dept2
            auto deptItrFirst = department.find(emp);
            employee = (*deptItrFirst).second;
            
            auto deptItrSecond = department.find(dept);
            if (deptItrSecond != department.end()){
                for (auto e : employee){
                ((*deptItrSecond).second).push_back(e);
             }
            }
            else {
                department[dept] = employee;
            }
            

            department.erase(deptItrFirst);
            employee.clear();
        }

    }

    for (auto e : department){
        sort((e.second).begin(), (e.second).end());
        cout << e.first << ": ";
        for (auto r : e.second){
            cout << r << " ";
        }
        cout << endl;
    }

}
