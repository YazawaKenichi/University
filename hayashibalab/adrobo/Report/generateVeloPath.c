/****************************************************************/
/* Generating Path File                                         */
/*                                                              */
/*                            ZD.Wang   Orgiinal .Dec. 21, 2008 */
/*                        Revised  Dec.11, 2016 and Dec.5, 2020 */
/****************************************************************/

// 両車輪の速度を格納した csv データを使って、その値を 1000 倍して配列にするだけのプログラム。

#include<stdio.h>
#include<stdlib.h>

int main(){
	FILE *fp1, *fp2;
	int cnt=0;
	int t_cnt=0;
	double v_right, v_left;
	
	if((fp1 = fopen("Data.csv", "r"))==NULL){
		fprintf(stderr, "Can not find Data.csv\n");
		exit(1);
	}
	if((fp2 = fopen("path_data.h","w"))==NULL){
		fprintf(stderr, "Can not find DataPath.txt\n");
		exit(1);
	}
	

	fprintf(fp2, "const double velo_data[]={\n");
	while(fscanf(fp1, "%lf ,%lf", &v_right, &v_left) != EOF){
		if(t_cnt == 1){
			fprintf(fp2, "\t%lf ,\t%lf,\n", (double)(v_right*1000), (double)(v_left*1000) );
			cnt++;
			t_cnt = 0;
		}
		else
			t_cnt++;
        }

	fprintf(fp2, "\t0,\t0};\n\n");
        
	fprintf(fp2, "#define MaxNum %d\n", cnt );
        
	fclose(fp1);
	fclose(fp2);
	
	printf("The header file of velocity trajectories path_data.h is generated sucessfully.\n");

          return 0;
}

