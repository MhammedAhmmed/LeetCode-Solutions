class Solution {
int totalFuel(int v, int seats, vector<vector<int>>& adj, vector<bool>& vis, long long* fuel) {
	vis[v] = 1;

	int numPeople = 1;

	for (int city : adj[v]) {
		if (!vis[city]) {
			numPeople += totalFuel(city, seats, adj, vis, fuel);
		}
	}
	int numCar = (numPeople + seats - 1) / seats;
	if(v != 0)
		*fuel += numCar;
	return numPeople;
}
public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size() + 1;
        vector<vector<int>>adj(n);

        for (auto road : roads) {
            adj[road[0]].push_back(road[1]);
            adj[road[1]].push_back(road[0]);
        }
        long long res = 0;
        vector<bool>vis(n, false);
        totalFuel(0, seats, adj, vis, &res);

        return res;
    }
};