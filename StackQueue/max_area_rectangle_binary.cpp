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
Given a binary matrix, find the maximum size rectangle binary-sub-matrix with all 1’s.
Example:

Input :   0 1 1 0
          1 1 1 1
          1 1 1 1
          1 1 0 0

Output :  1 1 1 1
          1 1 1 1

*/

ll maximum_area_histogram(vector<ll>a, ll n){
	ll i,j,k,m;
	stack<ll>s;
   	vector<pair<ll,ll> >ind(n);
   	for(i=0;i<n;i++){
   		if(s.empty()){
   			ind[i].first=-1;
   		} else if(a[s.top()]<a[i]){
   			ind[i].first=s.top();
   		} else {
   			while(!s.empty() && a[s.top()]>=a[i]){
   				s.pop();
   			}
   			if(s.empty()){
   				ind[i].first=-1;
   			} else {
   				ind[i].first=s.top();
   			}
   		}
   		s.push(i);
   	}
   	
   	while(!s.empty())
   		s.pop();

   	for(i=n-1;i>=0;i--){
   		if(s.empty())
   			ind[i].second=n;
   		else if(a[i]>a[s.top()]){
   			ind[i].second=s.top();
   		} else {
   			while(!s.empty() && a[s.top()]>=a[i]){
   				s.pop();
   			}
   			if(s.empty()){
   				ind[i].second=n;
   			} else {
   				ind[i].second=s.top();
   			}
   		}
   		s.push(i);
   	}
   	
   	ll maxArea=INT_MIN;
   	
   	for(i=0;i<n;i++){
   		k = ind[i].second-ind[i].first-1;
   		maxArea = max(maxArea, k*a[i]);
   	}
   	return maxArea;
}


int main()
{
    FAST;
    ll i,j,k,n,m,t;
    cin>>n>>m;
    ll a[n][m];
    for(i=0;i<n;i++)
    	for(j=0;j<m;j++)
    		cin>>a[i][j];
   	vector<ll>r(m,0);
   	ll maxAreaBinary = INT_MIN;
   	for(i=0;i<n;i++){
   		for(j=0;j<m;j++){
   			if(a[i][j]==0)
   				r[j]=0;
   			else
   				r[j]+=a[i][j];
   		}
   		k = maximum_area_histogram(r,m);
   		maxAreaBinary = max(maxAreaBinary, k);
   	}
   	cout<<maxAreaBinary;
   	cout<<endl;
    return 0;
}