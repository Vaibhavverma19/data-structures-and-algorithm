class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> tempList(wordList.begin(),wordList.end());
        queue<string> q;
        q.push(beginWord);
        if(tempList.find(beginWord)!=tempList.end())
        {
            tempList.erase(beginWord);
        }
        int ans=1;
        while(!q.empty())
        {
            int size=q.size();
            while(size)
            {
                string temp=q.front();
                q.pop();
                
                for(int i=0;i<temp.length();++i)
                {
                    char c=temp[i];
                    for(int j=0;j<26;++j)
                    {
                       temp[i]='a'+j;
                       if(tempList.find(temp)!=tempList.end())
                       {   if(temp==endWord)
                           { //we were about to enter out target word in queue but lets tackle it before only.
                               return ans+1;
                           }
                           q.push(temp);
                           tempList.erase(temp);
                       }
                    }
                    //yaha pe if temp=be in starting then it must me ze by now 
                    //so if we wan to change e in be then we first make temp asbe.
                    temp[i]=c;
                }
                size--;
            }
            ans++; //means one level of bfs completed.

        }
        return 0;
    }
};