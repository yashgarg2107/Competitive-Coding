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