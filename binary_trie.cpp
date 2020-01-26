// Implementaton of binary trie (used for xor applications mainly). 

// Arrays based implementation.
// Here size of this array is Max number of nodes * Alphabet size.
// Will work for numbers till 2^30.

// Intialise with:
// memset(trie, 0, sizeof(trie));
// memset(vals, 0, sizeof(vals));
ll trie[3200000][2], vals[3200000];
ll counter = 1;

void add_bin(ll val) {
    ll curr = 1;
    for(ll i=30;i>=0;i--) {
        vals[curr] += 1;
        ll c = !!((1<<i)&val);
        if(!trie[curr][c]) trie[curr][c] = ++counter;
        curr = trie[curr][c];
    }
    vals[curr] += 1;
}

void rem_bin(ll val) {
    ll curr = 1;
    for(ll i=30;i>=0;i--) {
        vals[curr] -= 1;
        ll c = !!((1<<i)&val);
        curr = trie[curr][c];
    }
    vals[curr] -= 1;
}

ll count_bin(ll val) {
    ll curr = 1;
    for(ll i=30;i>=0;i--) {
        ll c = !!((1<<i)&val);
        curr = trie[curr][c];
    }
    return vals[curr];
}


// Node tree based implementation.
// Use C++11 for correct node and pointer behaviour.
struct node {
    ll bit;
    node* c0;
    node* c1;
    node* par;
    ll val;

    node() {
        c0 = NULL;
        c1 = NULL;
        val = 0;
    }
};

void add_bin(node *root, ll val) {
    node* curr = root;
    ll i = 30;

    while(i>=0) {
        if((1<<i)&val) {
            if(curr->c1==NULL) {
                curr->c1 = new node();
                curr->c1->par = curr;
            }
            curr = curr->c1;
        }
        else {
            if(curr->c0==NULL) {
                curr->c0 = new node();
                curr->c0->par = curr;
            } 
            curr = curr->c0;
        } 
        i--;
    }

    while(curr) {
        curr->val += 1;
        curr = curr->par;
    }
}

void rem_bin(node *root, ll val) {
    node* curr = root;
    ll i = 30;

    while(i>=0) {
        curr->val -= 1;
        if((1<<i)&val) {
            curr = curr->c1;
        }
        else {
            curr = curr->c0;
        } 
        i--;
    }
    curr->val-=1;
}

ll count_bin(node *root, ll val) {
    node* curr = root;
    ll i = 30;

    while(i>=0) {
        curr->val -= 1;
        if((1<<i)&val) {
            curr = curr->c1;
        }
        else {
            curr = curr->c0;
        } 
        i--;
        if(!curr) return 0;
    }
    return curr->val;
}