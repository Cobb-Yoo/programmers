#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int len = progresses.size();
    vector<int> arr(len);
    
    for(int i=0;i<len;i++){
        arr[i] = ceil((100 - progresses[i])/(float)speeds[i]);
    }
    
    int M = arr[0];
    int cnt =1;
    
    for(int i=1;i<len;i++){
        if(M >= arr[i]){
            cnt++;
        }else{
            answer.push_back(cnt);
            cnt = 1;
            M = arr[i];
        }
    }
    answer.push_back(cnt);
    return answer;
}
