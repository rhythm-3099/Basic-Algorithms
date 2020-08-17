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
	Given the array, k, and X, find the k closest numbers to X.
*/

void top_k_frequent(vector<ll>a, ll k){
	ll i,n=a.size(),diff;
	priority_queue<pair<ll,ll>, vector<pair<ll,ll> >, greater<pair<ll,ll> > > pq;
	map<ll,ll>mp;
	for(i=0;i<n;i++)
		mp[a[i]]++;
	for(auto it=mp.begin();it!=mp.end();it++){
		if(pq.size()<k){
			pq.push({it->second, it->first});
		} else if(pq.top().second<it->second){
			pq.pop();
			pq.push({it->second, it->first});
		}
	}
	while(!pq.empty()){
		cout<<pq.top().second<<" : "<<pq.top().first<<endl;
		pq.pop();
	}
}


int main()
{
    FAST;
    ll i,j,k,n,m,t,x;
    cin>>n>>k>>x;
    vector<ll>a(n);
    for(i=0;i<n;i++){
    	cin>>a[i];
    }
   	top_k_frequent(a,k);
   	cout<<endl;
    return 0;
}