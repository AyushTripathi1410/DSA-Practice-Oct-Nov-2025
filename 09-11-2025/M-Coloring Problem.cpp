class Solution
{
public:
    bool find(int node, vector<vector<int>> &adj, int v, int m, vector<int> &color)
    {
        if (node == v)
            return true; // Base case: all nodes colored

        // Try all m colors
        for (int i = 0; i < m; i++)
        {
            bool IsPossible = 1;

            // Check all adjacent nodes
            for (int j = 0; j < adj[node].size(); j++)
            {
                int neighbor = adj[node][j];
                if (color[neighbor] == i)
                {
                    IsPossible = 0;
                    break;
                }
            }

            if (IsPossible)
            {
                color[node] = i;
                if (find(node + 1, adj, v, m, color))
                    return true;
                color[node] = -1; // backtrack
            }
        }

        return false;
    }

    bool graphColoring(int v, vector<vector<int>> &edges, int m)
    {
        vector<vector<int>> adj(v);
        for (auto &edge : edges)
        {
            int u = edge[0];
            int w = edge[1];
            adj[u].push_back(w);
            adj[w].push_back(u);
        }

        vector<int> color(v, -1);
        return find(0, adj, v, m, color);
    }
};
