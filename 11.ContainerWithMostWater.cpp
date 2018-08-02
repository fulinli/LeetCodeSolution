/* 
Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container and n is at least 2.

The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.

Example:

Input: [1,8,6,2,5,4,8,3,7]
Output: 49 
*/
//错解
class Solution1 {
public:
    int maxArea(vector<int>& height) 
    {
        int maxarea = 0;
        while(height.size() > 1)
        {
            int maxindex;
            int maxheight = findmax(height, maxindex);
            int area = findmaxarea(height, maxheight, maxindex);
            // ***********************************************//
            height.erase(height.begin() + maxindex);
            // ***********************************************//
            maxarea = area > maxarea ? area : maxarea;
        }
        return maxarea;
    }
    int findmax(vector<int>& height, int& maxindex)
    {
        int maxheight = 0;
        for(int i = 0; i < height.size(); i++)
        {
            if(height[i] > maxheight)
            {
                maxheight = height[i];
                maxindex = i;
            }
        }
        return maxheight;
    }
    int findmaxarea(vector<int>& height, int maxheight, int maxindex)
    {
        int maxarea;
        for(int i = 0; i < height.size(); i++)
        {

            maxarea = abs(i - maxindex)*height[i] > maxarea ? abs(i - maxindex)*height[i] : maxarea;
        }

        return maxarea;
    }
};

//正解
class Solution2 {
public:
    int maxArea(vector<int>& height) {
        int maxarea = 0; 
        int temparea = 0;
        for(int i = 0; i < height.size(); i++)
        {
            for(int j = i + 1; j < height.size(); j++)
            {
                temparea = abs(j-i) * min(height[i], height[j]);
                maxarea = temparea > maxarea ? temparea : maxarea;
            }
        }
        return maxarea;      
    }
};