#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
 
    int numSize = number.size() - k;
    int start = 0;
    
    //한개씩 answer에 적재
    for(int i=0; i<numSize; i++) {
        
        char maxNum = number[start];
        int maxIdx = start;
        
        //큰수 찾기
        //start : maxIdx+1, k+i : 여기까지 못찾으면..size가 더 짧아져버림..
        for(int j=start; j<=k+i; j++) {
            
            if(maxNum < number[j]) {
                maxNum = number[j];
                maxIdx = j;
            }
        }
        start = maxIdx + 1;
        answer += maxNum;
    }
    
    return answer;
}