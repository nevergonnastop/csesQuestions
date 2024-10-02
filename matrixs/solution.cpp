// // Matrix rotate90(Matrix &mat) {
// //     int n = mat.size();
// //     Matrix rotated(n, vector<int>(n));
// //     for (int i = 0; i < n; i++) {
// //         for (int j = 0; j < n; j++) {
// //             rotated[j][n - i - 1] = mat[i][j];
// //         }
// //     }
// //     return rotated;
// // }

// // // Function to rotate the matrix by 180 degrees
// // Matrix rotate180(Matrix &mat) {
// //     return rotate90(rotate90(mat));
// // }

// // // Function to rotate the matrix by 270 degrees
// // Matrix rotate270(Matrix &mat) {
// //     return rotate90(rotate180(mat));
// // }

// // // Function to vertically flip the matrix
// // Matrix flipVertical(Matrix &mat) {
// //     int n = mat.size();
// //     for (int i = 0; i < n / 2; i++) {
// //         swap(mat[i], mat[n - i - 1]);
// //     }
// //     return mat;
// // }

// // // Function to horizontally flip the matrix
// // Matrix flipHorizontal(Matrix &mat) {
// //     int n = mat.size();
// //     for (int i = 0; i < n; i++) {
// //         reverse(mat[i].begin(), mat[i].end());
// //     }
// //     return mat;
// // }

// // // Function to process the image
// // Matrix processImage(Matrix &mat, int rotation, int vertical_flip, int horizontal_flip) {
// //     // Apply rotation
// //     if (rotation == 90) {
// //         mat = rotate90(mat);
// //     } else if (rotation == 180) {
// //         mat = rotate180(mat);
// //     } else if (rotation == 270) {
// //         mat = rotate270(mat);
// //     }

// //     // Apply vertical flip if necessary
// //     if (vertical_flip == 1) {
// //         mat = flipVertical(mat);
// //     }

// //     // Apply horizontal flip if necessary
// //     if (horizontal_flip == 1) {
// //         mat = flipHorizontal(mat);
// //     }

// //     return mat;
// // }

// // #include<bits/stdc++.h>
// // using namespace std;
 
// // bool primes[1000000];
// // const int maxn = 1000000;
 
// // // Sieve of Eratosthenes
// // void sieve()
// // {
// //     memset(primes,true,sizeof(primes));
// //     primes[0] = primes[1] = 0;
     
// //     for(int i = 2; i * i <= maxn; i++)
// //     {
// //         if(primes[i])
// //         {
// //             for(int j = i * i ;
// //                    j <= maxn ; j += i)
// //             primes[j] = false;
// //         }
// //     }
// // }
 
// // // Function Convert integer
// // // to binary string
// // string toBinary(int n)
// // {
// //     string r = "";
// //     while(n != 0) 
// //     {
// //         r = (n % 2 == 0 ?"0":"1") + r;
// //         n /= 2;
// //     }
// //     return (r == "")?"0":r;
// // }
 
// // // Function print all the 
// // // ways to split the given string
// // // into Primes.
// // void PrimeSplit(string str)
// // {
// //     string temp;
// //     int cnt=0;
     
// //     // To store all possible strings
// //     vector<string> ans;
// //     int bt = 1<<(str.size()-1);
// //     int n = str.size();
 
 
// //     // Exponetnital complexity n*(2^(n-1))
// //     // for bit 
// //     for(int i = 0 ; i < bt ; i++)
// //     {
// //         temp = toBinary(i) + "0";
// //         int j = 0, x = n - temp.size(), y;
// //         while(j < x)
// //         {
// //             temp = "0" + temp;
// //             j++;
// //         }
// //         j = 0; 
// //         x = 0;
// //         y = -1;
         
// //         string sp = "", tp = "";
// //         bool flag = 0;
         
// //         while(j < n)
// //         {
// //             sp += str[j];
// //             if(temp[j] == '1')
// //             {
// //                 tp += sp + ',';
// //                 y = stoi(sp);
                 
// //                 // Pruning step
// //                 if(!primes[y])
// //                 {
// //                     flag = 1;
// //                     break;
// //                 }
// //                 sp = "";
// //             }
// //             j++;
// //         }
// //         tp += sp;
// //         if(sp != "")
// //         {
// //             y = stoi(sp);
// //             if(!primes[y])
// //             flag = 1;
// //         }
// //         if(!flag)
// //         ans.push_back(tp);
// //     }
// //     if(ans.size() == 0)
// //     {
// //         cout << -1 << endl;
// //     }
// //     cout << ans.size() << endl;
// //     for(auto i:ans)
// //     {
// //         cout << i << endl;
// //     }
// // }
 



// // // Driver code
// // int main()
// // {
// //     string str = "11375";
// //     sieve();
     
// //     PrimeSplit(str);
     
