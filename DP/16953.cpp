#include <cstdio>
#include <string>
#include <map>

using namespace std;

inline int min(int a, int b){return a > b ? b : a;};
const int MAXN = 1e9;
int A,B;
map<long long,int> m;

int f(long long cur){
	if(m.count(cur)) return m[cur];
	int &ret = m[cur];
	if(cur > B) return ret = MAXN;
	ret = min(1e9,min(f(cur*2)+1,f(cur*10+1)+1));
	return ret;
}

int main(){
	scanf("%d%d",&A,&B);
	m[B] = 1;
	printf("%d",f(A) == 1e9 ? -1 : m[A]);
}