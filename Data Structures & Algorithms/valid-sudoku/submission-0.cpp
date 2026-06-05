#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // 9 sets for rows, columns, and boxes
        vector<unordered_set<char>> rows(9), cols(9), boxes(9);

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char c = board[i][j];
                if (c == '.') continue;  // skip empty cells

                int boxIndex = (i / 3) * 3 + (j / 3);

                // check row
                if (rows[i].count(c)) return false;
                rows[i].insert(c);

                // check column
                if (cols[j].count(c)) return false;
                cols[j].insert(c);

                // check 3x3 box
                if (boxes[boxIndex].count(c)) return false;
                boxes[boxIndex].insert(c);
            }
        }
        return true;
    }
};
