#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void rotate(int depth, vector<vector<int>>& inputArr, int row, int col)
{
    vector<vector<int>> tmp(row, vector<int>(col));
    for (int k = 0; k < depth; k++)
    {
        int r1 = k, c1 = k;
        int r2 = row - k - 1, c2 = col - k - 1;

        // 좌
        for (int i = r2 - 1; i >= r1; i--)
            tmp[i + 1][c1] = inputArr[i][c1];
        // 하
        for (int i = c2 - 1; i >= c1; i--)
            tmp[r2][i + 1] = inputArr[r2][i];
        // 우
        for (int i = r1 + 1; i <= r2; i++)
            tmp[i - 1][c2] = inputArr[i][c2];
        // 상
        for (int i = c1 + 1; i <= c2; i++)
            tmp[r1][i - 1] = inputArr[r1][i];
    }
    inputArr = tmp;
}

int main()
{
    int n, m, r;
    cin >> n >> m >> r;
    vector<vector<int>> arr(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];

    int cnt = min(n, m) / 2;

    while (r--)
        rotate(cnt, arr, n, m);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << arr[i][j] << ' ';
        cout << '\n';
    }
}