// Implementation for matrix multiplication and exponentiation.

ll sz;

class M {
public:
    vector<vector<ll>> m;

    M() {
        m.resize(sz, vector<ll>(sz));
    }

    M operator*(const M &mat2) {
        M res;
        for(ll i=0;i<sz;i++) {
            for(ll j=0;j<sz;j++) {
                for(ll k=0;k<sz;k++) {
                    res.m[i][j] = (res.m[i][j] + m[i][k]*mat2.m[k][j]%N)%N;
                }
            }
        }

        return res;
    }

    // Usage M::power(matr,n);
    static M power(M &matr, ll n) {
        M res;
        for(ll i=0;i<sz;i++)
            res.m[i][i] = 1;

        while(n) {
            if(n%2) {
                res = res*matr;
            }
            matr = matr*matr;
            n /= 2;
        }

        return res;
    }
};

// Array Exponentiation.

ll sz;

class Arr {
public:
    vector<vector<ll>> A;

    Arr() {
        A.resize(sz, vector<ll>(3));
    }

    Arr operator*(const Arr &arr) {
        Arr res;
        for(ll i=0;i<sz;i++) {
            res.A[i][0] = A[arr.A[i][0]][0];
            res.A[i][1] = min(A[arr.A[i][0]][1], arr.A[i][1]);
            res.A[i][2] = A[arr.A[i][0]][2] + arr.A[i][2];
        }

        return res;
    }

    // Usage Arr::power(arr,n);
    static Arr power(Arr &arr, ll n) {

    	// Here res initialised with given matrix. So raise to power k-1.
    	// Or adjust suitably as per requirements.
        Arr res; res.A = arr.A;

        while(n) {
            if(n%2) {
                res = res*arr;
            }
            arr = arr*arr;
            n /= 2;
        }

        return res;
    }
};
