#include <iostream>
#include <vector>
#include <string>
#include<algorithm>
#include<map>
using namespace std;

bool cmp(pair<string, int>a, pair<string, int>b){
    if(a.second == b.second){
        if(a.first.size() == b.first.size()){
            return a.first<b.first;
        }
        return a.first.size() > b.first.size();
    }
    return a.second > b.second;

}


int main(){
    int a,b;
    cin>>a>>b;
    vector<string>word(a);
    map<string, int>newword;
    vector<string>answer;
    
    for(int i=0;i<a;i++){
        cin>>word[i];
    }  
    for(int i=0;i<a;i++){
        if(word[i].size()>=b){
            if(newword.find(word[i]) != newword.end()){
                newword[word[i]]++;
            }else{
                newword[word[i]] = 1;
            }
        }

    }
    vector<pair<string, int>>data1(newword.begin(), newword.end());
    sort(data1.begin(), data1.end(),cmp);
    for(int i=0;i<data1.size();i++){
        cout<<data1[i].first<<"\n";    
        }


}
