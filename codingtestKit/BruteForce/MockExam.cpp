#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> ret;
    
    int a[5] = {1, 2, 3, 4, 5};
    int b[8] = {2, 1, 2, 3, 2, 4, 2, 5};
    int c[10] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    
    vector<int> count(4, 0); // 0 index는 사용 하지 않는다.
    
    for(int i=0; i<answers.size(); i++) {
        if(a[i%5] == answers[i])
            count[1]++;
        if(b[i%8] == answers[i])
            count[2]++;
        if(c[i%10] == answers[i])
            count[3]++;
    }
    
    // 가장 높은 카운트를 찾는다.
    int maxcount = max(count[1], max(count[2], count[3]));
    
    // 가장 높은 카운트와 값이 동일한 index를 오름차순으로 넣는다.
    for(int i=1; i<4; i++) {
        if(maxcount == count[i])
            ret.push_back(i);
    }
    
    
    return ret;
}