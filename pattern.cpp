// Functons for strings and pattern matching related concepts.

// Function for calculating z-function.
// z[i] = length of longest common prefix between s and s[i..n-1];
vector<ll> z_func(string s) {
	ll n = s.size();
	vector<ll> z(n,0);

	for(ll i=1,l=0,r=0; i<n; i++) {
		if(i<=r)
			z[i] = min(z[i-l], r-i+1);

		while(i+z[i]<n && s[i+z[i]]==s[z[i]])
			++z[i];

		if(i+z[i]-1 > r)
			l = i, r = i+z[i]-1;
	}

	return z;
}


// Function for calculating lps array (Knuth Morris Pratt).
// lps[i] = length of longest proper prefix of s[0..i] which is also suffix of s[0..i].
vector<ll> kmp(string s) {
	ll n = s.size();
	vector<ll> lps(n,0);

	for(ll i=1;i<n;i++) {
		ll j = lps[i-1];

		while(j>0 && s[i]!=s[j])
			j = lps[j-1];

		if(s[i]==s[j])
			j++;
		lps[i] = j;
	}

	return lps;
}


// String Hashing.