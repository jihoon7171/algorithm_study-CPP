#include <iostream>
#include <vector>
#include<algorithm>
#include<unordered_set>
#include<queue>
#include<cstring>
#include<climits>
using namespace std;
int a, result=INT_MAX;
int sumstart;
int sumlink;
vector<int>startnumber(10);
vector<int>checkstart(20);
vector<bool>numbercheck;
vector<int>startnum(2);
vector<int>linknum(2);
vector<vector<int>>sl(21, vector<int>(21));
vector<vector<int>>teamresult(21, vector<int>(21));
void memo(){
    for(int i=1;i<=a;i++){
        for(int j=1;j<=a;j++){
            if(i!=j)
            teamresult[i][j] = sl[i][j]+sl[j][i];
        }
    }
}

void dfs(int count, int index){
    if(count==a/2){
        sumlink=0;
        sumstart=0;
        for(int i=1;i<=a;i++){
            for(int j=i+1;j<=a;j++){
                if(numbercheck[i] && numbercheck[j]){
                    sumstart += teamresult[i][j];
                }else if(!numbercheck[i] && !numbercheck[j]){
                    sumlink += teamresult[i][j];
                }
            }
        }

        result = min(result, abs(sumlink-sumstart));
        return;
    }
    for(int i=index;i<=a;i++){
        if(!numbercheck[i]){
            numbercheck[i] = true;
            dfs(count+1, i+1);
            numbercheck[i]=false;
        }
    }
}

int main() {
    cin>>a;
    sl.resize(a+1, vector<int>(a+1));
    for(int i=1;i<=a;i++){
        for(int j=1;j<=a;j++){
            cin>>sl[i][j];
        }
    }
    numbercheck.resize(a+1, false);
    memo();
    dfs(0,1);
    cout<<result;
} 