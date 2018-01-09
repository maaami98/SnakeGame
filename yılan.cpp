#include <windows.h>
#include <iostream>
#include <conio.h>
#include <ctime>

	int secim; //yön secimi
	int uzunluk=10;
	int x1=10,y1=45; //baþlangýç yýlan kordinatý
	int konumx[1000]; //yýlanýn konum kordinatlarý kaydedilcek 
	int konumy[1000];
	int n=0;
	int cilekx=16; //cileðin varsayýlan kordinatlarý
	int cileky=25;
	char a[20][90];//ana ekran
int main()
{

	srand(time(NULL)); //rasgele sayý vermek için gerekli
	
	
	do{		
		for(int i=0;i<20;i++){//alan temizleme
			for(int j=0;j<90;j++)a[i][j]=' ';	}
			
			
	a[ cilekx ][ cileky ]='*';
	
	for(int i=0;i<90;i++)//yatay eksen çizgiler
		{
			a[0][i]='#';
			a[19][i]='#';
			
		 } 
		 
	for(int i=0;i<20;i++)//diken eksen çizgiler
		{
			a[i][0]='#';
			a[i][89]='#';
			
		 }
	konumx[n]=x1;//yýlan konumunu dizide saklýyoruz
	konumy[n]=y1;
	if(kbhit())//tuþ algýlanýrsa getch() çalýþtýr
	if(getch()==224)switch(getch())//eðer tuþ giriþi varsa getch secim
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
	
	
	 switch(secim)//en son seçime göre hareket et
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
			
			
	for(int i=0;i<uzunluk;i++)		//KONUMA GÖRE KUYRUK
		{
				a[konumx[n-i]][konumy[n-i]]='O'; //uzunluðu kadar konumda geri gider
		}
		n++; 
		if(a[x1][y1]=='*')//KAFASI MANTARA DEÐERSE YE
			{
				uzunluk++;
				a[x1][y1]=' ';
				cilekx=rand()%19;
				cileky=rand()%89;
				} 
		
		
			else if(a[x1][y1]!=' ')break;//GÝTTÝÐÝ YER BOÞLUK DEÐÝLSE BÝTÝR
			
	
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
