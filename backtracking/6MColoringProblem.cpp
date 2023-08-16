#include<bits/stdc++.h>
bool issafe(int color,int node,vector<vector<int>> &mat,map<int,int>& thisNodeColor)
{
    for(int i=0;i<mat.size();++i)
    {   if(mat[node][i]==1)
        {
            if(thisNodeColor[i]==color)
            {
                return false;
            }

        }
    }

    return true;
}
bool solve(vector<vector<int>> &mat, int m,map<int,int>& thisNodeColor,int node)
{     if(node==mat.size())
         return true;
    
        for(int color=1;color<=m;++color)
        {
             if(issafe(color,node,mat,thisNodeColor))
             {   thisNodeColor[node]=color;
                 bool ans=solve(mat,m,thisNodeColor,node+1);
                 if(ans)
                 {
                     return true;
                 }
                 thisNodeColor[node]=0;
             }
        }

        return false;
    
}
string graphColoring(vector<vector<int>> &mat, int m) {
    map<int,int> thisNodeColor;
    for(int i=0;i<mat.size();++i)
    {
        thisNodeColor[i]=0;
    }
    bool gotIt=solve(mat,m,thisNodeColor,0);
    if(gotIt)
    return "YES";
    
    return "NO";
}