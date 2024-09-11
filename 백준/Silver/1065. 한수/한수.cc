#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int main(){
    int a;
    cin>>a;
    if(a<100){
    cout<<a;
    return 0;
    }
    int ans = 99;
    for(int i=100;i<=a;i++){
        int temp = i;
        vector<int>num;
        while(temp>0){
            num.push_back(temp%10);
            temp = temp/10;
        }
        bool isHansu = true;
        int stand = num[0]-num[1];
        for(int k=1;k<num.size()-1;k++){
           if(stand != num[k] - num[k+1]){
            isHansu = false;
            break;
           }
        }
        if(isHansu){
            ans++;
        }

       
    }
    cout<<ans;
}