class Solution {
public:
    int rotatedDigits(int n) {
        int count=0, number;
        bool changed;
        for(int i=1;i<=n;i++){
            number=i;
            changed=false;
            while(number > 0){
                if(number%10==2 || number%10==5 || number%10==6 || number%10==9){
                    changed=true;
                }
                else if(number%10!=0 && number%10!=1 && number%10!=8){
                    changed=false;
                    break;
                }
                number=number/10;
            }
            if(changed){
                count++;
            }
        }
        return count;
    }
};
