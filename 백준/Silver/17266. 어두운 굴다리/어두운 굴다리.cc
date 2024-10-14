#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <queue>
#include <map>
#include <cstring>
#include <climits>
#include <string>
#include<cstring>
#include<deque>
using namespace std;
int n,m;

int main() {
    int n,m;
    cin>>n>>m;
    vector<int>lamp(m);
    for(int i=0;i<m;i++){
        cin>>lamp[i];
    }
    int answer = 0;
    answer =  max(lamp[0]-0, n-lamp[m-1]);
    for(int i=1;i<m;i++){
       if((lamp[i]-lamp[i-1])%2 == 0){
        answer = max(answer, (lamp[i]-lamp[i-1])/2);
       }else {
         answer = max(answer, (lamp[i]-lamp[i-1])/2+1);
       }
    }
    cout<<answer;

}