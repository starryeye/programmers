#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int solution(int k, vector<vector<int>> dungeons) {

    vector<int> v;
   	
    for (int i = 0;i < dungeons.size(); i++) {
        v.push_back(i);
    }
     	
    int result = 0;

    do{
 		int copyK = k;
        int cnt = 0;
 		
        for(int i = 0; i < v.size(); i++) {

            if (dungeons[v[i]][0] > copyK)	
                break;

            copyK -= dungeons[v[i]][1];
            cnt++;
        }
        
        result = max(result, cnt);
      	
    } while (next_permutation(v.begin(), v.end()));
    
    return result;
}

/*
//backtracking
void backtracking(int& k, int& count, int& answer, vector<vector<int>>& dungeons, vector<bool>& check) {
    
    answer = max(answer, count);

    int size = dungeons.size();
    for (int i = 0; i < size; i++) {

        //예외처리
        if (check[i] == true)
            continue;

        if (k < dungeons[i][0])
            continue;

        k -= dungeons[i][1];
        check[i] = true;
        count++;

        backtracking(k, count, answer, dungeons, check);

        k += dungeons[i][1];
        check[i] = false;
        count--;
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    
    int answer = -1;
    int count = 0;
    vector<bool> check(dungeons.size(), false);
    
    backtracking(k, count, answer, dungeons, check);

    return answer;
}
*/
/*
//왜 안되는지 모르겠음
//k: 남은 피로도
//count : 방문 던전 수
void dfs(int start, int k, vector<vector<int>> d, vector<bool>& check, int count, int& answer) {
    
    check[start] = true;
    answer = max(answer, count);
    
    for(int next = 0; next < d.size(); next++) {
        
        if(check[next] == true)
            continue;
        
        //최소 필요 피로도 안됨.
        if(k < d[next][0])
            continue;
        
        //소모 피로도 감소, 방문 던전 카운트 + 1
        dfs(next, k - d[next][1], d, check, count+1, answer);
        check[next] = false;
    }
}

//k : 남은 피로도
int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    
    for(int start = 0; start < dungeons.size(); start++) {
        
        vector<bool> check(dungeons.size(), false);
        dfs(start, k, dungeons, check, 1, answer);
    }
    
    
    return answer;
}
*/