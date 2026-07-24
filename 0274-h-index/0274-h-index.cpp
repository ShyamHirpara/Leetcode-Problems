class Solution {
public:
    int hIndex(vector<int>& citations) {

        // Algorithm:
        //
        // Step 1:
        // Let n be the total number of papers.
        // The maximum possible H-index is n because a researcher
        // cannot have an H-index greater than the number of papers.
        //
        // Step 2:
        // Create a frequency array (bucket) of size n+1.
        // bucket[i] stores the number of papers having exactly i citations.
        //
        // Since any citation count greater than n cannot increase the
        // H-index beyond n, store all such papers in bucket[n].
        //
        // Example:
        // citations = [3,0,6,1,5], n = 5
        //
        // bucket index : 0 1 2 3 4 5
        // bucket value : 1 1 0 1 0 2
        //
        // (6 is stored in bucket[5])

        int n = citations.size();
        int* arr = new int[n + 1]();

        for (int i = 0; i < n; i++) {

            if (citations[i] > n)
                arr[n]++;          // Group all citations > n into last bucket.
            else
                arr[citations[i]]++;
        }

        // Step 3:
        // Traverse buckets from highest citation count to lowest.
        //
        // 'count' keeps track of the number of papers having
        // citations greater than or equal to the current index.
        //
        // If count >= current index (i),
        // then there are at least i papers with at least i citations.
        // Therefore, i satisfies the H-index definition.
        //
        // Since we are checking from largest to smallest,
        // the first valid i encountered is the maximum H-index.

        int count = 0;

        for (int i = n; i >= 0; i--) {

            count += arr[i];

            if (count >= i)
                return i;
        }

        // If no valid H-index is found, return 0.
        return 0;
    }
};