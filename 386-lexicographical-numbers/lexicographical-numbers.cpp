class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<string>vec;
        for(int i=1;i<=n;i++){
            vec.push_back(to_string(i));
        }
        sort(vec.begin(),vec.end());
        vector<int>ans(n);
        for(int i=0;i<vec.size();i++){
            ans[i]=stoi(vec[i]);
        }
        return ans;
    }
};