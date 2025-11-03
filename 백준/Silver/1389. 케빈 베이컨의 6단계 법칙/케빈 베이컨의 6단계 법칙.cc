#include <iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
int answer = INT_MAX;
int answerdistance = INT_MAX;
vector<vector<int>>v;
int n,m;
void bfs(int start){
	vector<int>visited(n+1,-1);
	visited[start] = 0;
	queue<pair<int, int>>q; //지금, 거리
	q.push({start, 0});
	while(!q.empty()){
		int now = q.front().first;
		int nowd = q.front().second;
		q.pop();
		for(int i=0;i<v[now].size();i++){
			int go = v[now][i];
			if(visited[go] == -1){
				visited[go] = nowd+1;
				q.push({go, nowd+1});
			}
		}
	}
	int sum  = 0;

	for(int i=1;i<=n;i++){
		if(i == start)continue;
		sum+=visited[i];
	}

	if(sum < answerdistance){
		answerdistance = sum;
		answer = start;
	}else if(sum == answerdistance){
		if(start < answer){
			answerdistance = sum;
			answer = start;
		}
	}
}


int main() {
    cin>>n>>m;
	v.resize(n+1);
	for(int i=0;i<m;i++){
		int q,w;
		cin>>q>>w;
		v[q].push_back(w);
		v[w].push_back(q);
	}
	for(int i=1;i<=n;i++){
		bfs(i);
	}
	cout<<answer;
}
