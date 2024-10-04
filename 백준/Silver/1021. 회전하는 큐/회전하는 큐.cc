#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <queue>
#include <map>
#include <cstring>
#include <climits>
#include <string>
#include<deque>
using namespace std;

int main() {
    int n,m;
    cin>>n>>m;
    deque<int>q;
    for(int i=1;i<=n;i++){
        q.push_back(i); //1 2 3 4 .... i
    }
    int count=0;
    for(int i=0;i<m;i++){
        int temp;
        cin>>temp;
        if(q.front() == temp){
            q.pop_front();
        }else{
            int fronttemp = q.front();
            int backtemp = q.back();
            int numcount=0;
            for(int j=0;j<q.size();j++){
                numcount++;
                if(q[j] == temp){
                    break;
                }
            }
            int leftmove = numcount-1;
            int rightmove = q.size() - numcount+1;
            if(leftmove<=rightmove){
                while(leftmove--){
                    int move = q.front();
                    q.pop_front();
                    q.push_back(move);
                    count++;
                }
                q.pop_front();
                }else{
                    while(rightmove--){
                        int move = q.back();
                        q.pop_back();
                        q.push_front(move);
                        count++;
                    }
                q.pop_front();
            }
        }
    }
    cout<<count;
}