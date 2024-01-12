//05_String_Spoonersim
#include <iostream>
#include <string>
using namespace std;

int findVowelIndex (string input){
    for (int i=0;i<input.length();i++){
        if (input[i] == 'a' || input[i] == 'e' || input[i] == 'i' || input[i] == 'o' || input[i] == 'u'){
            return i;
            
        }
    }
    return 0;
}

int main() {
    string line; getline(cin, line);
    line+= " ";
    int n = 0;
    for (int i=0;i<line.length();i++){
        if (line[i] == ' '){
            n++;
        }
    }

    string temp = ""; string words[n];
    int count = 0;
    for (int i=0;i<line.length();i++){
        if (line[i] != ' '){
            temp += line[i];
        }
        else {
            words[count++] = temp;
            temp = "";
        }
    }

    string firstWord = words[0];
    string lastWord = words[n-1];

    string CstFirstWord = "" , VwlFirstWord = "";
    for (int i=0;i<firstWord.length();i++){
        if (i<findVowelIndex(firstWord))CstFirstWord += firstWord[i];
        else VwlFirstWord += firstWord[i];
    }

    string CstLastWord = "" , VwlLastWord = "";
    for (int i=0;i<lastWord.length();i++){
        if (i<findVowelIndex(lastWord))CstLastWord += lastWord[i];
        else VwlLastWord += lastWord[i]; 
    }

    words[0] = CstFirstWord + VwlLastWord;
    words[n-1] = CstLastWord + VwlFirstWord;

    string answer = "";
    for (int i=0;i<n-1;i++){
        answer += words[i] + " ";
    }
    
    answer += words[n-1];
    cout << answer;
}