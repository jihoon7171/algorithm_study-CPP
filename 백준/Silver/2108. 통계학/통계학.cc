#include<iostream>
#include<vector>
#include<cmath>
#include<queue>
#include<algorithm>
using namespace std;
vector<vector<int>>maze;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int a;
    cin>>a;
    vector<int>number(a);
    for(int i=0;i<a;i++){
        cin>>number[i];
    }
    sort(number.begin(), number.end());
    int range = number[a-1] - number[0];
    vector<int>count(4001,0);
    vector<int>minuscount(4001,0);
    int bigs = 0;
    for(int i=0;i<a;i++){
        if(number[i] <0){
            minuscount[-number[i]]++;
            if(bigs < minuscount[-number[i]]){
                bigs = minuscount[-number[i]];
            }
        }else{
            count[number[i]]++;
            if(bigs < count[number[i]]){
                bigs = count[number[i]];
            }
        }
    }
    vector<int>as;
    for(int i=0;i<4001;i++){
        if(minuscount[i] == bigs){
            as.push_back(-1*i);
        }
        if(count[i] == bigs){
            as.push_back(i);
        }
    }
    int very;
    sort(as.begin(), as.end());
    if(as.size()>1){
        very = as[1];
    }else{
        very = as[0];
    }


    double average=0;
    for(int i=0;i<a;i++){
        average+=(double)number[i];
    }
    average = average/a;
    if(average<0){
        average -=0.5;
    }else{
        average +=0.5;
    }

    cout<<(int)average<<"\n"<<number[a/2]<<"\n"<<very<<"\n"<<range;



}
