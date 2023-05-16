N = int(input())
nums = list(map(int, input().split()))

nums.sort() # 수를 오름차순으로 정렬

res = 0

for i in range(N):
    left, right = 0, N-1 # left를 0, right를 찾고자 하는 수 - 1로 설정
    while left < right: # left가 right를 넘어가면 더 이상 찾는 의미가 없으므로 종료
        sumNum = nums[left] + nums[right]
        if sumNum > nums[i]: # left와 right의 합이 찾고자 하는 수보다 크면
            right -= 1 # right를 1만큼 줄여 합이 더 적도록 유도
        elif sumNum < nums[i]: # left와 rght의 합이 찾고자 하는 수보다 작으면
            left += 1 # left를 1만큼 키워 합이 더 크도록 유도
        else: # 합이 같을 때, left나 right가 자기 자신이 아닐 때만 res에 1 추가
            if(left == i):
                left += 1
            elif(right == i):
                right -= 1
            else:  
                res += 1
                break
print(res) # 결과 출력
            
            