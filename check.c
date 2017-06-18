#include <stdio.h>
#include <string.h>

#define MAX_SIZE 256

char func_name[2][MAX_SIZE];

/* store __func__ into char func_name */
int def_func(int func_num, const char *func){
	strcpy(func_name[func_num], func);
	strcat(func_name[func_num], "()");
	printf("function defined: %d -- %s --\n", func_num+1, func_name[func_num]);
	return 0;
}

/* hehe checking */
int check_laugh(int argc, char *argv[]){
	int i = 0;
	int laugh_count = 0;

	def_func(1, __func__);

	do{
		if (strncmp(argv[i], "hehe", 4) == 0){
			laugh_count++;
		}
		i++;
	} while(i < argc);
	printf("laugh_count: %d...\n", laugh_count);
	printf("%s terminated. Returning to %s...\n", func_name[1], func_name[0]);
	return 0;
}

int main(int argc, char *argv[]){
	def_func(0, __func__);

	if (argc < 2){
		printf("- CHECK FOR HEHE -\n");
		printf("USAGE: ./check [hehe]\n");
	}
	else{
		check_laugh(argc, argv);
	}
	return 0;
}
