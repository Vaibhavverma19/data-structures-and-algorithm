#include <bits/stdc++.h> 
/*
	This is signature of helper function 'knows'.
	You should not implement it, or speculate about its implementation.

	bool knows(int A, int B); 
	Function 'knows(A, B)' will returns "true" if the person having
	id 'A' know the person having id 'B' in the party, "false" otherwise.
*/

int findCelebrity(int n) {
	stack<int> st;
	for(int i=0;i<n;++i)
	{
		st.push(i);

	}

	//now we will elimate those who are definitely not celeb. that is for sure.
	//we dont know those are in stack at any point of time are celeb or not
	//but those who are not in stack are definitely not celeb.
	while(st.size()>1)
	{
		int a=st.top();
		st.pop();
		int b=st.top();
		st.pop();

		if(knows(a,b))
		{
			st.push(b);
		}else{
			st.push(a);
		}
	}
   int ideal=st.top();
	//now we have the all the non celeb out of the stack
	//check its credibility.
	for(int i=0;i<n;++i)
	{
        if(i!=ideal && (knows(i,ideal)!=true || knows(ideal,i)==true))
		{
			return -1;
		}
	}

	return ideal;

}