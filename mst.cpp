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