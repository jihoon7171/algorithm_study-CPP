#include<iostream>
#include<vector>
#include<cmath>
#include<queue>
#include<algorithm>
using namespace std;

int main(){
    string a, b;
    cin >> a >> b;
    vector<vector<int>> answer(a.size() + 1, vector<int>(b.size() + 1, 0));
    
    for(int i = 1; i <= a.size(); i++){
        for(int j = 1; j <= b.size(); j++){
            if(a[i - 1] == b[j - 1])  
                answer[i][j] = answer[i - 1][j - 1] + 1;
            else
                answer[i][j] = max(answer[i - 1][j], answer[i][j - 1]);
        }
    }
    
    cout << answer[a.size()][b.size()];
}