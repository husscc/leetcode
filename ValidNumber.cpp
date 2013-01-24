/*
Validate if a given string is numeric.

Some examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true
Note: It is intended for the problem statement to be ambiguous. 
You should gather all requirements up front before implementing one.
*/
class Solution {
public:
    bool isNumber(const char *s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len=strlen(s);
    	
		//remove extra space
		int i;
		for(i=0;i<len;i++){
			if(s[i]!=' ')
				break;
		}
		
		if(i==len)
			return false;
		
		
		if(s[i]=='+'||s[i]=='-')
			i++;
		
		bool hasE=false,hasDot=false,hasNumber=false;
		for(;i<len;i++){
			if(isdigit(s[i]))
				hasNumber=true;
			else if(s[i]=='e'||s[i]=='E'){
				hasE=true;
				break;
			}
			else if(s[i]=='.'&&!hasDot)
				hasDot=true;
			else if(s[i]==' '){
				//remove extra space
				do{
					i++;
				}while(s[i]==' '&&i<len);
				if(i!=len)
					break;
			}
			else
				break;
		}
		
		if(i<len){
			if(hasE&&hasNumber){
				hasNumber=false;
				i++;
				
                if((i<len)&&(s[i]=='+'||s[i]=='-'))
                    i++;
                
				for(;i<len;i++){
					if(isdigit(s[i]))
						hasNumber=true;
					else if(s[i]==' '){
						//remove extra space
						do{
							i++;
						}while(s[i]==' '&&i<len);
						if(i!=len)
							break;
					}
					else
						break;
				}
				
				if(!hasNumber||i<len)
					return false;
				else 
					return true;
			}
			else
				return false;
		}
		else if(hasNumber)
			return true;
		else 
			return false;
    }
};