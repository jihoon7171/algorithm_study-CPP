#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string temp;
    cin >> temp;

    int acount = 0, bcount = 0;


    for (char c : temp) {
        if (c == 'a') acount++;
        else bcount++;
    }


    int start = 0, end = acount - 1;
    int changeb = 0;


    for (int i = start; i <= end; ++i) {
        if (temp[i] == 'b') changeb++;
    }

    int mina = changeb;


    while (end + 1 < temp.size()) {
        if (temp[start] == 'b') changeb--;
        start++;
        end++;
        if (temp[end] == 'b') changeb++;
        mina = min(mina, changeb);
    }


    start = 0;
    end = bcount - 1;
    int changea = 0;


    for (int i = start; i <= end; ++i) {
        if (temp[i] == 'a') changea++;
    }

    int minb = changea;


    while (end + 1 < temp.size()) {
        if (temp[start] == 'a') changea--;
        start++;
        end++;
        if (temp[end] == 'a') changea++;
        minb = min(minb, changea);
    }


    cout << min(mina, minb);

    return 0;
}