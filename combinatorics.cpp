// Functons for combinatorics related concepts.

vector<ll> facts, invfacts;

ll extended_gcd(ll a, ll b, ll &x, ll &y) {
    if(a==0) {
        x = 0;
        y = 1;
        return b;
    }

    ll x1, y1;
    ll g = extended_gcd(b%a, a, x1, y1);

    x = y1-(b/a)*x1;
    y = x1;
    return g;
}

ll nck(ll n, ll k) {
    if(k>n)
        return 0;
    return (facts[n]*invfacts[k]%N*invfacts[n-k]%N+N)%N;
}

ll npk(ll n, ll k) {
    if(k>n)
        return 0;
    return (facts[n]*invfacts[n-k]%N+N)%N;
}

void initialize_facts(ll n, ll mod) {
    facts.resize(n+1);
    invfacts.resize(n+1);
    facts[0] = 1;
    invfacts[0] = 1;

    for(ll i=1;i<=n;i++) {
        facts[i] = (facts[i-1]*i)%N;
        ll x,y;
        extended_gcd(facts[i],mod,x,y);
        invfacts[i] = x;
    }
}