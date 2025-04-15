struct SegmentTree {
    int n;
    vector<int> tree;

    SegmentTree(int size) : n(size), tree(4 * size, 0) {}

    void update(int idx, int l, int r, int pos, int val) {
        if (l == r) {
            tree[idx] += val;
            return;
        }
        int mid = (l + r) / 2;
        if (pos <= mid)
            update(2 * idx, l, mid, pos, val);
        else
            update(2 * idx + 1, mid + 1, r, pos, val);
        tree[idx] = tree[2 * idx] + tree[2 * idx + 1];
    }

    int query(int idx, int l, int r, int ql, int qr) {
        if (qr < l || r < ql) return 0;
        if (ql <= l && r <= qr) return tree[idx];
        int mid = (l + r) / 2;
        return query(2 * idx, l, mid, ql, qr) +
               query(2 * idx + 1, mid + 1, r, ql, qr);
    }

    void add(int pos, int val) {
        update(1, 0, n - 1, pos, val);
    }

    int sum(int pos) {
        return query(1, 0, n - 1, 0, pos);
    }
};
class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        vector<int> a(n),b(n);
        for(int i=0;i<n;++i) a[nums2[i]]=i;
        for(int i=0;i<n;++i) b[a[nums1[i]]]=i;
        long long ans=0;
        SegmentTree tree(n);
        for(int i=0;i<n;++i){
            int pos=b[i];
            long long l=tree.sum(pos);
            tree.add(pos,1);
            long long r=(n-pos-1)-(i-l);
            ans+= l*r;
        }
        return ans;
    }
};