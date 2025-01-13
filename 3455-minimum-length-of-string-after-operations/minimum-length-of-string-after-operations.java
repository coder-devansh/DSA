class Solution {
    public int minimumLength(String s) {

        Map<Character, Integer> map = new HashMap<>();
        int left = 0;
        int right = 0;
        int minLength = Integer.MAX_VALUE;

        while (right < s.length()) {
            map.put(s.charAt(right), map.getOrDefault(s.charAt(right), 0) + 1);

            if (map.get(s.charAt(right)) == 3) {
                int i = right;
                char ch = s.charAt(i);

                while (map.get(ch) > 1 && i >= 0) {
                    if (s.charAt(i) == ch) {
                        map.put(s.charAt(i), map.get(s.charAt(i)) - 1);
                    }
                    i--;
                }
            }
            right++;
        }

        StringBuilder ans = new StringBuilder();
        for (Map.Entry<Character, Integer> entry : map.entrySet()) {
            for (int i = 0; i < entry.getValue(); i++) {
                ans.append(entry.getKey());
            }
        }
        return ans.length();
        
    }
}
