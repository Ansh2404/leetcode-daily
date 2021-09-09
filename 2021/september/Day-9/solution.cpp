class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        vector<vector<int>> u(n,vector<int>(n,1)),d(n,vector<int>(n,1)),l(n,vector<int>(n,1)),r(n,vector<int>(n,1)),o(n,vector<int>(n,1));
        for(int i=0;i<mines.size();i++)
        {
            o[mines[i][0]][mines[i][1]]=0;
            u[mines[i][0]][mines[i][1]]=0; //up
            d[mines[i][0]][mines[i][1]]=0; //down
            l[mines[i][0]][mines[i][1]]=0; //left
            r[mines[i][0]][mines[i][1]]=0; //right
        }
        // for(int i=0;i<n;i++)
        // {
        //     for(int j=0;j<n;j++)
        //     {
        //         cout<<o[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(o[i][j]==1) u[i][j]+=u[i-1][j];
                else u[i][j] = 0;
                // cout<<u[i][j]<<" ";
            }
            // cout<<endl;
        }
        for(int i=n-2;i>=0;i--)
        {
            for(int j=0;j<n;j++)
            {
                if(o[i][j]==1) d[i][j]+=d[i+1][j];
                else d[i][j] = 0;
                // cout<<d[i][j]<<" ";
            }
            // cout<<endl;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<n;j++)
            {
                if(o[i][j]==1) l[i][j]+=l[i][j-1];
                else l[i][j] = 0;
                // cout<<l[i][j]<<" ";
            }
            // cout<<endl;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=n-2;j>=0;j--)
            {
                if(o[i][j]==1) r[i][j]+=r[i][j+1];
                else r[i][j] = 0;
                // cout<<r[i][j]<<" ";
            }
            // cout<<endl;
        }
        int ans=-1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(o[i][j]==1)
                ans=max(ans,min(u[i][j],min(d[i][j],min(l[i][j],r[i][j]))));
            }
        }
        if(ans==-1)
        {
            return 0;
        }
        return ans;
    }
};
