#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int count =0;
    int a;
    cin>>a;
    vector<int>as(a);
    for(int i=0;i<a;i++){
        cin>>as[i];
    }
    int b;
    cin>>b;
    vector<int>bs(b);
    for(int i=0;i<b;i++){
        cin>>bs[i];
    }


    sort(as.begin(), as.end());

    vector<int>result(b);
    for(int i=0;i<b;i++){
        int temp = bs[i];
        auto c1 = lower_bound(as.begin(), as.end(), temp);
        auto c2 = upper_bound(as.begin(), as.end(), temp);
        result[i] = c2-c1;
    }

    for(int i=0;i<b;i++){
        cout<<result[i]<<" ";
    }

   //10 10 10 7 6 3 3 2 -10

}