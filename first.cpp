#include <stdio.h>
int main( void )
{	
	//打开文件 
    FILE *p = fopen("one.txt","r");
    int c=0,i=0,t=0;
    int ch[256]={0};
   	//将文件中的256种字节值都记录下来 
    while( (c=fgetc(p)) != EOF)
        ch[c]++;                 
    fclose(p); 
    //定义数组用于存放26个字母
	//字母统计不区分大小写
	//A与a属于同一字母 
    int num[26]={0};
	//a 97 z 122 A 65 Z 95

	for(t=0;t<26;t++){
		num[t]=ch[t+97]+ch[t+65];
		//字母数目的结果存储到num数组中 
	}
	
	//排序输出 printf("%c : %d",t+65,num[t]);
	//重写一个数组，用于保存num数组中元素的大小情况
	//compare com[26] 
	int compare[26]={0};
	for(t=0;t<26;t++){
		compare[t]=num[t];
	}
	//将compare数组进行冒泡排序
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
	//输出测试代码 
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
