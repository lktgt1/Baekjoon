// 백준 2565

// 교차하지 않는 전깃줄 쌍의 최대 갯수는 왼쪽 전깃줄 번호로 정렬한 가장 긴 증가하는 부분수열의 갯수와 같다.
// Binary Search로 LIS를 구해주고 전체 전깃줄의 갯수에서 LIS의 크기만큼 빼주면 된다.

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int,int> pi;

int main(){
	vector<int> lis;
	int n,a,b;
	pi arr[100];
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d%d",&a,&b);
		arr[i] = {a,b};
	}
	sort(arr,arr+n);
	lis.push_back(arr[0].second);
	for(int i=1;i<n;i++){
		if(lis.back() < arr[i].second) lis.push_back(arr[i].second);
		else{
			int l,r,mid;
			l = -1, r = lis.size();
			while(l+1<r){
				mid = (l+r)/2;
				if(lis[mid] < arr[i].second) l = mid;
				else r = mid;
			}
			lis[r] = arr[i].second;
		}
	}
	printf("%d",n-lis.size());
}