#include <stdio.h>
#include <math.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<iomanip>
#include<iostream>
#include<time.h>
#include<string>
#include<windows.h>
using namespace std;
#define eps 0.000001
char in[20];
const int maxN = 15;
float a[maxN][maxN];
int n;
float x[maxN];
float u[maxN];
char s[50];
void docfile(FILE *f1);
void menu();
void thuattoangiai(int n);
int luachon2;
int z=0;
int b=0;
class DACS
{
public:
	void docfile(FILE *f1,float a[15][15] )
	{
			int i, j;
	if (f1 != NULL)
	{
		fscanf(f1, "%d", &n);
		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= n + 1; j++)
			{
				if (!feof(f1) || f1 != 0)
				{
					fscanf(f1, "%f", &a[i][j]);
					z = 1;
				}
				else
				{
					printf("\t\tdu lieu khong hop le\n");
					z = 0;
					break;
				}
			}
		}
	}
	else
	{
		printf("\t\tfile khong ton tai");
		getch();
		return;
	}
	fclose(f1);
	}
	void thuattoangiai(int n)
	{
	
	int t;
	int c=0;
    float  r[maxN];
        for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n + 1; j++) {
        	if (i != j) a[i][j] /= a[i][i];
        }
        a[i][i] = 1;
    }
     
    // tinh r[i] ban dau: 
    for (int i = 1; i <= n; i++) {
        r[i] = a[i][n+1];
        for (int j = 1; j <= n; j++) {
            r[i] = r[i]- a[i][j] * x[j];
        }
    }     
    do {     
    int p;
    p=c;
    printf("\t\t");
   	printf("X%-2d=",p);
 
    for (int i = 1; i <= n; i++)
	{      
	     printf("%8.3f", x[i]);
	}

		 printf("\n"); 
		 
        t = 0; // dk dung    
        // tim max(abs(r[i]));
        int idx = 1;
        for (int i = 2; i <= n; i++) {
            if (fabs(r[i]) > fabs(r[idx])) idx = i;
        }
        x[idx] += r[idx];    
        // tinh lai r[i] kiem tra tiep tuc lap:
        float d = r[idx];
        for (int i = 1; i <= n; i++) {
            r[i] -= a[i][idx] * d;
            if (fabs(r[i]) >= eps) t = 1;
        }    
        c=c+1;
    } while (t);  
    printf("\t\tNghiem cua hpt la: \n");
    printf("\t\tx=(");
    for (int i = 1; i <= n; i++)
	{
        printf("% 3.2f",x[i]);
    
            if(i==n)
            {
	            printf("");          
            }
            else
            {
                printf(";");    
            }   
    }  
    printf(")");
   	}
};
int main()
{
	DACS CS;
	printf("\t\t********NHOM:18N13B-N6 \n");
	printf("\t\t********Thanh vien :\n");
	printf("\t\t                    Ho Viet Phu\n");
	printf("\t\t                    Luong Thi Thuy Ngoc\n");
	printf("\t\t********De Tai:Tim nghiem bang phuong phap giam du");
	printf("\n\t\t                   bat dau");
	int q=1;
	int luachon=0,luachon1;
	FILE *f1;
	f1 = fopen("D:\\file4","r");
	HANDLE hConsoleColor;
    hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
	while(true)
	{
		system("cls");
        SetConsoleTextAttribute(hConsoleColor, 79);
        printf("\n\t\t                                                         \n");
        printf("\t\t               GIAI HE PHUONG GIAM DU                    \n");
        printf("\t\t                                                         \n");
        SetConsoleTextAttribute(hConsoleColor, 96);
        printf("\t\t  1.Nhap du lieu cua he phuong trinh                     \n");
        printf("\t\t---------------------------------------------------------\n");
        printf("\t\t  2.Nhap VecTor Nghiem Ban Dau                           \n");
        printf("\t\t---------------------------------------------------------\n");
        printf("\t\t  3.Tim Nghiem Cua Phuong Trinh                          \n");
        printf("\t\t---------------------------------------------------------\n");
        printf("\t\t  0.Thoat                                                \n");
        printf("\t\t---------------------------------------------------------\n");
        SetConsoleTextAttribute(hConsoleColor, 3);
        cout<<"\n\t\t-->Hay nhap lua chon cua ban: ";
     	scanf("\t\t%d",&luachon);
		if(luachon==1)
			{

				while(true)
				{
				system("cls");	
                        SetConsoleTextAttribute(hConsoleColor, 79);
                        printf("\n\t\t                                                         \n");
                        printf("\t\t       Nhap Du Lieu Cho Phuong Trinh                     \n");
                        printf("\t\t                                                         \n");
                        SetConsoleTextAttribute(hConsoleColor, 96);
                        printf("\t\t  1.Nhap Du Lieu Tu File                                 \n");
                        printf("\t\t---------------------------------------------------------\n");
                        printf("\t\t  2.Nhap Du Lieu Ngau Nhien                              \n");
                        printf("\t\t---------------------------------------------------------\n");
                        printf("\t\t  0.Quay lai                                             \n");
                        SetConsoleTextAttribute(hConsoleColor, 3);
				        printf("\n\t\t--> moi ban nhapm lua chon:");
			            scanf("\t\t%d",&luachon1);
			            SetConsoleTextAttribute(hConsoleColor, 7);
					if(luachon1==2)
						{
							time_t t;
							srand((unsigned) time(&t));
							printf("\n\t\t ban muon giai phuong trinh bao nhieu nghiem");
							scanf("\t\t%d",&n);
							
							for (int i = 1; i <= n; i++)
							{		
                                for (int j = 1; j <= n + 1; j++)
								{
							       a[i][j]=rand()%5000-1000;
							       z=1;
							    }
							}
						if(z==1)
							{
						    	for (int i = 1; i <= n; i++)
							    { 
							    printf("\t\t");
								printf("||");
										
                                for (int j = 1; j <= n ; j++)
                                {
                                	printf(" %3.2f*x%d ",a[i][j],j);
                                	if(j==n)
                                	{
									    printf("");
                                	}
                                	else
                                	{
                                		if(a[i][j+1]<0)
                                		{
                                			cout<<"";
                                		}
                                		else
										{
                                		printf("+");
                                		}
                                	}
								}
								printf("=%3.2f",a[i][n+1]);
								printf("\n");
								}
							}
							system("pause");
						}	
					else if(luachon1==1)
						{
						
							printf("\t\t-->moi ban nhap duong dan file chua phuong trinh \n");
							printf("\t\t");
							cin.ignore();
	                        cin.getline(s,50);
	                        FILE *f1;
	                        f1= fopen(s,"r");
	                        CS.docfile(f1,a);    
		    			if(z==0)
		    			{
		    				printf("\n\t\tphuong tri bi sai moi nhap lai");		    				
		    			}
		    			if(z==1)
		    			{
		    					for (int i = 1; i <= n; i++)
							    { 	
							    printf("\t\t");
                                for (int j = 1; j <= n+1 ; j++)
                                {
                                	
                                	printf("||");
	                               	printf("  %8.2f   ",a[i][j]);
                                         	
								}
							     	printf("\n");
								}
		    			}	
						system("pause");						
						}
						else if(luachon1==0)
						{
							break;
						}						
				}
			}
		else if(luachon==2)
			{
				if(z==0)
				{
					printf("\t\tban chua co du lieu nhan so 1\n");
				}
				if(z==1)
				{
				
				printf("\t\t||\n");
				printf("\t\t\\/");
				b=1;
				printf("\n\t\tNhap vector nghiem ban dau: \n");
				for (int i = 1; i <= n; i++)
				{
					printf("\t\t");
                  scanf("%f", &x[i]);
                }
                printf("\t\tx=(");
                for (int i = 1; i <= n; i++)
				{
                  printf("% 3.2f",x[i]);
                    if(i==n)
                 	{
				        printf("");
                    }
                    else
                    {
                        printf(";");
                    }
                }  
                printf(")");
            }
                system("pause");
            }
        else if(luachon==3)
		    {
		    	if(z==0)
		    	{
		    		SetConsoleTextAttribute(hConsoleColor, 7);
		    		printf("\t\tban chua co du lieu nhan so 1\n");  
		    		 
		    		system("pause");
		    	}
 		        if(z==1&&b==0)
 		        {
				 	printf("\t\tban chua co du lieu nhan so 2\n");
				 	system("pause");
		    	}
				if(z==1&&b==1)
				{
		            CS.thuattoangiai(n);
		            system("pause");
		            	
		            	while(true)
		            	{
		            		system("cls");
		            	printf("\n");
                       SetConsoleTextAttribute(hConsoleColor, 79);
                        printf("\n\t\t                                                          \n");
                        printf("\t\t       Ban co muon thay doi vecto nghiem ?                \n");
                        printf("\t\t                                                          \n");
                        SetConsoleTextAttribute(hConsoleColor, 96);
                        printf("\t\t      0.KHONG                                             \n");
                        printf("\t\t--------------------------------------------------------- \n");
                        printf("\t\t      1.CO                                                \n");
                        printf("\t\t--------------------------------------------------------- \n");
                        printf("\t\t      2 IN KET QUA RA FILE                                \n");
                        printf("\t\t----------------------------------------------------------\n");
                        SetConsoleTextAttribute(hConsoleColor,3);
		            	printf("\t\t-->moi ban nhap : ");
		            	scanf("%d",&luachon2);
		            	SetConsoleTextAttribute(hConsoleColor, 7);
		            		if(luachon2==0)
		            			{
		            			printf("\t\tchuong trinh da xong\n");
		            			system("pause");
		            			system("cls");
		            			z=0;
		            			b=0;
		            			break;
		            			}
		            		else if(luachon2==1)
								{
									printf("moi ban nhap-->\n");
									for (int i = 1; i <= n; i++)
			                       	{
			                       		printf("\t\t");
                                        scanf("%f", &x[i]);
                                    }									
                                    printf("\t\tphuong trinh moi cua ban la\n");     
									printf("\t\tx=(");                              
                                    for (int i = 1; i <= n; i++)
				                    {
                                        printf("% 3.2f",x[i]);
                                        if(i==n)
                                  	    {
				                            printf("");
                                        }
                                        else
                                        {
                                            printf(";");
                                        }
                                    }  
                                    printf(")");
                                    printf("\n");
                                    CS.thuattoangiai(n);
                                    system("pause");
                                    }
                                    else if(luachon2==2)
                                    {
                                    for(int i=1;i<=n;i++)
                                    {
                                     	u[i]=x[i];
                                        FILE *fptr;
                                       	printf("nhap duong dan file can in");
                                    	cin.ignore();
                                        scanf("%s",in);
                                        fptr = fopen(in,"w+");
                                       	int t;
                                    	int c=0;
                                        float  r[maxN];
                                        for (int i = 1; i <= n; i++)
									    {
                                            for (int j = 1; j <= n + 1; j++) 
											{
                                              	if (i != j) a[i][j] /= a[i][i];
                                            }
                                             a[i][i] = 1;
                                        }
     
                                          // tinh r[i] ban dau: 
                                        for (int i = 1; i <= n; i++) 
										{
                                            r[i] = a[i][n+1];
                                            for (int j = 1; j <= n; j++) 
											{
                                                 r[i] = r[i]- a[i][j] * u[j];
                                            }
                                        }     
                                        do {     
                                        int p;
                                        p=c;
                                        printf("\t\t");
                                       	printf("X%-2d=",p);
   	                                    fputs("X",fptr);
   	                                    fprintf(fptr, "%-2d",p );
                                    	fputs("=",fptr);
                                        for (int i = 1; i <= n; i++)
                                      	{   	     
	                                        printf("%8.3f", x[i]);
	                                        fprintf(fptr, "%8.3f",u[i] );	     
                                      	}
                                      	fprintf(fptr, "\n" );
	                                    printf("\n"); 
		 
                                        t = 0; // dk dung    
                                            	  // tim max(abs(r[i]));
                                        int idx = 1;
                                        for (int i = 2; i <= n; i++)
										{
                                     	    if (fabs(r[i]) > fabs(r[idx])) idx = i;
                                        }
                                        x[idx] += r[idx];    
                                     	 // tinh lai r[i] kiem tra tiep tuc lap:
                                     	 float d = r[idx];
                                        for (int i = 1; i <= n; i++)
										{
                                     	    r[i] -= a[i][idx] * d;
                                            if (fabs(r[i]) >= eps) t = 1;
                                        }
                                        c=c+1;
										}
										 while (t);  
                                        printf("\t\tNghiem cua hpt la: \n");
                                        fputs("Nghiem cua hpt la :",fptr);
                                        fputs("x=(",fptr);
                                        printf("\t\tx=(");
                                        for (int i = 1; i <= n; i++)
                                      	{
                                        	printf("% 3.2f",u[i]);
                                            fprintf(fptr, "%3.2f",u[i] );
                                            if(i==n)
                                            {
	                                            printf(""); 
	                                            fputs("",fptr);
                                            }
                                            else
                                       	    {
                                            printf(";");
                                            fputs(";",fptr);
                                            }
                                       	}  
                                   	    printf(")");
                                        fputs(")",fptr);
                                        fclose(fptr);
                                        printf("\t\t\nin thanh cong !");
                                        break;
                                       	}
                                    break;
								}
		            	}
		            	system("pause");	 
		            }
		        }
		else if(luachon == 0)
		{
			break;
		}	
	    
   }
   			
}


