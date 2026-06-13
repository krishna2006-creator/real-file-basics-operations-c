#include<stdio.h>
void createfile(){
	printf("creating file opened\n");
	char filename[100];
	printf("enter the file name with .txt:\n");
	scanf("%s",filename);
	FILE *fp=fopen(filename,"w");
	if(fp==NULL){
		printf("error\n");
	}
	else{
		printf("file is created\n");
	}
	fclose(fp);
}
void writefile(){
	printf("writing a file is opened");
	char filename[100];
	printf("enter the file name to open to write:\n");
	scanf("%s",filename);
	FILE *fp=fopen(filename,"a");
	if(fp==NULL){
		printf("error\n");
	}
	else{
		printf("file is there:\n");
		printf("the file is ready to write:\n");
	}
	int c;
	while((c=getchar())!=EOF){
			fprintf(fp,"%c",c);
			if(c=='\t'){//i written by this u can use any keyword that u want 
				break;
			}
	}
	fclose(fp);
}
void readfile(){
	printf("reading file\n");
	char filename[100];
	printf("enter the file name to read:\n");
	scanf("%s",filename);
	FILE *fp=fopen(filename,"r");
	if(fp==NULL){
		printf("error\n");
		printf("there is nothing\n");
	}
	else{
		char line[1000];
		while(fgets(line,sizeof(line),fp)){
				printf("%s",line);
				}
				}
				fclose(fp);
}
void deletefile(){}
void renamefile(){}
int main(){
	int choice=0;
	do{
	printf("enter the choice given below\n");
	printf("1.create file\n");
	printf("2.write file\n");
	printf("3.read file\n");
	printf("4.delete file\n");
	printf("5.rename file\n");
	printf("6.exit\n");
	scanf("%d",&choice);
	switch(choice){
		case 1:
			createfile();
			break;
		case 2:
			writefile();
			break;
		case 3:
			readfile();
		case 4:
			deletefile();
			break;
		case 5:
			renamefile();
			break;
                case 6:
			printf("exit");
			break;
		default:
			printf("choose the correct choice");
}
}while(choice!=6);

return 0;
}
