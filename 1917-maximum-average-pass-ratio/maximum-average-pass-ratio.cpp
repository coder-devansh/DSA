class Solution {
public:
double calculateGain(int pass,int total_student){
    return (double)(pass+1)/(total_student+1)-(double)pass/total_student;
}
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<double,pair<int,int>>>pq;
        for(auto it:classes){
            double value=calculateGain(it[0],it[1]);
            pq.push({value,{it[0],it[1]}});

        }
        while(extraStudents){
            auto it=pq.top();
            pq.pop();
            int pass_student=it.second.first;
            int total_student=it.second.second;
            double ratio=calculateGain(pass_student+1,total_student+1);

            pq.push({ratio,{pass_student+1,total_student+1}});
            extraStudents--;

        }
        double average_ratio=0;
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
           average_ratio+=((double)it.second.first)/(it.second.second);
            

        }
        average_ratio=average_ratio/classes.size();
        return average_ratio;
        
        
    }
};