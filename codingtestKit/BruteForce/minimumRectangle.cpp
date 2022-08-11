#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int maxmax = 0;
    int minmax = 0;
    
    for(int i=0; i < sizes.size(); i++) {
        
        maxmax = max(maxmax, max(sizes[i][0], sizes[i][1]));
        minmax = max(minmax, min(sizes[i][0], sizes[i][1]));
    }
    
    return maxmax * minmax;
}