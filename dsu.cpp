// Implementation of Disjoint Set Union functions and variants.


// Find method with path compression.

ll find(ll v) {
	if(parent[v]==v)
		return v;
	return parent[v]=find(parent[v]);
}


// Union method based on rank = size.
ll parent[Nmax];
ll size[Nmax];

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


// Union method based on rank = depth.

ll parent[Nmax];
ll depth[Nmax];

void make_set(ll n) {
	for(ll i=0;i<n;i++) {
		parent[i] = i;
		depth[i] = 0;
	}
}

void dounion(ll a, ll b) {
	a = find(a);
	b = find(b);

	if(a!=b) {
		if(depth[a]<depth[b])
			swap(a,b);
		parent[b] = a;
		if(depth[a]==depth[b])
			depth[a]++;
	}
}


// Union-find with explicit set storage. For m queries : O(m + nlogn).

vector<ll> seta[Nmax];
ll parent[Nmax];

void make_set(ll n) {
	for(ll i=0;i<n;i++) {
		seta[i] = vector<ll> (1,i);
		parent[i] = i;
	}
}

ll find(ll v) {
	return parent[v];
}

void dounion(ll a, ll b) {
	a = find(a);
	b = find(b);

	if(a!=b) {
		if(seta[a].size()<seta[b].size())
			swap(a,b);

		while(seta[b].size()) {
			ll v = seta[b].back();
			seta[b].pop_back();
			seta[a].push_back(v);
			parent[v] = a;
		}
	}
}