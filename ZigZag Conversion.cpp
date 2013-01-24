class Solution {
public:
    string convert(string s, int nRows) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        /*
            1        9              17                         interval=gap=8
            2     8 10          16                             interval=6,gap=8
            3   7   11      15                                 interval=4,gap=8
            4 6     12  14                                     interval=2,gap=8
            5       13                                         interval=0,gap=8
            
            if nRows, then gap = 2row-2 (e.g nRows=5,gap=8)
            resString[1]=s[1]
            resString[2]=s[9]
            .......            
            if nRows and begin=curRow, then interval=2(nRows-curRow)
        */
        int len=s.length(),index=0,gap=2*(nRows-1),interval=0,i;
        string resStr(len,'x');
        if(!gap)
            gap=1;
        for(int curRow=1;curRow<=nRows;curRow++){
            interval=2*(nRows-curRow);
            
            i=curRow-1;
            while(i<len){
                resStr[index++]=s[i];
                if(((0!=interval)&&(gap!=interval))&&(i+interval)<len){
                   resStr[index++]=s[i+interval];
                }
                i+=gap;
            }
        }
        return resStr;
    }
};