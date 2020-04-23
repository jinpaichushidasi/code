#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

using namespace std;
FILE* fp;
int main()
{
    int start;
    int num;
    int qnum;
    int yinzinum;
    int yinzi;
    float yinzif;
    int max;
    int zorx;
    int yunsuanfu[5];
    int yunsuanfuxz;
    int wenjian;
    int kuohao;
    int i;
    int j;
    int flag1 = 1;
    int flag2 = 0;
    printf("///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("///////// ////////   /////// //          // //////////      /////      //////  ////////   //////           ////////////\n");
    printf("////////// ////// /// ///// /// /////////// ///////// ///////// //////// /// // ////// /// ///// //////////////////////\n");
    printf("/////////// //// ///// /// ////          // //////// ///////// ///////// // //// //// ///// ////           ////////////\n");
    printf("//////////// // /////// / ///// /////////// ///////// ///////// /////// // ////// // /////// /// //////////////////////\n");
    printf("///////////// ////////// //////          //        ///      ////       // ////////  ///////// //           ////////////\n");
    printf("///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("///////////////////////////////                                       /////////////////////////////////////////////////\n");
    printf("///////////////////////////////         欢迎进入小学四则运算系统      /////////////////////////////////////////////////\n");
    printf("///////////////////////////////               1.开始做题              /////////////////////////////////////////////////\n");
    printf("///////////////////////////////                 2.退出                /////////////////////////////////////////////////\n");
    printf("///////////////////////////////         请输入您的选择:               /////////////////////////////////////////////////\n");
    printf("///////////////////////////////                                       /////////////////////////////////////////////////\n");
    printf("///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("\t\t\t\t");
    cin >> start;
    if (start == 1)
    {
        system("cls");
    }
    if (start == 2)
    {
        return 0;
    }
    cout << "输入需要题目的数量。" << endl;
    cin >> num;
    cout << "输入需要题目中的最大数。" << endl;
    cin >> max;
    cout << "输入需要题目中因子的最大数量。" << endl;
    cin >> yinzinum;
    cout << "输入整数运算还是小数运算：1为整数，2为小数。" << endl;
    cin >> zorx;
    while (zorx != 1 && zorx != 2)
    {
        cout << "输入有误请重新输入。" << endl;
        cout << "输入整数运算还是小数运算：1为整数，2为小数。" << endl;
        cin >> zorx;
    }
    cout << "输入所需要的运算符" << endl;
    cout << "是否需要+，1为需要，2为不需要。" << endl;
    cin >> yunsuanfu[0];
    while (yunsuanfu[0] != 1 && yunsuanfu[0] != 2)
    {
        cout << "输入有误请重新输入。" << endl;
        cout << "是否需要+，1为需要，2为不需要。" << endl;
        cin >> yunsuanfu[0];
    }
    cout << "是否需要-，1为需要，2为不需要。" << endl;
    cin >> yunsuanfu[1];
    while (yunsuanfu[1] != 1 && yunsuanfu[1] != 2)
    {
        cout << "输入有误请重新输入。" << endl;
        cout << "是否需要-，1为需要，2为不需要。" << endl;
        cin >> yunsuanfu[1];
    }
    cout << "是否需要*，1为需要，2为不需要。" << endl;
    cin >> yunsuanfu[2];
    while (yunsuanfu[2] != 1 && yunsuanfu[2] != 2)
    {
        cout << "输入有误请重新输入。" << endl;
        cout << "是否需要*，1为需要，2为不需要。" << endl;
        cin >> yunsuanfu[2];
    }
    cout << "是否需要/，1为需要，2为不需要。" << endl;
    cin >> yunsuanfu[3];
    while (yunsuanfu[3] != 1 && yunsuanfu[3] != 2)
    {
        cout << "输入有误请重新输入。" << endl;
        cout << "是否需要/，1为需要，2为不需要。" << endl;
        cin >> yunsuanfu[3];
    }
    cout << "输入有无括号：1为有，0为无。" << endl;
    cin >> kuohao;
    while (kuohao != 1 && kuohao != 2)
    {
        cout << "输入有误请重新输入。" << endl;
        cout << "是否需要括号，1为需要，2为不需要。" << endl;
        cin >> kuohao;
    }
    cout << "是否需要输出到文件，1为需要，2为不需要。" << endl;
    cin >> wenjian;
    while (wenjian != 1 && wenjian != 2)
    {
        cout << "输入有误请重新输入。" << endl;
        cout << "是否需要输出到文件，1为需要，2为不需要。" << endl;
        cin >> wenjian;
    }
    //srand((unsigned)time(NULL));
    if ((fp = fopen("E:\\yunsuan.txt", "w")) == NULL)   //将表达式写入到文件
    {
        printf("不能打开文件！\n");
        exit(0);
    }
    for (i = 0; i < num; i++)
    {
        cout << i + 1 << ". ";
        if (wenjian == 1)
        {
            fprintf(fp, "%d. ", i + 1);
        }
        qnum = rand() % yinzinum;
        if (qnum < 1)
        {
            qnum = 1;
        }
        for (j = 0; j < qnum + 1; j++)
        {
            if (kuohao == 1 && flag2 == 0 && rand() % 2 == 1 && j != qnum)
            {
                printf(" ( ");
                if (wenjian == 1)
                {
                    fprintf(fp, " ( ");
                }
                flag2 = 1;
                flag1 = 1;
            }
            if (zorx == 1)
            {
                yinzi = rand() % max + 1;
                cout << yinzi;
                if (wenjian == 1)
                {
                    fprintf(fp, "%d", yinzi);
                }
            }
            if (zorx == 2)
            {
                yinzif = rand() / (double)(RAND_MAX / max);
                printf("%.1f", yinzif);
                if (wenjian == 1)
                {
                    fprintf(fp, "%.1f", yinzif);
                }
            }
            if (kuohao == 1 && flag2 == 1 && rand() % 2 == 1 && flag1 != 1)
            {
                printf(" ) ");
                if (wenjian == 1)
                {
                    fprintf(fp, " ) ");
                }
                flag2 = 0;
            }
            flag1 = 0;
            if (j != qnum)
            {
                yunsuanfuxz = rand() % 4;
                switch (yunsuanfuxz)
                {
                    case 0:
                        if (yunsuanfu[0] == 1)
                        {
                            printf(" + ");
                            if (wenjian == 1)
                            {
                                fprintf(fp, " + ");
                            }
                            break;
                        }
                        else
                        {
                            printf(" + ");
                            if (wenjian == 1)
                            {
                                fprintf(fp, " + ");
                            }
                            break;
                        }
                    case 1:
                        if (yunsuanfu[1] == 1)
                        {
                            printf(" - ");
                            if (wenjian == 1)
                            {
                                fprintf(fp, " - ");
                            }
                            break;
                        }
                        else
                        {
                            printf(" + ");
                            if (wenjian == 1)
                            {
                                fprintf(fp, " + ");
                            }
                            break;
                        }
                    case 2:
                        if (yunsuanfu[2] == 1)
                        {
                            printf(" * ");
                            if (wenjian == 1)
                            {
                                fprintf(fp, " * ");
                            }
                            break;
                        }
                        else
                        { 
                            printf(" + ");
                            if (wenjian == 1)
                            {
                                fprintf(fp, " + ");
                            }
                            break;
                        }
                    case 3:
                        if (yunsuanfu[3] == 1)
                        {
                            printf(" / ");
                            if (wenjian == 1)
                            {
                                fprintf(fp, " / ");
                            }
                            break;
                        }
                        else
                        {
                            printf(" + ");
                            if (wenjian == 1)
                            {
                                fprintf(fp, " + ");
                            }
                            break;
                        }
                }
            }
        }
        if (flag2 == 1)
        {
            printf(" ) ");
            if (wenjian == 1)
            {
                fprintf(fp, " ) ");
            }
            flag2 = 0;
        }
        cout << "= ? " << endl;
        if (wenjian == 1)
        {
            fprintf(fp, " = ? \n");
        }
    }
    fclose(fp);
}
