class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        
        vector<string> str;
        vector<string> temp;
        string line;
        
        temp.push_back(words[0]);
        int sz = words[0].size();

        for(int i = 1; i<words.size(); i++){
            if(sz+1+words[i].size() > maxWidth){
                int baki = maxWidth - sz;
                if(temp.size() == 1){
                    line = temp.back();
                    for(int i = 1; i<=baki; i++)
                        line += " ";
                    str.push_back(line);
                }
                else{
                    int per = baki/(temp.size()-1);
                    int ex = baki % (temp.size()-1);
                    line = temp[0];
                    for(int i = 1; i<temp.size(); i++){
                        int space = 1;
                        space += per;
                        if(ex != 0){
                            space += 1;
                            ex--;
                        }
                        for(int j = 1; j<=space; j++)
                            line += " ";
                        line += temp[i];
                    }
                    str.push_back(line);
                }
                temp.clear();
                sz = words[i].size();
                temp.push_back(words[i]);
            }
            else{
                sz += words[i].size() + 1;
                temp.push_back(words[i]);
            }
            
        }
        line = temp[0];
        for(int i = 1; i<temp.size(); i++){
            line += " ";
            line += temp[i];
        }
        int baki = maxWidth - sz;
        for(int i = 1; i<=baki; i++)
            line += " ";
        
        str.push_back(line);
        return str;
        
    }
};
