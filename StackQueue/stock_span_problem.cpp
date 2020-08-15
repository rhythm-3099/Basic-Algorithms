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
The stock span problem is a financial problem where we have a series of n daily price quotes
for a stock and we need to calculate span of stock’s price for all n days.
The span Si of the stock’s price on a given day i is defined as 
the maximum number of consecutive days just before the given day,
for which the price of the stock on the current day is less than or equal 
to its price on the given day.

For example, if an array of 7 days prices is given as 
{100, 80, 60, 70, 60, 75, 85}, 
then the span values for corresponding 7 days are 
{1, 1, 1, 2, 1, 4, 6}

*/
int main()
{
    FAST;
    ll i,j,k,n,m,t;
    cin>>n;
    vector<ll>a(n);
    for(i=0;i<n;i++)
    	cin>>a[i];
   	stack<ll>s;
   	vector<ll>ans;
   	for(i=0;i<n;i++){
   		if(s.empty()){
   			ans.push_back(1);
   		} else if(a[s.top()]>a[i]){
   			ans.push_back(i-s.top());
   		} else {
   			while(!s.empty() && a[s.top()]<=a[i]){
   				s.pop();
   			}
   			if(s.empty()){
   				ans.push_back(1);
   			} else {
   				ans.push_back(i-s.top());
   			}
   		}
   		s.push(i);
   	}
   	for(i=0;i<n;i++)
   		cout<<ans[i]<<" ";
   	cout<<endl;
    return 0;
}