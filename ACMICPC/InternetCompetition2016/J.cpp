// ACMICPC InternetCompetition 2016

// pair를 right우선 오름차순,left 오름차순으로 정렬하고 각 선분에 맞춰서 얼마나 많은 선분이 포함되는지 확인하면 된다.
// pq를 써서 naive하게 확인하지 않도록 한다.

#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>

using namespace std;
typedef pair<int,int> pi;

int main(){
	priority_queue<int,vector<int>,greater<int>> pq;
	int n,ans = 0,d;
	scanf("%d",&n);
	pi arr[100000];
	for(int i=0;i<n;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		if(a > b) swap(a,b);
		arr[i] ={a,b};
	}
	scanf("%d",&d);
	sort(arr,arr+n,[](pi &a,pi &b){
		if(a.second != b.second) return a.second < b.second;
		return a.first < b.first;
	});
	for(int i=0;i<n;i++){
		if(arr[i].second - arr[i].first > d) continue;
		while(!pq.empty() && pq.top() < arr[i].second - d) pq.pop();
		pq.push(arr[i].first);
		ans = max(ans,(int)pq.size());
	}
	printf("%d",ans);
}