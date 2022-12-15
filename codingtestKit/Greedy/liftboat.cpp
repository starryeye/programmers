#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//two pointer
int solution(vector<int> people, int limit) {
    int answer = 0;
    
    sort(people.begin(), people.end());
    
    int l = 0;
    int r = people.size() - 1;
    
    int count = 0;
    
    while(l < r) {
        if(people[l] + people[r] > limit) {
            answer++;
            r--;
            count++;
        }else {
            answer++;
            r--;
            l++;
            count += 2;
        }
    }
    
    //answer에 포함되지 않은 사람들을 더해줌
    return answer + people.size() - count;
}