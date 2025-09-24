#include <iostream>
#include<queue>
#include<vector>
#include<queue>
#include<algorithm>
#include<climits>
#include<set>
using namespace std;

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,1,-1};
int w,h;
void run_fire(vector<vector<int>>&fire_visited, vector<vector<int>>&space,vector<pair<int, int>>fire){
    queue<pair<int, int>>q;
    for(int i=0;i<fire.size();i++){
        q.push({fire[i].second, fire[i].first});
    }
    while(!q.empty()){
        int x  = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(nx>=0&&nx<w&&ny>=0&&ny<h&&fire_visited[ny][nx] == -1 && space[ny][nx] != '#'){
                fire_visited[ny][nx] = fire_visited[y][x] + 1;
                q.push({nx,ny});
            }
        }
    }

}

void run_human(vector<vector<int>>&human_visited, vector<vector<int>>&space, int y, int x){
    queue<pair<int, int>>q;
    q.push({x,y});
    while(!q.empty()){
        int x  = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(nx>=0&&nx<w&&ny>=0&&ny<h&&human_visited[ny][nx] == -1 && space[ny][nx] =='.'){
                human_visited[ny][nx] = human_visited[y][x] + 1;
                q.push({nx,ny});
            }
        }
    }
}

// void can_exit(vector<vector<int>>&human_visited, vector<vector<int>>&fire_visited){
//     int answer = INT_MAX;
//     for(int i=0;i<h;i++){
//         if(fire_visited[i][0] > human_visited[i][0] && human_visited[i][0] != -1){
//             answer = min(answer, human_visited[i][0]);
//         }
//         if(fire_visited[i][0] == -1 && human_visited[i][0] != -1){
//             answer = min(answer, human_visited[i][0]);
//         }
//         if(fire_visited[i][w-1] > human_visited[i][w-1] && human_visited[i][w-1] != -1){
//             answer = min(answer, human_visited[i][w-1]);
//         }
//         if(fire_visited[i][w-1] == -1 && human_visited[i][w-1] != -1){
//             answer = min(answer, human_visited[i][0]);
//         }
//     }

//     for(int i=0;i<w;i++){
//         if(fire_visited[0][i] > human_visited[0][i] && human_visited[0][i] != -1){
//             answer = min(answer, human_visited[0][i]);
//         }
//         if(fire_visited[0][i] == -1 && human_visited[0][i] != -1){
//             answer = min(answer, human_visited[i][0]);
//         }
//         if(fire_visited[h-1][i] > human_visited[h-1][i] && human_visited[h-1][i] != -1){
//             answer = min(answer, human_visited[h-1][i]);
//         }
//         if(fire_visited[h-1][i] == -1 && human_visited[h-1][i] != -1){
//             answer = min(answer, human_visited[i][0]);
//         }
//     }
//     cout<<answer<<" \n";
//     if(answer == INT_MAX){
//         cout<<"IMPOSSIBLE\n";
//     }else{
//         cout<<answer+1<<"\n";
//     }
// }

void can_exit(vector<vector<int>>&human_visited, vector<vector<int>>&fire_visited){
    int answer = INT_MAX;
    for(int i=0;i<h;i++){
        if(fire_visited[i][0] != -1 && fire_visited[i][0] > human_visited[i][0] && human_visited[i][0] != -1){
            answer = min(answer, human_visited[i][0]);
           
        }
        if(fire_visited[i][0] == -1 && human_visited[i][0] != -1){
            answer = min(answer, human_visited[i][0]);
           
        }
        if(fire_visited[i][w-1] != -1 && fire_visited[i][w-1] > human_visited[i][w-1] && human_visited[i][w-1] != -1){
            answer = min(answer, human_visited[i][w-1]);
           
        }
        if(fire_visited[i][w-1] == -1 && human_visited[i][w-1] != -1){
            answer = min(answer, human_visited[i][w-1]);
           
        }
    }

    for(int i=0;i<w;i++){
        if(fire_visited[0][i] != -1 && fire_visited[0][i] > human_visited[0][i] && human_visited[0][i] != -1){
            answer = min(answer, human_visited[0][i]);
           
        }
        if(fire_visited[0][i] == -1 && human_visited[0][i] != -1){
            answer = min(answer, human_visited[0][i]);
           
        }
        if(fire_visited[h-1][i] != -1 && fire_visited[h-1][i] > human_visited[h-1][i] && human_visited[h-1][i] != -1){
            answer = min(answer, human_visited[h-1][i]);
            
        }
        if(fire_visited[h-1][i] == -1 && human_visited[h-1][i] != -1){
            answer = min(answer, human_visited[h-1][i]);
           
        }
    }

    if(answer == INT_MAX){
        cout<<"IMPOSSIBLE\n";
    }else{
        cout<<answer+1<<"\n";
    }
}

int main() {
    int t;
    cin>>t;
    while(t--){
        cin>>w>>h;
        vector<vector<int>>space(h, vector<int>(w));
        vector<vector<int>>sg(h, vector<int>(w));
        vector<vector<int>>fire_visited(h, vector<int>(w,-1));
        vector<vector<int>>human_visited(h, vector<int>(w,-1));
        vector<pair<int, int>>fire;
        pair<int, int> st;
        for(int i=0;i<h;i++){
            string temp;
            cin>>temp;
            for(int j=0;j<temp.size();j++){
                space[i][j] = temp[j];
                if(space[i][j] == '@'){
                    st.first = i;
                    st.second = j;
                    human_visited[i][j] = 0;
                }else if(space[i][j] =='*'){
                    fire.push_back({i,j}); // y,x
                    fire_visited[i][j] = 0;
                }
            }
        }
        run_fire(fire_visited, space, fire);
        run_human(human_visited, space, st.first, st.second);
        can_exit(human_visited, fire_visited);
    }

}
