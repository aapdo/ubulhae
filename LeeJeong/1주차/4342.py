import sys

def solution(a, b):
    
    if(a % b == 0): # 0으로 만들 수 있으면 1 return
        return 1
    elif(a - b > a): # a - b 했을 때, a보다 크면 내가 경우를 선택할 수 있음.
        return 1
    else: # 내가 경우를 선택하지 못하는 경우
        return not solution(b, a-b) # 바로 다음 상태에서 상대가 이기면 내가 진거고, 상대가 이기면 내가 진거임
    
A, B = map(int, sys.stdin.readline().split())

while A != 0 or B != 0:
    
    if B > A:
        A, B = B, A
    
    if solution(A, B):
        print("A wins")
    else:
        print("B wins")
        
    A, B = map(int, sys.stdin.readline().split())