#include<iostream>
#include<bits/stdc++.h>
#include<string.h>
#include<vector>
#include<algorithm>
#include<math.h>
#include<stack>
#define lli long long int
#define db double
#define str string
#define ch char
#define pb push_back
#define FOR(a,n) for(i=0;i<n;i++){	cin>>a[i];}
#define sortVector(a) sort(a.begin(),a.end())
#define reverseSortVector(a) sort(a.rbegin(),a.rend())
#define FAST ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);srand(time(NULL));
#define endl "\n"
using namespace std;

lli choose(lli n , lli m){   // (n c k)
	lli ans=0;
	lli num=1;
	lli den=1;
	for(lli i=0;i<m;i++){
		num*=(n-i);
		num=num/(i+1);
	}
	return num;
}
bool isPrime(int n)
        {

            if (n <= 1)  return false;
            if (n <= 3)  return true;

            if (n%2 == 0 || n%3 == 0)
                return false;

            for (int i=5; i*i<=n; i=i+6)
            {
                if (n%i == 0 || n%(i+2) == 0)
                   return false;
            }

            return true;
        }

lli gcd (lli a , lli b){
	if(a == 0){
		return b;
	} else {
		return gcd(b%a,a);
	}
}
int main() {
    FAST;
    lli i,j,k,n,m;
    cin>>n>>m;
    vector<bool>visited(n+1);
    priority_queue<pair<lli,lli>, vector<pair<lli,lli> >, greater<pair<lli,lli> > >pq;
    vector<vector<pair<lli,lli> > >adj(m+1);
    pair<lli,lli>p;
    lli l;
    for(i=0;i<m;i++){
        cin>>j>>k>>l;   // startNode endNode weight
        adj[j].pb({k,l});
    }
    vector<lli>distance(n+1);
    for(i=0;i<=n;i++){
        distance[i]=LONG_LONG_MAX;
    }
    distance[1]=0;
    pq.push({0,1});
    lli v,wt;
    while(!pq.empty()){
        p=pq.top();
        pq.pop();
        lli u=p.second;
        if(visited[u])
            continue;
        visited[u]=true;
        for(i=0;i<adj[u].size();i++){
            v=adj[u][i].first;
            wt=adj[u][i].second;
            if(distance[v]>distance[u]+wt){
                distance[v]=distance[u]+wt;
                pq.push({distance[v],v});
            }
        }
    }
    for(i=2;i<=n;i++){
        if(distance[i]!=LONG_LONG_MAX)
            cout << distance[i] << " ";
    }
	return 0;
}
