// Frequently required function for tree data structure.

// Diameter of tree.

vector<ll> dim(Nmax,0);

pair<ll,ll> diameter(ll idx, vector<vector<ll>> &adj) {
    for(ll i=0;i<Nmax;i++)
        dim[i] = Nmax+1;
    dim[idx] = 0;

    queue<ll> q;
    q.push(idx);
    ll last = idx;

    while(!q.empty()) {
        last = q.front();
        q.pop();

        for(auto i:adj[last]) {
            if(dim[i] > dim[last]+1) {
                dim[i] = dim[last] + 1;
                q.push(i);
            }
        }

    }
    return make_pair(last, dim[last]);
}

// Usage:
// auto p1 = diameter(st, tree);
// auto p2 = diameter(p1.fi, tree);
// cout<<p2.se<<endl;