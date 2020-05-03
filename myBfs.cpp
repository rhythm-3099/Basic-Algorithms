#include<iostream>
#include<bits/stdc++.h>
#include<string.h>
#include<vector>
#include<algorithm>
#include<math.h>
#include<stack>
#include<cstdio>
#define lli long long int
#define db double
#define str string
#define ch char
#define pb push_back
#define FOR(a,n) for(i=0;i<n;i++){	cin>>a[i];}
using namespace std;

lli d,x,y;
void extendedEuclid(lli A, lli B)	// don't consider this! 
{
    if(B == 0) 
    {
         d = A;
         x = 1;
         y = 0;
    }
    else 
    {
        extendedEuclid(B, A%B);
        int temp = x;
        x = y;
        y = temp - (A/B)*y;
    }
}

/*    We use Queue DataStructure for the implementation of BFS Algorithm  */

int main() {
	lli i,j,k,n,m,a,b,root;
	queue<lli> q;
	cout << "The number of nodes: \n";
	cin >> n;   // n = Number of nodes, m = Number of Edges
	cout << "\nThe number of edges: \n";
	cin >> m;
	vector< vector<lli> > adj(n+1);  //  To show the connection between two nodes by an edge
	bool visited[n+1];  // This boolean array will help in knowing if all the nodes are visited or not
	memset(visited,false,sizeof(visited));

	/*Input the edges between two nodes  */
	for(i=0;i<m;i++){
		cout << "Enter the nodes between whom an edge is present \n";
		cin >> a >> b;
		adj[a].pb(b);  // Push back the value of b in adj[a]
		adj[b].pb(a);  // Push back the value of a in adj[b]
	}
	root = 1;  // Root is the starting node. Here, the starting node is 1
    visited[root]=true;  //  Root node is visited
    q.push(root);
    cout << "\nThe order in which the graph is traversed is:\n";

    while(!q.empty()){
        k = q.front();   // We will traverse from this node
        q.pop();
        cout << k << " "; // This will print the order in which the graph is traversed by BFS
        for(i=0;i<adj[k].size();i++){
            if(!visited[adj[k][i]]){
                visited[adj[k][i]]=true;  //  The node has been visited
                q.push(adj[k][i]);
            }
        }
    }

	return 0;
}
