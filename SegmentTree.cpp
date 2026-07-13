#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
const int N = 2e5+5;

// Segment Tree Node structure to track maximum subarray sum properties
struct Node {
    ll sum;  // Total sum of the current segment
    ll pref; // Maximum prefix sum in the current segment
    ll suff; // Maximum suffix sum in the current segment
    ll ans;  // Maximum subarray sum overall in the current segment
    // ans -> (pref & suff) -> ans
};

// tree array size is 4*N to accommodate the binary tree nodes safely
Node tree[4*N];
int a[N];

// Merges two child nodes (left and right) into a parent node
Node combine(Node l, Node r) {
    Node res;
    // 1.Total sum is simply the sum of both halves
    res.sum = l.sum + r.sum;
    
    // 2.Max prefix is either in the left child or extends into the right child.
    res.pref = max(l.pref, l.sum + r.pref);
    
    // 3.Max suffix is either in the right child or extends into the left child.
    res.suff = max(r.suff, r.sum + l.suff);
    
    // 4.Max subarray sum could be entirely in the left child, entirely in the right child,
    //    or bridge across the middle (left's suffix + right's prefix)
    res.ans = max({l.ans, r.ans, l.suff + r.pref});
    
    return res;
}

// Builds the Segment Tree
void build(int node, int st, int en) {
    // Base Case: Leaf node (covers a single element)
    if (st == en) {
        // Values are forced to be >= 0 (empty subarray gives sum 0)
        tree[node] = {(ll)a[st], max(0LL,(ll)a[st]),
                     max(0LL,(ll)a[st]), max(0LL,(ll)a[st])};
        return;
    }
    
    int mid = (st + en) / 2;
    build(2*node, st, mid);     // Build left child
    build(2*node+1, mid+1, en); // Build right child
    
    // ***Merge child results into the parent node***
    tree[node] = combine(tree[2*node], tree[2*node+1]);
}

// Updates an element at a specific index in O(log N) time
void update(int node, int st, int en, int idx, int val) {
    // Base Case: Reached the exact leaf node to update
    if (st == en) {
        a[st] = val; // Update the original array
        tree[node] = {(ll)val, max(0LL,(ll)val),
                     max(0LL,(ll)val), max(0LL,(ll)val)};
        return;
    }

    int mid = (st + en) / 2;
    // Decide whether to go down the left or right subtree
    if (idx <= mid)
        update(2*node, st, mid, idx, val);
    else
        update(2*node + 1, mid + 1, en, idx, val);
        
    // Recalculate parent values up the tree after the update
    tree[node] = combine(tree[2*node], tree[2*node + 1]);
}

// Queries a range [l, r] to find its Maximum Subarray Sum in O(log N) time
Node Query(int node, int st, int en, int l, int r) {
    // Case 1: Completely Out of Bounds (No overlap)
    if (st > r || en < l) {
        return {0, 0, 0, 0}; // Return neutral identity element
    }
    
    // Case 2: Completely In Bounds (Total overlap)
    if (l <= st && en <= r) {
        return tree[node];
    }
    
    // Case 3: Partial Overlap (Split query down both children)
    int mid = (st + en) / 2;
    return combine(Query(2*node, st, mid, l, r), 
                   Query(2*node + 1, mid + 1, en, l, r));
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, q;
    if (cin >> n >> q){
        for (int i = 0; i < n; ++i){
            cin>>a[i];
        }
        // Construct the initial segment tree
        build(1, 0, n-1);

        for (int i = 0; i < q; ++i){
            int k, x;
            cin>>k>>x;
            k--;
            
            // Apply the update
            update(1, 0, n-1, k, x);

            // Fetch the maximum subarray sum for the entire array [0, n-1]
            Node qRes = Query(1, 0, n-1, 0, n-1);
            cout<<qRes.ans<<endl;
        }
    }
    return 0;
}