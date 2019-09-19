// 백준 1062

// 앞 뒤 8개를 제외하면 한 스트링의 최대 문자 수는 15-8 = 7,
// a,i,n,c,t를 제외한 모든 알파벳의 수는 26-5 = 21 ->
// 7*50*21C10번 반복하여 모든경우를 계산해 볼 수 있다.

#include <iostream>
#include <string>

inline int max(int a,int b){return a > b ? a:b;};
using namespace std;


int n,k,ans,sz[50];
bool switche[26];
string s[50];

void f(int cur,int ks){
	if(cur > 26 || ks <= 0){
		int tmp = 0;
		for(int i=0;i<n;i++){
			bool flag = true;
			for(int j=4;j<sz[i]-4;j++){
				if(!switche[s[i][j]-'a']) {
					flag = false;
					break;
				}
			}
			if(flag) tmp++;
		}
		ans = max(ans,tmp);
		return;
	}
    if(!switche[cur]){
        switche[cur] = true;
        f(cur+1,ks-1);
        switche[cur] = false;
    }
    f(cur+1,ks);
}

int main(){
	switche[0] = switche['n'-'a'] = switche['i'-'a'] = switche['t'-'a'] = switche['c'-'a'] = true;
	cin >> n >> k;
	k -= 5;
	if(k<0){
		cout << 0;
		return 0;
	}
	for(int i=0;i<n;i++) cin >> s[i],sz[i] = s[i].size();
	f(1,k);
	cout << ans;
}