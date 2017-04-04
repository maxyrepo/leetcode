class Solution {
    public:
        vector<string> generateParenthesis(int n) {
            vector<string> vec;
            Recursion(vec,"",0,n,n);
            return vec;
        }

        void Recursion(vector<string> &vec,string str,int counter,int left,int right){
            if(counter < 0)return;
            if(left == 0 && right == 0) {
                vec.push_back(str);
                return;
            }
            if(left){
                Recursion(vec,str + "(" ,counter + 1,left -1 ,right);
            }
            if(right){
                Recursion(vec,str + ")" ,counter - 1,left,right - 1);
            }
        }
};
