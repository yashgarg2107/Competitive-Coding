// Famous dp algorithms which can be used as subroutines in other problems.

// Longest Increasing Subsequence in nlogn.

vector<ll> dp1(Nmax,0);
vector<ll> store(Nmax,INF);

ll lis(vector<ll> &A) {
	ll n = A.size();
	ll maxi = 0;
	for(ll i=0;i<n;i++) {
        ll idx = upper_bound(ALL(store), A[i]) - store.begin();
        store[idx] = A[i];
        dp1[i] = idx+1;
        maxi = max(maxi, dp1[i]);
    }
    return maxi;
}