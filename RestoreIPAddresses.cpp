/*
Given a string containing only digits, restore it by returning all possible valid IP address combinations.

For example:
Given "25525511135",

return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)
*/
class Solution {

    inline bool lessThan255(string s){
    	int len=s.size();
		if(len>3)
			return false;
		else if(len<3)
			return true;
		else 
			return (s[0]-'2')*100+(s[1]-'5')*10+(s[2]-'5')<=0;
	}
	
    void createIpAddr(string cr,string remain,int section,vector<string> &res){
		int len=remain.size();
    	if(section==4){
			if((remain[0]=='0'&&len==1)||(len>0&&remain[0]!='0'&&lessThan255(remain)))
				res.push_back(cr+remain);
		}	
		else{
			int len=remain.size();
			if(len>1)
				createIpAddr(cr+remain[0]+'.',remain.substr(1,len-1),section+1,res);
			if(remain[0]!='0'){
				if(len>2)
					createIpAddr(cr+remain.substr(0,2)+'.',remain.substr(2,len-2),section+1,res);
				if(len>3&&lessThan255(remain.substr(0,3))){
					createIpAddr(cr+remain.substr(0,3)+'.',remain.substr(3,len-3),section+1,res);
				}
			}
		}
	}
public:
    vector<string> restoreIpAddresses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> res;
		createIpAddr("",s,1,res);
		return res;
    }
};

/*											Network ID    Host ID
0XXXXXXX XXXXXXXX XXXXXXXX XXXXXXXX				7bits		24bits

10XXXXXX XXXXXXXX XXXXXXXX XXXXXXXX				14bits		16bits

110XXXXX XXXXXXXX XXXXXXXX XXXXXXXX				21bits		8bits

1110XXXX XXXXXXXX XXXXXXXX XXXXXXXX

11110XXX XXXXXXXX XXXXXXXX XXXXXXXX

255.255.255.X									broadcast
*/