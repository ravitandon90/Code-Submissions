class Solution {
public:
    string reformatNumber(string number) {
        string p;
        int n=number.length(),m=0;
        for(int i=0;i<n;i++){
            
            if(number[i]!=' ' && number[i]!='-'){
                if(m>0 && m%3==0)
                p+='-';
                p+=number[i];
                m++;
            }
        }
      int s=p.length();
        if(p[s-2]=='-'){
            swap(p[s-3],p[s-2]);
        }
        return p;
        
    }
};
