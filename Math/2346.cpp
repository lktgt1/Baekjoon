// 백준 2346

// 조세퍼스와 비슷한 문제
// 생각해야 할 것:현재 풍선에 쓰여있는 숫자가 양수면 하나를 줄여야 한다.
// 			-> 현재 풍선은 지우고 이동하기 때문
// 			나머지 연산을 이용할 때 현재 배열의 크기 x 충분히 큰 숫자를 써야 했다.
// 			-> 숫자가 -일 때 arr.size()만 더해주면 그 결과가 여전히 음수일 수 있음

#include <cstdio>
#include <vector>
using namespace std;
typedef pair<int,int> pii;

int main(){
	int n;
	vector<pii> arr;
	scanf("%d",&n);
	for(int i=0;i<n;i++) {
		int in;
		scanf("%d",&in);
		arr.push_back({in,i+1});
	}
	int pt = 0,next;
	while(1){
		printf("%d ",arr[pt].second);
		next = arr[pt].first;
		if(next>0) next--;
		arr.erase(arr.begin()+pt);
		if(arr.empty()) break;
		pt += next+arr.size()*n;
		pt %= arr.size();
	}
}