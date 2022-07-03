#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    
    //0 : 한개 가짐, -1 : 1개부족, +1 : 2개 가짐
    vector<int> students(n, 0); //0번부터 n-1번까지 (총 n)
    
    for(auto l : lost) { //도난
        students[l-1]--;    //1~n 을 0~n-1로 변환
    }
    
    for(auto r : reserve) { //여분
        students[r-1]++;      //1~n 을 0~n-1로 변환
    }
    
    for(int i = 0; i<n; i++) {
        if(students[i] < 0) {
            if(i!=0 && students[i-1] > 0) {
                students[i]++;
                students[i-1]--;
            }else if(i!=n-1 && students[i+1] > 0) { //이걸 if로 바꾸면.. 두번계산이 될수있다..
                students[i]++;
                students[i+1]--;
            }
        }
    }
    
    for(auto student : students) {
        if(student >= 0)
            answer++;
    }
    
    
    return answer;
}