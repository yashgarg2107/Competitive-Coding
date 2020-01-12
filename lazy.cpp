// Implementation of Lazy propagation based variants of Segment tree.

// Lazy Propogation - Adding on segment, querying for a point.
// Initialise with memset to 0.
ll tree[4*Nmax];    
ll A[Nmax];

void make_tree(ll idx, ll low, ll high) {
    
    if(low==high) {
        tree[idx] = A[low];
        return;
    }

    ll mid = low + (high-low)/2;
    make_tree((idx<<1),low,mid);
    make_tree((idx<<1)+1,mid+1,high);
    tree[idx] = 0;
}

ll find(ll idx, ll low, ll high, ll pos) {
    
    if(low==high)
        return tree[idx];

    ll mid = low + (high-low)/2;
    if(pos<=mid)
        return tree[idx] + find((idx<<1),low,mid,pos);
    else
        return tree[idx] + find((idx<<1)+1,mid+1,high,pos);
}

void update(ll idx, ll low, ll high, ll l, ll r, ll val) {
    
    if(r<l) return;

    if(low==l && high==r) {
        tree[idx] += val;
        return;
    }

    ll mid = low + (high-low)/2;
    if(mid<l)
        update((idx<<1)+1,mid+1,high,l,r,val);
    else if(r<=mid)
        update((idx<<1),low,mid,l,r,val);
    else {
        update((idx<<1),low,mid,l,mid,val);
        update((idx<<1)+1,mid+1,high,mid+1,r,val);
    }
}


// Adding on segments, querying for max/min

ll lazy[4*Nmax];
pll t[4*Nmax];

void push(ll v) {
    if(lazy[v]==0) 
        return;
    
    t[v*2].fi += lazy[v]; t[v*2].se += lazy[v];
    lazy[v*2] += lazy[v];
    t[v*2+1].fi += lazy[v]; t[v*2+1].se += lazy[v];
    lazy[v*2+1] += lazy[v];
    
    lazy[v] = 0;
}
 
void update(ll v, ll tl, ll tr, ll l, ll r, ll addend) {
    if (l > r) 
        return;
 
    if (l == tl && tr == r) {
        t[v].fi += addend; t[v].se += addend;
        lazy[v] += addend;
    } else {
        push(v);
        ll tm = (tl + tr) / 2;
        update(v*2, tl, tm, l, min(r, tm), addend);
        update(v*2+1, tm+1, tr, max(l, tm+1), r, addend);
        t[v].fi = max(t[v*2].fi, t[v*2+1].fi);
        t[v].se = min(t[v*2].se, t[v*2+1].se);
    }
}
 
ll max_query(ll v, ll tl, ll tr, ll l, ll r) {
    if (l > r)
        return -INF;
    if (l <= tl && tr <= r)
        return t[v].fi;
 
    push(v);
    ll tm = (tl + tr) / 2;

    if(tm<l)
        return max_query((v<<1)+1, tm+1, tr, max(l, tm+1), r);
    else if(r<=tm)
        return max_query((v<<1), tl, tm, l, min(r, tm));

    return max(max_query(v*2, tl, tm, l, min(r, tm)), 
               max_query(v*2+1, tm+1, tr, max(l, tm+1), r));
}
 
ll min_query(ll v, ll tl, ll tr, ll l, ll r) {
    if (l > r)
        return INF;
    if (l <= tl && tr <= r)
        return t[v].se;
 
    push(v);
    ll tm = (tl + tr) / 2;

    if(tm<l)
        return min_query((v<<1)+1, tm+1, tr, max(l, tm+1), r);
    else if(r<=tm)
        return min_query((v<<1), tl, tm, l, min(r, tm));

    return min(min_query(v*2, tl, tm, l, min(r, tm)), 
               min_query(v*2+1, tm+1, tr, max(l, tm+1), r));
}
 
void build(ll v, ll tl, ll tr) {
    if (tl == tr) {
        t[v] = A[tl];
    } else {
        ll tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = max(t[v*2], t[2*v+1]);
    }
}