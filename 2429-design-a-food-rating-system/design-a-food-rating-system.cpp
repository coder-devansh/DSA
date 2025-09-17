struct ITEM{
    int val;
    string food;
};
struct compare {
    bool operator()(const ITEM &a, const ITEM &b) const {
      if(a.val==b.val){
        string ele1=a.food;
        string ele2=b.food;
       return ele1>ele2;
      }
      return a.val<b.val;
    }
};
class FoodRatings {
public:
map<string,pair<string,int>>mp;
map<string, priority_queue<ITEM, vector<ITEM>, compare>> fd_cu;

   
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i=0;i<foods.size();i++){
            mp[foods[i]]={cuisines[i],ratings[i]};
            fd_cu[cuisines[i]].push({ratings[i],foods[i]});
        }
        

    }
    
    void changeRating(string food, int newRating) {
        if(mp.find(food)!=mp.end()){
            auto it=mp[food];
            string cuisine=it.first;
            mp[food]={cuisine,newRating};
            fd_cu[cuisine].push({newRating,food});
            
        }

        
    }
    
   string highestRated(string cuisine) {
        auto &pq = fd_cu[cuisine];
        while(!pq.empty()) {
            ITEM topItem = pq.top();
            if(mp[topItem.food].second == topItem.val)
                return topItem.food;
            pq.pop(); // remove stale
        }
        return "";
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */