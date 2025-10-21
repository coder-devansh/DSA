class Solution {
public:
void rotate(string&s,int k){
    reverse(s.begin(),s.begin()+k);
    reverse(s.begin()+k,s.end());
    reverse(s.begin(),s.end());
}
    string findLexSmallestString(string s, int a, int b) {
        set<string>visited;
        visited.insert(s);
        queue<string>q;
        q.push(s);
        string smallest_string=s;
        while(!q.empty()){
            string str=q.front();
            q.pop();
            if(str<smallest_string){
                smallest_string=str;
            }
            string temp=str;
            for(int i=1;i<str.size();i+=2){
                temp[i]=((temp[i]-'0'+a)%10)+'0';

            }
            if(visited.find(temp)==visited.end()){
                visited.insert(temp);
                q.push(temp);
            }
            rotate(str,b);
            if(visited.find(str)==visited.end()){
                visited.insert(str);
                q.push(str);
            }

        }
        return smallest_string;
        
    }
};