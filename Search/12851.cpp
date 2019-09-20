백준 12851

BFS로 탐색한다.
같은 시간에 들어오는 방법을 카운트하기 위해
어떤 지점까지 걸린 시간을 int로 저장하여 같은 시간에 들어오는 방법들도 큐에 담아준다.

#include <cstdio>
#include <queue>

using namespace std;
typedef pair<int,int> pi;

int chk[100001];

int main(){
	for(int i=0;i<=100000;i++) chk[i] = 999999;
	int n,k,anssec=-1,anscnt=1;
	scanf("%d%d",&n,&k);
	queue<pi> q;
	q.push({n,0});
	chk[n] = true;
	while(!q.empty()){
		pi cur = q.front();
		q.pop();
		int curPoint = cur.first;
		int curSec = cur.second;
		if(curPoint == k){
			if(anssec == -1) anssec = curSec;
			else if(anssec != curSec) break;
			else anscnt++;
		}
		if(curPoint+1 <= 100000 && curSec+1 <= chk[curPoint+1]) q.push({curPoint+1,curSec+1}),chk[curPoint+1] = curSec+1;
		if(curPoint*2 <= 100000 && curSec+1 <= chk[curPoint*2]) q.push({curPoint*2,curSec+1}),chk[curPoint*2] = curSec+1;
		if(0 <= curPoint-1 && curSec+1 <= chk[curPoint-1]) q.push({curPoint-1,curSec+1}),chk[curPoint-1] = curSec+1;
	}
	printf("%d\n%d",anssec,anscnt);
}