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
#define MAX_NUM 200001

// Q: Find the length of the longest common subsequence between two strings

// n=3 sum=5
// x = abc
// y = acrpk
// ans = 2

ll longestCommonSubsequence(string x, string y, int n, int m){
	int dp[n+1][m+1];
    // if first string is 0, or second string is 0, then the LCS for those strings will be 0.
    memset(dp,0,sizeof dp);

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(x[i-1]==y[j-1]){             // If the characters are same, then 1 + LCS(remaining strings)
                dp[i][j] = dp[i-1][j-1]+1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]); // If not same, then max(LCS(full string1, string2-1), LCS(string1-1, full string2))
            }
        }
    }
	return dp[n][m];
}


int main(){
    FAST;
    ll i,j,k,n,m,t=1;
    cin>>n>>m;
    string x,y;
    cin>>x>>y;
    cout<<longestCommonSubsequence(x,y,n,m)<<endl;
    return 0;
}