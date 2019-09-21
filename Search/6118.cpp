// 백준 6118

// 간선의 가중치가 모두 1로 동일하기 때문에
// 1번 정점부터 시작하여 BFS를 돌리면 된다.

#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

inline int min(int a,int b){return a > b ? b : a;};
typedef pair<int,int> pi;

vector<int> adj[20001];
bool chk[20001];
int n,m,a,b,ansdist,anscnt,ansnum;

int main(){
	ansnum = anscnt = 1;
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%d%d",&a,&b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	queue<pi> q;
	q.push({1,0});
	chk[1]= true;
	while(!q.empty()){
		pi p = q.front();
		q.pop();
		int cur = p.first;
		int dist = p.second;
		if(ansdist <= dist){
			if(ansdist == dist) anscnt++;
			else ansnum = cur,ansdist = dist, anscnt = 1;
			ansnum = min(ansnum,cur);
		}
		for(int next : adj[cur]){
			if(!chk[next]) chk[next] = true,q.push({next,dist+1});
		}
	}
	printf("%d %d %d",ansnum,ansdist,anscnt);
}