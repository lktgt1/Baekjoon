// 백준 2532

// 동물 a가 b의 먹이사슬 상위에 있으려면 a의 활동영역이 b의 활동영역을 완전히 포함하면 된다.
// 어떤 동물 x의 활동 영역을 pair<int,int> 로 저장하여 first에는 L, second에는 R을 저장하면
// a.first <= b.first && a.second >= b.second를 만족하면 된다.

// pair 배열의 first를 오름차순으로 정렬하면 첫번째 조건은 항상 만족한다.
// 여기서 pair 배열의 second를 내림차순으로 정렬하면 pair 배열의 first는 조건을 항상 만족하기 때문에
// pair 배열의 second 를 기준으로 Longest Decreasing Subsequence를 구하는 문제로 바뀐다.

// 문제의 조건을 보면 a.first == b.first && a.second == b.second인 경우에는 먹이사슬에 포함되지 않으므로
// first와 second값이 중복되는 원소들은 모두 지워준다.

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int,int> pii;

int main(){
	int n,l,r,idx = 1,LIS[500000],sz = 0;
	pii arr[500000];
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%*d%d%d",&l,&r);
		arr[i] = {l,r};
	}
	sort(arr,arr+n,[&](pii a, pii b){
		if(a.first != b.first) return a.first < b.first;
		return a.second > b.second;
	});
	for(int i=1;i<n;i++){
		if (arr[i-1].first != arr[i].first || arr[i-1].second != arr[i].second) arr[idx++] = arr[i];
	}
	n = idx;
	LIS[sz++] = arr[0].second;
	for(int i=1;i<n;i++){
		if(arr[i].second <= LIS[sz-1]) LIS[sz++] = arr[i].second;
		else{
			idx = lower_bound(LIS,LIS+sz,arr[i].second,[](int it,int val){
				return it >= val;
			})-LIS;
			LIS[idx] = arr[i].second;
		}
	}
	printf("%d",sz);
}