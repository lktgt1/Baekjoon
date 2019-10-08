// 백준 1068

// 단순히 트리를 구현하고 삭제되는 노드로 가지 않으면서 리프 노드의 개수만 리턴해주는 함수를 짜면 되지만,
// 루트가 지워지는 코너 케이스를 주의한다.

#include <cstdio>
#include <vector>

using namespace std;

vector<int> children[50];
int p[50],n,root;

int getN(int k){
	if(children[k].empty()) return 1;
	int ret = 0;
	for(int x : children[k]){
		if(x==n){
			if(children[k].size()==1) return 1;
		}
		else ret += getN(x);
	}
	return ret;
}

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int par;
		scanf("%d",&par);
		p[i] = par;
		if(par == -1) root = i;
		else children[par].push_back(i);
	}
	scanf("%d",&n);
	printf("%d",root == n ? 0 : getN(root));
}