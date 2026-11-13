class UnionFind {
public:
    vector<int> par;
    vector<int> rank;

    UnionFind(int n) {
        par.resize(n);
        for (int i = 0; i < n; i++) {
            par[i] = i;
        }
        rank.assign(n, 1);
    }

    int find(int n) {
        int p = n;

        while (p != par[p]) {
            par[p] = par[par[p]];
            p = par[p];
        }

        return p;
    }

    // "union" is a C++ keyword, hence unionSets
    void unionSets(int n1, int n2) {
        int p1 = find(n1);
        int p2 = find(n2);

        if (p1 == p2) {
            return;
        }
        if (rank[p1] < rank[p2]) {
            par[p1] = par[p2];
            rank[p2] += rank[p1];
        } else {
            par[p2] = par[p1];
            rank[p1] += rank[p2];
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        UnionFind uf(accounts.size());
        unordered_map<string, int> mail_to_acc; // {email: account_index, ...}

        // 1. Map each email to the account (by index, not the name!); if some email has already been mapped - then connect it to already existing mapping (union). At the end of it you have nodes (mail: account) organized in unions.

        // For each account asign an index
        for (int i = 0; i < (int)accounts.size(); i++) {
            // Go through emails of an account (items after first position)
            for (int j = 1; j < (int)accounts[i].size(); j++) {
                const string& mail = accounts[i][j];
                // If an email has already been mapped to account
                if (mail_to_acc.count(mail)) {
                    uf.unionSets(i, mail_to_acc[mail]); // Union an account it belongs to, to the one is already mapped (it's parent)
                } else {
                    mail_to_acc[mail] = i; // Map email to account by index
                }
            }
        }

        // 2. Take unions from previous part and map a parent account (the account that is a parent of an union) to it's list of mails. This way redundant accounts are disregarded.

        unordered_map<int, vector<string>> par_to_mails; // {parent_account_indx : [email1, email2 ...], ...}

        // Iterate thorugh each edge
        for (const auto& [mail, i] : mail_to_acc) {
            int parent = uf.find(i); // Identify a parent of an union
            par_to_mails[parent].push_back(mail); // Add an email to the parent
        }

        // 3. Construct expected output

        vector<vector<string>> res; // The template is : [name , mail1, mail2] and mails are in sorted order

        for (auto& [parent, emails] : par_to_mails) {
            string name = accounts[parent][0]; // First element of parent account is the name
            sort(emails.begin(), emails.end());
            vector<string> row;
            row.push_back(name);
            row.insert(row.end(), emails.begin(), emails.end()); // Arrays concat
            res.push_back(row);
        }

        return res;
    }
};
