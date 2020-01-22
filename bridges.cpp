// Implementation of functions for finding bridges in a graph.

ll timer = 0;
vector<ll> tin(Nmax,0), low(Nmax,0);
vector<char> visited(Nmax,0);

void process_bridge(ll u, ll v) {
	// Add entry or do something else.
}

void bridge_dfs(ll idx, ll par, vv<vv<ll>> &adj) {
    visited[idx] = 1;
    tin[idx] = low[idx] = ++timer;

    for(auto i:adj[idx]) {
        if(!visited[i]) {
            bridge_dfs(i, idx, adj);
            low[idx] = min(low[idx], low[i]);
            
            if(low[i]>tin[idx])
            	process_bridge(idx, i);
        }
        else if(i!=par) {
            low[idx] = min(low[idx], tin[i]);
        }
	}
}

void find_bridges(vector<vector<ll>> &adj) {
	ll n = adj.size();
	for(ll i=0;i<n;i++) {
		if(!visited[i])
			bridge_dfs(i,-1,adj);
	}
}


// Implementation for obtaining bridge tree of a graph (using union find).
// Graph is assumed to be connected.

ll parent[Nmax];
ll size[Nmax];

ll find(ll v) {
    if(parent[v]==v)
        return v;
    return parent[v]=find(parent[v]);
}

void make_set(ll n) {
    for(ll i=0;i<n;i++) {
        parent[i] = i;
        size[i] = 1;
    }
}

void dounion(ll a, ll b) {
    a = find(a);
    b = find(b);

    if(a!=b) {
        if(size[a]<size[b])
            swap(a,b);
        parent[b] = a;
        size[a] += size[b];
    }
}

ll timer = 0, st;
vector<ll> tin(Nmax,0), low(Nmax,0);
vector<char> visited(Nmax,0);
vector<pll> bridges;
vector<vector<ll>> tree(Nmax);

void bridge_dfs(ll idx, ll par, vv<vv<ll>> &adj) {
    visited[idx] = 1;
    tin[idx] = low[idx] = ++timer;

    for(auto i:adj[idx]) {
        if(!visited[i]) {
            bridge_dfs(i, idx, adj);
            low[idx] = min(low[idx], low[i]);
            
            if(low[i]>tin[idx])
                bridges.pb({idx,i});
            else {
                dounion(idx,i);
            }
        }
        else if(i!=par) {
            low[idx] = min(low[idx], tin[i]);
        }
    }
}

void build() {
    for(auto i:bridges) {
        ll x = find(i.first);
        ll y = find(i.second);
        tree[x].pb(y);
        tree[y].pb(x);

        // Any node in the tree (for staring traversal purposes).
        st = x;
    }
}

// Usage:
// make_set(Nmax);
// bridge_dfs(0,-1,adj);
// build();