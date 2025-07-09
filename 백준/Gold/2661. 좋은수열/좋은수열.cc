#include<iostream>
#include<vector>
#include<unordered_map>
#include<set>
#include<unordered_set>
#include<queue>
#include<climits>
#include<string>
using namespace std;
int n;
bool found = false;
bool checking(const string& temp) {
    int len = temp.size();
    // 마지막 부분이 반복되는지 확인
    for (int i = 1; i <= len / 2; i++) {
        string s1 = temp.substr(len - i, i);
        string s2 = temp.substr(len - 2 * i, i);
        if (s1 == s2) return false;
    }
    return true;
}
void plusnum(string now, int depth){
    if(found) return;
    if(depth == n){
        cout<<now;
        found = true;
        return;
    }
    for(int i=1;i<=3;i++){
        string temp = now+to_string(i);
        if(checking(temp)){
            plusnum(temp, depth+1);
        }
    }
}

int main(){
    cin>>n;
    string now = "";
    plusnum(now,0);
    
}


