#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<long long>distance(n-1);
    vector<long long>price(n);
    for(int i=0;i<n-1;i++){
        cin>>distance[i];
    }
    for(int i=0;i<n;i++){
        cin>>price[i];
    }
    long long answer =  distance[0] * price[0];
    long long minprice = price[0];
    for(int i=1;i<n-1;i++){
         if(minprice>price[i]){
            minprice = price[i];
         }
         answer = answer +minprice*distance[i];
    }

    cout<<answer;
    




}