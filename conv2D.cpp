#include<bits/stdc++.h>

using namespace std;

void conv2d(int input[3][4],int kernel[2][2],int stride=1,int padding=1)
{
    // Calculate the number of rows
    int input_rows = 3;
    // Calculate the number of columns
    int input_cols = 4;

    // Calculate the number of rows
    int kernel_rows = 2;
    // Calculate the number of columns
    int kernel_cols = 2;

    int padinput_rows = input_rows + 2*padding;
    int padinput_cols = input_cols + 2*padding;

    int padinput[padinput_rows][padinput_cols];
    memset(padinput, 0, sizeof(padinput));

    for(int i=0;i<input_rows;i++)
    {
        for(int j=0;j<input_cols;j++)
        {
            padinput[i+padding][j+padding] = input[i][j];
        }
    }

    int output_rows = ((input_rows - kernel_rows + 2*padding) / stride) + 1;
    int output_cols = ((input_cols - kernel_cols + 2*padding) / stride) + 1;

    int output[output_rows][output_cols];

    for(int n = 0;n<output_rows;n++)
    {
        for(int m=0;m<output_cols;m++)
        {
            int temp = 0;
            for(int i=0;i<kernel_rows;i++)
            {
                for(int j=0;j<kernel_cols;j++)
                {

                    temp += (padinput[n*stride + i][m*stride + j] * kernel[i][j]);
                }
            }

            output[n][m] = temp;

        }
    }

    for(int n = 0;n<output_rows;n++)
    {
        for(int m=0;m<output_cols;m++)
        {
            cout<<output[n][m]<<" ";
        }

        cout<<"\n";
    }



}

int main()
{
    int input[3][4] = {
        {2, 3, 6, 9},
        {1, 9, 5, 1},
        {4, 7, 8, 5}
    };

    int kernel[2][2] = 
    {
        {1, 2},
        {3, 1}
    };

    conv2d(input,kernel);

    return 0;
}




/*
Answer:

2 9 15 27 27 
5 20 47 40 12 
6 38 48 36 16 
8 18 23 18 5 






*/
