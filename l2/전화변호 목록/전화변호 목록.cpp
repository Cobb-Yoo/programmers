#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(string a, string b){
    return a.size() < b.size();
}

bool solution(vector<string> phone_book) {
    bool answer = true;
    int len = phone_book.size();
    
    sort(phone_book.begin(),phone_book.end(),cmp);
    
    for(int i=0;i<len-1;i++){
        for(int j=i+1;j<len;j++){
            string cut_string = phone_book[j].substr(0,phone_book[i].size());
            if(phone_book[i] == cut_string) return false;
        }
    }
    return answer;
}
