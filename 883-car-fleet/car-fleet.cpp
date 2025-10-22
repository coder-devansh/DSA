class Solution {
public:
static bool compare(const pair<int,int>&a,const pair<int,int>&b){
    return a.first>b.first;
}
double find_meet(double posA,double posB,double spA,double spB){
    if(spA <= spB) return -1; // will never meet
    double time = (posB - posA) / (spA - spB);
    return posA + spA * time;
}

double calculate(int p,int s,int target){
    double time=(target-p)/(double)s;
    return time;
}
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>>vec;
        for(int i=0;i<position.size();i++){
            vec.push_back({position[i],speed[i]});
        }
        stack<double>st;
        sort(vec.begin(),vec.end(),compare);
        for(int i=0;i<vec.size();i++){
            int posA=vec[i].first;
            int spA=vec[i].second;
            double time=calculate(vec[i].first,vec[i].second,target);
            if(!st.empty()){
                auto it=st.top();
                if (!st.empty() && time <= st.top());
                else st.push(time);
                
            }else{
                st.push(time);
            }
        }
        return st.size();

        
    }
};