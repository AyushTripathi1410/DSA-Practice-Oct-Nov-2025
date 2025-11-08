#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void generateAllTriplets(vector<int> &input, int sum, int begin,
    vector<int> &comb, vector<vector<int>> &result)
{
    if (comb.size() == 3)
    {
        result.push_back(comb);
        return;
    }
 
    for (int i = begin; i < input.size() && input[i] <= sum; i++)
    {
        comb.push_back(input[i]);
        generateAllTriplets(input, sum - input[i], i + 1, comb, result);
        comb.pop_back();        // backtrack
    }
}
void printAllTriplets(vector<int> &input, int sum)
{
    // sort the input
    sort(input.begin(), input.end());
    vector<int> comb;
 
    // find all distinct triplets
    vector<vector<int>> result;
    generateAllTriplets(input, sum, 0, comb, result);
 
    // print all triplets
    for (vector<int> v: result) {
        cout << "(" << v[0] << ", " << v[1] << ", " << v[2] << ")\n";
    }
}
 
int main()
{
    int sum = 10;
    vector<int> input = { 2, 7, 4, 9, 5, 1, 3 };    // 1 2 3 4 5 7 9
 
    printAllTriplets(input, sum);
 
    return 0;
}
