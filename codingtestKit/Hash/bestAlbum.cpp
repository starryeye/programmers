#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    unordered_map<string, int> check; // 장르별 재생된 횟수 총합
    unordered_map<string, unordered_map<int, int>> countArray; // 장르별 재생된 횟수 배열, 그 인덱스, 정렬 필요
    //순서대로 장르, 인덱스, count
    
    for(int i=0; i<genres.size(); i++) {
        
        //장르별 총합 구하기
        check[genres[i]] += plays[i];
        
        //장르별로 재생된 횟수배열을 index와 함께
        countArray[genres[i]][i] = plays[i];
    }
    
    while(check.size()) {
        string tmp;
        int maxcount = 0;
        
        // 재생된 횟수가 가장높은 장르 찾기
        for(auto &kv : check) {
            if(maxcount < kv.second) {
                maxcount = kv.second;
                tmp = kv.first;
            }
        }
        
        //2개 선택
        for(int i = 0; i<2; i++) {
            int maxcount_music = 0;
            int indexTmp;
                
            for(auto &kv : countArray[tmp]) {
                if(maxcount_music < kv.second) {  
                    maxcount_music = kv.second;
                    indexTmp = kv.first;
                }else if(maxcount_music == kv.second) { 
                    // 가장높은 장르의 노래중 조회가 같으면 index낮은놈으로 고름
                    if(indexTmp > kv.first)
                        indexTmp = kv.first;
                }
            }
            countArray[tmp].erase(indexTmp); // 가장높은 장르의 가장높은 조회 노래 삭제
                
            answer.push_back(indexTmp); // 가장높은 장르의 가장높은 조회 노래 index넣기
                
            if(countArray[tmp].size() == 0) // 지웠는데 0개 남으면 그대로 break, 원래 배열이 1개인 경우 예외처리 됨.
                break;
                
        }    
        
        // 재생된 횟수가 가장높은 장르 삭제
        check.erase(tmp);
        
    }
    
    return answer;
}