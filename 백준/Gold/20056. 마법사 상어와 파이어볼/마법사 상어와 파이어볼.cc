#include<iostream>
#include<vector>

using namespace std;
int n,mc,kc;
struct fireball{
    int r;
    int c;
    int d;
    int s;
    int m;

};
int dx[8] = {0,1,1,1,0,-1,-1,-1};
int dy[8] = {-1,-1,0,1,1,1,0,-1};


//vector<vector<vector<fireball>>>(n+1, vector<vector<int>>(n+1, vector<fireball>(n+1)))
vector<vector<vector<fireball>>> space(51, vector<vector<fireball>>(51));

void move_fireball(){
    vector<vector<vector<fireball>>> copy_space(51, vector<vector<fireball>>(51));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(space[i][j].size()>0){
                for(int k=0;k<space[i][j].size();k++){
                    fireball temp_fireball = space[i][j][k];
                    int m = temp_fireball.m;
                    int d = temp_fireball.d;
                    int s = temp_fireball.s;
                    int xx = j-1;
                    int yy = i-1;

                    int newx = ( ( (j - 1 + dx[d] * s) % n + n ) % n ) + 1;
                    int newy = ( ( (i - 1 + dy[d] * s) % n + n ) % n ) + 1;
                    temp_fireball.r = newy;
                    temp_fireball.c = newx;
                   // cout<<i<<" "<<j<<newy<<" "<<newx<<"\n";
                    copy_space[newy][newx].push_back(temp_fireball);
                }
            }
        }
    }
    space = copy_space;
}

void plus_fireball(){
    vector<vector<vector<fireball>>> copy_space(51, vector<vector<fireball>>(51));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(space[i][j].size()==1){
                copy_space[i][j] = space[i][j];
            }else if(space[i][j].size()>1){
                int total_m = space[i][j][0].m;
                int total_s = space[i][j][0].s;
                bool original_flag = true; // true - 짝수 false - 홀수
                if(space[i][j][0].d % 2 != 0){
                    original_flag = false;
                }
                bool temp_flag = true;
                bool result_direction = true;
                for(int k=1;k<space[i][j].size();k++){
                    total_m += space[i][j][k].m;
                    total_s +=space[i][j][k].s;
                    if(space[i][j][k].d % 2 == 0){
                        temp_flag = true;
                    }else{
                        temp_flag = false;
                    }
                    if(temp_flag != original_flag){
                        result_direction = false; // 한번이라도 홀짝 다르면 false
                    }
                }
                int sep_m = total_m/5;
                int sep_s = total_s/space[i][j].size();
                if(sep_m == 0){
                    continue; //질량이 0이면 소멸되어 없어짐
                }else{
                    //짝수일경우
                    if(result_direction){
                        for(int k=0;k<7;k+=2){
                            copy_space[i][j].push_back({i,j,k,sep_s, sep_m});
                          //  cout<<i<<" "<<j<<k<<"\n";
                        }
                    }else if(!result_direction){
                        for(int k=1;k<8;k+=2){
                            copy_space[i][j].push_back({i,j,k,sep_s, sep_m});
                          //  cout<<i<<" "<<j<<k<<"\n";
                        }
                    }
                }
            }
        }
    }
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++){
    //         if(copy_space[i][j].size()>0){
    //             for(int k=0;k<copy_space[i][j].size();k++){
    //                 cout<<i<<" "<<j<<"의 "<<k<<"번째 파이어볼 질량 :"<<copy_space[i][j][k].m<<"\n";
    //             }
    //         }
    //     }
    //     cout<<"\n";
    // }
    space = copy_space;
}


void result(){
    int answer = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=0;k<space[i][j].size();k++){
                answer += space[i][j][k].m;
            }
        }
    }
    cout<<answer;
}

void cout_space(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int answer = 0;
            for(int k=0;k<space[i][j].size();k++){
                answer +=space[i][j][k].m;
            }
            cout<<answer<<" ";
        }
        cout<<"\n";
    }
}
int main(){
    cin>>n>>mc>>kc;
     //cout<<"입력시작";
    while(mc>0){
        //out<<"입력시작"<<mc<<"\n";
        mc--;
        int d,r,c,m,s;
        cin>>r>>c>>m>>s>>d;
        fireball t_fireball;
        t_fireball.r =r;
        t_fireball.c = c;
        t_fireball.m = m;
        t_fireball.s = s;
        t_fireball.d = d;
        space[r][c].push_back(t_fireball);
    }
   // cout<<"입력 완료";
   // cout_space();
    //cout<<"\n";
    while(kc>0){
       // cout<<"move start \n";
        kc--;
       // cout<<kc<<"\n";
        move_fireball();
       //cout_space();
        plus_fireball();

       // cout_space();
    }
   result();




    return 0;
}