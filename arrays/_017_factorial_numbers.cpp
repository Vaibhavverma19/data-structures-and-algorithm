void Multiply(vector<int> &arr,int i){

        int n = arr.size();

        int rem = 0;

        int curr;

        for(int it = 0; it<n; it++)

        {

            curr = arr[it]*i;

            curr += rem;

            arr[it] = curr%10;

            rem = curr/10;

        }

        while(rem>0){

            arr.push_back(rem%10);

            rem = rem/10;

        }

    }

string calculateFactorial(int n)

{

    //    Write your code here.

    vector<int> ans;

        

        ans.push_back(1);

        

        for(int i = 2; i <= n; i++){

            Multiply(ans,i);

        }

    

    reverse(ans.begin(),ans.end());

      string s="";

      for(int i=0;i<ans.size();i++){

          

          s.push_back(char(ans[i]+'0'));

      }

      return s;

}