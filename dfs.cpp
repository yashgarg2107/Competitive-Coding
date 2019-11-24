// DFS for a graph with adjacency list representation.

void dfs(ll idx, vector<vector<ll>> &adj, vector<char> &visited) {

    visited[idx] = 1;
    printf("%lld", idx);

    for(auto i:adj[idx]) {
        if(!visited[i]) {
            dfs(i,adj,visited);
        }
    }
}

// DFS for a tree like graph

void dfs_tree(ll idx, ll par, vector<vector<ll>> &adj) {
    
    printf("%lld", idx);
    
    if(adj[idx].size()==1 && par!=-1) {
        // leaf node
        return;
    }

    for(auto i:adj[idx]) {
        if(i!=par) {
            dfs_tree(i,idx,adj);
        }
    }
}

