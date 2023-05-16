from collections import deque

N = int(input())
grid = []
for i in range(N):
    grid.append(list(map(int, input().split())))
curEatFishCount = 0
curSize = 2
sharkPos = [0, 0]
moveCount = 0

def GetSharkPos():
    for i in range(N):
        for j in range(N):
            if grid[i][j] == 9:
                sharkPos[0] = i
                sharkPos[1] = j
                grid[i][j] = 0
                return
            
            

nPos = [[-1,0],[0,-1],[0,1],[1,0]]

def GetFish(curSize, x, y): # A* 알고리즘
    checkPos = deque([[x,y,0]]) # 덱을 이용하여 자료를 넣고 빼는 것의 시간 복잡도 단축
    checkedPos = [[x,y]]
    returnPos = None
    
    while checkPos:
        
        curPos = checkPos.popleft() # 탐색할 노드의 첫번째 리턴
        
        if returnPos != None and curPos[2] > returnPos[2]: # 최소 비용의 간선을 찾았다면 리턴
            break
        
        if grid[curPos[0]][curPos[1]] != 0 and grid[curPos[0]][curPos[1]] < curSize: # 먹을 수 있는 물고기를 발견했다면
            if returnPos == None:
                returnPos = curPos
            else: # 왼쪽 상단의 먹이를 먼저 먹어야 함
                if curPos[0] < returnPos[0] or (curPos[0] == returnPos[0] and curPos[1] < returnPos[1]):
                    returnPos = curPos
        
        for nx, ny in nPos: # 자식 노드를 탐색 노드에 추가
            rx = nx + curPos[0]
            ry = ny + curPos[1]
            if rx < 0 or rx >= N or ry < 0 or ry >= N:
                continue
            if not [rx,ry] in checkedPos: # 이미 탐색한 노드인가?
                if grid[rx][ry] <= curSize: # 지나 갈 수 있는 땅인가?
                    checkPos.append([rx,ry, curPos[2]+1])
                    checkedPos.append([rx,ry])
    return returnPos

GetSharkPos()
while True:
    res = GetFish(curSize, sharkPos[0], sharkPos[1])
    if res == None:
        break
    curEatFishCount += 1
    sharkPos[0] = res[0]
    sharkPos[1] = res[1]
    grid[sharkPos[0]][sharkPos[1]] = 0 # 먹은 물고기 자리를 0으로 바꾸기
    if curEatFishCount == curSize: # 상어 사이즈업
        curSize += 1
        curEatFishCount = 0
    moveCount += res[2]
print(moveCount)
    
