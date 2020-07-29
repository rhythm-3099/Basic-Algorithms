// WOOF!!
#include <bits/stdc++.h>
#include <time.h>
using namespace std;
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
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

int lps(string s) {
	int n=s.size();
	int i,j,currLen;
	int L[n][n];

	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			L[i][j]=0;

	for(i=0;i<n;i++)
		L[i][i]=1;

	for(currLen=2;currLen<=n;currLen++){
		for(i=0;i<n-currLen+1;i++){
			j=i+currLen-1;
			if(s[i]==s[j] && currLen==2){
				L[i][j]=2;
			} else if(s[i]==s[j]){
				L[i][j] = 2+L[i+1][j-1];
			} else {
				L[i][j] = max(L[i+1][j],L[i][j-1]);
			}
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++)
			cout<<L[i][j]<<" ";
		cout<<endl;
	}
	return L[0][n-1];
}

int main()
{
    FAST;
    ll i,j,k,n,m,t;
    str s;
    cin>>s;
    cout<<lps(s)<<endl;
    return 0;
}