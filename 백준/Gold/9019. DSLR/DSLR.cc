#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<cmath>
#include<queue>
#include<tuple>
#include<string>
#include<deque>
using namespace std;
int A,B;
char comm[4] = {'D','S','R','L'};
int visited[10000];
int calD(int now){
    return now*2%10000;
}

int calS(int now){
    return (now == 0) ? 9999 : now - 1;
}

int calL(int n){
    return (n % 1000) * 10 + n / 1000;
}

int calR(int n){
    return (n % 10) * 1000 + n / 10;
}

void bfs(int start, int target){
    queue<pair<string, int>>q;
    q.push({"", start});
    while(!q.empty()){
        string nowcommand = q.front().first;
        int nownumber = q.front().second; q.pop();

        if(nownumber == target){
            cout<<nowcommand<<"\n";
            return ;
        }

        for(int i=0;i<4;i++){
            char nowc = comm[i];
            if(nowc=='D'){
                int newnumber = calD(nownumber);
                if(visited[newnumber] == 0){
                    visited[newnumber] = 1;
                    q.push({nowcommand+string(1,'D'), calD(nownumber)});
                }

            }else if(nowc=='S'){
                bool flag = false;
                int newnumber = calS(nownumber);
                if(visited[newnumber] == 0) {
                    visited[newnumber] = 1;
                    q.push({nowcommand+string(1,'S'), newnumber});
                }

            }else if(nowc=='R'){
                int newnumber = calR(nownumber);
                if(visited[newnumber] == 0){
                    visited[newnumber] = 1;
                    q.push({nowcommand+string(1,'R'), calR(nownumber)});
                }

            }else {
                int newnumber = calL(nownumber);
                if(visited[newnumber] == 0){
                    visited[newnumber] = 1;
                    q.push({nowcommand+string(1,'L'), calL(nownumber)});
                }

            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
        while(t--){
            cin>>A>>B;
            fill(visited, visited+10000, 0);
            bfs(A,B);
        }
    //cout<<calR(1);

}
 