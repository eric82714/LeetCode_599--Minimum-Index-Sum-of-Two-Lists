class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        vector<string> result;
        int least = list1.size() + list2.size();
        
        for(int i = 0; i < list1.size(); i++) {
            for(int j = 0; j < list2.size(); j++) {
                if(list1[i] == list2[j] && (i+j) == least)
                    result.push_back(list1[i]);
                if(list1[i] == list2[j] && (i+j) < least) {
                    result.clear();
                    result.push_back(list1[i]);
                    least = i + j;
                }
            }
        }
                
        return result;
    }
};
