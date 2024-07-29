#include<vector>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<string>
#include<unordered_map>
using namespace std;


int main(){
    int a,b;
    int start=0, length=0;
    cin>>a>>b;
    int original[a];
    for(int i=0;i<a;i++){
        cin>>original[i]; 
    }
    unordered_map<int, int>answer;

    for(int i=0;i<a;i++){
          answer[original[i]]++;
          while(answer[original[i]]>b){
            answer[original[start]]--;
            start++;
          }
          length = max(length, i-start+1);
    }
    cout<<length;

}