// WOOF!!
#include <bits/stdc++.h>
#include <time.h>
using namespace std;
#define ll long long
#define ld long double
#define pb push_back
#define ff first
#define ss second
#define str string
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define FILL(a,b) memset((a),(b),sizeof((a)))
#define precision(x,d) cout<<fixed<<setprecision(d)<<x
#define minQueue priority_queue<ll,vector<ll>,greater<ll> > 
#define maxQueue priority_queue<ll,vector<ll>,less<ll> > 
#define deb1(x) cout<<#x<<" : "<<x<<endl;
#define deb2(x,y) cout<<#x<<" : "<<x<<" "<<#y<<" : "<<y<<endl;
#define deb3(x,y,z) cout<<#x<<" : "<<x<<"   "<<#y<<" : "<<y<<"  "<<#z<<" : "<<z<<endl;
#define FAST ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define READ freopen("input.txt","r",stdin);
#define WRITE freopen("output.txt","w",stdout);
#define RANDOM srand(time(NULL));
#define MOD 1000000007
#define NAX 1000005
#define INF LONG_LONG_MAX
#define MINF LONG_LONG_MIN

// Given a string, find the length of the longest repeating subsequence 
// a: AABEBCDD
// ans: 3

// cloudera
// altassian
// 

ll longest_common_subsequence(str s1, str s2){
	ll n=s1.size();
	ll m=s2.size();
	ll dp[n+1][m+1];
	memset(dp,0,sizeof dp);
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=m;j++){
			if(s1[i-1]==s2[j-1] && i!=j){
				dp[i][j] = dp[i-1][j-1]+1;
			} else {
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}
	return dp[n][m];
}

ll longest_repeating_subsequence(str s1){
	ll n=s1.size();
	str s2=s1;
	ll lcs=longest_common_subsequence(s1,s2);
	return lcs;
}

int main(){
    FAST;
    ll i,j,k,n,m,t=1;
    str s1;
    cin>>s1;
    cout<<longest_repeating_subsequence(s1)<<endl;
    return 0;
}