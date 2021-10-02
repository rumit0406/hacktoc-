class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size();
        int m = dungeon[0].size();
        vector<vector<pair<int, int>>> ans(n, vector<pair<int,int>> (m, {0, 0}));
        //first int of pair will be min health reached till now and second is current health
        pair<int, int> current = {0, 0};
        
        //filling first row;
        for(int j=0; j<m; j++)
        {
            ans[0][j].second = current.second + dungeon[0][j];
            ans[0][j].first = min(current.first, ans[0][j].second);
            current = ans[0][j];
        }
        
        //filling first column
        current = {0,0};
        for(int i=0; i<n; i++)
        {
            ans[i][0].second = current.second + dungeon[i][0];
            ans[i][0].first = min(current.first, ans[i][0].second);
            current = ans[i][0];
        }
        
        for(int i=1; i<n; i++)
        {
            for(int j=1; j<m; j++)
            {
                pair<int, int> op1, op2;
                //op1 for top element op2 for left element
                op1.second = ans[i-1][j].second + dungeon[i][j];
                op1.first = min(ans[i-1][j].first, op1.second);
                
                op2.second = ans[i][j-1].second + dungeon[i][j];
                op2.first = min(ans[i][j-1].first, op2.second);
                if(i==n-1 and j==m-1){
                    cout<<op1.first<<"|"<<op1.second<<"\n";
                    cout<<op2.first<<"|"<<op2.second<<"\n";
                }
                
                if(op1.first == op2.first)  //min health reached is same so take the one with more current health
                {
                    if(op1.second >= op2.second)
                        ans[i][j] = op1;
                    else
                        ans[i][j] = op2;
                }
                else if(op1.first > op2.first)    //min health reached of op1 is less so take it.
                    ans[i][j] = op1;
                else
                    ans[i][j] = op2;
            }
        }
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
                cout<<ans[i][j].first<<"|"<<ans[i][j].second<<" ";
            cout<<"\n";
        }
        
        if(ans[n-1][m-1].first > 0)     //if min health reached is postive then that is ans else ans will be min health + 1 as it should not reach 0;
            return ans[n-1][m-1].first;
        return abs(ans[n-1][m-1].first) + 1;
    }
};
