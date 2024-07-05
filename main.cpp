#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

void printMatFormatted(const std::vector<std::vector<char>> &matrix, int colWidth)
{
    std::cout << std::string(matrix[0].size() * (colWidth + 2) + 1, '-') << "\n";

    for (unsigned x = 0; x < matrix.size(); x++)
    {
        std::cout << "|";
        for (unsigned y = 0; y < matrix[x].size(); y++)
        {
            std::cout << std::setw(colWidth) << matrix.at(x).at(y) << " |";
        }
        std::cout << "\n";
    }

    std::cout << std::string(matrix[0].size() * (colWidth + 2) + 1, '-') << "\n";
}

int main()
{
    std::string str;
    std::getline(std::cin, str);
    for (const auto &c : str)
    {
        std::cout << "\"" << c << "\"" << std::endl;
    }
    std::cout << str << std::endl;
    int matrixSize = sqrt(str.size());
    if (matrixSize % 2 == 0)
    {
        matrixSize++;
    }
    if (str.size() > matrixSize * matrixSize)
        matrixSize += 2;

    std::vector<std::vector<char>> matrix(matrixSize, std::vector<char>(matrixSize, '@'));
    int currX = matrixSize / 2;
    int currY = matrixSize / 2;
    printMatFormatted(matrix, 5);
    std::cout << std::endl;
    int turnCount = 1;
    matrix[currX][currY] = str[0];
    for (int i = 0;;)
    {
        for (size_t r = 0; r < turnCount and i < str.size(); r++)
        {
            std::cout << "Turn Right" << std::endl;
            currX++;
            i++;
            matrix[currY][currX] = str[i];
        }
        for (size_t u = 0; u < turnCount and i < str.size(); u++)
        {
            std::cout << "Turn Up" << std::endl;
            currY--;
            i++;
            matrix[currY][currX] = str[i];
        }
        turnCount++;
        for (size_t l = 0; l < turnCount and i < str.size(); l++)
        {
            std::cout << "Turn Left" << std::endl;
            currX--;
            i++;
            matrix[currY][currX] = str[i];
        }
        for (size_t d = 0; d < turnCount and i < str.size(); d++)
        {
            std::cout << "Turn Down" << std::endl;
            currY++;
            i++;
            matrix[currY][currX] = str[i];
        }
        turnCount++;
        if (i == str.size())
            break;
    }
    printMatFormatted(matrix, 5);
    std::cout << std::endl;

    for (size_t i = 0; i < matrix.size(); i++)
    {
        for (size_t j = 0; j < matrix.size(); j++)
        {
            if (matrix[i][j] != '@')
                std::cout << matrix[i][j];
        }
        std::cout << std::endl;
    }
    return 0;
}
