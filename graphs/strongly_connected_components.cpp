/*  Function to find the number of strongly connected components
*   using Kosaraju's algorithm
*   V: number of vertices
*   adj[]: array of vectors to represent graph
*/  

void topo(int v, stack<int> &st, bool vis[], vector<int> adj[]){
    vis[v]=true;
    for(auto i=adj[v].begin();i!=adj[v].end();i++){
        if(!vis[*i]){
            topo(*i, st, vis, adj);
        }
    }
    st.push(v);
}

void dfs(int v, bool vis[], vector<int> g[]){
    vis[v]=true;
    for(auto i=g[v].begin();i!=g[v].end();i++){
        if(!vis[*i]){
            dfs(*i, vis, g);
        }
    }
}

int kosaraju(int V, vector<int> adj[])
{
    bool vis[V];
    memset(vis,false,sizeof(vis));
    int i,j,k;
    stack<int>st;
    for(i=0;i<V;i++){
        if(!vis[i]){
            topo(i,st,vis,adj);
        }
    }
    
    vector<int> g[V];
    for(i=0;i<V;i++){
        for(j=0;j<adj[i].size();j++){
            g[adj[i][j]].push_back(i);
        }
    }

    memset(vis,false,sizeof(vis));
    int count=0;
    while(!st.empty()){
        int k=st.top();
        st.pop();
        if(!vis[k]){
            dfs(k,vis,g);
            count++;
        }
    }
    return count;
}