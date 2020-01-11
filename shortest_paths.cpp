// Implementations of algorithms for finding shortest paths in graphs.

// Dijkstra's Algorithm.

class Compare {
public:
    bool operator() (pll a, pll b) {
        if(a.first>b.first)
            return true;
        return false;
    }
};

void dijkstra(vector<vector<pll>> &adj) {

    ll n = adj.size();
    priority_queue<pll, vector<pll>, Compare> pq;

    // adj has {cost,neighbour} pairs.
    // par[i] denotes parent for ith vertex in path from src to i.
    // dist[i] denotes the shortest dist between src and i.
    vector<char> vis(n,0);
    vector<ll> par(n,-1), dist(n,1e18);

    dist[0] = 0;
    pq.push({0,0});

    while(!pq.empty()) {
        pll t = pq.top();
        pq.pop();

        if(vis[t.second])
            continue;
        vis[t.second]=1;

        for(auto i:adj[t.second]) {
            if(!vis[i.second]) {
                if(i.first + dist[t.second] < dist[i.second]) {
                    dist[i.second] = i.first + dist[t.second];
                    par[i.second] = t.second;
                    pq.push({dist[i.second], i.second});
                }
            }
        }
    }
}