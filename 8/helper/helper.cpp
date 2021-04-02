#include <vector>

bool numIsInVector(const std::vector<int>& nums, int num)
{
    for(auto& val: nums)
    {
        if (val == num)
            return true;
    }
    return false;
}