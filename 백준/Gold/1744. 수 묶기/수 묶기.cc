#include <iostream>
#include<queue>
#include<vector>
#include<queue>
#include<algorithm>
#include<climits>
#include<set>
using namespace std;
int n;
long long answer = 0;
vector<int>p;
vector<int>num;


int main() {
    cin>>n;
    for(int i=0;i<n;i++){
        int q;
        cin>>q;
        if(q>0){
            p.push_back(q);
        }else{
            num.push_back(q);
        }
    }
    sort(p.begin(), p.end(), greater<int>());
    sort(num.begin(), num.end());
    if(p.size()%2 == 1)answer+=p[p.size()-1];
    for(int i=0;i<(int)p.size()-1;){
        if( p[i+1]==1){
            answer += p[i]+p[i+1];
        }else if(p[i+1]>0) answer+=p[i]*p[i+1];
        i+=2;
    }

    if(num.size()%2 ==1) answer+=num[num.size()-1];
    for(int i=0;i<(int)num.size()-1;i+=2){
        answer += num[i]*num[i+1];
    }
    cout<<answer;



}
