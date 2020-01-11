// Implementation for topological sorts and DAG algorithms.

// Topological sort implementation based on dfs and stack.
void toposort(ll idx, vector<vector<ll>> &adj, vector<char> &visited, vector<ll> &st) {

	visited[idx] = 1;

	for(auto i:adj[idx]) {
		if(!visited[i])
			toposort(i,adj,visited,st);
	}

	st.pb(idx);
}

// Topological sort implementation based on indegree.
void toposort(ll idx, vector<vector<ll>> &adj, vector<char> &visited, vector<ll> &indeg, vector<ll> &st) {

	visited[idx] = 1;
	st.pb(idx);

	for(auto i:adj[idx]) {
		indeg[i]--;
		if(!visited[i] && !indeg[i])
			toposort(i,adj,visited,indeg,st);
	}
}

// Caller function (example).
void caller() {

	// For first implementation.
	for(ll i=0;i<n;i++) {
		if(!visited[i]) {
			toposort(i,adj,visited,st);
		}
	}

	// For second implementation.
	for(ll i=0;i<n;i++) {
		if(!visited[i] && !indeg[i]) {
			toposort(i,adj,visited,indeg,st);
		}
	}
}

// TODO : Topological sort with lexicographic ordering