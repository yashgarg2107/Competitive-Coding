// Ternary search implementations for unimodal functions.

void ternary_valley() {
    double eps = 1e-25;  
    double l = -1e9, r = 1e9;  // Adjust suitably.
    ll count  = 0;    

    auto find = [&](double mid) {
        // Find function at mid.
        return ans;
    };

    while (r - l > eps && count<min(10000LL,((ll)1e8/n)) ){
        double m1 = l + (r - l) / 3;
        double m2 = r - (r - l) / 3;

        double f1 = find(m1);
        double f2 = find(m2);
        
        if (f1 < f2)
            r = m2;
        else
            l = m1;
        count++;
    }

    printf("%.10f\n", find(l));
}


void ternary_mountain() {
    double eps = 1e-25;  
    double l = -1e9, r = 1e9;  // Adjust suitably.
    ll count  = 0;    

    auto find = [&](double mid) {
        // Find function at mid.
        return ans;
    };

    while (r - l > eps && count<min(10000LL,((ll)1e8/n)) ){
        double m1 = l + (r - l) / 3;
        double m2 = r - (r - l) / 3;

        double f1 = find(m1);
        double f2 = find(m2);
        
        if (f1 < f2)
            l = m1;
        else
            r = m2;
        count++;
    }

    printf("%.10f\n", find(l));
}