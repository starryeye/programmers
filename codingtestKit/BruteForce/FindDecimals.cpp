#include <string>
#include <vector>
#include <unordered_set>
#include <cmath>
#include <algorithm>

using namespace std;

int checkPrime(int n) {
    if(n==0 || n==1)
        return 0;
    for(int i=2; i<=sqrt(n); i++) {
        if(n % i == 0)
            return 0;
    }
    return 1; // 소수이다.
}

int solution(string numbers) {
    unordered_set<int> us;
    int trial = 0;
    
    sort(numbers.begin(), numbers.end()); //next_permutation을 제대로 사용하기 위하여 정렬해주기..
    do {
        for(int i=1; i <= numbers.size(); i++) {
            trial = stoi(numbers.substr(0, i)); //이거 최적화가 되나..?
            if(checkPrime(trial))
                us.insert(trial); //소수이면 넣는다.
        }
    } while(next_permutation(numbers.begin(), numbers.end())); //자동으로 numbers의 순열을 만들어준다.
    
    return us.size();
}