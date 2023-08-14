#include<algorithm>
#include<bits/stdc++.h>
bool cmp(vector<int>& a,vector<int>& b)
{
  return a[2]<b[2];
}
void makeset(vector<int>& parent,vector<int>& rank,int n)
{
  for(int i=0;i<n;++i)
  {
    parent[i]=i;
    rank[i]=0;
  }
}
int findparent(vector<int>& parent,int node)
{
  if(parent[node]==node)
    return node;
   
  return parent[node]=findparent(parent,parent[node]); //path compression 
  //for eg 4 <- 6 <- 7 so if we find parent of 7 it will find parent of 6 first and then parent of 4 and then while returning it will
  //set each child's parent as ultimate parent that is 4.
  //so next time if we want to know the parent of 7 it will simply return 4.
}
void unionset(int u,int v,vector<int> & parent,vector<int>& rank)
{
  int p1=findparent(parent,u);
  int p2=findparent(parent,v);
  if(rank[p1]<rank[p2])
  {
    parent[p1]=p2;
  }
  else{
    if(rank[p2]<rank[p1])
    {
      parent[p2]=p1; //here we merge shorter tree into larger tree so that height of the longer tree remain same.
    }
    else{
      parent[p2]=p1;
      rank[p1]++;
    }
  }
}
int minimumSpanningTree(vector<vector<int>>& edges, int n)
{   int ans=0;
    sort(edges.begin(),edges.end(),cmp);
    vector<int> parent(n);
    vector<int> rank(n);
    makeset(parent,rank,n);
    for(int i=0;i<edges.size();++i)
    {
      int u=edges[i][0];
      int v=edges[i][1];
      int wt=edges[i][2];
      int p1=findparent(parent,u);
      int p2=findparent(parent,v);
      if(p1!=p2)
      { ans+=wt;
        unionset(p1,p2,parent,rank);
      }

    }

    return ans;


}