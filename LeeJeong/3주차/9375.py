import sys
input = sys.stdin.readline

# 입을 수 있는 경우의 수 = (종류 별 개수 + 1) 한거 전부 곱한거에 모두 벗은 경우 1가지를 제외한 것

T = int(input())

for _ in range(T):
    N = int(input())
    wear = {}
    for __ in range(N):
        key = input()
        key = key[key.find(" "):]
        if key in wear.keys():
            wear[key] += 1
        else:
            wear[key] = 1
    result = 1
    for case in wear.values():
        result *= (case+1)
    print(result - 1)