// Functions for mst calculations.

// Comparator for min heap.
class Compare {
public:
    bool operator() (pll a, pll b) {
        if(a.first>b.first)
            return true;
        return false;
    }
};

void prim_mst(vector<vector<pll>> &adj) {

    ll n = adj.size();
    priority_queue<pll, vector<pll>, Compare> pq;

    vector<char> vis(n,0);

    // adj has {cost,neighbour} pairs.
    // par[i] denotes parent for ith vertex in mst.
    // keys[i] denotes the edge weight between ith index and its par in mst.
    vector<ll> par(n,-1), keys(n,1e18);

    keys[0] = 0;
    pq.push({0,0});

    while(!pq.empty()) {
        pll t = pq.top();
        pq.pop();

        if(vis[t.second])
            continue;
        vis[t.second]=1;

        for(auto i:adj[t.second]) {
            if(!vis[i.second]) {
                if(i.first<keys[i.second]) {
                    keys[i.second] = i.first;
                    par[i.second] = t.second;
                    pq.push(i);
                }
            }
        }
    }
}


// DSU methods for Kruskals mst.

ll parent[Nmax];
ll size[Nmax];

void make_set(ll n) {
    for(ll i=0;i<n;i++) {
        parent[i] = i;
        size[i] = 1;
    }
}

ll find(ll v) {
    if(parent[v]==v)
        return v;
    return parent[v]=find(parent[v]);
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

vector<pair<ll,pll>> kruskal_mst(vector<vector<pll>> &adj) {
    ll n = adj.size();
    vector<pair<ll,pll>> edges;
    for(ll i=0; i<n; i++) {
        for(auto j:adj[i]) {
            edges.push_back({j.fi, {i, j.se}});
        }
    }

    sort(edges.begin(), edges.end());
    make_set(n);

    vector<pair<ll,pll>> res_edges;
    for(auto e:edges) {
        ll a = find(e.se.fi);
        ll b = find(e.se.se);
        if(a==b) continue;

        dounion(a,b);
        res_edges.push_back(e);
    }

    return res_edges;
}