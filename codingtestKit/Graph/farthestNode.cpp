#include <string>
#include <vector>
#include <queue>

using namespace std;

int bfs(int start, vector<bool>& check, vector<int> v[]) {
    queue<int> que;
    que.push(start);
    check[start] = true;
    
    int cycl = 1;
    
    while(!que.empty()) 
    {
        cycl = que.size();
        
        for(int i=0; i<cycl; i++) 
        {
            int now = que.front();
            que.pop();
            
            for(int j=0 ; j < v[now].size() ; j++) 
            {
                int next = v[now][j];
                
                if(check[next])
                    continue;
                
                que.push(next);
                check[next] = true;
            }
        }
    }
    
    return cycl;
}

int solution(int n, vector<vector<int>> edge) {
    
    //adj
    vector<int> v[n+1];
    
    //check
    vector<bool> check(n+1, false);
    
    //adj
    for(int i=0; i<edge.size(); i++) {
        v[edge[i][0]].push_back(edge[i][1]);
        v[edge[i][1]].push_back(edge[i][0]);
    }
    
    
    return bfs(1, check, v);
}