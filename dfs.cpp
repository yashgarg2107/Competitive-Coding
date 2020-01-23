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

// Cycle detection in directed graph.
vector<char> vis(Nmax,0), rec(Nmax,0);

bool cyc(ll idx, vector<vector<ll>> &adj) {
    vis[idx]=1;
    rec[idx]=1;

    for(auto i:adj[idx]) {
        if(rec[i]) return true;
        if(!vis[i] && cyc(i,adj)) {
            return true;
        }
    }
    rec[idx]=0;
    return false;
}

// Cycle detection in undirected graph.
vector<char> vis(Nmax,0);

bool cyc(ll idx, ll par, vector<vector<ll>> &adj) {
    vis[idx]=1;

    for(auto i:adj[idx]) {
        if(!vis[i]) {
            if(cyc(i,idx,adj))
                return true;
        }
        else if(i!=par)
            return true;
    }
    return false;
}