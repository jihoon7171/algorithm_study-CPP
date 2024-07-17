#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

vector<vector<int>> inputa(1001);
queue<int> mybfs;
bool dfsvisited[1001];
bool bfsvisited[1001];

void dfs(int a) {
    dfsvisited[a] = true;
    cout << a << " ";
    for (int i = 0; i < inputa[a].size(); i++) {
        if (!dfsvisited[inputa[a][i]])
            dfs(inputa[a][i]);
    }
}

void bfs(int a) {
    bfsvisited[a] = true;
    mybfs.push(a);
    while (!mybfs.empty()) {
        int curr = mybfs.front();
        mybfs.pop();
        cout << curr << " ";
        for (int i = 0; i < inputa[curr].size(); i++) {
            if (!bfsvisited[inputa[curr][i]]) {
                mybfs.push(inputa[curr][i]);
                bfsvisited[inputa[curr][i]] = true;
            }
        }
    }
}

int main() {
    int a, b, start;
    cin >> a >> b >> start;
    for (int i = 0; i < b; i++) {
        int one, two;
        cin >> one >> two;
        inputa[one].push_back(two);
        inputa[two].push_back(one);
    }

    for (int i = 1; i <= a; i++) {
        sort(inputa[i].begin(), inputa[i].end());
    }

    dfs(start);
    cout << "\n";
    bfs(start);

    return 0;
}
