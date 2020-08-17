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
#define ppi pair<float, pair<ll,ll> >

/*
	Given the array, k, and X, find the k closest numbers to X.
*/

void k_closest_to_origin(vector<pair<ll,ll> >a, ll k){
	ll i,n=a.size(),diff;
	priority_queue<ppi> pq;
	for(i=0;i<n;i++){
		float d = a[i].first*a[i].first + a[i].second*a[i].second;
		d = sqrt(d);=
		ll x = a[i].first, y = a[i].second;
		if(pq.size()<k)
			pq.push({d, {x,y}});
		else if(pq.top().first>d){
			pq.pop();
			pq.push({d, {x,y}});
		}
	}
	while(!pq.empty()){
		cout<<pq.top().second.first<< " " <<pq.top().second.second<<" : "<<pq.top().first<<endl;
		pq.pop();
	}
}


int main()
{
    FAST;
    ll i,j,k,n,m,t,x;
    cin>>n>>k;
    vector<pair<ll,ll> >a(n);
    for(i=0;i<n;i++){
    	cin>>a[i].first>>a[i].second;
    }
   	k_closest_to_origin(a,k);
   	cout<<endl;
    return 0;
}