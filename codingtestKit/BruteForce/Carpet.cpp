#include <string>
#include <vector>
#include <math.h>

using namespace std;


vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    //예외 처리
    if(yellow == 1) {
        answer.push_back(3);
        answer.push_back(3);
    } else if(yellow == 2) {
        answer.push_back(4);
        answer.push_back(3);
    }
    
    for(int i=2; i <= sqrt(yellow); i++) {
        if(yellow % i == 0) { //나누어진다.
            
            // 4: 양꼭짓점, i: 세로길이, yellow / i : 가로길이
            int comp = 4 + i * 2 + yellow / i * 2;
            
            if(comp == brown) {
                answer.push_back(yellow/i + 2);
                answer.push_back(i + 2);
            } 
        }
    }
    
    return answer;
}