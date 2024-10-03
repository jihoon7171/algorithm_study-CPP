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
vector<int>belt(101); //내구도
vector<int>nowbelt(101);
vector<bool>robot(51);

int main() {
    int n,k;
    cin>>n>>k;
    belt.resize((2*n) +1);
    robot.resize(n+1);
    nowbelt.resize((2*n)+1);
    for(int i=1;i<=2*n;i++){
        nowbelt[i] = i;
    }
    for(int i=1;i<=n*2;i++){
        cin>>belt[i];
    }
    int count=0;

    while(1){
        count++;

        /*벨트 이동*/
        int temp = belt[2*n];
        for(int i=2*n;i>=2;i--){
            belt[i] = belt[i-1];
        }
        belt[1] = temp;
        for(int i=n-1;i>=1;i--){
            robot[i+1] = robot[i];
        }   
        robot[1] = false;
        robot[n] = false;

        for(int i=n-1;i>=1;i--){
            if(robot[i] == true && robot[i+1] == false && belt[i+1]>0){
                robot[i] = false;
                robot[i+1] = true;
                belt[i+1]--;
            }
        }
        if(belt[1]>0){
            robot[1] = true;
            belt[1]--;
        }

        robot[n] = false;


        int cnt=0;
        for(int i=1;i<=n*2;i++){
            if(belt[i] ==0){
                cnt++;
            }
        }
        if(cnt>=k)break;
    }
    cout<<count;
}