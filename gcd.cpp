// Functions for gcd and related concepts.

// GCD calculation - O(log(min(a,b))).

ll gcd(ll a, ll b) {
	return (a==0) ? b : gcd(b%a,a);
}

// Iterative version.

ll gcd(ll a, ll b) {
	while(a) {
		b %= a;
		swap(a,b);
	}
	return b;
}

// Function for lcm.

ll lcm(ll a, ll b) {
	ll g = gcd(a,b);
	return (a/g)*b;
}


// Extended Euclid's GCD function.

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


// Some solution to Diophantine Equation ax + by = c. Corner case a=0,b=0 has to be handled separately.

bool find_any_solution(ll a, ll b, ll c, ll &x, ll &y, ll &g) {
    g = gcd(abs(a), abs(b), x, y);
    if((c%g)!=0) {
        return false;
    }

    x *= c/g;
    y *= c/g;
    if(a<0) x = -x;
    if(b<0) y = -y;
    return true;
}

// TODO : Possible solutions when x can lie in range [x1,x2] and y can lie in range [y1,y2].
// Ref - https://cp-algorithms.com/algebra/linear-diophantine-equation.html