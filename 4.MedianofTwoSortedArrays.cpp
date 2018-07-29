/* 
There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

You may assume nums1 and nums2 cannot be both empty.

Example 1:

nums1 = [1, 3]
nums2 = [2]
The median is 2.0

Example 2:

nums1 = [1, 2]
nums2 = [3, 4]
The median is (2 + 3)/2 = 2.5

                   left_part          |        right_part
    num1[0], num1[1], ..., num1[i-1]  |  num1[i], num1[i+1], ..., num1[m-1]    [2 ,4]   m = 2
    num2[0], num2[1], ..., num2[j-1]  |  num2[j], num2[j+1], ..., num2[n-1]    [1, 3]   n = 2
    
    1. i + j = m + n - i -j
    2. n >= m  i=0~m, j = (m+n)/2 - i 保证j不是负的
    3. num2[j-1] <= num1[i] && num1[i-1] <= num2[j]
*/

class Solution {
    
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int median;
        int m = nums1.size();
        int n = nums2.size();
        if(m > n)
        {
            int temp = m;
            m = n;
            n = temp;
            nums1.swap(nums2);
        }
        cout<<"m = "<<m<<endl;
        cout<<"n = "<<n<<endl;
        int iMin = 0;
        int iMax = m;
        int halfLen = ( m + n ) / 2;
        cout<<"halfLen = "<<halfLen<<endl;
        while(iMin <= iMax)
        {
            int i = (iMin + iMax) / 2;
            int j = halfLen - i;
            if(i < iMax && nums2[j-1] > nums1[i])
            {
                iMin = iMin + 1; // i太小了
            }
            else if(i > iMin && nums1[i-1] < nums2[j])
            {
                iMax = iMax - 1; // i太大了
            }
            else
            {
                int maxLeft = 0;
                if(i == 0)
                {
                    maxLeft = nums2[j-1];
                }
                else if(j == 0)
                {
                    maxLeft = nums1[i-1];
                }
                else
                {
                    maxLeft = max(nums1[i-1], nums2[j-1]);
                }
                if((m+n)%2 == 1)
                {
                    return maxLeft;
                }
                int minRight = 0;
                if(i == m)
                {
                    minRight = nums2[j];
                }
                else if(j == n)
                {
                    minRight = nums1[i];
                }
                else
                {
                    minRight = min(nums1[i], nums2[j]);
                }

                return (maxLeft + minRight)/2;
            }
        }
    }
};