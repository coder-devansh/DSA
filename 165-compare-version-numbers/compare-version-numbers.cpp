class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i=0;
        int j=0;
       
        while(i<version1.size() && j<version2.size()){
            string str1="";
            string str2="";
            while(i<version1.size() && version1[i]!='.'){
                str1+=version1[i];
                i++;


            }
            while(j<version2.size() && version2[j]!='.'){
                str2+=version2[j];
                j++;
            }
            int val1=stoi(str1);
            int val2=stoi(str2);
            if(val1>val2)return 1;
            if(val1<val2)return -1;
            i++;
            j++;
        }
        while(i<version1.size()){
            string str="";
            while(i<version1.size() && version1[i]!='.'){
            str+=version1[i];
            i++;
            }
            if(str.size()==0)continue;
        int val=stoi(str);
        if(val>0)return 1;
        i++;
        }
        
        while(j<version2.size()){
            string str="";
            while(j<version2.size() && version2[j]!='.'){
            str+=version2[j];
            j++;
        }
        if(str.size()==0)continue;
        int val=stoi(str);
        if(val>0)return -1;
        j++;

        }
        return 0;
       
        
    }
};