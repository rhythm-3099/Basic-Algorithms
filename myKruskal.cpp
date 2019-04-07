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

// This is the kruskal algorithm using DSU for cycle detection.
// This program prints the cost of the minimum spanning tree and shows the minimum spanning tree by the adjacency list.
// The nodes are 1-indexed.
// DSU uses path compression for optimization
// Note: vectors "arr" and "size" should be declared globally

vector<lli>arr(1000007);
vector<lli>size(100007);

lli root(lli a){
    while(a!=arr[a]){
        arr[a]=arr[arr[a]];
        a=arr[a];
    }
    return a;
}


bool find(lli a, lli b){
    if(root(a)==root(b)){
        return true;
    } else {
        return false;
    }
}

void weightedUnion(lli a, lli b){
    lli rootOfA=root(a);
    lli rootOfB=root(b);
    if(size[rootOfA]>size[rootOfB]){
        arr[rootOfB]=arr[rootOfA];
        size[rootOfA]+=size[rootOfB];
    } else {
        arr[rootOfA]=arr[rootOfB];
        size[rootOfB]+=size[rootOfA];
    }
}

int main() {
    //FAST;
    lli i,j,k,n,m;
    cout << "Enter the number of nodes and edges:\n";
    cin>>n>>m;
    for(i=0;i<=n;i++){
        arr[i]=i,size[i]=1;
    }
    cout << "Enter the starting node, ending node and the weight of the edge one by one:\n";
    vector<pair<lli,pair<lli,lli> > >pq(m+1);
    lli cost;
    for(i=0;i<m;i++){
        cin>>j>>k>>cost;
        pq[i].first=cost;
        pq[i].second.first=j;
        pq[i].second.second=k;
    }
    sortVector(pq);
    i=0;
    lli c=0;
    lli ff,ss,cc;
    vector<vector<lli> > adj(n+1);
    while(i<m){
        cc=pq[i].first;
        ff=pq[i].second.first;
        ss=pq[i].second.second;
        if(find(ff,ss)){
            ;
        } else {
            c+=cc;
            adj[ff].pb(ss);
            adj[ss].pb(ff);
            weightedUnion(ff,ss);
        }
        i++;
    }
    cout << "The total cost of the spanning tree is: " << c << endl;
    cout << "The construction of the tree is:\n";
    for(i=0;i<=n;i++){
        cout << i << " ";
        for(j=0;j<adj[i].size();j++){
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
	return 0;
}
