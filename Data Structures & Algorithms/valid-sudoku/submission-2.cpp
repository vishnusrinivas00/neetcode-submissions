class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();  // should be 9
        vector<unordered_set<char>> row(n), col(n), box(n);
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                char c = board[i][j];
                if (c == '.') continue;

                int boxIndex = (i / 3) * 3 + (j / 3);

                if (row[i].count(c)) return false;
                row[i].insert(c);

                if (col[j].count(c)) return false;
                col[j].insert(c);

                if (box[boxIndex].count(c)) return false;
                box[boxIndex].insert(c);
            }
        }

        return true;
    }
};
