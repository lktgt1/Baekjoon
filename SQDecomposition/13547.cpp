// 백준 13547

// 구간의 정보-> Segment Tree? 힘들다(구간 정보 갱신을 어떻게하지?)
// 평방분할을 이용한 모스알고리즘을 이용한다.
// Query = {s,e} 배열을 s/sqrt(N),e로 정렬하면 쿼리마다 옮겨다니는 비용을 최소화 시킬 수 있다.
// count배열에 각 원소가 0이 되거나 0보다 커질 때 서로다른 수의 갯수를 카운트하는 variable을 더하고 빼면서
// 쿼리를 돌아다니면서 해결할 수 있다.

#include <algorithm>
#include <cstdio>
#include <cmath>

using namespace std;

int sqrtN;

struct queryNode{
	int s,e,idx;
	bool operator <(const queryNode &q)const{
		if(s/sqrtN != q.s/sqrtN) return s/sqrtN < q.s/sqrtN;
		return e < q.e;
	}
};

int main(){
	int N,M,arr[100001],cnt[1000001]={},ans = 0,ansv[100000]={};
	queryNode q[100000];
	scanf("%d",&N);
	sqrtN = sqrt(N);
	for(int i=1;i<=N;i++) scanf("%d",&arr[i]);
	scanf("%d",&M);
	for(int i=0;i<M;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		q[i] = {a,b,i};
	}
	sort(q,q+M);
	int l = q[0].s,r = q[0].e;
	for(int i=l;i<=r;i++)
		if(cnt[arr[i]]++ == 0) ans++;
	ansv[q[0].idx] = ans;
	for(int i=1;i<M;i++){
		while(q[i].s < l) if(cnt[arr[--l]]++ == 0) ans++;
		while(r < q[i].e) if(cnt[arr[++r]]++ == 0) ans++;
		while(l < q[i].s) if(--cnt[arr[l++]] == 0) ans--;
		while(q[i].e < r) if(--cnt[arr[r--]] == 0) ans--;
		ansv[q[i].idx] = ans;
	}
	for(int i=0;i<M;i++) printf("%d\n",ansv[i]);
}