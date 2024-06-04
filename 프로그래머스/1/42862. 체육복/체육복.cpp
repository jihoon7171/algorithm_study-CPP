#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int>all(n+1,1);
    for(int i=0;i<reserve.size();i++){
        int a = reserve[i];
        all[a]++; 
        }
    for(int i=0;i<lost.size();i++){
      int a = lost[i];
      all[a]--;
    }

    
    if(all[1] == 0){
        if(all[2] == 2){
            all[2]--;
            all[1]++;
            }        
    }
    if(all[n] == 0){
        if(all[n-1] == 2){
            all[n]++;
            all[n-1]--;
        }
    }
    
    for(int i=1;i<all.size();i++){
    if(all[i] == 0){
        if(all[i-1] == 2){
            all[i-1]--;
            all[i]++;
            }else if(all[i+1] == 2){
            all[i+1]--;
            all[i]++;
            }
        }
    }
    for(int i=1;i<all.size();i++){
    if(all[i] !=0){
    answer++;    
        }    
    }
    
    return answer;
}