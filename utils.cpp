// My Template 

#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define pb push_back
#define N 1000000007
#define N2 998244353
#define nmax 500001
#define pll pair<ll,ll>
#define pii pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(ll i=m;i<(n);i++)
#define ALL(c) (c).begin(),(c).end()
#define fill_nums(A,n) for(ll i=0;i<n;i++) scanf("%lld",&A[i]);
#define fill_edges(adj,m) for(ll i=0;i<m;i++) {ll a, b; scanf("%lld %lld",&a,&b); adj[a-1].pb(b-1); adj[b-1].pb(a-1);}
#define fill_direct(adj,m) for(ll i=0;i<m;i++) {ll a, b; scanf("%lld %lld",&a,&b); adj[a-1].pb(b-1);}


// Merge overlapping intervals given in interval array (pairs)

void merge_overlapping(vector<pair<ll,ll>> &A) {

    ll n = A.size();
    if(!n) return;

    sort(A.begin(),A.end());
    stack<pair<ll,ll>> st;

    for(int i=0;i<n;i++) {
        if(st.empty())
            st.push(A[i]);
        else {
            pair<ll,ll> temp = st.top();
            if(A[i].first<=temp.second) {
                st.top().second = max(temp.second, A[i].second);
            } 
            else {
                st.push(A[i]);
            }
        }
    }

    A.clear();
    while(!st.empty()) {
        A.push_back(st.top());
        st.pop();
    }

    reverse(A.begin(), A.end());
    return;
}