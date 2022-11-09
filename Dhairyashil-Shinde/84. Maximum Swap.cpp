class Solution {
public:

    int maximumSwap(int num) {
        
        string str = to_string(num);
        int n = str.size();
        
        for(int i=0; i<n; i++) {
            char maxi = str[i];
            int max_idx = i;
            
            for(int j=i+1; j<n; j++) {

                if(str[j] >= maxi) {
                    maxi = str[j];
                    max_idx = j;
                }
            }
            
            if(maxi > str[i]) {
                swap(str[i], str[max_idx]);
                break;
            }
        }
        
        return stoi(str);
    }

    /*
    void solve (string &s) {

        char maxi = '0';
        int index = 0;

        bool flag = true;
        for(int i=0; i<s.size()-1; i++) {

            if(s[i] < s[i+1]) {
                flag = false;
            }
            
        }

        if(flag == true) return;

        for(int i=0; i<s.size(); i++) {
            if(s[i] > maxi) {
                maxi = s[i];
                index = i;
            }
            
        }
        cout << "maxi : " << maxi << endl;
        cout << "index : " << index << endl;

        string temp;

        for(int i=0; i<s.size(); i++) {

            if(s[i] != maxi) {
                s[index] = s[i];
                s[i] = maxi;
                break;
            }
            else if(s[i] == maxi) {

                temp = s.substr(i + 1);
                solve(temp);
                s = s.substr(0, i + 1);
                s.append(temp);
            }

        }

        
    }

    int maximumSwap(int num) {
        string s = to_string(num);
        solve(s);
        return stoi(s);
    }
    */
};
