#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//남, 서, 북, 동
int dy[4] = {-1,0,1,0};
int dx[4] = {0,-1,0,1};

struct pos{
    
    int y, x; //좌표
    int dir; //방향
    int dist; //거리
    
    pos(int _y, int _x, int _dir, int _dist) {
        y = _y;
        x = _x;
        dir = _dir;
        dist = _dist;
    }
};

void dfs(vector<string>& grid, vector<vector<vector<bool>>>& check, pos cur, vector<int>& answer) {
    
    
    check[cur.y][cur.x][cur.dir] = true;
     
    pos next(0, 0, 0, 0);
    next.y = cur.y + dy[cur.dir];
    next.x = cur.x + dx[cur.dir];
        
    //경계 넘어감
    if(next.y < 0) {
        next.y = grid.size() - 1;
    }else if(next.x < 0) {
        next.x = grid[0].size() - 1;
    }else if(next.y >= grid.size()) {
        next.y = 0;
    }else if(next.x >= grid[0].size()) {
        next.x = 0;
    }
        
    //방향 결정
    if(grid[next.y][next.x] == 'S') {
        next.dir = cur.dir;
        next.dist = cur.dist + 1;
    }else if(grid[next.y][next.x] == 'R') {
        next.dir = (cur.dir + 1) % 4;
        next.dist = cur.dist + 1;
    }else if(grid[next.y][next.x] == 'L') {
        next.dir = (cur.dir + 3) % 4;
        next.dist = cur.dist + 1;
    }

    //방향도 계산하면, check 돌려서 한번 보기..
    //check가 true 이면.. answer에 dist 집어 넣어야 한다.. 그리고 dfs는 돌리지 않는다.
    //false이면 dfs
        
    if(check[next.y][next.x][next.dir] == true) {
        answer.push_back(next.dist);
    }else {        
        dfs(grid, check, next, answer);
    }
}


vector<int> solution(vector<string> grid) {
    vector<int> answer;
    
    vector<vector<vector<bool>>> check(grid.size(), vector<vector<bool>>(grid[0].size(), vector<bool>(4, false)));
    
    for(int i = 0; i < grid.size(); i++) {
        for(int j = 0; j < grid[0].size(); j++) {
            for(int k = 0; k < 4; k++) {
                if(check[i][j][k] == false) {
                    pos start(i, j, k, 0);
                    dfs(grid, check, start, answer);
                }   
            }
        }
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}