import java.util.ArrayList;
import java.util.List;

public class test {
    class Solution {
        public List<String> buildArray(int[] target, int n) {
            List<String> ans = new ArrayList<>();
            for (int i = 0; i < target.length; i++) {
                if (i == 0) {
                    int timesPush = target[i] - 1;
                    for (int j = 0; j < timesPush; j++) {
                        ans.add("Push");
                        ans.add("Pop");
                    }
                    ans.add("Push");
                } else {
                    int diff = target[i] - target[i - 1];
                    int timesPush = diff - 1;
                    for (int j = 0; j < timesPush; j++) {
                        ans.add("Push");
                        ans.add("Pop");
                    }
                    ans.add("Push");
                }
            }
            ans.add("Push");
            ans.add("Pop");
            return ans;
        }
    }

    public static void main(String[] args) {
        Solution solution = new test().new Solution();
        int[] target = {1, 3};
        System.out.println(solution.buildArray(target, 3));
    }
}