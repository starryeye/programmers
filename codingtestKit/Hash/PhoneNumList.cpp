#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

bool solution(vector<string> phone_book) {
    
    //전화 번호 갯수
    int n = phone_book.size();
    
    unordered_map<string, int> um;
    
    //폰번호 해싱
    for(int i =0; i<n; i++)
    {
        um[phone_book[i]] = 1;
    }
    
    // i : 폰번호 수 만큼 순회 
    for (int i = 0; i < phone_book.size(); i++) 
    { 
        // j : 하나의 폰번호의 string 인덱스 -1 만큼 순회 (그게 substr 개념이다)
        for (int j = 0; j < phone_book[i].size() - 1; j++) 
        { 
            //substr사용법 : substr(시작위치, 길이!)
            string phone_number = phone_book[i].substr(0, j+1); 
            
            if (um[phone_number]) 
                return false; 
        } 
    }

    return true;

    
    
    /*
    //아래 방법은 이중 for문이다. 이걸 단일 for문으로 바꾸려면... phone_book을 정렬하여 인접한 것 끼리만 비교
    //정렬을 하면 사전 순으로 정렬이 된다... ㄷㄷ
    
    //전화 번호 갯수
    int n = phone_book.size();
    
    for(int i=0; i<n; i++)
    {
        int leng = phone_book[i].size();
        
        for(int j=0; j<n; j++)
        {
            //leng보다 전화번호 길이가 짧으면 스킵, 같은 전화번호끼리 비교시 스킵
            if(leng > phone_book[j].size() || i == j)
                continue;
            
            //부분 전화번호 캐치
            if(phone_book[i] == phone_book[j].substr(0, leng))
                return false;
        }
        
    }
    */
    
    
}