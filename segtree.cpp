// Different implementations for segment trees.


// Segment tree for range sum query - 0 based indexing in A, 1 based in segtree.
// Initialise with memset(tree,0,sizeof(tree));.
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
    tree[idx] = tree[(idx<<1)] + tree[(idx<<1)+1];
}

ll find(ll idx, ll low, ll high, ll l, ll r) {
    
    if(l>high || r<low)
        return 0;

    if(l<=low && high<=r)
        return tree[idx];

    ll mid = low + (high-low)/2;
    if(mid<l)
        return find((idx<<1)+1,mid+1,high,l,r);
    if(r<=mid)
        return find((idx<<1),low,mid,l,r);

    return find((idx<<1),low,mid,l,r) + find((idx<<1)+1,mid+1,high,l,r);
}

void update(ll idx, ll low, ll high, ll pos, ll val) {
    
    if(low==high) {
        A[low] = val;
        tree[idx] = val;
        return;
    }

    ll mid = low + (high-low)/2;

    if(pos<=mid)
        update((idx<<1),low,mid,pos,val);
    else
        update((idx<<1)+1,mid+1,high,pos,val);

    tree[idx] = tree[(idx<<1)] + tree[(idx<<1)+1];
}
// Usage - make_tree(1,0,n-1);
// Usage - find(1,0,n-1,l,r);
// Usage - update(1,0,n-1,x,val);


// Segment tree for range min query. Returns the first index where A[index] = minimum of query range.

vector<ll> tree(4*Nmax,0);
vector<ll> A(Nmax,0);

void make_tree(ll idx, ll low, ll high) {

    if(low==high) {
        tree[idx] = low;
        return;
    }

    ll mid = low+(high-low)/2;
    make_tree((idx<<1),low,mid);
    make_tree((idx<<1)+1,mid+1,high);

    ll left = tree[(idx<<1)], right = tree[(idx<<1)+1];
    tree[idx] = A[left] <= A[right] ? left : right;
}

ll find(ll idx, ll low, ll high, ll l, ll r) {

    if(r<low || l>high) 
        return -1;

    if(l<=low && high<=r)
        return tree[idx];

    ll mid = low+(high-low)/2;

    if(mid<l)
        return find((idx<<1)+1,mid+1,high,l,r);
    if(r<=mid)
        return find((idx<<1),low,mid,l,r);

    ll left = find((idx<<1),low,mid,l,r);
    ll right = find((idx<<1)+1,mid+1,high,l,r);

    // if(left==-1)
    //     return right;
    // if(right==-1)
    //     return left;

    return A[left]<=A[right] ? left : right;
}

void update(ll idx, ll low, ll high, ll pos, ll val) {

    if(low==high) {
        A[low] = val;
        return;
    }

    ll mid = low+(high-low)/2;
    if(pos<=mid)
        update((idx<<1),low,mid,pos,val);
    else
        update((idx<<1)+1,mid+1,high,pos,val);

    ll left = tree[(idx<<1)], right = tree[(idx<<1)+1];
    tree[idx] = A[left] <= A[right] ? left : right;
}