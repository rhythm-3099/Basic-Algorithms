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

/*
	Given the array of prices of stocks, we have to perform at max K transactions 
	and find the maximum profit possible.
*/

ll k_stocks(vector<ll>price, ll transactions){
	ll days = price.size();
	ll i,j,k,n,m;
	ll dp[transactions+1][days+1];
	memset(dp, 0, sizeof dp);
	for(i=1;i<=transactions;i++){
		ll prevDiff = INT_MIN;
		for(j=1;j<days;j++){
			prevDiff = max(prevDiff, dp[i-1][j-1] - price[j-1]);
			dp[i][j] = max(dp[i][j-1], price[j] + prevDiff);
		}
	}
	return dp[transactions][days-1];
}


int main()
{
    FAST;
    ll i,j,k,n,m,t;
    ll transactions, days;
    cin>>transactions>>days;
    vector<ll>price(days);
    for(i=0;i<days;i++)
    	cin>>price[i];
    cout<<k_stocks(price, transactions)<<endl;
   	cout<<endl;
    return 0;
}