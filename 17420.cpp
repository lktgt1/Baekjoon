// 백준 17420

// 예정 사용 날짜를 기준으로 오름차순 정렬한다.
// 예정 사용 날짜가 같은 기프티콘들은 그보다 먼저 사용한 기프티콘 중 가장 늦게 사용한 기프티콘을 기준으로
// 남은 기간 연장을 그리디하게 할 수 있다.

// minv = 예정 사용 날짜 이전에 사용한 기프티콘중 가장 늦게 사용된 기프티콘 날짜
// maxv = 지금까지 사용한 기프티콘중 가장 늦게 사용된 기프티콘 날짜

// 예정 사용 날짜가 달라지면 (소트했기 때문에 달라지는 경우는 예정 사용 날짜가 더 큰 경우 뿐)
// minv를 maxv로 바꿔준다.

// target = minv와 이 기프티콘의 예정 사용 날짜 (= arr[i].first)중 더 큰것을 기준으로 삼아서
// add = 연장일수 를 계산한다.

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int size = 1e5;

typedef pair<long long,long long> pll;

int main(){
	int n;
	long long ans = 0,in,minv,maxv;
	pll arr[size];
	scanf("%d",&n);
	for(int i=0;i<n;i++) {
		scanf("%lld",&in);
		arr[i].second = in;
	}
	for(int i=0;i<n;i++){
		scanf("%lld",&in);
		arr[i].first = in;
	}
	sort(arr,arr+n);
	maxv = minv = arr[0].first;
	//first - 예정 사용 날짜, second = 남은 기간
	for(int i=0;i<n;i++){
		long long target = max(minv,arr[i].first);
		if(target > arr[i].second){
			long long add = (target - arr[i].second)/30 + ((target - arr[i].second)%30 > 0);
			ans += add;
			arr[i].second += 30*add;
		}
		maxv = max(maxv,arr[i].second);
		if(arr[i+1].first > arr[i].first)
			minv = maxv;
	}
	printf("%lld",ans);
}