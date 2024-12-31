#include <iostream>
#include <vector>
#include <climits>
#include <string>
#include <algorithm>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<limits.h>
#include<queue>
using namespace std;
int a;

string minimum(vector<char>giho){
    string answer;
    vector<int>num(a+1);
    for(int i=0;i<=a;i++){
        num[i] = i;
    }
    
    for(int i=0;i<giho.size();i++){
        if(giho[i] == '>'){
            int start = i;
            while(i<giho.size() && giho[i] == '>'){
                i++;
            }
            reverse(num.begin()+start, num.begin()+i+1);
        }
    }
    for(int i=0;i<num.size();i++){
        answer += (num[i]+'0');
    }
    return answer;

}

string maximum(vector<char>giho){
    string answer;
    vector<int>num(a+1);
    for(int i=0;i<=a;i++){
        num[i] = 9-i;
    }
    
    for(int i=0;i<giho.size();i++){
        if(giho[i] == '<'){
            int start = i;
            while(i<giho.size() && giho[i] == '<'){
                i++;
            }
            reverse(num.begin()+start, num.begin()+i+1);
        }
    }
    for(int i=0;i<num.size();i++){
        answer += (num[i]+'0');
    }
    return answer;

}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>a;
    vector<char>giho(a);
    vector<bool>num(10,false);
    for(int i=0;i<a;i++){
        cin>>giho[i];
    }
    cout<<maximum(giho)<<endl;
    cout<<minimum(giho);

    
    

}
