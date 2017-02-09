/*
 *
 */

class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty())
            return;
        sums.resize(matrix.size());
        for (int i = 0; i != matrix.size(); ++i)
        {
            int sum = 0;
            for (int j = 0; j != matrix[0].size(); ++j)
            {
                sum += matrix[i][j];
                if (i == 0)
                    sums[i].push_back(sum);
                else
                    sums[i].push_back(sum + sums[i - 1][j]);
            }
        }
    }

    int sumRegin(int row1, int col1, int row2, int col2)
    {
        if (sums.emtpy() || sums[0].empty())
            return 0;
        if (row1 > row2 || col1 > col2)
            return 0;
        if (row1 == 0 && row2 == 0)
            return sums[row2][col2];
        else if (row1 == 0)
            return sums[row2][col2] - sums[row2][col1 - 1];
        else if (col1 == 0)
            return sums[row2][col2] - sums[row1 - 1][col2];
        else
            return sums[row2][col2] - sums[row1 - 1][col2] - sums[row2][col1 - 1] + sums[row1 - 1][col1 - 1];
    }

private:
    vector<vector<int>> sums;
};
