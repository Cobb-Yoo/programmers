#include <vector>
#include <cstring>
#include <iostream>
using namespace std;

int option[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
bool visited[101][101];
int M,N;

int check(int a,int b,vector<vector<int>> picture){
    int cnt=0;
    if(0 <= a && a <M-1 && 0 <= b && b < N-1) {
        for(int i=0;i<4;i++){
            if(visited[a+option[i][0]][b+option[i][1]]) continue;
            if(picture[a][b] == picture[a+option[i][0]][b+option[i][1]]){
                visited[a+option[i][0]][b+option[i][1]] = 1;
                cnt += check(a+option[i][0],b+option[i][1],picture);
            }
        }    
    }
    return cnt;
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    M = m;
    N = n;
    
    memset(visited,0,sizeof(visited));
    
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(visited[i][j]) cout << 1;
            else cout << 0;
        }
        cout << endl;
    }
    cout << "=================" << endl;
    
    
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(visited[i][j]) continue;
            if(!picture[i][j]) continue;
            
            int tmp = check(i,j,picture);
            
            if(tmp > max_size_of_one_area) {
                number_of_area++;
                max_size_of_one_area = tmp;
            }
        }
    }
    
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(visited[i][j]) cout << 1;
            else cout << 0;
        }
        cout << endl;
    }
    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}
