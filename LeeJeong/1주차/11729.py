N = int(input())
answer = []

def solution(number, start, moveTo):
    if(number == 1):
        answer.append([start, moveTo]) # 이동한 경로 result에 넣어놓기
        return
    solution(number-1, start, 6 - start - moveTo) # Base 빼고 전부 다른 곳으로 이동
    answer.append([start, moveTo]) # Base를 도착지로 이동시키고
    solution(number-1, 6 - start - moveTo, moveTo) # Base를 제외한 나머지 이동
    
solution(N, 1, 3)
print(len(answer)) # 총 이동 횟수
for nums in answer:
    print(nums[0], nums[1]) # 이동 경로 출력