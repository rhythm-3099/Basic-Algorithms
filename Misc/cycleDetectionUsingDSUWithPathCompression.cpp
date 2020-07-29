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

// This is the DSU algorithm with balanced union function. It maintains the "size" array and establishes the root element comparing the size of the sets.
// This program prints "YES" if the undirected graph contains a cycle, prints "NO" otherwise.
// Note: this program uses path compression
// Note: vectors "arr" and "size" should be declared globally

vector<lli>arr(1000007);
vector<lli>size(1000007);

lli modifiedRoot(lli a){        // modified root with path compression
    while(arr[a]!=a){
        arr[a]=arr[arr[a]];
        a=arr[a];
    }
    return a;
}

bool find(lli a, lli b){
    //cout << "a " << a << " root a " << root(arr,a) << " b " << b << " root b " << root(arr,b) << endl;
    if(modifiedRoot(a)==modifiedRoot(b)){   //if A and B have same root, that means that they are connected
        return true;
    } else {                // they aren't connected
        return false;
    }
}

void weightedUnion(lli a, lli b){  // this merges the subsets containing a and b
    lli rootOfA=modifiedRoot(a);
    lli rootOfB=modifiedRoot(b);
    //cout << "a " << a << " roota " << root(a)<< " arr[roota] " << arr[rootOfA] << " b " << b << " rootb " << root(b) << " arr[rootB] " << arr[rootOfB] << endl;
    if(size[rootOfA]<size[rootOfB]){    // make B as a parent
        arr[rootOfA]=arr[rootOfB];
        size[rootOfB]+=size[rootOfA];
    } else {
        arr[rootOfB]=arr[rootOfA];
        size[rootOfA]+=size[rootOfB];
    }
    //cout << "a " << a << " roota " << root(a)<< " arr[roota] " << arr[rootOfA] << " b " << b << " rootb " << root(b) << " arr[rootB] " << arr[rootOfB] << endl;
}

int main() {
    //FAST;
    lli i,j,k,n,m;
    cout << "Enter the number of nodes and edges:\n";
    cin>>n>>m; // n=nodes, m=edges
    for(i=0;i<n;i++)
        arr[i]=i;
    for(i=0;i<=n;i++){
        size[i]=1;
    }
    vector<pair<lli,lli> > adj(m+1);
    cout << "Enter the starting node and ending node of each edge:\n";
    for(i=0;i<m;i++){
        cin>>adj[i].first>>adj[i].second;
    }
    for(i=0;i<m;i++){
        if(!find(adj[i].first,adj[i].second)){
            weightedUnion(adj[i].first,adj[i].second);
        } else {
            cout << "Cycle detected!\n";
            return 0;
        }
    }
    cout << "No cycle in the graph!\n";
	return 0;
}
