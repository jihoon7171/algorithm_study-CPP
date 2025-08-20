#include <iostream>
#include <vector>
#include <algorithm>
#include<climits>
#include<cmath>
#include<queue>
#include<tuple>
#include<string>
#include<deque>
using namespace std;
int n;
deque<int>dq;

bool del(bool isreverse, deque<int>&dq){
    if(dq.empty()){
        return false;
    }
    if(isreverse){
        dq.pop_back();
    }else{
        dq.pop_front();
    }
    return true;
}

void printing(bool isreverse, deque<int>&dq){
    vector<int>v;
    while(!dq.empty()){
        v.push_back(dq.front());
        dq.pop_front();
    }
    if(v.size()==0){
        cout<<"[]\n";
        return ;
    }
    cout<<"[";
    if(isreverse){
        for(int i=v.size()-1;i>=0;i--){
            if(i!=0){
                cout<<v[i]<<",";
            }else{
                cout<<v[i];
            }
        }
    }else{
        for(int i=0;i<v.size();i++){
            if(i!=v.size()-1){
                cout<<v[i]<<",";
            }else{
                cout<<v[i];
            }
        }
    }
    cout<<"]\n";
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    while(n--){
        string ac;
        cin>>ac;
        int num;
        cin>>num;
        string temp;
        cin>>temp;

        string tempnum;
        for(char c : temp){
            if(isdigit(c)){
                tempnum += c;
            }else if(!tempnum.empty()){
                dq.push_back(stoi(tempnum));
                tempnum.clear();
            }
        }
        bool flag = true;
        if (!tempnum.empty()) dq.push_back(stoi(tempnum));
        bool isreverse = false;
        for(int i=0;i<ac.size();i++){
            if(ac[i] == 'R'){
                isreverse = !isreverse;
            }else {
                flag = del(isreverse, dq);
                if(flag == false){
                    break;
                }
            }
        }
        if(flag){
            printing(isreverse, dq);
        }else{
            cout<<"error\n";
        }

    }
}
