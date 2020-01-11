// Functons for combinatorics related concepts.

vector<ll> facts, invfacts;

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

ll nck(ll n, ll k, ll d) {
    if(k>n)
        return 0;
    return (facts[n]*invfacts[k]%d*invfacts[n-k]%d+d)%d;
}

ll npk(ll n, ll k, ll d) {
    if(k>n)
        return 0;
    return (facts[n]*invfacts[n-k]%d+d)%d;
}

void initialize_facts(ll n, ll mod) {
    facts.resize(n+1);
    invfacts.resize(n+1);
    facts[0] = 1;
    invfacts[0] = 1;

    for(ll i=1;i<=n;i++) {
        facts[i] = (facts[i-1]*i)%mod;
        invfacts[i] = power(facts[i], mod-2, mod);
    }
}