from collections import deque

##### BFS 사용 #####

N, M = map(int, input().split())

MAX = 100001

dp = [False for i in range(MAX)]

q = deque([])
q.append([N, 0])
dp[N] = True

while q:
    
    currentPos = q.popleft()
    if currentPos[0] == M:
        print(currentPos[1])
        break
    
    if currentPos[0]*2 < MAX and not dp[currentPos[0]*2]:
        q.appendleft([currentPos[0] * 2, currentPos[1]])
        dp[currentPos[0] * 2] = True
    
    if currentPos[0]-1 >= 0 and not dp[currentPos[0]-1]:
        q.append([currentPos[0] - 1, currentPos[1] + 1])
        dp[currentPos[0] - 1] = True
        
    if currentPos[0]+1 < MAX and not dp[currentPos[0]+1]:
        q.append([currentPos[0] + 1, currentPos[1] + 1])
        dp[currentPos[0] + 1] = True
        
    
