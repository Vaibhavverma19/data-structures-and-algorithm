class SpecialStack {
    int minEl=INT_MAX;
    stack<int> st;
    public:
        
    void push(int data) {
        if(st.empty())
        {
            st.push(data);
            minEl=data;
        }else{
            if(data>=minEl)
            {
                st.push(data);
            }else{
                int temp=2*data-minEl;
                minEl=data;
                st.push(temp);
            }
        }
    }

    void pop() {
        if(st.empty())
        return;
       int t=st.top();
       
           st.pop();
       
       if(t<minEl){ 
        
       
        minEl=2*minEl-t;
        // cout<<"after popping"<<t<<" new minEl is "<<minEl;

       }
    }

    int top() {

        if(st.empty())
        return -1;
        if(st.top()<minEl)
        {
            return minEl;
        }

        return st.top();
    }

    int getMin() {
        if(st.empty())
        return -1;

        return minEl;
    }  
};