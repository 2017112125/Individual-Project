#include <stdio.h>
int main( void )
{	
	//���ļ� 
    FILE *p = fopen("one.txt","r");
    int c=0,i=0,t=0;
    int ch[256]={0};
   	//���ļ��е�256���ֽ�ֵ����¼���� 
    while( (c=fgetc(p)) != EOF)
        ch[c]++;                 
    fclose(p); 
    //�����������ڴ��26����ĸ
	//��ĸͳ�Ʋ����ִ�Сд
	//A��a����ͬһ��ĸ 
    int num[26]={0};
	//a 97 z 122 A 65 Z 95

	for(t=0;t<26;t++){
		num[t]=ch[t+97]+ch[t+65];
		//��ĸ��Ŀ�Ľ���洢��num������ 
	}
	
	//������� printf("%c : %d",t+65,num[t]);
	//��дһ�����飬���ڱ���num������Ԫ�صĴ�С���
	//compare com[26] 
	int compare[26]={0};
	for(t=0;t<26;t++){
		compare[t]=num[t];
	}
	//��compare�������ð������
	int j=0;
	int temp=0;
	for(t=0;t<26-1;t++){
		for(j=0;j<26-1-t;j++){
			if(compare[j]<compare[j+1]){
				temp=compare[j];
				compare[j]=compare[j+1];
				compare[j+1]=temp;
			}
		}
	} 
	//������Դ��� 
//	for(t=0;t<26;t++){
//		printf("%c : %d  %d\n",t+65,num[t],compare[t]);
//	}
	for(t=0;t<26;t++){
		for(j=0;j<26;j++){
			if(compare[t]==num[j]){
				printf("%c:  %d\n",j+65,num[j]);
			}
		}
	}

}
