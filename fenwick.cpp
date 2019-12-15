// Implementation of Fenwick tree and its variants.


// 0-based indexing approach (sum queries).
// Initialise with memset(bit,0,sizeof(bit));.
ll bit[Nmax];

void add(ll idx, ll delta) {
    while(idx<Nmax) {
        bit[idx] += delta;
        idx = idx|(idx+1);
    }
}

ll sum(ll idx) {
    ll res = 0;
    while(idx>=0) {
        res += bit[idx];
        idx = (idx & (idx+1))-1;
    }
    return res;
}

ll sum(ll l, ll r) {
    return sum(r)-sum(l-1);
}

void make_tree(vector<ll> &A) {
	for(ll i=0;i<Nmax;i++)
        bit[i] = 0;

    for(ll i=0;i<A.size();i++)
        add(i,A[i]);
}


// 1-based indexing approach (sum queries(queries still 0 based)).
// Initialise with memset(bit,0,sizeof(bit));.
ll bit[Nmax+1];

void add(ll idx, ll delta) {
	++idx;
    while(idx<=Nmax) {
        bit[idx] += delta;
        idx += idx & (-idx);
    }
}

ll sum(ll idx) {
    ll res = 0; ++idx;
    while(idx>0) {
        res += bit[idx];
        idx -= idx & (-idx);
    }
    return res;
}

ll sum(ll l, ll r) {
    return sum(r)-sum(l-1);
}

void make_tree(vector<ll> &A) {
	for(ll i=0;i<=Nmax;i++)
        bit[i] = 0;

    for(ll i=0;i<A.size();i++)
        add(i,A[i]);
}
