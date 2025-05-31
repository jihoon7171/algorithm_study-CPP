from collections import deque
t = int(input())
#matrix = [list(map(int, input().split())) for _ in range(m)]
dx,dy = [-1,1,0,0], [0,0,1,-1]

def bfs(matrix, visited,y,x):
    q = deque([])
    q.appendleft([y,x])
    while q :
        nowy, nowx = q.popleft()
        for i in range(4):
            newx, newy = nowx+dx[i], nowy+dy[i]
            if(0<=newx<m and 0<=newy<n and visited[newy][newx] is False and matrix[newy][newx] == 1):
                visited[newy][newx] = True
                q.append([newy,newx])

        


while t>0:
    t-=1
    #가로 m8 세로 n10
    m,n, k = map(int, input().split())
    matrix = [[0 for _ in range(m)] for _ in range(n)]
    visited = [[False for _ in range(m)] for _ in range(n)]
    for _ in range(k):
        x,y = map(int, input().split())
        matrix[y][x] = 1
    cnt = 0
    for i in range(n):
        for j in range(m):
            if visited[i][j] == False and matrix[i][j] == 1:
                visited[i][j] = True
                cnt+=1
                bfs(matrix, visited, i,j)
    print(cnt)



