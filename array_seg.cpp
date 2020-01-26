// Functions for array segments manipulations like range additions with querying at end.

// Main array.
vector<ll> pri(Nmax,0);

// Auxillary array for arithmetic progression additions.
vector<ll> sec(Nmax,0);

// Addition of value to all entries in range l to r.
void add_val(ll l, ll r, ll val) {
	pri[l] += val;
	pri[r+1] -= val;
}

// Addition of val*(x-l) (AP) to range l to r.
void add_prog(ll l, ll r, ll val) {
	pri[r+1] -= val*(r-l+1);
	sec[l] += val;
	sec[r+1] -= val;
}

// Addition of val1 + val2*(x-l) to range l to r.
void add_comb(ll l, ll r, ll val1, ll val2) {
	add_val(l,r,val1);
	add_prog(l,r,val2);
}

// Final values of the array after all queries are processed.
void final_proc() {
	// Generating k,k,k types values in secondary array.
	rep2(i,1,Nmax)
		sec[i] += sec[i-1];

	// Adding the repeated values 0,k,k.. to main array.
	rep2(i,1,Nmax)
		pri[i] += sec[i-1];
	
	// Generating progression value 0,k,k*2.. in main array.
	rep2(i,1,Nmax)
		pri[i] += pri[i-1];
}