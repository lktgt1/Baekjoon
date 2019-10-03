// 백준 9019

// 각 테스트 케이스마다 BFS를 돌려주면 된다.
// L과 R의 연산만 조금 생각해주면 된다.


#include <iostream>
#include <string>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;
typedef pair<int,string> pis;

bool visit[10000];
int a,b,cur,D,S,L,R;
string curs;

string solve(){
	memset(visit,0,sizeof(visit));
	cin >> a >> b;
	queue<pis> q;
	q.push({a,""});
	visit[a] = true;
	while(!q.empty()){
		pis p = q.front();
		q.pop();
		cur = p.first;
		curs = p.second;
		if(cur == b) return curs;
		D = (cur*2)%10000;
		S = cur ? cur-1 : 9999;
		L = (cur*10)%10000+cur/1000;
		R = cur/10+(cur%10)*1000;
		if(D < 10000 && !visit[D]) visit[D] = true,q.push({D,curs+'D'});
		if(S >= 0 && !visit[S]) visit[S] = true,q.push({S,curs+'S'});
		if(!visit[L]) visit[L] = true,q.push({L,curs+'L'});
		if(!visit[R]) visit[R] = true,q.push({R,curs+'R'});
	}
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--) cout << solve() << "\n";
}