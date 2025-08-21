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

void palljjack(string temp){
    vector<int>alph(27);
    for(int i=0;i<temp.size();i++){
        int a = temp[i] - 'A';
        alph[a]++;
    }
    string answer;
    for(int i=0;i<27;i++){
        if(alph[i]>0){
            if(alph[i]%2==1){
                cout<<"I'm Sorry Hansoo\n";
                return;
            }else{
                int t = i;
                int count = alph[i]/2;
                char c = t+'A';
                //cout<<c<<"\n";
                for(int j=0;j<count;j++){
                    answer+=c;
                }
            }
        }
    }
    //cout<<answer;
    string rev = answer;
    reverse(answer.begin(), answer.end());
    rev += answer;
    cout<<rev<<"\n";
}

void pallhol(string temp){
    int hollsu;
    bool flag = true;
    vector<int>alph(27);
    for(int i=0;i<temp.size();i++){
        int a = temp[i] - 'A';
        alph[a]++;
    }
    for(int i=0;i<27;i++){
        if(alph[i]>0 && alph[i]%2==1){
            if(flag){
                hollsu = i;
                alph[i]--;
                flag = false;
            }else{
                cout<<"I'm Sorry Hansoo\n";
                return;  
            }
        }
    }
    string answer;
    for(int i=0;i<27;i++){
        if(alph[i]>0){
            if(alph[i]%2==1){
                cout<<"I'm Sorry Hansoo\n";
                return;
            }else{
                int t = i;
                int count = alph[i]/2;
                char c = t+'A';
                //cout<<c<<"\n";
                for(int j=0;j<count;j++){
                    answer+=c;
                }
            }
        }
    }
    string rev = answer;
    rev += hollsu + 'A';
    reverse(answer.begin(), answer.end());
    rev += answer;
    cout<<rev<<"\n";

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string temp;
    cin>>temp;
    if(temp.size()%2==0){
        palljjack(temp);
    }else{
        pallhol(temp);
    }

}