// //     return 0;
// // }


// #include <iostream>
// #include <vector>
// #include <string>
// #include <cmath>

// using namespace std;

// const int MOD = 1000000007;
// const int MAX_PRIME = 1000000;
// vector<bool> sieve(MAX_PRIME + 1, true);

// // Sieve of Eratosthenes to mark prime numbers up to MAX_PRIME
// void buildSieve() {
//     sieve[0] = sieve[1] = false;  // 0 and 1 are not prime
//     for (int p = 2; p * p <= MAX_PRIME; ++p) {
//         if (sieve[p]) {
//             for (int multiple = p * p; multiple <= MAX_PRIME; multiple += p) {
//                 sieve[multiple] = false;
//             }
//         }
//     }
// }

// // Function to check if a number (given as a string) is prime
// bool isPrime(const string& number_str) {
//     int number = stoi(number_str);
//     return sieve[number];
// }

// // Recursive DP function to count all prime segments
// int countAllPrimeSegmentDP(const string &s, int i, vector<int> &dp) {
//     // If already computed
//     if (dp[i] != -1) {
//         return dp[i];
//     }

//     // Base case: when we reach the end of the string
//     if (i == s.length()) {
//         return 1;
//     }

//     // If the string starts with '0', it's invalid
//     if (s[i] == '0') {
//         return 0;
//     }

//     int count = 0;
//     // Try to form prime numbers from substrings of length 1 to 6
//     for (int j = 1; j <= 6; ++j) {
//         if (i + j <= s.length()) {
//             string num_str = s.substr(i, j);
//             if (isPrime(num_str)) {
//                 count += countAllPrimeSegmentDP(s, i + j, dp);
//                 count %= MOD;
//             }
//         }
//     }
//     dp[i] = count;  // Save result for memoization
//     return dp[i];
// }

// // int main() {
// //     // Build sieve to mark prime numbers
// //     buildSieve();
    
// //     // Input the string
// //     string s = "11375";
// //     // cout << "Enter the string: ";
// //     // cin >> s;

// //     // Initialize DP array with -1
// //     vector<int> dp(s.length() + 1, -1);
// //     dp[s.length()] = 1;  // Base case: 1 way to split an empty string
    
// //     // Call the DP function to count the number of prime segments
// //     int result = countAllPrimeSegmentDP(s, 0, dp);
    
// //     // Output the result
// //     cout << result << endl;

// //     return 0;
// // }



// vector<int> countPairsOfConnectableServers(vector<vector<int>>& edges, int signalSpeed) {
//     int n = edges.size() + 1;
//     vector<pair<int, int>> g[n];
//     for (auto& e : edges) {
//         int a = e[0], b = e[1], w = e[2];
//         g[a].emplace_back(b, w);
//         g[b].emplace_back(a, w);
//     }
//     function<int(int, int, int)> dfs = [&](int a, int fa, int ws) {
//         int cnt = ws % signalSpeed == 0;
//         for (auto& [b, w] : g[a]) {
//             if (b != fa) {
//                 cnt += dfs(b, a, ws + w);
//             }
//         }
//         return cnt;
//     };
//     vector<int> ans(n);
//     for (int a = 0; a < n; ++a) {
//         int s = 0;
//         for (auto& [b, w] : g[a]) {
//             int t = dfs(b, a, w);
//             ans[a] += s * t;
//             s += t;
//         }
//     }
//     return ans;
// }
// #include <iostream>
// #include <vector>
// #include <functional>
// using namespace std;

// // Function to count pairs of connectable servers
// vector<int> countPairsOfConnectableServers(vector<vector<int>>& edges, int signalSpeed) {
//     int n = edges.size() + 1;
//     vector<pair<int, int>> g[n];
    
//     // Building the adjacency list
//     for (auto& e : edges) {
//         int a = e[0], b = e[1], w = e[2];
//         g[a].emplace_back(b, w);
//         g[b].emplace_back(a, w);
//     }

//     // DFS function to explore the graph
//     function<int(int, int, int)> dfs = [&](int a, int fa, int ws) {
//         int cnt = ws % signalSpeed == 0;
//         for (auto& [b, w] : g[a]) {
//             if (b != fa) {
//                 cnt += dfs(b, a, ws + w);
//             }
//         }
//         return cnt;
//     };

//     vector<int> ans(n);
    
//     // Loop through each node to calculate pairs
//     for (int a = 0; a < n; ++a) {
//         int s = 0;
//         for (auto& [b, w] : g[a]) {
//             int t = dfs(b, a, w);
//             ans[a] += s * t;
//             s += t;
//         }
//     }
//     return ans;
// }

// // Main function
// int main() {
//     // Input: number of edges and signal speed
//     int numEdges, signalSpeed;
//     cout << "Enter number of edges and signal speed: ";
//     cin >> numEdges >> signalSpeed;
    
