class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes,
                                  vector<vector<string>>& ingredients,
                                  vector<string>& supplies) {
        unordered_set<string> is_available(supplies.begin(), supplies.end());
        vector<string> result; 
        bool flag1 = true;

        while (flag1) {
            flag1 = false;

            for (int i = 0; i < recipes.size(); ++i) {
                if (is_available.count(recipes[i]))
                    continue;

                bool flag2 = true;
                for (const string& ing : ingredients[i]) {
                    if (!is_available.count(ing)) {
                        flag2 = false;
                        break;
                    }
                }

                if (flag2) {
                    is_available.insert(recipes[i]);
                    result.push_back(recipes[i]);
                    flag1 = true;
                }
            }
        }

        return result;
    }
};