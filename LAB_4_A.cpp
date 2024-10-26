#include <iostream>
#include <vector>

std::vector<std::vector<int>> Get_matrix_input(int row, int col)
{
    using namespace std;
    vector<vector<int>> matrix;
    for (int j = 0; j< row; j++)
    {
        vector<int> Row = {};
        for (int i = 0; i < col; i++)
        {
            int a;
            cin >> a;
            Row.push_back(a);
        }
        matrix.push_back(Row);
    }
    return matrix;
}

std::vector<int> get_row_and_col()
{
    using namespace std;
    vector<int> matrix;
    int row,col;
    cin >> row >> col;
    matrix.push_back(row);
    matrix.push_back(col);
    return matrix;
}

std::vector<std::vector<int>> calculate_dot_product(const std::vector<std::vector<int>> & matrix1, const std::vector<std::vector<int>> & matrix2, int row, int col)
{
    using namespace std;
    vector<vector<int>> matrix;
    for (int j = 0; j< row; j++)
    {
        vector<int> Row = {};
        for (int i = 0; i < col; i++)
        {
            int a = matrix1[j][i] * matrix2[j][i];
            Row.push_back(a);
        }
        matrix.push_back(Row);
    }
    return matrix;
}

void print_matrix(const std::vector<std::vector<int>> & matrix, int row, int col)
{
    using namespace std;
    for (int j = 0; j< row; j++)
    {
        for (int i = 0; i < col; i++)
        {
            cout << matrix[j][i] << " ";
        }
        cout << endl;
    }
}
int main()
{
    using namespace std;
    vector<int> row_and_col = get_row_and_col();
    int row = row_and_col[0];
    int col = row_and_col[1];
    vector<vector <int>> matrix1 = Get_matrix_input(row, col);
    vector<vector <int>> matrix2 = Get_matrix_input(row, col);
    vector<vector <int>> matrix0 = calculate_dot_product(matrix1, matrix2, row, col);
    print_matrix(matrix0, row, col);
    return 0;
}