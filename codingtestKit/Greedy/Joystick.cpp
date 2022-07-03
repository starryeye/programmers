#include <string>
#include <vector>

using namespace std;
//https://velog.io/@rlagksql219/%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%A8%B8%EC%8A%A4C-%EC%A1%B0%EC%9D%B4%EC%8A%A4%ED%8B%B1-Greedy-nu1ltwjh
int solution(string name) {
    
    int answer = 0;
    int n = name.length();
    int turn = n-1;
    
    for(int i=0; i<n; i++) {
        
        //상하 이동
        if(name[i] - 'A' < 14) {
            answer += name[i] - 'A';
        }
        else {
            answer += 'Z' - name[i] + 1;
        }
        
        
        //좌우 이동 (turn)
        int index = i+1;
        while(index < n && name[index] == 'A') {
            index++;
        }
        int a = i;
        int b = n - index;
        turn  = min(turn, min(2*a+b, a+2*b));
    }
    answer += turn;
    
    return answer;
}