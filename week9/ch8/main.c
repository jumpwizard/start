#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*检查一个9*9的数组是否是一个有效数独，线扫描每一行，再扫描每一列，再扫描9个3*3的小九宫格，有重复的就无效，
全部扫描完就说明有效*/

//扫描函数，采用哈希表对应检查
void isValidSudoku(char board[][9]) {
    int rows[9][9];  
    int columns[9][9];
    int subboxes[3][3][9];
    int i,j;
        
    memset(rows,0,sizeof(rows));//用meset函数将三个数组全填0,初始化
    memset(columns,0,sizeof(columns));
    memset(subboxes,0,sizeof(subboxes));
    for ( i = 0; i < 9; i++) {
        for ( j = 0; j < 9; j++) {

            char c = board[i][j];

            if (c != '.') {
                int index = c - '0' - 1;  //由于数组是char类型，需要转换成ascll码
                rows[i][index]++;
                columns[j][index]++;
                subboxes[i / 3][j / 3][index]++;//定位小九宫格
                if (rows[i][index] > 1 || columns[j][index] > 1 || subboxes[i / 3][j / 3][index] > 1) {
                    printf("Invalid sudoku!!!");

                    return;
                }
            }
        }
    }
    printf("Valid sudoku!!!");
    return;
}

int main()
{

    char board[9][9] = 
{{'8','3','.','.','7','.','.','.','.'}
,{'6','.','.','1','9','5','.','.','.'}
,{'.','8','8','.','.','.','.','6','.'}
,{'8','.','.','.','6','.','.','.','3'}
,{'4','.','.','8','.','3','.','.','1'}
,{'7','.','.','.','2','.','.','.','6'}
,{'.','6','.','.','.','.','2','8','.'}
,{'.','.','.','4','1','9','.','.','5'}
,{'.','.','.','.','8','.','.','7','9'}};

    isValidSudoku(board);

    return 0;


}