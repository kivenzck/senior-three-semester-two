//题目B1：代码分析器
//（一）课题内容
//读入C源文件，统计文件中的代码、注释和空行的行数以及函数的个数和平均行数，并利用统计信息分析评价该程序的风格。
//（二）课题要求
//(1)	将程序文件按字符顺序读入源程序；
//(2)	边读入程序，边识别统计代码行、注释行和空行，同时还要识别函数的开始和结束，以便统计其个数和平均行数。
//(3)	程序的风格评价分为代码（函数平均长度）、注释（占总行数比例）和空行（占总函数比例）三个方面。每个方面分为A，B，C:和D 四个等级。等级的划分标准如下：
//(4)	测试时先对较小程序进行分析。当你的程序能正确运行时，对你的程序本身进行分析。
//【其他要求】
//(1)	变量、函数命名符合规范。
//(2)	注释详细：每个变量都要求有注释说明用途；函数有注释说明功能，对参数、返回值也要以注释的形式说明用途；关键的语句段要求有注释解释。
//(3)	程序的层次清晰，可读性强。

#pragma warning(disable:4996) //解决返回值被忽略问题 scanf
#include<iostream>
#include<stdio.h>
#include"analy.h"

using namespace std;

#define COUNT 20 // 可以统计的最大的文件个数
#define LEN 20 // 文件名的最大长度

int main()
{
	int i=0;
	int c;
	char filename[COUNT][LEN];
	printf("\t-------------------------------------------------------------\n");
	printf("\t                         代码分析器 \n");
	printf("\t-------------------------------------------------------------\n");
	while (1) {
		printf("\t\t\t**********程序分析*********\n");
		printf("请输入您要分析的源文件: ");
		scanf("%s", filename[i]);
		fflush(stdin);//使用“fflush（stdin）”清除某些编译器中的输入缓冲区
		analy(filename);
		cout << "\t----------------------------------------------------------" << endl;
		cout << "\t               1.分析其他代码   2.退出                    " << endl;
		cout << "\t----------------------------------------------------------" << endl;
		cout << "请输入序号 ： ";
		cin >> c;
		if (c == 1) {
			system("cls");	//清屏
			getchar();	  //清除缓存
			main();
		}
		return 0;
	}
}