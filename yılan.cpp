#include <windows.h>
#include <iostream>
#include <conio.h>
#include <ctime>

	int secim; //y�n secimi
	int uzunluk=10;
	int x1=10,y1=45; //ba�lang�� y�lan kordinat�
	int konumx[1000]; //y�lan�n konum kordinatlar� kaydedilcek 
	int konumy[1000];
	int n=0;
	int cilekx=16; //cile�in varsay�lan kordinatlar�
	int cileky=25;
	char a[20][90];//ana ekran
int main()
{

	srand(time(NULL)); //rasgele say� vermek i�in gerekli
	
	
	do{		
		for(int i=0;i<20;i++){//alan temizleme
			for(int j=0;j<90;j++)a[i][j]=' ';	}
			
			
	a[ cilekx ][ cileky ]='*';
	
	for(int i=0;i<90;i++)//yatay eksen �izgiler
		{
			a[0][i]='#';
			a[19][i]='#';
			
		 } 
		 
	for(int i=0;i<20;i++)//diken eksen �izgiler
		{
			a[i][0]='#';
			a[i][89]='#';
			
		 }
	konumx[n]=x1;//y�lan konumunu dizide sakl�yoruz
	konumy[n]=y1;
	if(kbhit())//tu� alg�lan�rsa getch() �al��t�r
	if(getch()==224)switch(getch())//e�er tu� giri�i varsa getch secim
				{
					case 77:{secim=0;
						break;
					}
					
					case 75:{secim=1;
						break;
					}
					
					case 80:{secim=2;
						break;
					}
					
					case 72:{secim=3;
						break;
					}
				}
	
	
	 switch(secim)//en son se�ime g�re hareket et
			{
				case 0:{y1++;
					break;
				}
				case 1:{y1--;
					break;
				}
				case 2:{x1++;
					break;
				}
				case 3:{x1--;
					break;
				}
			}
			
			
	for(int i=0;i<uzunluk;i++)		//KONUMA G�RE KUYRUK
		{
				a[konumx[n-i]][konumy[n-i]]='O'; //uzunlu�u kadar konumda geri gider
		}
		n++; 
		if(a[x1][y1]=='*')//KAFASI MANTARA DE�ERSE YE
			{
				uzunluk++;
				a[x1][y1]=' ';
				cilekx=rand()%19;
				cileky=rand()%89;
				} 
		
		
			else if(a[x1][y1]!=' ')break;//G�TT��� YER BO�LUK DE��LSE B�T�R
			
	
		printf("\n\n\n\t");
	for(int i=0;i<20;i++){////EKRAN YAZDIRMA

		for(int j=0;j<90;j++)printf("%c",a[i][j]);
		printf("\n\t");	}


Sleep(100);
system("cls");
}while(1);
printf("Oyun Bitmistir.\n");
printf("Skor:%d.\n",uzunluk);

Sleep(3000);
}//main sonu
