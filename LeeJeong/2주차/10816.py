N = int(input())
cards = list(map(int, input().split()))
M = int(input())
finds = list(map(int, input().split()))

res = {} # 입력 받은 카드를 미리 읽어 찾고자 하는 수의 개수를 바로 찾을 수 있도록 한다.
for i in cards:
    if i in res.keys(): # 찾고자 하는 수가 없다면 딕셔너리에 새로 추가하고, 이미 있다면 1 추가
        res[i] += 1
    else:
        res[i] = 1
for i in finds: 
    if i in res.keys(): # 딕셔너리에 추가된 수를 바탕으로 딕셔너리 키 중에 없다면 0, 있다면 값을 리턴
        print(res[i],end=" ")
    else:
        print(0, end=" ")