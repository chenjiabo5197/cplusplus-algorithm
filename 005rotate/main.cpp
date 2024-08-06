#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // 求矩阵的转置
        int length = matrix.size();
        for (int i = 0; i < length; ++i) {
            for (int j = i+1; j < length; ++j) {  // j从i+1开始处理，只处理对角线右上部分
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
        // 将矩阵基于垂直对角线各个元素进行互换
        for (int i = 0; i < length; ++i) {
            for (int j = 0; j < length/2; ++j) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[i][length-1-j];
                matrix[i][length-1-j] = temp;
            }
        }
    }
};