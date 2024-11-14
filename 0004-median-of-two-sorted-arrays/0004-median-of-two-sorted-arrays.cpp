class Solution {
    int kthSmallesInTwoSorted(vector<int>& n, int ln, int rn, vector<int>& m,
                              int lm, int rm, int k) {
        if (lm > rm) {
            return n[ln + k - 1];
        }

        if (ln > rn) {
            return m[lm + k - 1];
        }

        int midm = (lm + rm) / 2;
        int midn = (ln + rn) / 2;

        int countm = midm - lm + 1;
        int countn = midn - ln + 1;

        int midK = countm + countn;

        if (midK <= k) {
            if (m[midm] <= n[midn]) {
                return kthSmallesInTwoSorted(n, ln, rn, m, midm + 1, rm,
                                             k - countm);
            } else {
                return kthSmallesInTwoSorted(n, midn + 1, rn, m, lm, rm,
                                             k - countn);
            }
        } else {
            if (m[midm] >= n[midn]) {
                return kthSmallesInTwoSorted(n, ln, rn, m, lm, midm - 1, k);
            } else {
                return kthSmallesInTwoSorted(n, ln, midn - 1, m, lm, rm, k);
            }
        }
    }

public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();

        double median =
            kthSmallesInTwoSorted(nums1, 0, nums1.size() - 1, nums2, 0,
                                  nums2.size() - 1, (n1 + n2) / 2 + 1);
        if (!((n1 + n2) & 1)) {
            median += kthSmallesInTwoSorted(nums1, 0, nums1.size() - 1, nums2,
                                            0, nums2.size() - 1, (n1 + n2) / 2);

            median /= 2.0;
        }

        return median;
    }
};