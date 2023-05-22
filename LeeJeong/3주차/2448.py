N = int(input())
grid = [[' ' for __ in range(2*N-1)] for _ in range(N)]

def solution(x, y, size):
    if(size == 1):
        grid[x][y] = '*'
        grid[x+1][y-1] = '*'
        grid[x+1][y+1] = '*'
        for i in range(-2, 3):
            grid[x+2][y+i] = '*'
        return
    else:
        solution(x, y, size//2)
        solution(x + size, y - size, size//2)
        solution(x + size, y + size, size//2)

solution(0,N-1,N//2)
for i in grid:
    for j in i:
        print(j, end= "")
    print()