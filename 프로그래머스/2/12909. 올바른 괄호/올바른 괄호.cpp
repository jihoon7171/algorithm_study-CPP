#include<string>
#include<vector>
#include <iostream>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    int count=0;
    vector<char>word;
    for(int i=0;i<s.size();i++){
        word.push_back(s[i]);
        }
    for(int i=0;i<s.size();i++){
        if(s[i] == '('){
            count++;
            }else if(s[i] == ')'){
            count--;
            if(count<0){
                return false;
                }
            }
        }
    if(count == 0){
return true;
    }else{
        return false;
    }
    

    return answer;
}