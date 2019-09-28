#include <cstdio>
#include <vector>
using namespace std;
typedef pair<int,int> pi;

int main(){
	int n,k,v[100]={},in,curv,idx;
	bool flag = true;
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++){
		scanf("%d",&in);
		curv = 1e9;
		for(int j=0;j<k;j++){
			if(v[j] < in && in-v[j] < curv){
				curv = in-v[j];
				idx = j;
			}
		}
		if(curv == 1e9) flag = false;
		v[idx] = in;
	}
	flag ? printf("YES") : printf("NO");
}