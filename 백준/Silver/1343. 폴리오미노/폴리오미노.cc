#include<iostream>
#include<vector>
#include<string>
using namespace std;


int main(){
    vector<string>pol = {"AAAA", "BB"};
    string as;
    cin>>as;
    vector<string>answer;
    int count=0;
    for(int i=0;i<as.size();i++){
        if(as[i] == 'X'){
            count++;
        }else if(as[i]=='.'){
            
            while(count>0 && count!=1){
            if(count>=pol[0].size()){
                count -=pol[0].size();
                answer.push_back(pol[0]);
            }else{
                count-=pol[1].size();
                answer.push_back(pol[1]);
            }
        }
        answer.push_back(".");
        if(count==1){
            cout<<"-1";
            return 0;
        }else if(count==0){
            
            count=0;
        }
    }
}

    if(count>0){
                   while(count>0 && count!=1){
            if(count>=pol[0].size()){
                count -=pol[0].size();
                answer.push_back(pol[0]);
            }else{
                count-=pol[1].size();
                answer.push_back(pol[1]);
            }
        }
        if(count==1){
            cout<<"-1";
            return 0;
        }else if(count==0){
          
            count=0;
        }
    }
    for(int i=0;i<answer.size();i++){
        cout<<answer[i];
    }
}


