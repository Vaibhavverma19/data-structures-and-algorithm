int romanToInt(string s) {
    vector<pair<char,pair<int,int>> > data;
    // data.push_back({'I',{1,1}});
    // data.push_back({'V',{5,2}});
    // data.push_back({'X',{10,3}});
    // data.push_back({'L',{50,4}});
    // data.push_back({'C',{100,5}});
    // data.push_back({'D',{500,6}});
    // data.push_back({'M',{1000,7}});

    unordered_map<char,int> value;
    value['I']=1;
    value['V']=5;
    value['X']=10;
    value['L']=50;
    value['C']=100;
    value['D']=500;
    value['M']=1000;

    int digit=value[s[0]];
    for(int i=1;i<s.length();++i)
    {
        if(value[s[i]]<=value[s[i-1]])
        {
            digit+=value[s[i]];
        }else{
            digit-=value[s[i-1]];
            digit+=value[s[i]]-value[s[i-1]];
        }
    }

    return digit;
}