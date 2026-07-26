class Solution {
public:
    int strStr(string haystack, string needle) {
        bool match = true;
        for (int i = 0; i < haystack.size(); i++) {
            if (i + needle.size() < haystack.size()+1) {
                match = true;
                for (int j = 0; j < needle.size(); j++) 
                    if (haystack[i + j] != needle[j]) {
                        match = false;
                        break;
                    }
                if (match == true)
                    return i;
            }
        }
        return -1;
    }
};