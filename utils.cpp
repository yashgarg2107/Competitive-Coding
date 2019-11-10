// My Template 

#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define pb push_back
#define N 1000000007
#define N2 998244353
#define Nmax 100001
#define INF (ll)1e18
#define pll pair<ll,ll>
#define pii pair<ll,ll>
#define mp make_pair
#define fi first
#define se second
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(ll i=m;i<(n);i++)
#define get(n) ll (n); scanf("%lld",&(n));
#define get2(n,k) ll (n),(k); scanf("%lld%lld",&(n),&(k));
#define get3(n,m,k) ll (n),(m),(k); scanf("%lld%lld%lld",&(n),&(m),&(k));
#define gets(s) string (s); cin >> (s);
#define ALL(c) (c).begin(),(c).end()
#define fill_nums(A,n) vector<ll> A((n)); for(ll i=0;i<n;i++) scanf("%lld",&A[i]);
#define fill_edges(adj,m) for(ll i=0;i<m;i++) {ll a, b; scanf("%lld %lld",&a,&b); adj[a-1].pb(b-1); adj[b-1].pb(a-1);}
#define fill_direct(adj,m) for(ll i=0;i<m;i++) {ll a, b; scanf("%lld %lld",&a,&b); adj[a-1].pb(b-1);}
#define pi 3.1415926535897


// Custom hash function for long long int types -> to prevent unordered_map/set fails/hacks

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};


// Merge overlapping intervals given in interval array (pairs).

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


// Binary exponentiation for fast power calculations.

ll power(ll x, ll n) {
    if(n==0) return 1;
    if(n==1) return x;

    ll val = power(x,n/2);
    if(n%2) return val*val*x;
    return val*val;
}

// Iterative version.

ll power(ll x, ll n) {
    ll val = x, res = 1;
    while(n>0) {
        if(n&1)
            res = res*val;
        val = val*val;
        n = n>>1;
    }
    return res;
}


// Binary exponentiation (mod d) calculations.

ll power(ll x, ll n, ll d) {
    if(n==0) return 1;
    if(n==1) return (x%d+d)%d;

    ll val = power(x,n/2,d);
    if(n%2) return ((((val*val)%d)*x)%d+d)%d;
    return (val*val)%d;
}

// Iterative version.

ll power(ll x, ll n, ll d) {
    ll val = (x%d), res = 1;
    while(n>0) {
        if(n&1)
            res = (res*val)%d;
        val = (val*val)%d;
        n = n>>1;
    }
    return (res+d)%d;
}


// Function for calculating prefix sums of matrix.

void prefix_matrix(vector<vector<ll>> &A) {
    ll n = A.size();

    for(ll i=0;i<n;i++) {
        for(ll j=0;j<n;j++) {
            A[i][j] += ((i>=1 ? A[i-1][j]:0) + (j>=1 ? A[i][j-1]:0) - ((i*j > 0) ? A[i-1][j-1]:0));
            // cout<<A[i][j]<<" ";
        }
        // cout<<endl;
    }
}


// Digit dp code - example

// int main() {
    
//     string s;
//     cin >> s;

//     get(d);

//     vector<vector<ll>> dp(d, vector<ll>(2,0));
//     dp[0][1] = 1;

//     for(ll i=0;i<s.length();i++) {
//         vector<vector<ll>> dp2(d, vector<ll>(2,0));
//         for(ll j=0;j<=9;j++) {
//             for(ll k=0;k<d;k++)
//                 dp2[(k+j)%d][0] += dp[k][0]; 
//         }

//         ll digi = s[i]-'0';
//         for(ll j=0;j<digi;j++) {
//             for(ll k=0;k<d;k++)
//                 dp2[(k+j)%d][0] += dp[k][1];
//         }

//         for(ll k=0;k<d;k++)
//             dp2[(k+digi)%d][1] += dp[k][1];

//         dp = dp2;
//     }

//     ll ans = (dp[0][1]+dp[0][0]-1)%N;

//     printf("%lld\n",(N+ans)%N);
//     return 0;  
// }