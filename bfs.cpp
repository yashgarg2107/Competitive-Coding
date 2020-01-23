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


// BFS on complement graph.

// seta is set of edges (u,v) where u<v.
// This functions finds the number and sizes of connected components.
void bfs_compl(vector<pll> &seta) {
    set<ll> nvisited;
    rep(i,n) 
        nvisited.insert(i);

    vector<ll> res;
    rep(i,n) {
        if(nvisited.count(i)) {
            queue<ll> q;
            nvisited.erase(i);
            q.push(i);
            ll sz = 1;

            while(!q.empty()) {
                ll t = q.front(); 
                q.pop();

                vector<ll> temp;
                for(auto i:nvisited) {
                    pll edge = {min(i,t),max(i,t)};
                    if(!seta.count(edge)) {
                        temp.pb(i);
                    }
                }

                for(auto i:temp) {
                    q.push(i);
                    nvisited.erase(i);
                    sz++;
                }
            }

            res.pb(sz);
        }
    }

    sort(ALL(res));

    printf("%lld\n", (ll)res.size());
    for(auto i:res)
        printf("%lld ", i);
    printf("\n");
}