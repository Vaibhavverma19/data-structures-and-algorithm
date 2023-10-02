vector < vector < int > > nearest(vector < vector < int >> & mat, int n, int m) {
    vector<vector<int> > dist(n,vector<int>(m,0));
    vector<vector<int> > vis(n,vector<int>(m,0));

    queue<pair<pair<int,int>,int> > q;

    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            if(mat[i][j]==1)
            {
                q.push({{i,j},0});
                vis[i][j]=1;
            }
        }
    }

    while(!q.empty())
    {
        int size=q.size();
        while(size--)
        {
            auto temp=q.front();
            q.pop();
            int i=temp.first.first;
            int j=temp.first.second;
            int d=temp.second;
            dist[i][j]=d;

            //up
            if(i-1>=0 && mat[i-1][j]!=1 && vis[i-1][j]!=1)
            {
                q.push({{i-1,j},d+1});
                vis[i-1][j]=1;
            }

            //down
            if(i+1<=n-1 && mat[i+1][j]!=1 && vis[i+1][j]!=1)
            {
                q.push({{i+1,j},d+1});
                vis[i+1][j]=1;
            }

            //left
            if(j-1>=0 && mat[i][j-1]!=1 && vis[i][j-1]!=1)
            {
                 q.push({{i,j-1},d+1});
                vis[i][j-1]=1;
            }

            //right
            if(j+1<=m-1 && mat[i][j+1]!=1 && vis[i][j+1]!=1)
            {
                 q.push({{i,j+1},d+1});
                vis[i][j+1]=1;
            }


        }
    }

    return dist;
}