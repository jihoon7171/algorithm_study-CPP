#include <iostream>
#include <vector>
#include <algorithm>
#include<climits>
#include<tuple>
#include<string>
using namespace std;

// 가로 세로 대각선 방향으로 3칸 이상 -> 가능할 수 없는 게임
// 게임판이 가득 

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

//pair<pair<int, int>, int> ch[8] = {{{2,4},6},{{0,4},8},{{0,1},2},{{3,4},5},{{6,7},8},{{0,3},6},{{1,4},7},{{2,5},8}};
tuple<int, int, int> ch[8] = {
    {2, 4, 6},
    {0, 4, 8},
    {0, 1, 2},
    {3, 4, 5},
    {6, 7, 8},
    {0, 3, 6},
    {1, 4, 7},
    {2, 5, 8}
};

void iswin(string temp, int  dotcount, int xcount, int ocount){
    int xwin = 0;
    int owin = 0;
    for(int i=0;i<8;i++){
        int a,b,c;
        tie(a,b,c) = ch[i];
        if(temp[a]==temp[b]&&temp[b]==temp[c]&&temp[a] != '.'){
            if(temp[a] == 'X'){
                xwin++;
            }else{
                owin++;
            }
        }
    }
    if(xwin>0 && owin>0){
        cout<<"invalid\n";
        return;
    }
    if(xwin > 0){
        if(xcount == ocount+1){
            cout<<"valid\n";
            return ;
        }else{
            cout<<"invalid\n";
            return ;
        }
    }
    if(owin > 0){
        if(xcount == ocount){
            cout<<"valid\n";
            return ;
        }else{
            cout<<"invalid\n";
            return ;
        }

    }
    if(dotcount == 0){
        cout<<"valid\n";
        return ;
    }
    if(dotcount > 0){
        cout<<"invalid\n";
        return ;
    }
    cout<<"valid\n"; //패배
}


void checking(string temp){
    int xcount = 0;
    int ocount = 0;
    int dotcount = 0;
    for(int i=0;i<9;i++){
        if(temp[i] == 'X'){
            xcount++;
        }else if(temp[i] == 'O'){
            ocount++;
        }else{
            dotcount++;
        }
    }
    //cout<<xcount<<" "<<ocount<<" "<<dotcount<<"\n";
    //꽉 찼을경우
    if(dotcount == 0){
        if(xcount != ocount+1){
            cout<<"invalid\n";
            return ;
        }else{
            iswin(temp, dotcount, xcount, ocount);
        }
    }else{
        // if(xcount  > ocount+2 || ocount > xcount+2 ){
        //     cout<<"invalid\n";
        //     return ;
        // }
        if(dotcount % 2 == 0){
            if(xcount != ocount+1){
                cout<<"invalid\n";
                return ;
            }
        }else{
            if(xcount != ocount){
                cout<<"invalid\n";
                return ;
            }
        }
        iswin(temp, dotcount, xcount, ocount);
    }

}


int main(){
    while(1){
        string temp;
        cin>>temp;
        if(temp == "end") break;
        checking(temp);

    }
}
