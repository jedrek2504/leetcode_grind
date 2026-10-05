class Solution {
public:
    void bfs(vector<vector<char>>& board, int ROWS, int COLS, const vector<std::pair<int, int>>& dirs, int r, int c) {
        std::queue<std::pair<int, int>> q; // Queue for bfs, stack for dfs
        q.push({r, c});
        board[r][c] = '.'; // Mark as NOT eligable for removal (mark as "X")

        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for (const std::pair<int, int>& d : dirs) {
                int nr = row + d.first;
                int nc = col + d.second;

                // Check if in bounds and of "O" type and not already marked "."
                if (!(0 <= nr && nr < ROWS) || !(0 <= nc && nc < COLS) || board[nr][nc] != 'O' || board[nr][nc] == '.') {
                    continue; // Skip iteration
                }

                // If we got here - none of the above triggered continue
                q.push({nr, nc});
                board[nr][nc] = '.';
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int ROWS = board.size();
        int COLS = board[0].size();
        vector<std::pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // Directions

        // First loop - go on the borders and perform bfs if "O" is present and mark "." those which are not eligable for removal
        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                // Ensure its borders only - AND - de morgan
                if (!(r == 0 || r == ROWS - 1) && !(c == 0 || c == COLS - 1)) {
                    continue;
                }

                // If we got here
                if (board[r][c] == 'O') {
                    bfs(board, ROWS, COLS, dirs, r, c);
                }
            }
        }

        // Second pass - If still "O" - doesnt connect to border so replace, if "." - make it "O" as before
        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                if (board[r][c] == 'O') {
                    board[r][c] = 'X';
                } else if (board[r][c] == '.') {
                    board[r][c] = 'O';
                }
            }
        }
    }
};
