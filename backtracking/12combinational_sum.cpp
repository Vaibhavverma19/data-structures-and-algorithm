

void solve(vector<int> &ARR, int B,vector<vector<int>>& ans,vector<int>& temp,int index)
{   if(B==0)
    { 
        ans.push_back(temp);
    }
    for(int i=index;i<ARR.size();++i)
    {
        if(B>=ARR[i])
        {
            temp.push_back(ARR[i]);
            solve(ARR,B-ARR[i],ans,temp,i);
            temp.pop_back();
        }
    }
}

vector<vector<int>> combSum(vector<int> &ARR, int B)
{  sort(ARR.begin(),ARR.end());
   vector<vector<int>> ans;
   vector<int> temp;
   solve(ARR,B,ans,temp,0);
   return ans;
}