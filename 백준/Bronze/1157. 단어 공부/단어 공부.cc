#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
int main(){
        vector<int>answer(26);
        string str;
        int count=0;
        cin>>str;
        for(int i=0;i<str.size();i++){
            int a = toupper(str[i]) - 'A';
            answer[a]++;            
        }
        int bigone = answer[0];
        int bigindex=0;
        for(int i=1;i<26;i++){
            if(bigone < answer[i]){
                bigone = answer[i];
                bigindex = i;
            }
        }
        for(int i=0;i<26;i++){
            if(i != bigindex){
                if(answer[bigindex] == answer[i]){
                    count++;
                }
            }
        }
        if(count>0){
            cout<<"?";
        }else{
            char as = bigindex+65;
            cout<<as;
        }
}