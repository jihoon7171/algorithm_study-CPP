#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<queue>
using namespace std;
int stringnumber(string as){
    int count=0;
    for(int i=0;i<as.size();i++){
        if((int)as[i]>=48 && (int)as[i]<58 ){
            count+= as[i]-'0';
        }
    }
    return count;
}

bool compare(string a, string b){
    if(a.size() != b.size()){
        return a.size()<b.size();
    }
    int asum = stringnumber(a);
    int bsum = stringnumber(b);
    if(asum!=bsum){
        return asum<bsum;
    }
    return a<b;
}

int main(){
    int a;
    cin>>a;
    vector<string>serial(a);
    for(int i=0;i<a;i++){
        cin>>serial[i];
    }
    sort(serial.begin(), serial.end(), compare);

    for(int i=0;i<a;i++){
        cout<<serial[i]<<"\n";
    }

}