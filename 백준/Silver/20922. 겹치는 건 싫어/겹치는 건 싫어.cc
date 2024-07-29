#include<vector>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<string>
#include<unordered_map>
using namespace std;

long long inputa[100001];

int main(){
    int a,b;
    int length=0;
    int temp=0,start=0,end=0;
    memset(inputa, 0, sizeof(inputa));
    cin>>a>>b;
    int original[a];
    for(int i=0;i<a;i++){
        int qw;
        cin>>qw;
        original[i] = qw;
    }
    for(end=0;end<a;end++){
        inputa[original[end]]++;
        while(inputa[original[end]]>b){
            inputa[original[start]]--;
            start++;
        }
        length = max(length, end-start+1);
    }

    cout<<length;

}