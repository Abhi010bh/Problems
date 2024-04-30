/*
 * The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
 */
class Solution {
    public String convert(String s, int numRows) {
	    char [][]zigZag=new char[numRows][s.length()];
	    boolean down=true;
	    int row=0,col=0,ht=numRows-1;
	    
	    for(int i=0;i<s.length();i++){

            if(numRows==1)
                return s;
                
	        if(row<numRows && col<s.length()){
	            zigZag[row][col]=s.charAt(i);
	        }
	        
	        if(down && row==ht){
	            down=false;
	            if(row>0)row--;
	            col++;
	        }
	        else if(down && row!=ht){
	            row++;
	        }
	        else if(!down && row==0){
	            down=true;
	            row++;
	            
	        }
	        else if(!down && row!=0){
	            col++;
	            if(row>0)row--;
	        }
	        
	    }

	    String output="";
	    for(int i=0;i<numRows;i++)
	        for(int j=0;j<s.length();j++)
                if(zigZag[i][j]!='\u0000')
                 output+=zigZag[i][j];

	    return output;
        }
}