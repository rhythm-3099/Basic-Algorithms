#include<bits/stdc++.h>
// This is the C++ implementation of dijkstra's algorithm for directed weighted graph
// Disclaimer: The names of the vertices should be between 1 to n only
// The weights of the edges should be positive.
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
    //done[0]=true;
    for(i=2;i<=n;i++){
        dist[i]=999899;     // Initialise it to a big number(infinity)
    }

    int count=0,min_ind,min;
    while(count!=n){
        min=1000000;
        for(i=1;i<=n;i++){
            if(dist[i]<=min && !done[i]){   // !done[i] checks if the endnode is already relaxed
                min=dist[i],min_ind=i;
            }
        }
        //cout << "min_ind  " << min_ind << endl;
        done[min_ind]=true;
        for(i=0;i<adj[min_ind].size();i++){
            startnode = min_ind;
            endnode = adj[min_ind][i].first;
            cost = adj[min_ind][i].second;
            if(dist[endnode]>dist[startnode]+cost && !done[endnode]){
                dist[endnode]=dist[startnode]+cost;
            }
        }
        count++;
    }

    for(i=1;i<=n;i++){
        if(dist[i]!=99899)
            cout << i << " " << dist[i] << endl;    //Distance of the ith node from the source node '1'
        else
            cout << i << " " << "Not reachable!\n";  // There is no path from source node to the ith node
    }

    return 0;
}
