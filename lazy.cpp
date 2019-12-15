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