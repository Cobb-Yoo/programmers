#include <cstring>
#include <string>
using namespace std;

int solution(string dirs) {
	int answer = 0;
    int len = dirs.size();
    
    bool map[11][11][11][11];
    memset(map,0,sizeof(map));
    int x = 5;
    int y = 5;
    int option[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
    
    for(int i=0;i<len;i++){
        int xx = x;
        int yy = y;
        
        if(dirs[i] == 'U'){
            xx += option[0][0];
            yy += option[0][1];
        }else if(dirs[i] == 'D'){
            xx += option[1][0];
            yy += option[1][1];
        }else if(dirs[i] == 'R'){
            xx += option[2][0];
            yy += option[2][1];
        }else if(dirs[i] == 'L'){
            xx += option[3][0];
            yy += option[3][1];
        }
        
        if(0 <= xx && xx < 11 && 0 <= yy && yy < 11){
            if(!map[x][y][xx][yy]){
                map[x][y][xx][yy] = 1;
                map[xx][yy][x][y] = 1;
                answer++;
            }
        }else continue;
        
        x = xx;
        y = yy;
    }
	return answer;
}
