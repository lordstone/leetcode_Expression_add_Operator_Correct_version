class Solution {
public:

    vector<string> myarr;

    string inttostr(int tmp){
        string mystr = "";
        bool sign = tmp < 0;
        int mytmp = tmp;
        if(mytmp == 0) return "0";
        while(mytmp > 0 ){
            int digit = mytmp % 10;
            mystr.insert(0,1,(char) ('0' + digit) );
            mytmp /= 10;
        }
        if(sign) mystr.insert(0,1,'-');
        return mystr;
    }

    vector<string> addOperators(string num, int target) {
        
         if(target >= INT_MAX || target <= INT_MIN){
             int mynum = atoi(num.c_str());
             vector<string> arr;
             if((target) <= INT_MAX && target >= INT_MIN){
                if(inttostr(target) == num)
                    arr.push_back(num);
                
             }
             return arr;
         }
        
         mysearch(num, target, "", 0, 0);
         
         return myarr;
         
    }
    
    void mysearch(string num, int target, string tmp, int curr, int prev){
        
        if(num.length() == 0 && curr == target){
            
            myarr.push_back(tmp);
            
            return;
            
        }//if finished and results match
        
        for(int i = 1; i <= num.length() ; i ++){
            
            if(num[0] == '0' && (i > 1)) return; //no 0 before another number allowed
            
            int firstNum = atoi(num.substr(0, i).c_str());
            
            string second = num.substr(i);
            
            if(tmp.length() > 0){
                
                mysearch(second, target, tmp + "*" + inttostr(firstNum), (curr - prev) + prev * firstNum,  prev * firstNum ); //multiplication
                
                mysearch(second, target, tmp + "+" + inttostr(firstNum), firstNum + curr, firstNum ); // addition
                
                mysearch(second, target, tmp + "-" + inttostr(firstNum), curr - firstNum, -firstNum ); // substraction
                
            }else{
                
                mysearch(second, target, num.substr(0, i).c_str(),  firstNum, firstNum );
                
            }

            
        }
        
    }
};
