#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<stack>
#include<cstring>
using namespace std;

bool check(const char as[]){
    int len = strlen(as);
    stack<char>stk;
    for(int i=0;i<len;i++){
        if(as[i] == '('){
            stk.push('(');  
        }else if(as[i] == ')'){
            if(!stk.empty()){
                stk.pop();

            }else{
                return false;
            }
        }
        }
        if(stk.empty()){
            return true;
        }else{
            return false;
        }
    }


int main(){
    int a;
    cin>>a;
    cin.ignore();
    string word;
    bool mymy;
    for(int i=0;i<a;i++){
        cin>>word;
        mymy = check(word.c_str());
        if(mymy == true){
            cout<<"YES";
        }else {
            cout<<"NO";
        }
        cout<<"\n";
    }

}