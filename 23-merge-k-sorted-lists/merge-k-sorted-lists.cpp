/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
void merge(vector<int>&arr,int low,int mid,int high){
    int i=low;
    int j=mid+1;
    int k=0;
    vector<int>ans(arr.size(),0);
    while(i<=mid && j<=high){
        if(arr[i]<=arr[j]){
            ans[k++]=arr[i++];

        }
        else{
            ans[k++]=arr[j++];
        }
    }
    while(i<=mid){
        ans[k++]=arr[i++];
    }
    while(j<=high){
        ans[k++]=arr[j++];
    }
    for(int i=low;i<=high;i++){
        arr[i]=ans[i-low];
    }
}
void mergesort(vector<int>&arr,int low,int high){
    if(low>=high){
        return;
    }
    int mid=(low+high)/2;
    mergesort(arr,low,mid);
    mergesort(arr,mid+1,high);

    merge(arr,low,mid,high);

}
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int>arr;
        for(auto it:lists){
            ListNode*temp=it;
            while(temp!=NULL){
                arr.push_back(temp->val);
                temp=temp->next;
            }
        }
        if(arr.size()==0) return NULL;
        mergesort(arr,0,arr.size()-1);
        ListNode*head=new ListNode(arr[0]);
        ListNode*temp=head;
        for(int i=1;i<arr.size();i++){
            ListNode*perm=new ListNode(arr[i]);
            temp->next=perm;
            temp=perm;
        }
        return head;
        
    }
};