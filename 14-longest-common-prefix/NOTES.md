
/*****WORKING EXPLAINED =====work by taking the first element of strs array as prefix and for further elements matching the [maximum] part of that element that conform or is same as the stored 
and in while loop doing same by removing one char from last of that element  ***/

public String longestCommonPrefix(String[] strs) {
        if (strs == null || strs.length == 0) return "";
        String pre = strs[0];
        for (int i = 1; i < strs.length; i++) {
            while (strs[i].indexOf(pre) !=  0) {
                pre = pre.substring(0, pre.length() - 1); //substring works inclusive of first character and exclusive of end index
                if (pre.length() == 0) return pre;
            }
        }
        return pre;
    }
