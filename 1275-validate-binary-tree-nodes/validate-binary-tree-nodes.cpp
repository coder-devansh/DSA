class Solution {
public:

    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        if(n==1){
            if(leftChild[0]==-1 && rightChild[0]==-1)return true;
        }
        if(n==1)return false;
        vector<vector<int>>adj(n+1);
        vector<int>indegree(n,0);
        for(int i=0;i<n;i++){
            if(leftChild[i]!=-1){
                indegree[leftChild[i]]++;
                 if(indegree[leftChild[i]]>1)return false;
                adj[i].push_back(leftChild[i]);
            }
            if(rightChild[i]!=-1){
                indegree[rightChild[i]]++;
                if(indegree[rightChild[i]]>1)return false;
                adj[i].push_back(rightChild[i]);
            }
        }
        int root=-1;
        queue<int>q;
        for(int i=0;i<indegree.size();i++){
            if(indegree[i]==0){
                q.push(i);
                if(root!=-1)return false;
                root=i;
            }
        }
        int cnt=1;
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            for(auto it:adj[it]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                    cnt++;
                }
            }
        }
        if(cnt==n)return true;
        return false;

        
    }
};