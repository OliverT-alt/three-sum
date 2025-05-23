#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <chrono>
#include <random>
#include <fstream>

using namespace std;

//3sum brute force solution
vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> uniqueTriplets;
        int n = nums.size();
        sort(nums.begin(), nums.end());
     
        for (int i = 0; i < n-2;i++){
            for(int j = i+1; j <n-1;j++){
                for(int k = j+1; k <n; k++){
                    if (nums[i]+nums[j]+nums[k] == 0){
                        vector<int> triplet = {nums[i], nums[j], nums[k]};
                        sort(triplet.begin(), triplet.end());
                        uniqueTriplets.insert(triplet);
                    }
                }
            }
        }
        return vector<vector<int>>(uniqueTriplets.begin(),uniqueTriplets.end());

    }
 

//time tests
int main() {

    vector<int> input_sizes = {100, 200, 400, 800, 1600};

    ofstream outfile("runtime_data.csv");
    outfile << "n,time_ms\n";

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(-1000, 1000);

    for (int n : input_sizes) {
        vector<int> nums;

        
        int a = dist(gen);
        int b = dist(gen);
        nums.push_back(a);
        nums.push_back(b);
        nums.push_back(-(a + b));

        
        while (nums.size() < n) {
            nums.push_back(dist(gen));
        }

        
        auto start = chrono::high_resolution_clock::now();
        vector<vector<int>> result = threeSum(nums);
        auto end = chrono::high_resolution_clock::now();

        chrono::duration<double, milli> duration = end - start;
        double time_ms = duration.count();

        
        cout << "n = " << n << ", time = " << time_ms << " ms" << endl;
        outfile << n << "," << time_ms << "\n";
    }

    outfile.close();
    return 0;
}