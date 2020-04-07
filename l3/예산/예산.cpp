#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> budgets, int M) {
    int answer = 0;
    sort(budgets.begin(),budgets.end());
    int len = budgets.size();
    
    int max = budgets[len-1];
    int min = 0;
    int mid;
    int tmp = 0;
    
    while(min <= max){
        mid = (max + min)/2;
        
        int result = 0;
        for(int i=0;i<len;i++){
            if(mid > budgets[i]) result += budgets[i];
            else result += mid;
        }
        
        if(result > M) max = mid - 1;
        else{
            if(result >= tmp) answer = mid;
            min = mid + 1;
        }
    }
    return answer;
}
