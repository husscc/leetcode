/*
Given an array of words and a length L, format the text such that each line has exactly L characters and is fully (left and right) justified.

You should pack your words in a greedy approach; 
that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly L characters.

Extra spaces between words should be distributed as evenly as possible. 
If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.

For the last line of text, it should be left justified and no extra space is inserted between words.

For example,
words: ["This", "is", "an", "example", "of", "text", "justification."]
L: 16.

Return the formatted lines as:
[
   "This    is    an",
   "example  of text",
   "justification.  "
]
Note: Each word is guaranteed not to exceed L in length.

Corner Cases:
A line other than the last line might contain only one word. What should you do in this case?
In this case, that line should be left-justified.
*/
class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> res;
        for(int p1=0;p1<words.size();){
			int remain=L-words[p1].size(),p2=p1;
			
			while(
                    (p2<words.size()-1)&&
                    (remain>words[p2+1].size())
            ){
				p2++;
				remain=remain-words[p2].size()-1;
			}
			
            string str="";
            
			if(p1==p2){
				str=words[p2];
				for(int i=remain;i>0;i--)
					str+=" ";
				res.push_back(str);
				p1++;
			}
            else if(p2==words.size()-1){
                for(;p1<p2;p1++)
                    str=str+words[p1]+" ";
                
                str+=words[p2];
                
                for(int i=remain;i>0;i--)
                    str+=" ";
                res.push_back(str);
                break;
            }
            
			
			else{
				int wordcount=p2-p1+1;
				int spacelen=remain/(wordcount-1)+1;
				int extraspace=remain%(wordcount-1);
				
				for(;p1<p2;p1++){
                    str+=words[p1];
					for(int j=spacelen;j>0;j--)
						str+=" ";
					if(extraspace){
						str+=" ";
						extraspace--;
					}
				}
                str+=words[p2];
                p1=p2+1;
				res.push_back(str);
			}
		}
		return res;
    }
};