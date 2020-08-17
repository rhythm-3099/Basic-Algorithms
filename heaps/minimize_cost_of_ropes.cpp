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
	Given the array, find the minimum cost to connect all the ropes to form a single rope.
*/

ll cost_of_ropes(vector<ll>a){
	ll i,n=a.size();
	ll ans=0;
	priority_queue<ll, vector<ll> , greater<ll> > pq;
	for(i=0;i<n;i++){
		pq.push(a[i]);
	}

	while(pq.size()!=1){
		ll x = pq.top();
		pq.pop();
		ll y = pq.top();
		pq.pop();
		ans+=x+y;
		pq.push(x+y);
	}
	return ans;
}


int main()
{
    FAST;
    ll i,j,k,n,m,t,x;
    cin>>n;
    vector<ll>a(n);
    for(i=0;i<n;i++){
    	cin>>a[i];;
    }
   	cout<<cost_of_ropes(a);
   	cout<<endl;
    return 0;
}