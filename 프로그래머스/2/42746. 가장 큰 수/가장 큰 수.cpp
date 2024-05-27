#include <string>
#include <vector>
#include<algorithm>
using namespace std;

bool checking(string a, string b){
    if(a+b>b+a){
        return true;
    } 
    return false;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string>check;
    for(int i=0;i<numbers.size();i++){
check.push_back(to_string(numbers[i]));
    }
    
    sort(check.begin(), check.end(), checking);
    
    for(int i=0;i<check.size();i++){
answer +=check[i];}
    if(answer[0] == '0' )return "0";
    
    return answer;
}