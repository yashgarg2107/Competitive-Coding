// Functions for different implementation of LCA.

// Implementation of LCA using RMQ.

vector<ll> height, euler, first, segtree;

void dfs(ll idx, ll par, vector<vector<ll>> &adj, ll ht) {
	height[idx] = ht;
	first[idx] = euler.size();
	euler.pb(idx);

	for(auto i:adj[idx]) {
		if(i!=par) {
			dfs(i,idx,adj,ht+1);
			euler.pb(idx);
		}
	}
}

void make_tree(ll idx, ll low, ll high) {
	if(low==high) {
		segtree[idx] = euler[low];
		return;
	}

	ll mid = low+(high-low)/2;
	make_tree(2*idx,low,mid);
	make_tree(2*idx+1,mid+1,high);

	ll l = segtree[2*idx], r = segtree[2*idx+1];

	// storing indices which corresponds to minimum.
	segtree[idx] = height[l]<height[r] ? l : r;	
	return;
}

ll query(ll idx, ll low, ll high, ll left, ll right) {
	if(low>right || high<left)
		return -1;
	if(left<=low && right>=high)
		return segtree[idx];

	ll mid = low+(high-low)/2;

	ll l = query(2*idx,low,mid,left,right);
	ll r = query(2*idx+1,mid+1,high,left,right);

	if(l==-1) 
		return r;
	if(r==-1)
		return l;
	return height[l] < height[r] ? l : r;
}

ll lca(ll u, ll v) {
	if(first[u]>first[v])
		swap(u,v);
	return query(1, 0, euler.size()-1, first[u], first[v]);
}

void create(vector<vector<ll>> &adj) {
	ll n = adj.size();

	height.resize(n);
	first.resize(n);
	dfs(0,-1,adj,0);

	ll m = euler.size();
	segtree.resize(4*m);
	make_tree(1,0,m-1);
}


// Implementation of LCA using binary lifting.

vector<ll> tin, tout;
vector<vector<ll>> up;
ll L, timer = 0;

void dfs(ll idx, ll par, vector<vector<ll>> &adj) {

    tin[idx] = timer++;
    up[idx][0] = par;

    for(ll i=1;i<=L;i++)
        up[idx][i] = up[up[idx][i-1]][i-1];

    for(auto i:adj[idx])
        if(i!=par)
            dfs(i,idx,adj);

    tout[idx] = timer++;
}

bool is_ancestor(ll u, ll v) {
    return tin[u]<=tin[v] && tout[v]<=tout[u];
}

ll lca(ll u, ll v) {
    if(is_ancestor(u,v))
        return u;
    if(is_ancestor(v,u))
        return v;

    for(ll i=L;i>=0;i--) {
        if(!is_ancestor(up[u][i],v))
            u = up[u][i];
    }

    return up[u][0];
}

void create(vector<vector<ll>> &adj) {
    ll n = adj.size();

    tin.resize(n);
    tout.resize(n);
    timer = 0;

    L = ceil(log2((double)n));
    up.assign(n, vector<ll>(L+1));

    dfs(0,0,adj);
}