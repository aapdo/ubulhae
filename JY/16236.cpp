#include <iostream>
#include <queue>
#include <vector>
#define max_int 21
#define max_val 401

using namespace std;

/*
 시간 복잡도: O(n^4)

 사용한 알고리즘: BFS
 BFS를 사용한 이유:
 1. 최단 경로를 찾기 위해
 2. BFS는 모든 간선의 가중치가 1일때 최단경로 찾기 좋음
 3. BFS의 시간 복잡도:
    1) 인접리스트틀 사용한 경우 O(v+e)
    2) 인접행렬을 사용한 경우(v^2)

정점의 수 n^2 + 간선의 수 4*n^2 = O(n^2)
 사용한 자료구조: 2차원 배열, 큐
 */


// a 배열은 지도의 정보를 저장. check 배열은 이동거리를 저장.
int n, a[max_int][max_int], check[max_int][max_int], shark_x, shark_y, eat_cnt, shark_size = 2;
int min_dist, min_x, min_y, result;

int dx[] = {0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0};

// 상어 또는 물고의 좌표(x, y)를 저장할 구초제 정의
// 가장 위, 가장 왼쪽 비교가 들어가기 때문에
struct info{
    int x, y;
};

// BFS 수행을 위한 정보 초기화
void init_check(){
    min_dist = max_val;
    min_x = max_int;
    min_y = max_int;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            check[i][j] = -1;
        }
    }
}

//BFS 수행
void bfs(int x, int y){
    // BFS에 사용할 큐
    queue<info> q;
    //시간 초기화
    check[x][y] = 0;
    q.push({x, y});

    while(!q.empty()){
        //현재 위치가 될 info
        info cur = q.front();
        q.pop();
        int x = cur.x;
        int y = cur.y;

        // 4방향을 탐색
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            //맵 밖인 경우
            if(nx < 1 || nx > n || ny < 1 || ny > n) continue;
            // 1) 이미 방문, 2) 상어보다 큰 물고기인 경우
            if(check[nx][ny] != -1 || a[nx][ny] > shark_size) continue;

            //여기까지 온건 움직일 수 있음.
            //(nx, ny)에 있는 물고기까지의 이동거리를 갱신
            check[nx][ny] = check[x][y] + 1;

            //먹을 수 있는 물고기일 경우
            if(a[nx][ny] != 0 && a[nx][ny] < shark_size){

                // 만약 현재 물고기까지의 이동시간이 더 짧은 경우
                if(min_dist > check[nx][ny]){
                    min_x = nx;
                    min_y = ny;
                    min_dist = check[nx][ny];
                }
                // 만약 현재 물고기까지의 이동시간은 같으면 1) 가장 위쪽, 가장 왼쪽을 찾음
                else if(min_dist == check[nx][ny]){
                    if(min_x == nx){
                        if(min_y > ny){
                            min_x = nx;
                            min_y = ny;
                        }
                    }else if(min_x > nx){
                        min_x = nx;
                        min_y = ny;
                    }
                }
            }

            // 물고기의 위치를 큐에 넣기
            q.push({nx, ny});
        }
    }
}

int main(){
    scanf("%d", &n);

    //맵 만들기
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            scanf("%d", &a[i][j]);

            // 아기 상어일 경우
            if(a[i][j] == 9){
                // x, y 좌표를 따로 저장
                shark_x = i;
                shark_y = j;
                // 지도상에서 0으로 바꿔줌
                a[i][j] = 0;
            }
        }
    }

    // 총 n^2번 수행
    while(true){
        init_check();

        //bfs로 물고기 찾기
        bfs(shark_x, shark_y);

        // 먹을 수 있는 물고기를 찾은 경우
        if(min_x != max_int && min_y != max_int){
            // 이동시간을 더함
            result += check[min_x][min_y];

            // 물고기 먹은 수를 1 증가
            eat_cnt++;

            // 만약 먹은 물고기 수가 상어의 크기와 같다면
            if(eat_cnt == shark_size){
                // 상어의 크기를 1 증가시키고, 먹은 물고기 수를 0으로 초기화
                shark_size++;
                eat_cnt = 0;
            }

            // 먹은 물고기의 위치를 0으로 갱신
            a[min_x][min_y] = 0;

            // 상어의 위치를 갱신
            shark_x = min_x;
            shark_y = min_y;
        }

            // 먹을 수 있는 물고기가 없는 경우 반복문 끝냄
        else{
            break;
        }
    }

    printf("%d\n", result);
}