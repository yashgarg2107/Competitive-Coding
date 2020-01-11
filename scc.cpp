// Implementation for finding strongly connected components in a graph.

// Kosaraju's Algorithm.

ll curr_comp = 0;

void toposort(ll idx, vector<vector<ll>> &adj, vector<char> &visited, vector<ll> &st) {
    visited[idx] = 1;
    for(auto i:adj[idx]) {
        if(!visited[i])
            toposort(i,adj,visited,st);
    }
    st.pb(idx);
}

void sec_pass(ll idx, vector<vector<ll>> &adj, vector<char> &visited, vector<ll> &comps, vector<ll> &curr) {
    visited[idx] = 1;
    comps[idx] = curr_comp;
    curr.pb(idx);

    for(auto i:adj[idx]) {
        if(!visited[i]) {
            sec_pass(i,adj,visited,comps,curr);
        }
    }
}

void scc(vector<vector<ll>> &adj, vector<ll> &comps) {
    ll n = comps.size();

    vector<ll> st;
    vector<char> visited(n,0);
    for(ll i=0;i<n;i++) {
        if(!visited[i]) {
            toposort(i,adj,visited,st);
        }
    }
    reverse(st.begin(), st.end());

    vector<vector<ll>> cadj(n);
    for(ll i=0;i<n;i++) {
        for(auto j:adj[i])
            cadj[j].pb(i);
    }

    visited = vector<char> (n,0);
    for(auto i:st) {
        if(!visited[i]) {
            vector<ll> curr;
            sec_pass(i,cadj,visited,comps,curr);
            curr_comp++;
        }
    }
}