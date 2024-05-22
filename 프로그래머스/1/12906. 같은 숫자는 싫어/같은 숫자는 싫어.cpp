#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    int index =1;
    int as = arr[0];
    answer.push_back(arr[0]);
    for(int i=0;i<arr.size()-1;i++){
    if(arr[i] != arr[i+1]){
        answer.push_back(arr[i+1]);
        index++;
        }
    }

    return answer;
}