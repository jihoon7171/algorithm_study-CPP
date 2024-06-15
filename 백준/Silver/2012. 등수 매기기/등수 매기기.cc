#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int a;
    cin>>a;
    long long answercount=0;
    vector<int>arr(a+1);
    for(int i=1;i<a+1;i++){
        cin>>arr[i];
    }
    sort(arr.begin(), arr.end());

    for(int i=1;i<a+1;i++){
        long long asdf = arr[i] - i;
        if(asdf < 0 ){
            asdf = asdf*-1;
        }
        answercount +=asdf;
    }
    cout<<answercount;

}