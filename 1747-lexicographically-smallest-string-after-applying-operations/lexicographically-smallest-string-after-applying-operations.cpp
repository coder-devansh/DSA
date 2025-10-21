class Solution {
public:
void rotate(string&s,int k){
    reverse(s.begin(),s.begin()+k);
    reverse(s.begin()+k,s.end());
    reverse(s.begin(),s.end());
}
 set<string>visited;
void find_smallest(string str,string &smallest_string,int a,int b){
     if(str<smallest_string){
                smallest_string=str;
    }
            string temp=str;
            for(int i=1;i<str.size();i+=2){
                temp[i]=((temp[i]-'0'+a)%10)+'0';

            }
            if(visited.find(temp)==visited.end()){
                visited.insert(temp);
                find_smallest(temp,smallest_string,a,b);
            }
            rotate(str,b);
            if(visited.find(str)==visited.end()){
                visited.insert(str);
                find_smallest(str,smallest_string,a,b);
            }



}
    string findLexSmallestString(string s, int a, int b) {
       
        visited.insert(s);
        queue<string>q;
        q.push(s);
        string smallest_string=s;
        find_smallest(s,smallest_string,a,b);
        return smallest_string;
        
    }
};