//     vector<vector<int>> edges(numEdges, vector<int>(3));
    
//     // Input each edge (start, end, weight)
//     cout << "Enter the edges in format (start, end, weight):" << endl;
//     for (int i = 0; i < numEdges; ++i) {
//         cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
//     }

//     // Call the function to calculate the pairs
//     vector<int> result = countPairsOfConnectableServers(edges, signalSpeed);
    
//     // Output the results
//     cout << "Result (number of connectable pairs for each server):" << endl;
//     for (int i = 0; i < result.size(); ++i) {
//         cout << "Server " << i << ": " << result[i] << " connectable pairs" << endl;
//     }

//     return 0;
// }

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to find the maximum number of overlapping meetings
int maxOverlappingMeetings(const vector<pair<int, int>>& intervals) {
    // Vector to store events (start and end times)
    vector<pair<int, int>> events;

    // Convert each interval into start (+1) and end (-1) events
    for (const auto& interval : intervals) {
        events.push_back({interval.first, 1});   // Meeting starts
        events.push_back({interval.second, -1}); // Meeting ends
    }

    // Sort events: first by time, then by type (end before start if same time)
    sort(events.begin(), events.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return (a.first == b.first) ? a.second < b.second : a.first < b.first;
    });

    int maxOverlap = 0;     // To store the maximum overlap
    int currentOverlap = 0; // To keep track of current overlapping meetings

    // Traverse sorted events
    for (const auto& event : events) {
        currentOverlap += event.second;             // Update current overlap count
        maxOverlap = max(maxOverlap, currentOverlap); // Track the maximum overlap
    }

    return maxOverlap;
}

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to find the earliest time slot for a meeting of given length
int earliest_meeting_time(vector<vector<vector<int>>>& schedules, int length) {
    // Flatten all the schedules into one list
    vector<pair<int, int>> merged_meetings;
    for (const auto& employee : schedules) {
        for (const auto& meeting : employee) {
            merged_meetings.push_back({meeting[0], meeting[1]});
        }
    }
    
    // Sort meetings by start time, and by finish time if start times are equal
    sort(merged_meetings.begin(), merged_meetings.end());
    
    // Start of the day is time 0
    int current_time = 0;
    int end_of_day = 24 * 60; // 24 hours in minutes = 1440
    
    // Check the gaps between consecutive meetings
    for (const auto& meeting : merged_meetings) {
        int start = meeting.first;
        int finish = meeting.second;
        
        // If there's a gap between current_time and the next meeting's start time
        if (start - current_time >= length) {
            return current_time;
        }
        
        // Move the current time forward to the end of this meeting
        current_time = max(current_time, finish);
    }
    
    // Check if there's enough time after the last meeting till the end of the day
    if (end_of_day - current_time >= length) {
        return current_time;
    }
    
    // If no suitable time is found, return -1
    return -1;
}

// int main() {
//     // Example usage:
//     vector<vector<vector<int>>> schedules = {
//         {},  // Employee 1's meetings
//         {},
//         {} // Employee 2's meeting                                // Employee 3's meetings
//     };
//     int length = 75;
    
//     int result = earliest_meeting_time(schedules, length);
//     cout << result << endl;  // Expected output: 240
    
//     return 0;
// }

// int main() {
//     vector<pair<int, int>> intervals = {{1, 10}};

//     cout << "Maximum number of overlapping meetings: " << maxOverlappingMeetings(intervals) << endl;

//     return 0;
// }
#include <iostream>
#include <vector>
#include <numeric> // For accumulate
#include <algorithm> // For sort

int minPartitions(std::vector<int>& used, std::vector<int>& totalCapacity) {
    // Step 3: Calculate the total amount of data that needs to be accommodated
    int totalData = std::accumulate(used.begin(), used.end(), 0);
    
    // Step 2: Sort the totalCapacity in descending order
    std::sort(totalCapacity.begin(), totalCapacity.end(), std::greater<int>());
    
    // Step 4: Initialize counter for the number of partitions used
    int partitionsUsed = 0;
    
    // Step 5: Iterate over the sorted capacities and allocate data
    for (int capacity : totalCapacity) {
        totalData -= capacity;  // Subtract the capacity from the total data
        partitionsUsed++;       // Increment the partition counter
        
        // Stop when all data is allocated
        if (totalData <= 0) {
            break;
        }
    }
    
    // Step 6: Return the number of partitions used
    return partitionsUsed;
}

int main() {
    // Example usage
    std::vector<int> used = {3, 2, 1, 3, 1};
    std::vector<int> totalCapacity = {3, 5, 3, 5, 5};
    
    int result = minPartitions(used, totalCapacity);
    
    std::cout << "Minimum number of partitions required: " << result << std::endl;
    
    return 0;
}
