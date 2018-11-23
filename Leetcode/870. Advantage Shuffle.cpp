class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        
        multiset<int> s;
        vector<int> res;
        for(int i = 0; i<A.size(); i++){
            s.insert(A[i]);
        }
        
        for(int i = 0; i<B.size(); i++){
            auto it = s.upper_bound(B[i]);
            int temp;
            if(it != s.end()){
                temp = *(it);
                s.erase(it);
            }
            else{
                temp = *(s.begin());
                s.erase(s.begin());
            }
            res.push_back(temp);
        }
        return res;
        
    }
};
