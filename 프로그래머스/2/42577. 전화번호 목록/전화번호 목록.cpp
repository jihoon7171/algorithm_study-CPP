#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int check(string a, string b) {
    if (a.size() > b.size()) {
        string qw = a.substr(0, b.size());
        int qq = qw.compare(b);
        if (qq == 0) {
            return 1;
        } else {
            return 0;
        }
    } else if (a.size() < b.size()) {
        string qw = b.substr(0, a.size());
        int qq = qw.compare(a);
        if (qq == 0) {
            return 1;
        } else {
            return 0;
        }
    } else {
        int qq = a.compare(b);
        if (qq == 0) {
            return 1;
        } else {
            return 0;
        }
    }
}

bool solution(vector<string> phone_book) {
    bool answer = true;
    sort(phone_book.begin(), phone_book.end());
    for (int i = 0; i < phone_book.size() - 1; i++) {
        string prefix = phone_book[i];
        string next = phone_book[i + 1];
        if (next.find(prefix) == 0) {
            answer = false;
            break;
        }
    }
    return answer;
}
