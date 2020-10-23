#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int N = 50;//学生总数

typedef struct MyStruct
{
	char name[10];
	int grade1;
	int grade2;
	int grade3;
	int avg;
}Student;

extern "C" {int match(char* str1, char* str2); }

extern "C" { int toCal(int g1,int g2,int g3); }

int main() {
	//定义数据
	Student students[50];
	Student stu1 = {
		"zhangsan",
		100,85,80
	};
	Student stu2 = {
		"list",
		70,100,80
	};
	Student stu = {
		"TempValue",
		80,90,95
	};
	Student me = {
		"zhangbosi",
		100,100,100
	};
	students[0] = stu1;
	students[1] = stu2;
	students[49] = me;

	for (int i = 2; i < N - 1; i++) {
		students[i] = stu;
	}
	int flag = 0;
	int ptr = 0;
	char input[10];
	//待比较字符串
	char str1[10] = "q";
	char str2[10] = "1";


	while (1) {
		printf("Please input a student s name: \n");
		printf("(enter q to quit, enter 1 to calculate the avarage grade)\n");
		//用0比较来占位
		for (int j = 0; j < 10; j++) {
			input[j] = 0;
		}
		gets(input);
		if (match(input, str1) == 1) {
			printf("exit program!\n");
			return 0;
		}
		if (match(input, str2) == 1) {
			printf("Successfully calculated!\n");
			for (int i = 0; i < N; i++) {
				students[i].avg = toCal(students[i].grade1,students[i].grade2,students[i].grade3)/7;
			}
		}
		else {
			for (int i = 0; i < N; i++) {
				if (match(input, students[i].name) == 1) {
					flag = 1;
					ptr = i;
					break;
				}
			}
			if (flag) {
				int grade = toCal(students[ptr].grade1,students[ptr].grade2,students[ptr].grade3)/7;
				printf("%d \n", grade);
				//printf("successfully searched");
				printf("The grade of %s is %c !\n", input, grade >= 90 ? 'A' : grade >= 80 ? 'B' : grade >= 70 ? 'C' : grade >= 60 ? 'D' : 'F');
				flag = 0;
			}
			else
				printf("Sorry, the name does not exist.\n");
		}
		printf(" anything to continue...");
		char c = getchar();
	}
	system("pause");
	return 0;
}