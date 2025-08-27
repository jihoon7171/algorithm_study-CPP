#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<cmath>
#include<queue>
#include<tuple>
#include<string>
#include<deque>
using namespace std;
long long n;

// //입력받은 수의 다음 감소하는수 찾는 함수
// int finddown(long long now){
//     while(1){
//         now++;
//         string temp = to_string(now);
//         bool flag = false;
//         for(int i=0;i<temp.size()-1;i++){
//             if(temp[i] <= temp[i+1]){
//                 flag = true;
//                 break;
//             }
//         }
//         if(!flag){
//             return now;
//         }
//         if(now > 9876543210){
//             return -1;
//         }
//     }
// }

vector<long long>numb;
void generate(long long num, int last){
    numb.push_back(num);
    for(int i=0;i<last;i++){
        generate(num*10+i, i);
    }
}

int main(){
    cin>>n;
    if(n<=10){
        cout<<n;
        return 0;
    }
    for(int i=0;i<=9;i++){
        generate(i,i);
    }
    sort(numb.begin(), numb.end());
    if(n>=numb.size()){
        cout<<-1;
    }else{
        cout<<numb[n];
    }
    




}