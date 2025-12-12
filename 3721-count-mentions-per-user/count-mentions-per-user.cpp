class Solution {
public:
    static bool compare(vector<string>& a, vector<string>& b) {
        int t1 = stoi(a[1]);
        int t2 = stoi(b[1]);
        if (t1 == t2) {
            return a[0] > b[0];
        }
        return t1 < t2;
    }

    vector<int> countMentions(int no, vector<vector<string>>& events) {
        unordered_map<int,int> time;
        vector<int> mentions(no, 0);

        sort(events.begin(), events.end(), compare);

        for (auto &it : events) {
            string message = it[0];
            string timestamp = it[1];
            string message_id = it[2];
            int timeStamp = stoi(timestamp);

            // MESSAGE processing
            if (message == "MESSAGE") {

                // Case: MESSAGE HERE
                if (message_id == "HERE") {
                    for (int i = 0; i < no; i++) {

                        if (time.find(i) != time.end()) {
                            if (time[i] <= timeStamp) {
                                mentions[i]++; // fixed: removed ans[]
                            } 
                            // else do nothing (user still offline)
                        } 
                        else {
                            mentions[i]++; // user never went offline
                        }
                    }
                    continue;
                }

                // Case: MESSAGE ALL
                if (message_id == "ALL") {
                    for (int i = 0; i < no; i++) {
                        mentions[i]++;
                    }
                    continue;
                }

                // Case: MESSAGE <list of users>
                int n = message_id.size();
                int i = 0;

                while (i < n) {

                    // skip any letters
                    while (i < n && (message_id[i] >= 'a' && message_id[i] <= 'z')) {
                        i++;
                    }

                    // extract number
                    string str = "";
                    while (i < n && (message_id[i] >= '0' && message_id[i] <= '9')) {
                        str += message_id[i];
                        i++;
                    }

                    if (!str.empty()) {
                        int id = stoi(str);
                        mentions[id]++;
                    }

                    i++;
                }
            }

            // OFFLINE processing
            if (message == "OFFLINE") {
                int id = stoi(message_id);
                time[id] = timeStamp + 60; // your logic kept
            }
        }

        return mentions;
    }
};
