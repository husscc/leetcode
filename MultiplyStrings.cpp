/*
Given two numbers represented as strings, return multiplication of the numbers as a string.

Note: The numbers can be arbitrarily large and are non-negative.
*/
class Solution {
    inline string addStr(string s1,string s2){
    	if(s1.size()==0||(s1.size()==1&&!s1[0]))
			return s2;
		else if(s2.size()==0||(s2.size()==1&&!s2[0]))
			return s1;
		
		int adv=0,p1,p2,tmp;
		string res;
		if(s1.size()>s2.size()){
			res=s1;
			s1=s2;
			s2=res;
		}
		res="";
		for(p1=0,p2=0;p1<s1.size();p1++,p2++){
			tmp=(int)(s1[p1]-'0')+(int)(s2[p2]-'0')+adv;
			res+=(char)('0'+tmp%10);
			adv=tmp/10;
		}
		
		for(;p2<s2.size();p2++){
			if(!adv)
				res+=s2[p2];
			else{
				tmp=(int)(s2[p2]-'0')+adv;
				res+=(char)('0'+tmp%10);
				adv=tmp/10;
			}
		}
		
		if(adv)
			res+='1';
		return res;
	}
public:
    string multiply(string num1, string num2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		assert(num1.size()!=0&&num2.size()!=0);
        if((num1.size()==1&&num1[0]=='0')||(num2.size()==1&&num2[0]=='0'))
			return "0";
		        
		string str="",str1;
		int adv=0,tmp;
		for(int i=num1.size()-1;i>=0;i--){
			if(num1[i]!='0'){
				str1="";adv=0;
				for(int j=num1.size()-1;j>i;j--)	
					str1+='0';
				for(int j=num2.size()-1;j>=0;j--){
					tmp=(int)(num1[i]-'0')*(int)(num2[j]-'0')+adv;
					str1+=(char)('0'+tmp%10);
					adv=tmp/10;
				}
				while(adv){
					str1+=(char)('0'+adv%10);
					adv/=10;
				}
				str=addStr(str,str1);
			}
		}
		for(int i=0,j=str.size()-1;i<j;i++,j--){	// reverse the result array;
			str[i]^=str[j];
			str[j]^=str[i];
			str[i]^=str[j];
		}
		return str;
    }
};