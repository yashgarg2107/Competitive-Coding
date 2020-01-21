// Library for string hashing methods.

// String hasing defines.
#define m1 (ll)1000000009
#define m2 (ll)1000000007
#define p1 (ll)31
#define p2 (ll)37

// Use of 2 hashes to decrease probability of collisions.
vector<ll> h1(Nmax,0), h2(Nmax,0);
vector<ll> pow1(Nmax,1), pow2(Nmax,1);

bool pflag = 0;

void generate_powers() {
	for(ll i=1;i<Nmax;i++) {
        pow1[i] = pow1[i-1]*p1%m1;
        pow2[i] = pow2[i-1]*p2%m2;
    }
    pflag = 1;
}

void generate(string &str) {
	if(!pflag)
		generate_powers();

    ll n = str.size();
    // h[i+1] denotes hash of prefix str[0..i];
    rep(i,n) {
        h1[i+1] = (h1[i] + (ll)(str[i]-'a'+1)*pow1[i]%m1)%m1;
        h2[i+1] = (h2[i] + (ll)(str[i]-'a'+1)*pow2[i]%m2)%m2;
    }
}

void usage_help() {
	// l0 is offset.
	ll v1 = (h1[j+l0]-h1[j]+m1)%m1*pow1[n-j-1]%m1;
    ll v2 = (h2[j+l0]-h2[j]+m2)%m2*pow2[n-j-1]%m2;
    pll ha = {v1,v2};
}