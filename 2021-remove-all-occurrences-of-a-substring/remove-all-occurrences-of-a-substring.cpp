class Solution {
public:
    string removeOccurrences(string s, string part) {
       
        while(s.find(part) != std::string::npos){
           int pos=s.find(part);
           s.erase(pos,part.size());
           cout<<s<<endl;


        }
        return s;
    }
        
};