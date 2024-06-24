#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;
int main(){
    int a;
    cin>>a;
    vector<long long>answer;
    for(int i=0;i<a;i++){
        int b,c;
        cin>>b>>c;
        long long tempb=1;
        long long tempc =1;
        if(b>c/2){
            b = c-b;
        }
        for(int j=b;j>0;j--){
            tempb *= j;
        }
        long long com = c;
        for(int j=b;j>0;j--){
            tempc *= com;
            com--;
        }
       answer.push_back(tempc/tempb);
    }
    for(int i=0;i<answer.size();i++){
        cout<<answer[i]<<"\n";
    }
}