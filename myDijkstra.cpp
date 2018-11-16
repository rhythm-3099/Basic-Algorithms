#include<bits/stdc++.h>
// This is the C++ implementation of dijkstra's algorithm for directed weighted graph
// Disclaimer: The names of the vertices should be between 1 to n only
using namespace std;
int main(){
    int i,j,k,n,m,a,b,ed,endnode,startnode,cost;
    pair<int,int>p;
    // n = |v|,  m = |E|
    cout << "Enter the number of the vertices\n";
    cin >> n;
    cout << "Enter the number of the edges:\n";
    cin >> m;
    bool done[n+1];
    memset(done,false,sizeof(done));
    int dist[n+1];
    vector< vector< pair<int,int> > >adj(n+1);  // This matrix will show which edge is connected with which edge
    cout << "Enter the data in the following order:\n i) starting vertex  ii) Ending vertex iii) weight of the edge\n\n";
    for(i=0;i<m;i++){
        cin >> a >> b >> ed;        // a is the starting node, b is the ending node, and ed is the weight of the edge from a to b
        p.first = b;
        p.second = ed;
        adj[a].push_back(p);
    }

    // Source node is '1'

    dist[1]=0;
    for(i=2;i<=n;i++){
        dist[i]=999899;     // Initialise it to a big number(infinity)
    }

    for(i=1;i<=n;i++){
        startnode=i;
        for(j=0;j<adj[i].size();j++){
            endnode = adj[i][j].first;
            cost = adj[i][j].second;
            if(dist[startnode]+cost<dist[endnode]){
                dist[endnode]=dist[startnode]+cost;
            }
        }
    }

    for(i=1;i<=n;i++){
        cout << i << " " << dist[i] << endl;    //Distance of the ith node from the source node '1'
    }

    return 0;
}
