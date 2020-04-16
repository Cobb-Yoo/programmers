#include <string>
#include <vector>
using namespace std;

string solution(int n, int t, int m, int p) {
	vector <char> temp;
	string answer = "";
	int cnt = 0; 
	int turn = 1; 
	temp.push_back('0');
	if (m == p)
		p = 0;
	while (turn <= t * m) {
		int N = cnt;
		while (N > 0) {
			if (N % n >= 10)
				temp.push_back((char)(N % n + 55));
			else 
				temp.push_back((char)(N % n + 48));
			N /= n;
		}
		int s = temp.size();
		for (int i = 0; i < s; i++, turn++) {
			if ((turn % m == p) && (answer.length() < t))
				answer += temp.back();
			temp.pop_back();
		}
		cnt++;
	}
	return answer;
}
