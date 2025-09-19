#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> num;

void run(int now, vector<int>& answer, int start) {
    if(now == m) {
        for(int i=0;i<m;i++) cout<<answer[i]<<" ";
        cout<<"\n";
        return;
    }
    for(int i=start;i<num.size();i++) {
        answer[now] = num[i];
        run(now+1, answer, i); // 중복 허용
    }
}

int main() {
    cin>>n>>m;
    vector<bool> visited(10001,false);
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        if(!visited[a]){
            visited[a]=true;
            num.push_back(a);
        }
    }
    sort(num.begin(), num.end());
    vector<int> answer(m);
    run(0, answer, 0);
}