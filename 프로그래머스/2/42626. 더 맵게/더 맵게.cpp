#include <string>
#include <vector>
#include <algorithm>
#include<queue>
#include<functional>
using namespace std;

int solution(vector<int> scoville, int k) {
    priority_queue<int, vector<int>, greater<int>> qw(scoville.begin(), scoville.end());
        
    int count=0;
    int answer =0;
    int mm = qw.top();
    if(mm>=k){
return 0;}
    do{
        count =0;
        
        int min1 = qw.top();
        qw.pop();
        int min2 = qw.top();
        qw.pop();
        int min = min1 + min2*2;
        qw.push(min);
        answer ++ ;
      
        if(qw.top()<k){ 
            count++;
        }
        
    }while(count > 0 && qw.size() >1);
    if((qw.size() ==1 && qw.top() < k)){
        return -1;
    }
    return answer;
}