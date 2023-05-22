#from collections import deque

N = int(input())

primeList = []

########### 소수 찾기 #############

numList = [True for _ in range(N+1)]
numList[0] = False
numList[1] = False

########### 머시기 채 그걸로 소수 찾음 ############

for i in range(2,N+1):
    if numList[i]: # 소수라면?
        primeList.append(i) # 소수 리스트에 넣고,
        count = 2
        while i * count <= N: # 소수의 배수를 전부 합성수(False)라고 표시
            numList[i*count] = False
            count += 1


# 소수 리스트에서 시작 위치랑 끝 위치를 잡고
# 그 사이에 있는 수의 합이 N이랑 같을 경우를 추가하는 방법

startIdx = 0
endIdx = 0

if len(primeList) == 0:
    sumNum = 0
else:
    sumNum = primeList[0]
resultCount = 0

while endIdx < len(primeList):
    if sumNum == N: # N이랑 같으면, 결과값 추가 후, endIdx 1 추가
        resultCount += 1
        endIdx += 1
        if endIdx == len(primeList):
            break
        sumNum += primeList[endIdx]
    elif sumNum < N: # N보다 작으면, endIdx 1 추가
        endIdx += 1
        if endIdx == len(primeList):
            break
        sumNum += primeList[endIdx]
    else: # N보다 크면, startIdx 1 추가
        sumNum -= primeList[startIdx]
        startIdx += 1

print(resultCount)
    