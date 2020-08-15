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

// Given a string, form minimum partitions in the string such that the substrings thus formed are palindromes  
// s: nitik
// ans: 2 ( n | iti | k) -> 2 partitions

bool isPal(string s, ll i, ll j){
    ll lo=i,hi=j;
    while(lo<=hi){
        if(s[lo]!=s[hi])
            return false;
        lo++,hi--;
    }
    return true;
}

int palPart(string s, ll i, ll j){
	if(i>=j || isPal(s,i,j)){
		return 0;
	}
	ll mn=INT_MAX;
	for(ll k=i;k<=j-1;k++){
        // cost of left partition + cost of right partition + cost of merging both the partitions
		ll temp = palPart(s,i,k)+palPart(s,k+1,j)+1;
		mn=min(mn,temp);
	}
	return mn;
}



int main(){
    FAST;
    ll i,j,k,n,m,t=1;
    string s;
    cin>>s;
    n = s.size();
    cout<<palPart(s,0,n-1)<<endl;
    return 0;
}