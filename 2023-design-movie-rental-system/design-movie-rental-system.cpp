struct entry {
    int shop;
    int movie;
    int price;
};

struct compare {
    bool operator()(const entry &a, const entry &b) const {
        if (a.price == b.price) {
            if (a.shop == b.shop)
                return a.movie < b.movie;
            return a.shop < b.shop;
        }
        return a.price < b.price;
    }
};

class MovieRentingSystem {
public:
    unordered_map<long long, entry> entry_map;   // quick access (shop,movie) → entry
    map<int, set<entry, compare>> for_search;    // movies → unrented shops
    set<entry, compare> rented;                  // rented entries
    set<entry, compare> unrented;                // all unrented entries

    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for (auto &it : entries) {
            entry e{it[0], it[1], it[2]};
            long long k = key(it[0], it[1]);
            entry_map[k] = e;
            unrented.insert(e);
            for_search[it[1]].insert(e);
        }
    }

    vector<int> search(int movie) {
        vector<int> ans;
        auto &it = for_search[movie];
        int limit = min(5, (int)it.size());
        int taken = 0;
        for (auto &ele : it) {
            if (taken == limit) break;
            ans.push_back(ele.shop);
            taken++;
        }
        return ans;
    }

    void rent(int shop, int movie) {
        long long k = key(shop, movie);
        entry e = entry_map[k];

        for_search[movie].erase(e);
        unrented.erase(e);
        rented.insert(e);
    }

    void drop(int shop, int movie) {
        long long k = key(shop, movie);
        entry e = entry_map[k];

        rented.erase(e);
        unrented.insert(e);
        for_search[movie].insert(e);
    }

    vector<vector<int>> report() {
        vector<vector<int>> ans;
        int limit = min(5, (int)rented.size());
        int taken = 0;
        for (auto &it : rented) {
            if (taken == limit) break;
            ans.push_back({it.shop, it.movie});
            taken++;
        }
        return ans;
    }

private:
    long long key(int shop, int movie) {
        return ((long long)shop << 32) | movie;
    }
};
