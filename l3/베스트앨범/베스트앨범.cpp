#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cstring>
#include <iostream>
using namespace std;
 
vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, int> mp;
    map<string, int>::iterator it;
    map<int, string>::iterator rit;
    map<int, string> rev;
    pair<int, int> arr[10001];
    
    for(int i=0; i<genres.size(); i++){
        it = mp.find(genres[i]);
        
        if(it != mp.end()){ //map�� ������ ���� �߰�����.
            int pre = it->second;
            mp[genres[i]] = pre+plays[i];
        }else{// map�� ������ �߰� 
            mp.insert({genres[i], plays[i]}); //map�� key���� ������������ �ڵ����� �������� (�켱����) 
        }
    }

    for(it = mp.begin(); it != mp.end(); it++){//���� mp�� value�� ������ ����� key, value�� ���� �ٲ�. 
        rev.insert({-(it->second), it->first});
    }
    
    for(rit = rev.begin(); rit != rev.end(); rit++){
        string gen = rit->second;// tmp�� 
    
        memset(arr, 0, sizeof(arr));
        
        int idx = 0;
        for(int i=0; i<genres.size(); i++){
            if(gen.compare(genres[i]) == 0){
                arr[idx++] = {-plays[i], i}; // sort�� ���������̱� ������ first�� ������ ��.�ǽ�Ʈ(����������). 
            }
        }
        
        sort(arr, arr+idx);
        
        if(idx==1){
            answer.push_back(arr[0].second);             
        }else{
            answer.push_back(arr[0].second);
            answer.push_back(arr[1].second);     
        }
        
    }
    
    return answer;
}
