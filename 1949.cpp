// 백준 1949

// 조건을 살펴보면
// 2.우수 마을 끼리는 인접할 수 없다. -> root가 우수 마을로 선정되었을 경우 현재 node는 우수 마을이 될 수 없다.
// 	이 조건에서 1.우수 마을의 주민수를 최대로 하려면
// 	root가 우수마을이 아닐 때는 현재 node가 우수마을이 될 수도 있고, 안될 수도 있기 때문에
// 	우수마을이 된 경우, 안된 경우를 각각 계산하여 총합주민이 더 많은 쪽으로 선택한다.
// 3.우수마을로 선정되지 않은 마을은 적어도 하나의 우수마을과 인접해야 한다 -> 우수마을의 주민 수를 최대로 선택하면
// 	자동으로 달성되는 조건이다.

// m[node][rootGood] = 현재 node에서부터 시작하여 root가 우수마을이거나 우수마을이 아닐 때 최대 주민 수
// Tree이기 때문에 adj에서 prev로는 갈 수 없게 한다.

#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int sz = 1e4;

inline int max(int a,int b){return a > b ? a : b;};

vector<int> adj[sz+1];
int n,people[sz+1],m[sz+1][2];

int f(int cur,int prev,bool rootGood){
	int &ret = m[cur][rootGood];
	if(~ret) return ret;
	int tmp1 = 0,tmp2 = 0;
	if(!rootGood) tmp2 = people[cur];
	for(int next : adj[cur]){
		if(next == prev) continue;
		tmp1 += f(next,cur,0);
		if(!rootGood) tmp2 += f(next,cur,1);
	}
	ret = max(tmp1,tmp2);
	return ret;
}

int main(){
	memset(m,-1,sizeof(m));
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&people[i]);
	for(int i=0;i<n-1;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	printf("%d",max(f(1,-1,0),f(1,-1,1)));
}