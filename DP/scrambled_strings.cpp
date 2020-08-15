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

// Given two strings, find if string b is scrambled string of string a  
// a: great , b: grate
// ans: true

bool solve(string a, string b){
    if(a==b)
        return true;
    if(a.length()<=1)
        return false;
    
    ll n=a.length();
    bool flag=false;

    for(ll i=1;i<n;i++){
        bool cond1;
        bool cond2;

        cond1 = (solve(a.substr(0,i), b.substr(n-i,i)) && solve(a.substr(i,n-i),b.substr(0,n-i)));
        cond2 = (solve(a.substr(0,i), b.substr(0,i)) && solve(a.substr(i,n-i), b.substr(i,n-i)));

        if(cond1 || cond2){
            flag = false;
            break;
        }   
    }
    return flag;
}


int main(){
    FAST;
    ll i,j,k,n,m,t=1;
    string a,b;
    cin>>a>>b;
    n = a.size();
    cout<<solve(a,b)<<endl;
    return 0;
}