#define ll long long
#define Nmax 500000


// Segment tree for range sum query - 0 based indexing in A, 1 based in segtree.

vector<ll> tree(4*Nmax,0);
vector<ll> A(Nmax,0);

void make_tree(ll low, ll high, ll idx) {

    if(low==high) {
        tree[idx] = A[low];
        return;
    }

    ll mid = low+(high-low)/2;
    make_tree(low,mid,2*idx);
    make_tree(mid+1,high,2*idx+1);
    tree[idx] = tree[2*idx] + tree[2*idx+1];
}

ll find(ll low, ll high, ll l, ll r, ll idx) {

    if(r<low || l>high) 
        return 0;

    if(l<=low && high<=r)
        return tree[idx];

    ll mid = low+(high-low)/2;
    return find(low,mid,l,r,2*idx) + find(mid+1,high,l,r,2*idx+1);  
}

void update(ll low, ll high, ll idx, ll x, ll val) {

    if(low==high) {
        tree[idx] = val;
        A[x] = val;   
        return;
    }

    ll mid = low+(high-low)/2;
    if(x<=mid)
        update(low,mid,2*idx,x,val);
    else
        update(mid+1,high,2*idx+1,x,val);

    tree[idx] = tree[2*idx] + tree[2*idx+1];
}

// Usage - make_tree(0,n-1,1);
// Usage - find(0,n-1,l,r,1);
// Usage - update(0,n-1,1,x,val);


// Segment tree for range min query - 0 based indexing in A, 1 based in segtree.

vector<ll> tree(4*Nmax,0);
vector<ll> A(Nmax,0);

void make_tree(ll low, ll high, ll idx) {

    if(low==high) {
        tree[idx] = A[low];
        return;
    }

    ll mid = low+(high-low)/2;
    make_tree(low,mid,2*idx);
    make_tree(mid+1,high,2*idx+1);
    tree[idx] = min(tree[2*idx],tree[2*idx+1]);
}

ll find(ll low, ll high, ll l, ll r, ll idx) {

    if(r<low || l>high) 
        return INT_MAX;

    if(l<=low && high<=r)
        return tree[idx];

    ll mid = low+(high-low)/2;
    return min(find(low,mid,l,r,2*idx),find(mid+1,high,l,r,2*idx+1));  
}

void update(ll low, ll high, ll idx, ll x, ll val) {

    if(low==high) {
        tree[idx] = val;
        A[x] = val;   
        return;
    }

    ll mid = low+(high-low)/2;
    if(x<=mid)
        update(low,mid,2*idx,x,val);
    else
        update(mid+1,high,2*idx+1,x,val);

    tree[idx] = min(tree[2*idx],tree[2*idx+1]);
}