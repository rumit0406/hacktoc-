class Solution {
public:
    bool isValid(string s) {
        stack<char> j;
        char x;
        int flag=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('||s[i]=='{'||s[i]=='['){
                j.push(s[i]);
                continue;
            }
            if(j.empty()){
                return false;
            }
            else{
                if(!j.empty()){
                if(s[i]==')'){
                    if(j.top()=='('){
                        j.pop();
                        continue;
                    }
                    else
                        break;
                }
                    if(s[i]=='}'){
                        if(j.top()=='{'){
                            j.pop();
                            continue;
                        }
                        else
                            break;
                    }
                    if(s[i]==']'){
                        if(j.top()=='['){
                            j.pop();
                            continue;
                        }
                        else
                            break;
                    }
                    
            }
                else
                    break;
        }}
        if(j.empty())
            return true;
        else
            return false;
    }
};
