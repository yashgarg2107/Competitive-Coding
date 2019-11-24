// BFS for a graph with adjacency list representation.

// Can also use level in case of tree-like graphs
vector<ll> level(nmax,0);

void bfs(ll idx, vector<vector<ll>> &adj, vector<char> &visited) {

    queue<ll> q;
    q.push(idx);
    visited[idx] = 1;

    while(!q.empty()) {
        ll idx = q.front();
        q.pop();

        cout<<idx<<" "<<level[idx]<<endl;

        for(auto i:adj[idx]) {
            if(!visited[i]) {
                q.push(i);
                visited[i] = 1;
                level[i] = level[idx]+1;
            }
        }
    }
}
