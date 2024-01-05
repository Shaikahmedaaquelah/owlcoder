#define MOD 1000000007

long long TotalWays(int N){
    // Base case: when N is 1, there are 4 possible ways
    if (N == 1)
        return 4;
    
    // Initialize two arrays to store the count of ways for buildings and empty spaces
    vector<long long> building(N, 0);
    vector<long long> space(N, 0);
    
    // Initialize the first element
    building[0] = space[0] = 1;
    
    // Fill the arrays based on the recurrence relation
    for (int i = 1; i < N; ++i) {
        building[i] = (building[i-1] + space[i-1]) % MOD;
        space[i] = building[i-1];
    }
    
    // Calculate the total number of ways by considering both sides of the road
    long long totalWays = (building[N-1] + space[N-1]) % MOD;
    
    // Multiply by 2 to account for both sides of the road
    totalWays = (totalWays * totalWays) % MOD;
    
    return totalWays;