# 승리의 규칙
# 1 2 1 1 1 1 2 1 2 1 ...
# 1 : SK, 2 : CY
# 7번마다 반복됨

remain = (int(input()) - 1) % 7
print("CY" if remain == 1 or remain == 6 else "SK")