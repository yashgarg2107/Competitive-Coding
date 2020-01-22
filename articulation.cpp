// Implementation of functions for finding articulation(cut) points in a graph.

ll timer = 0;
vector<ll> tin(Nmax,0), low(Nmax,0);
vector<char> visited(Nmax,0);

void process_point(ll u) {
	// Add entry or do something else.
}

void cut_dfs(ll idx, ll par, vv<vv<ll>> &adj) {
    visited[idx] = 1;
    tin[idx] = low[idx] = ++timer;
    ll children = 0;

    for(auto i:adj[idx]) {
        if(!visited[i]) {
            cut_dfs(i, idx, adj);
            low[idx] = min(low[idx], low[i]);
            
            if(low[i]>=tin[idx] && par!=-1)
            	process_point(idx);
            children++;
        }
        else if(i!=par) {
            low[idx] = min(low[idx], tin[i]);
        }
	}

	if(par==-1 && children>1)
		process_point(idx);
}

void find_cutpoints(vector<vector<ll>> &adj) {
	ll n = adj.size();
	for(ll i=0;i<n;i++) {
		if(!visited[i])
			cut_dfs(i,-1,adj);
	}
}
