// 백준 3015

// 자기보다 키가 큰 사람이 옆에 있다면 그 너머는 절대로 서로 볼 수 없다.
// 키가 큰 사람이 나올 때까지 스택에 push하고 키가 큰 사람이 나오면
// 그보다 작은 stack에 있는 원소들에 대하여 서로 볼 수 있는 쌍을 세주면 된다.
// 일단 키가 큰 사람은 볼 수 있으므로 +1, 키가 같은 쌍들은 서로 볼 수 있으므로 cnt*(cnt-1)/2가 된다.


#include <cstdio>
#include <stack>

using namespace std;

int main(){
	int n,arr[500000];
	long long ans = 0;
	stack<int> s;
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&arr[i]);
	for(int i=n-1;i>=0;i--){
		while(!s.empty() && arr[i] > s.top()){
			long long cnt = 1;
			int pivot = s.top();
			s.pop();
			while(!s.empty() && s.top() == pivot) cnt++,s.pop();
			ans += cnt + cnt*(cnt-1)/2;
			if(!s.empty()) ans += cnt;
		}
		s.push(arr[i]);
	}
	while(!s.empty()){
		long long cnt = 1;
		int pivot = s.top();
		s.pop();
		while(!s.empty() && s.top() == pivot) cnt++,s.pop();
		ans += cnt*(cnt-1)/2;
		if(!s.empty()) ans += cnt;
	}
	printf("%lld",ans);
}