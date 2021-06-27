package leetcode29两数相除;

public class Solution {
    public int divide(int dividend, int divisor) {
        if(dividend == 0) return 0;
        else if(divisor == 1) return dividend;
        else if(divisor == -1) return dividend > Integer.MIN_VALUE?-dividend:Integer.MAX_VALUE;

        long a = dividend;
        long b = divisor;
        boolean sign = true;
        sign =  a > 0 && b > 0 || a < 0 && b < 0;
        a = a > 0 ? a : -a;
        b = b > 0 ? b : -b;

        long res = div (a , b);
        if(sign) return (res > Integer.MAX_VALUE)?Integer.MAX_VALUE: (int) res;
        return (int) -res;
    }

    private long div(long a, long b) {
        if(a<b) return 0;
        long count = 1;
        long tb = b; // 在后面的代码中不更新b
        while((tb+tb)<=a){
            count = count + count; // 最小解翻倍
            tb = tb+tb; // 当前测试的值也翻倍
        }
        return count + div(a-tb,b);
    }
}
