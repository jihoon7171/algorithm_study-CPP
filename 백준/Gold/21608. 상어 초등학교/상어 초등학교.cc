#include <iostream>
#include <vector>
#include <climits>
#include <string>
#include <algorithm>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<limits.h>
#include<queue>
using namespace std;
int n;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
vector<vector<int>>student;
vector<vector<int>>room;

void printqueue(queue<pair<int, int>>q){
    while(!q.empty()){
        cout<<q.front().first<<" "<<q.front().second<<" ";
        q.pop();
    }
    cout<<"\n";
}

int numberplus(int a){
    if(a == 0){
        return 0;
    }else if(a == 1){
        return 1;
    }else if(a == 2){
        return 10;
    }else if(a == 3){
        return 100;
    }else if(a==4){
        return 1000;
    }
    return 0;
}

void cal(){
    int count =0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int temp=0;
            for(int k=0;k<4;k++){
                int nx = j+dx[k];
                int ny = i+dy[k];
                if(nx>=1&&nx<=n&&ny>=1&&ny<=n){
                    int a = room[i][j];
                    if(room[ny][nx]==student[a][0]||room[ny][nx]==student[a][1]||room[ny][nx]==student[a][2]||room[ny][nx]==student[a][3]){
                        temp++;
                    }
                }
            }
            count += numberplus(temp);
        }
    }
    cout<<count;
}

void myseat(int a){
    queue<pair<int, int>>site;
    int nowbig = INT_MIN;
    int num = -1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(room[i][j] == 0){
                int count =0;
                for(int k=0;k<4;k++){
                    int nx = j+dx[k];
                    int ny = i+dy[k];
                    if(nx>=1&&nx<=n&&ny>=1&&ny<=n&&(room[ny][nx]==student[a][0]||room[ny][nx]==student[a][1]||room[ny][nx]==student[a][2]||room[ny][nx]==student[a][3])){
                        count++;
                    }
                }
                if(count == nowbig){
                    site.push({i,j});
                }else if(count > nowbig){
                    queue<pair<int, int>>empty;
                    site.swap(empty);
                    nowbig = count;
                    site.push({i,j});
                }
            }
        }
    }
    //printqueue(site);

    if(site.size()==1){
        room[site.front().first][site.front().second] = a;
    //         for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++){
    //         cout<<room[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
        return ;
    }
    queue<pair<int, int>>answer;
           int nowb = INT_MIN;
    while(!site.empty()){
        int x = site.front().second;
        int y = site.front().first;
        site.pop();
 
        int count = 0;
        for(int k=0;k<4;k++){
            int nx = x+dx[k];
            int ny = y+dy[k];
            if(nx>=1&&nx<=n&&ny>=1&&ny<=n&&room[ny][nx]==0){
                count++;
            }
        }
        //cout<<count<<"\n";
        if(count == nowb){
            answer.push({y,x});
        }else if(count > nowb){
            queue<pair<int, int>>empty;
            answer.swap(empty);
            nowb = count;
            answer.push({y,x});
        }        
    }
   // cout<<"answer";
   // printqueue(answer);

    room[answer.front().first][answer.front().second] = a;
    //     for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++){
    //         cout<<room[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    return ;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    room.resize(n+1, vector<int>(n+1,0));
    student.resize((n*n)+1, vector<int>(4,0));
    int temp;
    vector<int>seq((n*n)+1);
    for(int i=1;i<=n*n;i++){
        cin>>temp>>student[temp][0]>>student[temp][1]>>student[temp][2]>>student[temp][3];
        seq[i] = temp;
    }

    for(int i=1;i<=n*n;i++){
        myseat(seq[i]);
    }

    cal();
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++){
    //         cout<<room[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }   
}
