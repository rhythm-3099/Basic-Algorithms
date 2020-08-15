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

// Given an array of dimensions, find the minimum number of multiplications needed to perform matrix multiplications  
// a: 40, 20, 30, 10, 30
// ans: 3

int mcm(vector<ll>a, ll i, ll j){
	if(i>=j)
		return 0;
	ll mn=INT_MAX;
	for(ll k=i;k<=j-1;k++){
        // cost of left partition + cost of right partition + cost of merging both the partitions
		ll temp = mcm(a,i,k)+mcm(a,k+1,j)+a[i-1]*a[k]*a[j];
		mn=min(mn,temp);
	}
	return mn;
}



int main(){
    FAST;
    ll i,j,k,n,m,t=1;
    cin>>n;
    vector<ll>a(n);
    for(i=0;i<n;i++)
    	cin>>a[i];
    cout<<mcm(a,1,n-1)<<endl;
    return 0;
}