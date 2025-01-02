/*
    Leetcode Link : https://leetcode.com/problems/maximum-population-year/description/
*/

class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
    // Initialize an array to store population changes.
    int pop[2051] = {}, res = 0;

    // Loop through each log entry.
    for (auto &l : logs) {
        ++pop[l[0]];  // Increment the population for the birth year.
        --pop[l[1]];  // Decrement the population for the death year.
    }

    // Iterate from the year 1950 to 2050 to compute cumulative population.
    for (auto i = 1950; i < 2050; ++i) {
        pop[i] += pop[i - 1];  // Aggregate the population up to the current year.
        res = pop[i] > pop[res] ? i : res;  // Update the result if the current year has a higher population.
    }

    // Return the year with the maximum population.
    return res;
}
};