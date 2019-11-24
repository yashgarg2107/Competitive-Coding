// Functions for sparse table creation and range queries.

#define Nmax 1000001
#define K 25

vector<vector<ll>> st(Nmax, vector<ll>(K+1));
vector<ll> logg(Nmax,0);

void create_sparse_sum(vector<ll> &A) {
    ll n = A.size();

    for(ll i=0;i<n;i++)
        st[i][0] = A[i];

    for(ll j=1;j<=K;j++) {
        for(ll i=0;i+(1<<j)<=n;i++) {
            st[i][j] =  st[i][j-1] + st[i + (1<<(j-1))][j-1];
        }
    }
}

ll find_sum(ll l, ll r) {
    ll sum = 0;

    for(ll j=K;j>=0;j--) {
        if((1<<j)<=(r-l+1)) {
            sum += st[l][j];
            l += (1<<j);
        }
    }
    return sum;
}

void create_sparse_min(vector<ll> &A) {
    ll n = A.size();

    for(ll i=0;i<n;i++)
        st[i][0] = A[i];

    for(ll j=1;j<=K;j++) {
        for(ll i=0;i+(1<<j)<=n;i++) {
            st[i][j] =  min(st[i][j-1],st[i + (1<<(j-1))][j-1]);
        }
    }

    for(ll i=2;i<Nmax;i++)
        logg[i] = logg[i/2]+1;
}

ll find_min(ll l, ll r) {
    ll j = logg[r-l+1];
    return min(st[l][j], st[r-(1<<j)+1][j]);
}