#include <iostream>
#include <vector>
#include <climits>
#include <string>
#include <algorithm>
#include<stack>
using namespace std;
int h,w;
vector<vector<int>>th;
void change(int wheel, int direction){
    if(direction == 1){
        int temp = th[wheel][7];
        th[wheel][7] = th[wheel][6];
        th[wheel][6] = th[wheel][5];
        th[wheel][5] = th[wheel][4];
        th[wheel][4] = th[wheel][3];
        th[wheel][3] = th[wheel][2];
        th[wheel][2] = th[wheel][1];
        th[wheel][1] = th[wheel][0];
        th[wheel][0] = temp;
    }else if(direction == -1){
        int temp = th[wheel][0];
        th[wheel][0] = th[wheel][1];
        th[wheel][1] = th[wheel][2];
        th[wheel][2] = th[wheel][3];
        th[wheel][3] = th[wheel][4];
        th[wheel][4] = th[wheel][5];
        th[wheel][5] = th[wheel][6];
        th[wheel][6] = th[wheel][7];
        th[wheel][7] = temp;

    }

}

bool backoperate(int a){
    if(a-1>=1){
        if(th[a-1][2] != th[a][6]){
            return true;
        }
    }
    return false;
}
bool frontoperate(int a){
    if(a+1<=4){
        if(th[a+1][6] != th[a][2]){
            return true;
        }
    }
    return false;
}

void rightwheel(int wheel, int direction){
    if(frontoperate(wheel)){
        rightwheel(wheel+1, direction*-1);
    }
    change(wheel, direction);
}
void leftwheel(int wheel, int direction){
    if(backoperate(wheel)){
        leftwheel(wheel-1, direction*-1);
    }
    change(wheel, direction);
}


void changewheel(int wheel, int direction){
    if(backoperate(wheel)){
        leftwheel(wheel-1, direction*-1);
    }
    if(frontoperate(wheel)){
        rightwheel(wheel+1, direction*-1);
    }
    change(wheel, direction);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    th.resize(5,vector<int>(8,0));
    for(int i=1;i<=4;i++){
        string temp;
        cin>>temp;
        for(int j=0;j<8;j++){
            th[i][j] = temp[j]-'0';
        }
    }

    int a;
    cin>>a;
    for(int i=0;i<a;i++){
        int wheel, direction;
        cin>>wheel>>direction;
        changewheel(wheel, direction);

    }
    int answer=0;
    if(th[1][0] == 1){
        answer+=1;
    }
    if(th[2][0] == 1){
        answer+=2;
    }
    if(th[3][0] == 1){
        answer+=4;
    }
    if(th[4][0] == 1){
        answer+=8;
    }
    cout<<answer;

}