#include <iostream>
#include <algorithm>
using namespace std;
 
// Function to print all distinct triplets in an array with a sum
// less than or equal to a given number
void printAllTriplets(int nums[], int n, int sum)
{
    // sort the array in ascending order
    sort(nums, nums + n);
 
    // check if triplet is formed by `nums[i]` and a pair from
    // subarray `nums[i+1…n)`
    for (int i = 0; i <= n - 3; i++)
    {
        // maintain two indexes pointing to endpoints of the
        // subarray `nums[i+1…n)`
        int low = i + 1, high = n - 1;
 
        // do if `low` is less than `high`
        while (low < high)
        {
            // decrement `high` if the total is more than the remaining sum
            if (nums[i] + nums[low] + nums[high] > sum) {
                high--;
            }
 
            else {
                // if the total is less than or equal to the remaining sum,
                // print all triplets
                for (int x = low + 1; x <= high; x++) {
                    cout << "(" << nums[i] << ", " << nums[low] << ", " << nums[x] << ")";
                }
 
                low++;    // increment low
            }
        }
    }
}
 
int main()
{
    int nums[] = { 2, 7, 4, 9, 5, 1, 3 };
    int sum = 10;
 
    int n = sizeof(nums) / sizeof(nums[0]);
 
    printAllTriplets(nums, n, sum);
 
    return 0;
}
