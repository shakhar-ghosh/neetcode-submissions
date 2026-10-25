class UnionFind {
    std::unordered_map<int, int> parent;
    std::unordered_map<int, int> sz;
    int max_size = 0;

public:
    UnionFind(const std::unordered_set<int>& nums) {
        for (int num : nums) {
            parent[num] = num;
            sz[num] = 1;
        }
        if (!nums.empty()) max_size = 1;
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); 
        }
        return parent[x];
    }

    void unite(int x, int y) {
        int root_x = find(x);
        int root_y = find(y);

        if (root_x == root_y) return;

        if (sz[root_x] < sz[root_y]) {
            std::swap(root_x, root_y);
        }

        parent[root_y] = root_x;
        sz[root_x] += sz[root_y];
        max_size = std::max(max_size, sz[root_x]);
    }

    int getMaxSize() const {
        return max_size;
    }
};

class Solution {
public:
    int longestConsecutive(std::vector<int>& nums) {
        if (nums.empty()) return 0;

        std::unordered_set<int> unique_nums(nums.begin(), nums.end());
        UnionFind uf(unique_nums);

        for (int num : unique_nums) {
            if (unique_nums.count(num + 1)) {
                uf.unite(num, num + 1);
            }
        }

        return uf.getMaxSize();
    }
};