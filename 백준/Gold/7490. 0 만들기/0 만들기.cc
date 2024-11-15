#include <iostream>
#include <vector>
#include <climits>
#include <string>
#include <algorithm>
#include<stack>
#include<set>
#include<map>
#include<limits.h>
using namespace std;
int temp;


int cal(vector<char>qwer){
    int zerocal =0;
    int currentnum = 0;
    char currentop = '+';
    for(int i=0;i<qwer.size();i++){
        if(qwer[i] == ' '){
            currentnum = currentnum*10+(qwer[i+1]-'0');
            i++;
        }else if(qwer[i]>='0' && qwer[i]<='9'){
            currentnum = qwer[i] - '0';
        }else{
            if(currentop == '+'){
                zerocal += currentnum;
            }else if(currentop == '-'){
                zerocal -= currentnum;
            }
            currentop = qwer[i];
           currentnum = 0;
        }
    }

    if(currentop == '+'){
        zerocal += currentnum;
    }else if(currentop == '-'){
        zerocal -= currentnum;
    }
    return zerocal;
}

void dfs(int now,  vector<char>&answer){
    if(now >=answer.size()){
        if(cal(answer) == 0){
            for(char c : answer){
                cout<<c;
            }
            cout<<"\n";
          
        }
          return ;
    }
        for(int j=0;j<3;j++){
            if(j==0){
                answer[now] = ' ';
            }else if(j==1){
                answer[now] = '+';
            }else{
                answer[now] = '-';
            }
            dfs(now+2, answer);
        }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int a;
    cin>>a;
    for(int i=0;i<a;i++){
        cin>>temp;
        vector<char>answer(temp*2-1);
        for(int j=0;j<answer.size();j = j+2){
            answer[j] = '0'+(j/2+1);
        }
        dfs(1,answer);
        cout<<"\n";
    }


}