#include <iostream>
#include <vector>
#include <string>
#include<algorithm>
#include<map>
using namespace std;

int main(){
    int a,b;
    cin>>a>>b;
    vector<int>visiter(a);
    for(int i=0;i<a;i++){
        cin>>visiter[i];
    }
    int startpoint=0,endpoint = startpoint+b,count=1;
    int sum=0,big;
    for(int i=0;i<b;i++){
        sum+=visiter[i];
    }
    big = sum;
    while(endpoint<a){
        sum-=visiter[startpoint];
        sum+=visiter[endpoint];
        startpoint++;
        endpoint++;
        if(sum > big){
            big = sum;
            count =1;
        }else if (sum == big){
            count++;
        }
    }
    bool check=false;
    for(int i=0;i<a;i++){
        if(visiter[i] !=0){
            check = true;
        }
    }

    if(!check){
        cout<<"SAD"<<endl;
    }else {
        cout<<big<<"\n"<<count;
    }
}
