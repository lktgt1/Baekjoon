// 백준 17244

// 현재 가지고 있는 물건의 개수를 비트마스크로 표현하여 방문여부를 살펴보면서 BFS로 풀어낼 수 있다.

#include <cstdio>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int,int> pi;
typedef pair<pi,pi> qElement;

int main(){
	int n,m,cnt = 0,cy,cx,dist,has;
	int dy[4]={1,-1,0,0},dx[4]={0,0,1,-1};
	char map[51][51]={};
	bool chk[51][51][1<<5]={};
	scanf("%d%d",&m,&n);
	for(int i=0;i<n;i++) {
		getchar();
		for(int j=0;j<m;j++){
			scanf("%c",&map[i][j]);
			if(map[i][j] == 'X') map[i][j] = 'a'+cnt++;
			if(map[i][j] == 'S') cy = i, cx = j;
		}
	}
	queue<qElement> q;
	q.push({{cy,cx},{0,0}});
	chk[cy][cx][0] = true;
	while(!q.empty()){
		qElement pp = q.front();
		q.pop();
		cy = pp.first.first;
		cx = pp.first.second;
		dist = pp.second.first;
		has = pp.second.second;
		if(has == (1<<cnt)-1 && map[cy][cx] == 'E'){
			printf("%d",dist);
			return 0;
		}
		for(int i=0;i<4;i++){
			int ny = cy+dy[i];
			int nx = cx+dx[i];
			if(ny < 0 || nx < 0 || ny > n || nx > m) continue;
			if(map[ny][nx]!='#'){
				if(map[ny][nx] >= 'a' && map[ny][nx] <= 'e' && !(has & (1<<(map[ny][nx]-'a')))){
					chk[ny][nx][has|(1<<(map[ny][nx]-'a'))] = true;
					q.push({{ny,nx},{dist+1,has|(1<<(map[ny][nx]-'a'))}});
				}
				else if(!chk[ny][nx][has]){
					chk[ny][nx][has] = true;
					q.push({{ny,nx},{dist+1,has}});
				}
			}
		}
	}
}