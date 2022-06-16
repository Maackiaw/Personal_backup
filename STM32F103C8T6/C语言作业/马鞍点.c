#include<stdio.h>

int main()

{

	int a[4][4];
	int i,j,k,i0,j0,x=0;

	for (i=0;i<4;i++){
		for (j=0;j<4;j++){
			scanf("%d",&a[i][j]);
		} 
	}

	for(i=0;i<4;i++){
		j0=0;
			for(j=1;j<4;j++)
				if(a[i][j]>a[i][j0]){
					j0=j;
					k=1;
				}
		for(i0=0;i0<4;i0++)
			if(a[i0][j0]<a[i][j0]){
				k=0;
		    }
			if(k){
				printf("°°µã£ºa[%d][%d]=%d\n",i,j0,a[i][j0]);
				x=1;
			}
	}
	if(x!=1)
		printf("ÎÞ°°µã\n");

	return 0;

}
