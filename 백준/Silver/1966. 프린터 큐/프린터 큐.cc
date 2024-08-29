#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<algorithm>
#include<stack>
#include<unordered_set>

using namespace std;

bool find(vector<pair<int, int>>print, int cv){
    for(const auto&p : print){
        if(cv < p.first){
            return false;
        }
    }
    return true;
}


int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int m,a,count=0;
        cin>>m>>a;
        vector<pair<int ,int >>print;
        for(int i=0;i<m;i++){
            int temp;
            cin>>temp;
            print.push_back(make_pair(temp, i));
        }  
        while(1){
            pair<int, int> n = print.front();
            if(find(print, n.first)){
                if(n.second == a){
                    count++;
                    cout<<count<<"\n";
                    break;
                }
                print.erase(print.begin());
                count++;
            }else{
                print.erase(print.begin());
                print.push_back(n);
        }

    }
    }
}


