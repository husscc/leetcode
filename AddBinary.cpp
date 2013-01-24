#include <string>
#include <cstdlib>
#include <iostream>
#include <cstring>
using namespace std;

class Solution {
public:
    static string addBinary(string a, string b) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int aSize=a.length(),bSize=b.length();
        int resSize=aSize>bSize?aSize:bSize;
        char *reschar=(char*)malloc(sizeof(char)*(resSize+1));
        memset(reschar,'A',resSize);
        reschar[resSize]='\0';
        bool adv=false;
        int i=aSize-1,j=bSize-1,k=resSize-1;
        while(i>=0&&j>=0){
            if(!adv){
                if(a[i]=='0'&&b[j]=='0')
                    reschar[k]=(char)'0';
                else if((a[i]=='1'&&b[j]=='0')||(a[i]=='0'&&b[j]=='1'))
                    reschar[k]=(char)'1';
                else{
                    reschar[k]=(char)'0';
                    adv=true;
                }
            }
            else{
                if(a[i]=='0'&&b[j]=='0'){
                    reschar[k]=(char)'1';
                    adv=false;
                }
                else if((a[i]=='1'&&b[j]=='0')||(a[i]=='0'&&b[j]=='1')){
                    reschar[k]=(char)'0';
                    adv=true;
                }
                else{
                    reschar[k]=(char)'1';
                    adv=true;
                }
            }
            i--;
            j--;
            k--;
        }
            	
        int gap=abs(aSize-bSize);
        if(gap>0){
            string gapstring;
            if(aSize>bSize)
                gapstring=a;
            else
                gapstring=b;
            
            int gapIndex=gap-1;
            while(k>=0){
                if(adv){
                    if(gapstring[gapIndex]=='1')
                        reschar[k]=(char)'0';
                    else{
                        reschar[k]=(char)'1';
                        adv=false;
                    }
                }
                else{
                    adv=false;
                    reschar[k]=gapstring[gapIndex];
                }
                k--;
                gapIndex--;
            }
        }
        
        string res(reschar);
        free(reschar);
        if(adv){
            res='1'+res;
        }   

        return res;
    }
};