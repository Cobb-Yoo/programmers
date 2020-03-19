#include <string>
#include <vector>
#include <algorithm>

using namespace std;
const int MAX = 1000000;

string n="";
int len;
bool arr[MAX+1][10];
int 
string number_string;

string madeInt(){
    string answer="";
    for(int i=0;i<len;i++){
        if(!arr[number_string[i]-'0']) answer += number_string[i];
    }
    
    return answer;
}

void back(int cnt,int k){
    if(k == cnt){
        string m = madeInt();
        if(n < m ) n = m;
        return;
    }
    
    for(int i=0;i<len;i++){
        if(arr[i]) continue;
        arr[i] = 1;
        back(cnt+1,k);
        arr[i] = 0;
    }
}

string solution(string number, int k) {
    number_string = number;
    len = number.length();
    
    back(0,k);
    
    return n;
}
