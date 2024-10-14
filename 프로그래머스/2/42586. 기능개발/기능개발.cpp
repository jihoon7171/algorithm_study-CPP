#include <string>
#include <vector>
#include<queue>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int>pr;
    queue<int>sp;
    for(int i=0;i<progresses.size();i++){
        pr.push(progresses[i]);
    }
    for(int i=0;i<progresses.size();i++){
        sp.push(speeds[i]);
    }
    while(1){
        if(pr.size()==0){break;}
        for(int i=0;i<pr.size();i++){
            int prtemp = pr.front();
            int sptemp = sp.front();
            prtemp += sptemp;
            pr.pop();
            sp.pop();
            pr.push(prtemp);
            sp.push(sptemp);
        }
        int count=0;
        while(1){
            if(pr.size()!=0 && pr.front()>=100){
                sp.pop();
                pr.pop();
                count++;
            }else{
                break;
            }
        }
        if(count>0){
            answer.push_back(count);
        }
    }
    return answer;
    
}