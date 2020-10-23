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

int match(char* s1, char* s2) {
	_asm {
		mov esi, s1
		mov edi, s2
		cld
		mov cx, 10
		repz cmpsb
		je True
	}
	return 0;
	True:_asm {
	}
	return 1;
}

int toCal(Student * str) {
	_asm {
		mov edi,str
		mov eax, 0
		mov edx, 0
		mov eax, [edi].grade1
		add eax, eax
		add eax,eax
		mov edx, [edi].grade2
		add edx,edx
		add eax, edx
		mov edx, [edi].grade3
		add eax, edx
		cdq
		mov ecx,7
        idiv ecx	 
		mov [edi].avg, eax
	}
}

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

	while (true) {
		printf("Please input a student s name: \n");
		printf("(enter q to quit, enter 1 to calculate the avarage grade)\n");
		//用0比较来占位
		for (int j = 0; j < 10; j++) {
			input[j] = 0;
		}
		gets(input);
		if (match(input, str1)) {
			printf("exit program!\n");
			//delete(input);
			return 0;
		}
		if (match(input, str2)) {
			printf("Successfully calculated!\n");
			for (int i = 0; i < N; i++) {
				toCal(&students[i]);
			}
		}
		else {
			for (int i = 0; i < N; i++) {
				if (match(input, students[i].name)) {
					flag = 1;
					ptr = i;
					break;
				}
			}
			if (flag) {
				toCal(&students[ptr]);
				int grade = students[ptr].avg;
				printf("%d \n", grade);
				printf("The grade of %s is %c !\n", input, grade >= 90 ? 'A' : grade >= 80 ? 'B' : grade >= 70 ? 'C' : grade >= 60 ? 'D' : 'F');
				flag = 0;
			}else
				printf("Sorry, the name does not exist.\n");
		}
		printf(" anything to continue...");
		char c = getchar();
	}
	return 0;
}
