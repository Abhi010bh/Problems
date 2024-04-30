class Solution {
    public int reverse(int x) {
        ArrayList<Integer> digits=new ArrayList<Integer>();
        int rem;
        while(x!=0){
            digits.add(x%10);
            x/=10;
        }
        long rev=0;
        for(int i=0;i<digits.size();i++){
            rev=(rev*10)+digits.get(i);
        }
        if (rev < Integer.MAX_VALUE && rev >= Integer.MIN_VALUE) {
            return (int)rev;
        } else {
            return 0;
        }
    }
}