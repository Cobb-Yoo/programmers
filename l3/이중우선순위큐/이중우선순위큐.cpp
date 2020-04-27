#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

bool visited[1000000];
vector<int> solution(vector<string> operations) {
    vector<int> answer;
    int len = operations.size();
    
    priority_queue<pair<int,int>> ascending;
    priority_queue<pair<int,int>> descending;
    
    memset(visited,0,sizeof(visited));
    
    for(int i=0;i<len;i++){
        int num = stoi(operations[i].substr(2));
        
        if(operations[i][0] == 'I'){
            ascending.push({num, i}); //��������
            descending.push({-num, i}); //��������
            visited[i] = 1;
        }else{
            if(num == -1){ //�ּҰ� ���� == ���������� top����
                while(!descending.empty() && !visited[descending.top().second]) descending.pop();
                         
                if(!descending.empty()){
                    visited[descending.top().second] = 0;
                    descending.pop();    
                }
            }else{ //�ִ밪 ����, ���������� top����
                while(!ascending.empty() && !visited[ascending.top().second]) ascending.pop();
                  
                if(!ascending.empty()){
                    visited[ascending.top().second] = 0;
                    ascending.pop();    
                }
            }
        }
    }
    
    while(!descending.empty() && !visited[descending.top().second]) descending.pop();
    while(!ascending.empty() && !visited[ascending.top().second]) ascending.pop();
    
    if(descending.empty() && ascending.empty()) return {0,0};
    return {ascending.top().first,-descending.top().first};
}
