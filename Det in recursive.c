#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void add(int N,float Result[][N],float M1[][N],float M2[][N]){
        int i,j;
        printf("Output:\n");
        for(i=0;i<N;i++)
                for(j=0;j<N;j++){//�ۥ[��JRESULT
                        Result[i][j] = M1[i][j] + M2[i][j];
                        printf("%.0f ",Result[i][j]);
                }
        printf("\n");

}
void multiplication(int N,float Result[][N],float M1[][N],float M2[][N]){
        int i,j,k;
        float sum = 0.0;
        printf("Output:\n");
        for(i=0;i<N;i++){
                for(k=0;k<N;k++){//��C�����ۭ�
                        for(j=0;j<N;j++)
                                sum += M1[i][j]*M2[j][k];
                        Result[i][k] = sum;
                        printf("%.0f ",Result[i][k]);
                        sum = 0.0;
                }
        }
        printf("\n");
}
float det(int N,float R[][N]){
        int i,j,k,itemp=0,jtemp=0;
        float ispositive;
        float sum = 0.0;
        if(N==1)return R[0][0];//N=1,2���e����
        float arr[N-1][N-1];
        if(N==2){	//�^��2*2�x�}����C���ȡA�D�n���פ����
                return (R[0][0]*R[1][1]-R[0][1]*R[1][0]);
        }
        for(i=0;i<N;i++){
                for(k=1;k<N;k++){//K������0
					//��C����0�C������
                        for(j=0;j<N;j++){//�P�˦檺������
                                if(j==i)continue;
                                arr[itemp][jtemp] = R[k][j];
                                jtemp++;//�ŦX�W�w�N��Jarr
                                if(jtemp==N-1){
                                        itemp++;//��@�C���F�N���U
							//�@�C�������k0
                                        jtemp = 0;
                                }
                        }
                }
                jtemp = 0;
                itemp = 0;
                if(i%2==0)ispositive = 1.0;
                else ispositive = -1.0;//mod�ᬰ0�̬�1�_�h-1
                sum += R[0][i]*det(N-1,arr)*ispositive;
			//��C���̫�N�ȥ[�_�ӨéI�s���j�M�D����
        }
        return sum;
}
int main(int argc,char *argv[]){
        int n,m,x,i,j,temp;
        srand(time(NULL));
        n = atoi(argv[1]);
        m = atoi(argv[2]);//�r���ন�Ʀr
        x = atoi(argv[3]);
        float M1[n][n];
        float M2[n][n];
        float Result[n][n];
        if(x==0){
                for(i=0;i<n;i++){
                        for(j=0;j<n;j++){//��ƪ�100���ü�cast
						//�B�I��
                                M1[i][j]=(float)(rand()%100+1);
                                M2[i][j]=(float)(rand()%100+1);
                        }
                }
        }else if(x==1){
                for(i=0;i<n;i++)
                        for(j=0;j<n;j++)
                               scanf("%f" ,&M1[i][j]);
                for(i=0;i<n;i++)//��ʿ�JM1M2
                        for(j=0;j<n;j++)
                               scanf("%f",&M2[i][j]);
        }
        printf("Input:\n");
        for(i=0;i<n;i++)
                for(j=0;j<n;j++)
                        printf("%4.0f",M1[i][j]);
        printf("\n");
         for(i=0;i<n;i++)
                for(j=0;j<n;j++)//M1M2�L�X
                        printf("%4.0f",M2[i][j]);
        printf("\n\n");
        printf("Operation:\n");
        switch(m){
                case 0:
                        printf("Add\n\n");
                        add(n,Result,M1,M2);//����[�k
                        break;
                case 1:
                        printf("Multiplication\n\n");
                        multiplication(n,Result,M1,M2);
                        break;//����}�C�ۭ�
                case 2:
                        printf("Det\n\n");
                        printf("det(M1) = %.0f\n",det(n,M1));
                        printf("det(M2) = %.0f\n",det(n,M2));
                        break;//��Ӱ}�C����C��
        }
        printf("\n");
}

