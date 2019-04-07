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

// This is the Prim algorithm using min priority queue.
// This program prints the cost of the minimum spanning tree
// The nodes are 1-indexed.
// Traversal starts from node 1

int main() {
    //FAST;
    lli i,j,k,n,m;
    cout << "Enter the number of nodes and edges:\n";
    cin>>n>>m;
    cout << "Enter the starting node, ending node and the weight of the edge one by one:\n";
    vector<vector<pair<lli,lli> > >adj(n+1);        // for adjacency list
    lli cost;
    for(i=0;i<m;i++){
        cin>>j>>k>>cost;
        adj[j].pb({k,cost});
        adj[k].pb({j,cost});
    }
    priority_queue<pair<lli,lli> , vector<pair<lli,lli> > , greater<pair<lli,lli> > > pq;   // min-priority queue
    pq.push({0,1});
    lli c=0;
    vector<bool> visited(n+1);
    lli x,y;
    pair<lli,lli>p;
    while(!pq.empty()){
        p=pq.top();
        pq.pop();
        x=p.second;
        if(visited[x]){
            continue;
        } else {
            c+=p.first;
            visited[x]=true;
            for(i=0;i<adj[x].size();i++){
                y=adj[x][i].second;
                if(!visited[y]){
                    pq.push({adj[x][i].second,adj[x][i].first});
                }
            }
        }
    }
    cout << "The minimum cost of the minimum spanning tree is " << c << endl;
	return 0;
}
