// Link --> https://leetcode.com/problems/can-place-flowers/description/

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
                // If no flowers need to be planted, return true immediately
        if (n == 0) {
            return true;
        }
        // Iterate through the flowerbed
        for (int i = 0; i < flowerbed.size(); i++) {
            // Check if the current position is empty and its adjacent positions are also empty
            bool canPlant = flowerbed[i] == 0; // Is the current spot empty?
            bool isLeftEmpty = (i == 0 || flowerbed[i - 1] == 0); // Is the left spot empty?
            bool isRightEmpty = (i == flowerbed.size() - 1 || flowerbed[i + 1] == 0); // Is the right spot empty?
            // If all conditions are satisfied, plant a flower
            if (canPlant && isLeftEmpty && isRightEmpty) {
                flowerbed[i] = 1; // Plant the flower
                n--; // Decrement the number of flowers to plant
                if (n == 0) {
                    return true; // If all flowers are planted, return true
                }
            }
        }
        // If we exit the loop, not all flowers could be planted
        return false;
    }
};
