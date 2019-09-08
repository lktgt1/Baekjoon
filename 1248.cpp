// 백준 1248

// 입력에 들어오는 부호에 따라 답이 될 수 있는 수를 모두 시도해 본다.
// 답을 구하면 true를 리턴하여 모든 재귀함수를 끝내고 프로그램을 종료시킨다.

#include <cstdio>

int n,ans[10];
char arr[10][10];

bool f(int pos){
	if(pos < 0) {
		for(int i=0;i<n;i++) printf("%d ",ans[i]);
		return true;
	}
	if(arr[pos][pos] == '+'){
		for(int i=1;i<=10;i++){
			int sum = i;
			bool can = true;
			for(int j=pos+1;j<n;j++){
				sum += ans[j];
				if(sum > 0 && arr[pos][j] != '+'){
					can = false;
					break;
				}
				else if(sum < 0 && arr[pos][j] != '-'){
					can = false;
					break;
				}
				else if(sum == 0 && arr[pos][j] != '0'){
					can = false;
					break;
				}
			}
			if(can){
				ans[pos] = i;
				if(f(pos-1)) return true;
			}
		}
	}
	else if(arr[pos][pos] == '-'){
		for(int i=-1;i>=-10;i--){
			int sum = i;
			bool can = true;
			for(int j=pos+1;j<n;j++){
				sum += ans[j];
				if(sum > 0 && arr[pos][j] != '+'){
					can = false;
					break;
				}
				else if(sum < 0 && arr[pos][j] != '-'){
					can = false;
					break;
				}
				else if(sum == 0 && arr[pos][j] != '0'){
					can = false;
					break;
				}
			}
			if(can){
				ans[pos] = i;
				if(f(pos-1)) return true;
			}
		}
	}
	else{
		int sum = 0;
		bool can = true;
		for(int j=pos+1;j<n;j++){
			sum += ans[j];
			if(sum > 0 && arr[pos][j] != '+'){
				can = false;
				break;
			}
			else if(sum < 0 && arr[pos][j] != '-'){
				can = false;
				break;
			}
			else if(sum == 0 && arr[pos][j] != '0'){
				can = false;
				break;
			}
		}
		if(can){
			ans[pos] = 0;
			if(f(pos-1)) return true;
		}
	}
	return false;
}

int main(){
	scanf("%d",&n);
	getchar();
	for(int i=0;i<n;i++)
		for(int j=i;j<n;j++)
			scanf("%c",&arr[i][j]);
	f(n-1);
}