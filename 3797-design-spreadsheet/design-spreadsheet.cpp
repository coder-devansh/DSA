class Spreadsheet {
public:
vector<vector<int>>alpha;
    Spreadsheet(int rows) {
        alpha.resize(rows+1,vector<int>(26+1,0));
        
    }
    
    void setCell(string cell, int value) {
       char ch=cell[0];
         string str="";
         for(int i=1;i<cell.size();i++){
            str+=cell[i];
         }
         int val=stoi(str);
         alpha[val][ch-'A']=value;

        
    }
    
    void resetCell(string cell) {
         char ch=cell[0];
         string str="";
         for(int i=1;i<cell.size();i++){
            str+=cell[i];
         }
         int val=stoi(str);
         alpha[val][ch-'A']=0;
        
    }
    
    int getValue(string formula) {
        string str="";
        for(int i=0;i<formula.size();i++){
            if(formula[i]!='='){
                str+=formula[i];
            }
        }
        formula=str;
        int sum=0;
        for(int i=0;i<formula.size();){
            char ch=formula[i];
            if(isalpha(formula[i])){
                i++;
                string str="";
                while(i<formula.size() && isdigit(formula[i])){
                    str+=formula[i];
                    i++;
                }
                int val=stoi(str);
                sum+=alpha[val][ch-'A'];
                cout<<alpha[val][ch-'A'];
                continue;
            }
            if(isdigit(ch))
            {
                string str="";
                 while(i<formula.size() && isdigit(formula[i])){
                    str+=formula[i];
                    i++;
                 }
                 if(str[0]=='0'){
                    sum+=0;
                 }else{
                    sum+=stoi(str);

                 }
                 continue;
                 
            }

            
           
            i++;

        }
        return sum;
        
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */