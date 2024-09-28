#include <iostream>
#include <vector>
#include<algorithm>
#include<unordered_set>
#include<queue>
#include<map>
#include<cstring>
#include<climits>
using namespace std;
vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size(),0);
    vector<vector<int>>warning(id_list.size(), vector<int>(id_list.size(),0));
    vector<int>warningcount(id_list.size(),0);
    map<string, int>name;
    for(int i=0;i<id_list.size();i++){
        name[id_list[i]] = i;
    } // id 별 번호 지정
  
    for(int i=0;i<report.size();i++){
        string temp = report[i];
        int space_pos = temp.find(" "); 
        string from = temp.substr(0, space_pos);  
        string to = temp.substr(space_pos + 1);  
        
        if(warning[name[from]][name[to]] == 0){
        warning[name[from]][name[to]] = 1;
        warningcount[name[to]]++;
    }

    }

    for(int i=0;i<warningcount.size();i++){
        if(warningcount[i] >=k){
            for(int j=0;j<warning.size();j++){
                if(warning[j][i] == 1){
                    answer[j]++;
                }
            }
        }
    }
    return answer;
}


