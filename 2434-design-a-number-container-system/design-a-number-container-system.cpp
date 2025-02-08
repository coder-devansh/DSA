class NumberContainers {
public:
map<int ,long long >mp;
map<int,set<int>>first;
   
    NumberContainers() {



        
    }
    
    void change(int index, int number) {
        int i=1;
        while(i<index){
            i++;
        }
       if(mp.find(i)==mp.end() || mp[i]!=number){

        first[mp[i]].erase(i);
       
         mp[i]=number;
        first[number].insert(i);

       }
       
        
    }
    
    int find(int number) {
        if(first.find(number)!=first.end()){
            if(first[number].empty()){
                return -1;
            }
            return *first[number].begin();
        }
        return -1;
        
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */