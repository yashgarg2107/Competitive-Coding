// Implementaton of binary trie (used for xor applications mainly). 
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