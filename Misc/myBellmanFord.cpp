#include<bits/stdc++.h>
// This is the implementation of the Bellman-Ford Algorithm in C++ 14. Does the same thing as Dijkstra's Algorithm but also works for the negative weights of the edges also.
// Does not work for a negative weighted cycle
using namespace std;
int main(){
    int i,j,k,n,m,a,b,c,startnode,endnode,cost;
    cout << "Enter the number of vertices:\n";
    cin >> n;
    cout << "Enter the number of edges:\n";
    cin >> m;
    pair<int,int>p;
    int dist[n+1];
    dist[1]=0;
    vector<pair <int,pair<int,int> > > edges(m);    // this data structure stores the value of the starting node, ending node and the weight of the edge
    // between them as a single element.
    cout << "Enter the edges in the following order:  i) starting vertex, ii) ending vertex, iii) Weight of the edge\n\n";
    for(i=0;i<m;i++){
        cin >> a >> b >> c;
        edges[i].first=a;
        edges[i].second.first=b;
        edges[i].second.second=c;
    }

    for(i=0;i<n+1;i++){
        dist[i]=9998999;    // Initializing the values as infinite
    }

    dist[1]=0;
    for(i=0;i<n-1;i++){
        for(j=0;j<m;j++){
            startnode = edges[j].first;
            endnode = edges[j].second.first;
            cost = edges[j].second.second;
            if(dist[endnode]>dist[startnode]+cost){
                dist[endnode]=dist[startnode]+cost;
            }
        }
    }
    // Printing the result

    for(i=1;i<=n;i++){
        if(dist[i]!=INT_MAX)
            cout << i << "  " << dist[i] << endl;
        else
            cout << "Not Reachable!\n";
    }

    return 0;
}
