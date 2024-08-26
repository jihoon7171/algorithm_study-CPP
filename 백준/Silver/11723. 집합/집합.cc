#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<algorithm>
#include<stack>
#include<unordered_set>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a,qw;
    cin>>a;
    unordered_set<int>ans;
    unordered_set<int>new_ans = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    for(int i=0;i<a;i++){

        string as;
        cin>>as;
        if(as == "empty"){
            ans.clear();

        }else if(as == "add"){

            cin>>qw;
            ans.insert(qw);
        }else if(as== "remove"){

                cin>>qw;
            if(ans.find(qw) != ans.end()){
                ans.erase(qw);
                }
        }else if(as=="toggle"){

                cin>>qw;
             if(ans.find(qw) != ans.end()){
                    ans.erase(qw);
                }else{
                    ans.insert(qw);
                }
            }else if(as == "all"){
                ans = new_ans;
            }else if(as=="check"){

                cin>>qw;
                cout << (ans.find(qw) != ans.end() ? "1" : "0") << "\n";
            }
        }
}


