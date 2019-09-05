// 백준 3985

// 가장 많이 받을것을 기대한 방청객 = 입력의 길이
// 실제 가장 많이 받은 방청객 = 배열에 체크하며 하나하나 확인해본다

#include <cstdio>

int main(){
	int l,n,maxexpval = 0,maxexp = 0,maxrealval = 0,maxreal = 0;
	bool chk[1001]={};
	scanf("%d%d",&l,&n);
	for(int i=0;i<n;i++){
		int L,R,cnt = 0;
		scanf("%d%d",&L,&R);
		if(maxexpval < R-L+1){
			maxexpval = R-L+1;
			maxexp = i+1;
		}
		for(int j=L;j<=R;j++)
			if(!chk[j]) chk[j] = true, cnt++;
		if(maxrealval < cnt){
			maxrealval = cnt;
			maxreal = i+1;
		}
	}
	printf("%d\n%d",maxexp,maxreal);
}