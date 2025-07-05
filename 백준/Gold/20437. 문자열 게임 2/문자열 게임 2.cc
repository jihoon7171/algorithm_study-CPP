#include<iostream>
#include<vector>
#include<unordered_map>
#include<set>
#include<unordered_set>
#include<queue>
#include<climits>
#include<string>
using namespace std;
int t;
int main(){
    cin>>t;
    for(int i=0;i<t;i++){
        string temp;
        cin>>temp;
        int n;
        cin>>n;
        vector<vector<int>>alp(26);
        int one = INT_MAX;
        int two = INT_MIN;
        bool flag = false;
        for(int i=0;i<temp.size();i++){
            int num = temp[i]-97;
            alp[num].push_back(i);
            if(alp[num].size()>1) flag = true;
        }
        for(int j=0;j<alp.size();j++){
            if(alp[j].size()>=n){
                for(int k=0;k<=alp[j].size()-n;k++){
                    int now = abs(alp[j][k] - alp[j][k+n-1])+1;
                    one = min(one, now);
                    two = max(two, now);
                    //cout<<now<<"\n";
                }
            }
        }
        if(one == INT_MAX) cout << -1 << "\n";
        else cout << one << " " << two << "\n";
    }
    
}

