#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

// int ans[1001];

// void tile(int a){
//     int answer =0;
//     if( a == 1){
//         ans[1] = 1;
//         return;
//     }else if (a == 2){
//         ans[2] = 2;
//       return;
//     }else{
//         for(int i=3;i<=a;i++){
//             ans[i] = (ans[i-1]+ans[i-2])%10007;
//         }
//     }
//     return;
// }



int main(){
    int a;
    int ans[1001];
    cin>>a;
    ans[1] = 1;
    ans[2] = 2;
    for(int i=3;i<=a;i++){
        ans[i] = (ans[i-1]+ans[i-2])%10007;
    }
    cout<<ans[a];

        
    
}