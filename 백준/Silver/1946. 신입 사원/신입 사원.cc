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


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a;
    cin>>a;
    for(int i=0;i<a;i++){
        int count=1;
        int b;
        cin>>b;
        vector<vector<int>>test(b,vector<int>(2));
        for(int j=0;j<b;j++){
            cin>>test[j][0]>>test[j][1];
        }
        sort(test.begin(), test.end());
         int nowmin = test[0][1];
        // cout<<"\n";
        // for(int j=0;j<b;j++){
        //         cout<<test[j][0]<<" "<<test[j][1];
            
        //     cout<<"\n";
        // }
        for(int j=1;j<b;j++){
            if(test[j][1]<nowmin){
                count++;
                nowmin = test[j][1];
            }else{
            }
        }
        cout<<count<<"\n";



    }

 
}
