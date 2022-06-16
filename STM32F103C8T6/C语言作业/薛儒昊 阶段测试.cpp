#include <stdio.h> 

int main()
{
	int n=0;
	int sl=0;
	int sum[100];
	int i;
	double count=0;
	double x=0;
	scanf("%d %d",&n,&sl);
	
	struct simple{
		int number;
		int score[4];
	};
	
	struct simple student[100];
	for(i=0;i<n-1;i++){
		scanf("%d %d %d %d %d\n",&student[i].number,&student[i].score[0],&student[i].score[1],&student[i].score[2],&student[i].score[3]);
	}
	
	for(i=0;i<n-1;i++){
		sum[i]=student[i].score[0]+student[i].score[1]+student[i].score[2]+student[i].score[3];
		if(sum[i]>sl){
			printf("%d %d\n",student[i].number,sum[i]);
			count++;
		}
	}

	printf("%.f %.1f%%",count,x=(count/n)*100);
	return 0; 
}
