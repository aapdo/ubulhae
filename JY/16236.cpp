#include <iostream>
#include <queue>
#include <vector>
#define max_int 21
#define max_val 401

using namespace std;

/*
 �ð� ���⵵: O(n^4)

 ����� �˰���: BFS
 BFS�� ����� ����:
 1. �ִ� ��θ� ã�� ����
 2. BFS�� ��� ������ ����ġ�� 1�϶� �ִܰ�� ã�� ����
 3. BFS�� �ð� ���⵵:
    1) ��������ƮƲ ����� ��� O(v+e)
    2) ��������� ����� ���(v^2)

������ �� n^2 + ������ �� 4*n^2 = O(n^2)
 ����� �ڷᱸ��: 2���� �迭, ť
 */


// a �迭�� ������ ������ ����. check �迭�� �̵��Ÿ��� ����.
int n, a[max_int][max_int], check[max_int][max_int], shark_x, shark_y, eat_cnt, shark_size = 2;
int min_dist, min_x, min_y, result;

int dx[] = {0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0};

// ��� �Ǵ� ������ ��ǥ(x, y)�� ������ ������ ����
// ���� ��, ���� ���� �񱳰� ���� ������
struct info{
    int x, y;
};

// BFS ������ ���� ���� �ʱ�ȭ
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

//BFS ����
void bfs(int x, int y){
    // BFS�� ����� ť
    queue<info> q;
    //�ð� �ʱ�ȭ
    check[x][y] = 0;
    q.push({x, y});

    while(!q.empty()){
        //���� ��ġ�� �� info
        info cur = q.front();
        q.pop();
        int x = cur.x;
        int y = cur.y;

        // 4������ Ž��
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            //�� ���� ���
            if(nx < 1 || nx > n || ny < 1 || ny > n) continue;
            // 1) �̹� �湮, 2) ���� ū ������� ���
            if(check[nx][ny] != -1 || a[nx][ny] > shark_size) continue;

            //������� �°� ������ �� ����.
            //(nx, ny)�� �ִ� ���������� �̵��Ÿ��� ����
            check[nx][ny] = check[x][y] + 1;

            //���� �� �ִ� ������� ���
            if(a[nx][ny] != 0 && a[nx][ny] < shark_size){

                // ���� ���� ���������� �̵��ð��� �� ª�� ���
                if(min_dist > check[nx][ny]){
                    min_x = nx;
                    min_y = ny;
                    min_dist = check[nx][ny];
                }
                // ���� ���� ���������� �̵��ð��� ������ 1) ���� ����, ���� ������ ã��
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

            // ������� ��ġ�� ť�� �ֱ�
            q.push({nx, ny});
        }
    }
}

int main(){
    scanf("%d", &n);

    //�� �����
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            scanf("%d", &a[i][j]);

            // �Ʊ� ����� ���
            if(a[i][j] == 9){
                // x, y ��ǥ�� ���� ����
                shark_x = i;
                shark_y = j;
                // �����󿡼� 0���� �ٲ���
                a[i][j] = 0;
            }
        }
    }

    // �� n^2�� ����
    while(true){
        init_check();

        //bfs�� ����� ã��
        bfs(shark_x, shark_y);

        // ���� �� �ִ� ����⸦ ã�� ���
        if(min_x != max_int && min_y != max_int){
            // �̵��ð��� ����
            result += check[min_x][min_y];

            // ����� ���� ���� 1 ����
            eat_cnt++;

            // ���� ���� ����� ���� ����� ũ��� ���ٸ�
            if(eat_cnt == shark_size){
                // ����� ũ�⸦ 1 ������Ű��, ���� ����� ���� 0���� �ʱ�ȭ
                shark_size++;
                eat_cnt = 0;
            }

            // ���� ������� ��ġ�� 0���� ����
            a[min_x][min_y] = 0;

            // ����� ��ġ�� ����
            shark_x = min_x;
            shark_y = min_y;
        }

            // ���� �� �ִ� ����Ⱑ ���� ��� �ݺ��� ����
        else{
            break;
        }
    }

    printf("%d\n", result);
}