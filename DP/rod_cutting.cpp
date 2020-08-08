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

/*
Input : W = 100
       val[]  = {1, 30}
       wt[] = {1, 50}
Output : 100
*/

ll unboundedKnapsack(vector<ll>length, vector<ll>price, ll total){
	ll n=length.size();
    ll dp[n+1][total+1];
    memset(dp, 0, sizeof dp);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=total;j++){
            if(length[i-1]<=j){
                dp[i][j] = max(dp[i-1][j], price[i-1] + dp[i][j-length[i-1]]);  // we have two options: i) Include the current rod segment and 
                                                                                //check for the length-current rod segment, or ignore the current rod segment
            } else {
                dp[i][j]=dp[i-1][j];        // If the current rod segment is greater than the current capacity, then simply ignore the current rod.
            }
        }
    }

	return dp[n][total];
}


int main(){
    FAST;
    ll i,j,k,n,m,t=1;
    cin>>n;
    vector<ll>length(n),price(n);
    for(i=0;i<n;i++){
    	cin>>length[i];
    }
    for(i=0;i<n;i++){
        cin>>price[i];
    }
    ll total;
    cin>>total;
    cout<<unboundedKnapsack(val, weight, total)<<endl;
    return 0;
}