// Functions for prime number related computations.

// Sieve of Eratosthenes for marking primes upto n - O(n*loglogn).

void sieve_primes(vector<char> &siv) {
	ll n = siv.size();

	siv[0]=0; siv[1]=0;
	for(ll i=2;i<=sqrt(n);i++) {
		if(siv[i]) {
			for(ll j=i*i;j<n;j+=i)
				siv[j]=0;
		}
	}
}

// The following one requires n/8 bytes whereas previous one uses n 
// bytes nemeory, but bit level compression makes the operation slow,
// hence this is to be used only in case of memory constraints.

void sieve_primes(vector<bool> &siv) {
	ll n = siv.size();

	siv[0]=0; siv[1]=0;
	for(ll i=2;i<=sqrt(n);i++) {
		if(siv[i]) {
			for(ll j=i*i;j<n;j+=i)
				siv[j]=0;
		}
	}
}

// ----------------------------------
// TODO : Linear approach to sieve.
// Ref - https://cp-algorithms.com/algebra/prime-sieve-linear.html
// ---------------------------------

// Sieve of Euler to mark lowest prime factor for a number.

void euler_sieve(vector<ll> &siv) {
	ll n = siv.size();

	for(ll i=0;i<n;i++)
		siv[i] = i;

	for(ll i=2;i<=sqrt(n);i++) {
		if(siv[i]==i) {
			for(ll j=i*i;j<n;j+=i)
				if(siv[j]==j)
					siv[j] = i;
		}
	}
} 


// Prime factorization based on sieve of euler.
// O(logn) for single query after preprocessing of O(n).

vector<ll> prime_factors_euler(ll num, vector<ll> &siv) {
	ll n = siv.size(); 

	if(siv[num]==num)
		return vector<ll> {num};

	vector<ll> res;
	while(siv[num]!=num) {
		res.push_back(siv[num]);
		num /= siv[num];
	}
	res.push_back(siv[num]);

	// for(auto i:res)
	// 	printf("%lld ",i);
	// printf("\n");

	return res;
}


// Factors of a number - O(sqrt(N)).

vector<ll> factorize(ll num) {
	
	vector<ll> res;
	for(ll i=1;i<=sqrt(num);i++) {
		if((num%i)==0) { 
			if(i*i==num) {
				res.push_back(i);
			}
			else {
				res.push_back(i);
				res.push_back(num/i);
			}
		}
	}

	sort(res.begin(), res.end());

	// for(auto i:res)
	// 	printf("%lld ",i);
	// printf("\n");

	return res;
}


// Prime factorization of number - O(sqrt(N)).

vector<ll> prime_factors(ll num) {
	
	vector<ll> res;

	while((num%2)==0) {
		res.push_back(2);
		num/=2;
	}

	for(ll i=3;i<=sqrt(num);i+=2) {
		while((num%i)==0) {
			res.push_back(i);
			num/=i;
		}
	}

	if(num>1)
		res.push_back(num);

	// for(auto i:res)
	// 	printf("%lld ",i);
	// printf("\n");

	return res;
}

// Prime factorization using precomputed primes.

vector<ll> primes;

void primes_tilln(ll num) {
	vector<char> siv(num+1,1);
	sieve_primes(siv);

	for(ll i=2;i<=num;i++)
		if(siv[i])
			primes.push_back(i);
}

vector<ll> prime_factors(ll num) {
	
	vector<ll> res;

	for(auto i:primes) {
		if(i*i>num)
			break;

		while((num%i)==0) {
			res.push_back(i);
			num/=i;
		}
	}

	if(num>1)
		res.push_back(num);

	// for(auto i:res)
	// 	printf("%lld ",i);
	// printf("\n");

	return res;
}