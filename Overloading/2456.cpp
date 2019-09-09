// 백준 2456

// struct를 만들어 bool operator를 overloading하였다.
// 문제에서 요구하는 대로 bool operator를 만들고 sort해주면 된다.

#include <cstdio>
#include <algorithm>
using namespace std;

int cnt;

struct candidate{
	int *score;
	int sum;
	int idx;
	candidate(): sum(0),idx(++cnt) {
		score = new int[3];
	}
	bool operator <(const struct candidate &in){
		if(this->sum < in.sum) return false;
		else if(this->sum == in.sum){
			if(this->score[2] < in.score[2]) return false;
			else if(this->score[2] == in.score[2]){
				if(this->score[1] < in.score[1]) return false;
			}
		}
		return true;
	}
}candidates[3];

int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		for(int j=0;j<3;j++){
			int in;
			scanf("%d",&in);
			candidates[j].score[in-1]++;
			candidates[j].sum += in;
		}
	}
	sort(candidates,candidates+3);
	if(candidates[0].sum == candidates[1].sum && candidates[0].score[2] == candidates[1].score[2] &&
			candidates[0].score[1] == candidates[1].score[1]) 
		printf("0 %d",candidates[0].sum);
	else printf("%d %d",candidates[0].idx,candidates[0].sum);
}