#include <iostream>
#include <map>
using namespace std;

int main() {
    map<string, string> clicksToAlpha;
    clicksToAlpha = {
        {"2","a"}, {"22","b"}, {"222","c"},
        {"3","d"}, {"33","e"}, {"333","f"},
        {"4","g"}, {"44","h"}, {"444","i"},
        {"5","j"}, {"55","k"}, {"555","l"},
        {"6","m"}, {"66","n"}, {"666","o"},
        {"7","p"}, {"77","q"}, {"777","r"},{"7777", "s"},
        {"8","t"}, {"88","u"}, {"888","v"},
        {"9","w"}, {"99","x"}, {"999","y"},{"9999", "z"},
        {"0","a"}
    };

    for (auto e:clicksToAlpha){
        clicksToAlpha[e.second] = e.first;
    }

    string input;
    while(getline(cin, input)){
        input = input.substr(3,input.length());
        for (auto e:input){
            if (isalnum(e)){
                if (isupper(e)){
                    e = e-32;
                }

                auto itr = clicksToAlpha.find(e);



            }
        }

    }

}