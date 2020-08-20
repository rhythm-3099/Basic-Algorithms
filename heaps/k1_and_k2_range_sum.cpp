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
	Given the array and k1 and k2, find the sum between the two numbers. 
	k1 means the smallest k1th number and k2 means the smallest k2th number.
*/

ll kth_smallest(vector<ll>a, ll k){
	ll i,n=a.size();
	ll ans=0;
	priority_queue<ll> pq;
	for(i=0;i<n;i++){
		if(pq.size()<k)
			pq.push(a[i]);
		else if(pq.top()>a[i]){
			pq.pop();
			pq.push(a[i]);
		}
	}

	return pq.top();
}


int main()
{
    FAST;
    ll i,j,k,n,m,t,x;
    cin>>n>>k>>m;
    vector<ll>a(n);
    for(i=0;i<n;i++){
    	cin>>a[i];;
    }
   	ll ans=0;
   	ll k1,k2;
   	k1=kth_smallest(a,k);
   	k2=kth_smallest(a,m);
   	if(k1>k2){
   		j=k1;
   		k1=k2;
   		k2=j;
   	}
   	for(i=0;i<n;i++){
   		if(a[i]>k1 && a[i]<k2){
   			ans+=a[i];
   		}
   	}
   	cout<<ans;
   	cout<<endl;
    return 0;
}