class Solution {
     public int clumsy(int N) {
        int curr = N; // stores current cal result
        int ans = 0; // stores final answer
        int count = 0;
        while(--N >= 1){
            switch (count % 4) {
                case 0: // Multiplication
                    curr *= N;
                    break;
                case 1: // Division
                    curr /= N; 
                    break;
                case 2:  // Addition; store curr into ans, reset ans
                    ans = (count == 2) ? (ans += curr) : (ans -= curr); // Always substract curr from ans except first occurance
                    ans += N;
                    curr = 0;
                    break;
                case 3: // Substraction; 
                    curr = N;
                    break;
            }
            count++;
        }
        return count <=2 ? (ans += curr) : (ans -= curr);
    }
}
