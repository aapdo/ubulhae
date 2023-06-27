import sys

N = int(sys.stdin.readline().rstrip())
numbers = list(map(int, sys.stdin.readline().rstrip().split()))
people = int(sys.stdin.readline().rstrip())

offset = N // people # 한 사람당 정렬을 맡아야 하는 number 개수
for i in range(0, N, offset):
    for num in sorted(numbers[i:i+offset]):
        print(num, end = " ")