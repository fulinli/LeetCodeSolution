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
        int m = nums1.size();
        int n = nums2.size();
        if(m > n)
        {
            int temp = m;
            m = n;
            n = temp;
            nums1.swap(nums2);
        }
        if(m == 0)  
        {
            if(n % 2==1)
                return nums2[n/2];
            else
                return (nums2[(n-1)/2]+nums2[(n/2)])/2.0;
        }
        cout<<"m = "<<m<<endl;
        cout<<"n = "<<n<<endl;
        int iMin = 0;
        int iMax = m;
        int halfLen = ( m + n ) / 2;
        cout<<"halfLen = "<<halfLen<<endl;
        while(iMin <= iMax)
        {
            cout<<"*******"<<endl;
            cout<<"iMin = "<<iMin<<endl;
            cout<<"iMax = "<<iMax<<endl;
            int i = (iMin + iMax) / 2;
            cout<<"i = "<<i<<endl;
            int j = halfLen - i;
            cout<<"j = "<<j<<endl;
            cout<<"nums2[j-1] = "<<nums2[j-1]<<endl;
            cout<<"nums1[i]= "<<nums1[i]<<endl;
            cout<<"nums1[i-1] = "<<nums1[i-1]<<endl;
            cout<<"nums2[j] = "<<nums2[j]<<endl;
            if(nums1[i-1] > nums2[j] && i>iMin)
            {
                iMax = iMax - 1;
            }
            else if(nums1[i] < nums2[j-1] && i<iMax) 
            {
                iMin = iMin + 1;
            }
            else
            {
                int maxleft, minright;
                if(i == 0)
                {
                    maxleft = nums2[j-1];
                }
                else if(j == 0)
                {
                    maxleft = nums1[i-1];
                }
                else
                {
                    maxleft = max(nums1[i-1], nums2[j-1]);
                }
                if(i == m)
                {
                    minright = nums2[j];
                }
                else if(j == n)
                {
                    minright = nums1[i];
                }
                else
                {          
                    minright = min(nums1[i], nums2[j]);
                }
                cout<<"maxleft = "<<maxleft<<endl;
                cout<<"minright = "<<minright<<endl;
                if( ( m + n ) % 2 == 1)
                {
                    return minright;   
                }
                if( ( m + n ) % 2 == 0)
                {
                    return (maxleft+minright)/2.0;
                }   
            }
        }
    }
};