#include "iGraphics.h"
#include <stdlib.h>
#include <time.h>
#include <string.h>

/*
	function iDraw() is called again and again by the system.

	*/

bool jump_call = true;
bool rotate = 1, rotate2 = 0;

int Window[15][16] = {0};
int Tetris[7][4][4] = {0};
// int tetris[4][4]={};
int posx = 6, posy = 12;

int i, j;
bool music =true;
int k=1;
int h,  l;
int T = rand() % 7;
int T1 = 0;
int R = 255, G = 0, B = 0;
int a=0,b=1,c=2,d=3;
int f0=0,f1=0,f2=0,f3=0,f4=0,f5=0,f6=0;
int t[8]={0};
int col;
char Cover[25]="assests\\Cover.bmp";
char Pic1[25]="assests\\Pic1.bmp";
char Pic2[25]="assests\\Pic2.bmp";
char highscore[25]="assests\\highscore.bmp";
char EnterName[25]="assests\\EnterName.bmp";
char Gameover[25]="assests\\Gameover.bmp";
char Play[25]="assests\\Play.bmp";
char Rules[25]="assests\\Rules.PNG";
char Joker[25]="assests\\Joker.bmp";
char Music[25]="assests\\music.png";
char power[25]="assests\\power.jpg";
int gameState =0,gamelevel=0;
int Level;
int score=0,high=0;
int flag=0;
char point[100],lev[100],High[100],hhplayer[100];
int index=0;
char hplayer[100];
char name[100] ;
//int q=3;

// int T= rand() % 2;
//int collision(posy);
void iDraw()
{

	// place your drawing codes here
	iClear();

    if(gameState==7){ 
	iShowBMP(180,140,Gameover);

    
      int k=0;
	  while(name[k]!='\0'){
		name[k]='\0';
		k++;
	  }
	  score=0;
	  index=0;
		for(int i=0;i<15;i++){
			for(int j=0;j<16;j++)
			Window[i][j]=0;
		}
	}

	 FILE *Hscore = fopen("D:\\1-1\\CSE102\\Igraphics\\TETRIS CLONE _ MAIN\\text\\score.txt","r+");
      if(Hscore==NULL){
	printf("NN");
	exit(1);
	  }

	  FILE *Player = fopen("D:\\1-1\\CSE102\\Igraphics\\TETRIS CLONE _ MAIN\\text\\player.txt","r+");
	   if(Player==NULL){
	printf("NN");
	exit(1);
	  }
	  fscanf(Player,"%s",&hplayer);
	  fseek(Player ,0, SEEK_SET);

	  fscanf(Hscore,"%d",&high);
	  fseek(Hscore ,0, SEEK_SET);

	  if(score>high){
		high=score;
    
		strcpy(hplayer,name);
	  }
      fprintf(Hscore,"%d",high);
	  fprintf(Player,hplayer);
	  fclose(Hscore); 
      fclose(Player);
	

    
if(gameState==4){
		iShowBMP(0,0,highscore);
		sprintf(High, "%d", high);
		iText(465,195,High,GLUT_BITMAP_TIMES_ROMAN_24);

		// sprintf(hhplayer, "%s", name);
		iText(250,200,hplayer,GLUT_BITMAP_TIMES_ROMAN_24);
	}

if(gameState==6){
      iShowBMP(244,300,EnterName);
	  iShowBMP(320,45,Play);
iSetColor(255,0,0);
iRectangle(325,190,150,30);
iSetColor(255,255,255);
	iText(364,198, name , GLUT_BITMAP_TIMES_ROMAN_24);
}


	 
	  
	  if(gameState==5)
	iShowBMP(0,0,Rules);
	if(gameState==0) 
	iShowBMP(0,0,Cover);
	if(gameState==1){
	iShowBMP(0,0,Pic1);
    iShowBMP(715,348,"D:\\1-1\\CSE102\\Igraphics\\TETRIS CLONE _ MAIN\\assests\\music.png");
	iShowBMP(24,348,"D:\\1-1\\CSE102\\Igraphics\\TETRIS CLONE _ MAIN\\assests\\power.jpg");
	}
	 if(gameState==2){
	  iShowBMP(610,0,"D:\\1-1\\CSE102\\Igraphics\\TETRIS CLONE _ MAIN\\assests\\Joker.bmp");
      iShowBMP(668,394,"D:\\1-1\\CSE102\\Igraphics\\TETRIS CLONE _ MAIN\\assests\\power.jpg");
	 }
	if(gameState==2){
	iText(630,200, "Score : ", GLUT_BITMAP_TIMES_ROMAN_24);
	sprintf(point, "%d", score);
   iText(710,200, point, GLUT_BITMAP_TIMES_ROMAN_24);

    iText(630,250, "Player : ", GLUT_BITMAP_TIMES_ROMAN_24);
    iText(710,250, name, GLUT_BITMAP_TIMES_ROMAN_24);

	}

	
    if(gameState==3)
	iShowBMP(0,0,Pic2);
	// if(gamelevel == 1 && gameState==3)
	// iText(320,240,"So You Are A NEWBIE",  GLUT_BITMAP_HELVETICA_12);
	// if(gamelevel == 3 && gameState==3)
	// iText(320,240,"WOW",  GLUT_BITMAP_HELVETICA_12);
 

	if(gameState==2){

	for (i = 0; i < 15; i++)
	{

		for (j = 0; j < 16; j++)
		{

			if (Window[i][j] == 0)
			{
				iSetColor(255, 255, 255);
				iRectangle(40 * i, 40 * j, 40, 40);
			}
			if (Window[i][j] == 1)
			{
				iSetColor(255, 0, 0);
				iFilledRectangle(40 * i, 40 * j, 40, 40);
			}
			if (Window[i][j] == 2)
			{
				iSetColor(0, 255, 0);
				iFilledRectangle(40 * i, 40 * j, 40, 40);
			}
			if (Window[i][j] == 3)
			{
				iSetColor(0, 0, 255);
				iFilledRectangle(40 * i, 40 * j, 40, 40);
			}
			if (Window[i][j] == 4)
			{
				iSetColor(255, 255, 0);
				iFilledRectangle(40 * i, 40 * j, 40, 40);
			}
			if (Window[i][j] == 5)
			{
				iSetColor(255, 0, 255);
				iFilledRectangle(40 * i, 40 * j, 40, 40);
			}
			if (Window[i][j] == 6)
			{
				iSetColor(0, 255, 255);
				iFilledRectangle(40 * i, 40 * j, 40, 40);
			}
			if (Window[i][j] == 7)
			{
				iSetColor(255, 255, 255);
				iFilledRectangle(40 * i, 40 * j, 40, 40);
			}
		}
	}

//J shape
	if (T == 0)
	{
		if(f0==0){
			for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
		Tetris[0][i][j]=0;
			}
		}
			
		Tetris[0][1][0] = 1;
		Tetris[0][1][1] = 1;
		Tetris[0][1][2] = 1;
		Tetris[0][2][2] = 1;
		}
		
		for (k = 0; k < 4; k++)
		{
			for (l = 0; l < 4; l++)
			{
				if (Tetris[0][k][l] == 1)
				{
					iSetColor(255, 0, 0);
					iFilledRectangle((posx + k) * 40, (posy + l) * 40, 40, 40);
				}
			}
		}
	}
	//T shape
	else if (T == 1)
	{
		if(f1==0){
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
		Tetris[1][i][j]=0;
			}
		}
		Tetris[1][1][0] = 1;
		Tetris[1][1][1] = 1;
		Tetris[1][1][2] = 1;
		Tetris[1][2][1] = 1;
	}
		for (k = 0; k < 4; k++)
		{
			for (l = 0; l < 4; l++)
			{
				if (Tetris[1][k][l] == 1)
				{
					iSetColor(0, 255, 0);
					iFilledRectangle((posx + k) * 40, (posy + l) * 40, 40, 40);
				}
			}
		}
	}
// Z shape
	else if (T == 2)
	{
		if(f2==0){
			for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
		Tetris[2][i][j]=0;
			}
		}
		Tetris[2][1][0] = 1;
		Tetris[2][1][1] = 1;
		Tetris[2][2][1] = 1;
		Tetris[2][2][2] = 1;
	}
		for (k = 0; k < 4; k++)
		{
			for (l = 0; l < 4; l++)
			{
				if (Tetris[2][k][l] == 1)
				{
					iSetColor(0, 0, 255);
					iFilledRectangle((posx + k) * 40, (posy + l) * 40, 40, 40);
				}
			}
		}
	}
//S shape
	else if (T == 3)
	{
		if(f3==0){
			for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
		Tetris[3][i][j]=0;
			}
		}
		Tetris[3][2][0] = 1;
		Tetris[3][2][1] = 1;
		Tetris[3][1][1] = 1;
		Tetris[3][1][2] = 1;
	}
		for (k = 0; k < 4; k++)
		{
			for (l = 0; l < 4; l++)
			{
				if (Tetris[3][k][l] == 1)
				{
					iSetColor(255, 255, 0);
					iFilledRectangle((posx + k) * 40, (posy + l) * 40, 40, 40);
				}
			}
		}
	}
// O shape
	else if (T == 4)
	{
		if(f4==0){
			for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
		Tetris[4][i][j]=0;
			}
		}
		Tetris[4][1][0] = 1;
		Tetris[4][1][1] = 1;
		Tetris[4][2][0] = 1;
		Tetris[4][2][1] = 1;
	}

		for (k = 0; k < 4; k++)
		{
			for (l = 0; l < 4; l++)
			{
				if (Tetris[4][k][l] == 1)
				{
					iSetColor(255, 0, 255);
					iFilledRectangle((posx + k) * 40, (posy + l) * 40, 40, 40);
				}
			}
		}
	}
// I shape
	else if (T == 5)
	{
		if(f5==0){
			for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
		Tetris[5][i][j]=0;
			}
		}
		Tetris[5][1][0] = 1;
		Tetris[5][1][1] = 1;
		Tetris[5][1][2] = 1;
		Tetris[5][1][3] = 1;
	}
		for (k = 0; k < 4; k++)
		{
			for (l = 0; l < 4; l++)
			{
				if (Tetris[5][k][l] == 1)
				{
					iSetColor(0, 255, 255);
					iFilledRectangle((posx + k) * 40, (posy + l) * 40, 40, 40);
				}
			}
		}
	}
// L shape
	else if (T == 6)
	{
		if(f6==0){
			for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
		Tetris[6][i][j]=0;
			}
		}
		Tetris[6][2][0] = 1;
		Tetris[6][2][1] = 1;
		Tetris[6][2][2] = 1;
		Tetris[6][1][2] = 1;
	}
		for (k = 0; k < 4; k++)
		{
			for (l = 0; l < 4; l++)
			{
				if (Tetris[6][k][l] == 1)
				{
					iSetColor(255, 255, 255);
					iFilledRectangle((posx + k) * 40, (posy + l) * 40, 40, 40);
				}
			}
		}
	}
	}

	
}

/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
	*/
void iMouseMove(int mx, int my)
{
	//printf("x = %d, y= %d\n", mx, my);
	// place your codes here
}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
	*/
void iMouse(int button, int state, int mx, int my)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		// place your codes here
			//printf("x = %d, y= %d\n",mx,my);
		if(mx>=714 && mx<=769 && my>=350 && my<=403 && gameState==1){
			if (music)
			{
				music = false;
				PlaySound(0, 0, 0);
			}
			else
			{
				music = true;
				PlaySound("D:\\1-1\\CSE102\\Igraphics\\TETRIS CLONE _ MAIN\\assests\\audio.wav", NULL, SND_LOOP | SND_ASYNC);
			} 
		}
		if(mx>=23 && mx<=74 && my>=350 && my<=400 && gameState==1){
             exit(1);
		}
		if(mx>=666 && mx<=717 && my>=394 && my<=445 && gameState==2){
             gameState=1;
		}
		if(mx>=334 && mx<=450 && my>=107 && my<=174 && gameState==1){
			gameState=6;
		}
		if(mx>=325 && mx<=475 && my>=45 && my<=106 && gameState==6){
			gameState=2;
		}
		if(mx>=524 && mx<=639 && my>=235 && my<=303 && gameState==1){
			gameState=3;
		}
		if(mx>=174 && mx<=290 && my>=286 && my<=353 && gameState==3){
			Level=700;
			gamelevel=1;
			
		}
		if(mx>=475 && mx<=594 && my>=280 && my<=354 && gameState==3){
			Level=500;
			
		}
		if(mx>=308 && mx<=459 && my>=154 && my<=233 && gameState==3){
			Level=300;
			gamelevel=3;
		}
		if(mx>=365 && mx<=400 && my>=37 && my<=80 && gameState==3){
			gameState=1;
		}
		if(mx>=365 && mx<=400 && my>=37 && my<=80 && gameState==5){
			gameState=1;
		}
		if(mx>=365 && mx<=400 && my>=37 && my<=80 && gameState==4){
			gameState=1;
		}
		if(mx>=304 && mx<=481 && my>=235 && my<=298 && gameState==1){
			gameState=4;
		}
		if(mx>=140 && mx<=256 && my>=236 && my<=299 && gameState==1){
			gameState=5;
		}
		if(mx>=391 && mx<=427 && my>=187 && my<=220 && gameState==7){
			gameState=1;
		}
		
	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN )
	{
		
		
		// place your codes here
	}
}

int collision(int posy)
{
     for (int j = 0; j < 4; j++)
		{
			for (int i = 0; i < 4; i++)
			{
				if ((Tetris[T][i][j]!=0 && Window[i + posx][j + posy-1]!=0 && (j + posy-1)<15 && (j+posy-1)>=0 ) || (Tetris[T][i][j]!=0 && (j+posy-1)<0))
				{
					score+=5;
					return 1;
				}
			}
		}
		return 0; 
}

int rightshift()
{
     //int check=0;

		 for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				if ( (Tetris[T][i][j]!=0 && Window[i + posx][j + posy]!=0 && (i + posx)<15) || (Tetris[T][i][j]!=0 && (i + posx)>=15))
				{
					 return 1;
				}
			}
		}
    return 0;
}
int leftshift()
{
	for (int j = 0; j < 4; j++)
		{
			for (int i = 0; i < 4; i++)
			{
				if ( (Tetris[T][i][j]!=0 && Window[i + posx][j + posy]!=0 && (i + posx)>=0) || (Tetris[T][i][j]!=0 && (i + posx)<0))
				{
					return 1;
				}
			}
		}
		return 0;
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
	*/
void iKeyboard(unsigned char key)
{
	
	if(key!=' ' && gameState==6){
		
	if(key != '\b' ){
           name[index]=key;
             index++;
			 name[index] = '\0';
			 k++;
	}
	if(key=='\b' ){
		if(index<0)
		index=0;
		else {
		index--;
        name[index]='\0';
		}
	}
	}
    
	







	if (key == ' ')
	{
				int cd= Tetris[T][0][0];
				Tetris[T][0][0] = Tetris[T][3][3];
				Tetris[T][3][3] = cd;
				int d= Tetris[T][1][0];
				Tetris[T][1][0] = Tetris[T][3][2];
				Tetris[T][3][2] = d;
				int e= Tetris[T][2][0];
				Tetris[T][2][0] = Tetris[T][3][1];
				Tetris[T][3][1] = e;
				int f= Tetris[T][0][1];
				Tetris[T][0][1] = Tetris[T][2][3];
				Tetris[T][2][3] = f;
				int g= Tetris[T][1][1];
				Tetris[T][1][1] = Tetris[T][2][2];
				Tetris[T][2][2] = g;
				int h= Tetris[T][0][2];
				Tetris[T][0][2] = Tetris[T][1][3];
				Tetris[T][1][3] = h;

			for (int j = 0; j < 4; j++)
			{
                int c= Tetris[T][j][0];
				Tetris[T][j][0] = Tetris[T][j][3];
				Tetris[T][j][3] = c;
				 
			}
			for (int j = 0; j < 4; j++)
			{
                int c= Tetris[T][j][1];
				Tetris[T][j][1] = Tetris[T][j][2];
				Tetris[T][j][2] = c;
				 
			}

			if( collision(posy)==1 || rightshift()==1 || leftshift()==1)
			{
				for (int j = 0; j < 4; j++){
                int c= Tetris[T][j][0];
				Tetris[T][j][0] = Tetris[T][j][3];
				Tetris[T][j][3] = c;				 
			}
			for (int j = 0; j < 4; j++){
                int c= Tetris[T][j][1];
				Tetris[T][j][1] = Tetris[T][j][2];
				Tetris[T][j][2] = c;
			}
				int cd= Tetris[T][0][0];
				Tetris[T][0][0] = Tetris[T][3][3];
				Tetris[T][3][3] = cd;
				int d= Tetris[T][1][0];
				Tetris[T][1][0] = Tetris[T][3][2];
				Tetris[T][3][2] = d;
				int e= Tetris[T][2][0];
				Tetris[T][2][0] = Tetris[T][3][1];
				Tetris[T][3][1] = e;
				int f= Tetris[T][0][1];
				Tetris[T][0][1] = Tetris[T][2][3];
				Tetris[T][2][3] = f;
				int g= Tetris[T][1][1];
				Tetris[T][1][1] = Tetris[T][2][2];
				Tetris[T][2][2] = g;
				int h= Tetris[T][0][2];
				Tetris[T][0][2] = Tetris[T][1][3];
				Tetris[T][1][3] = h;
			
			}
		
int k=0;
		 for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
		if(Tetris[T][i][j]!=0)
				{
					t[k]=i;
					t[k+1]=j;
					k=k+2;
				}
			}
		}
		
		if(T==0) f0=1;
		if(T==1) f1=1;
		if(T==2) f2=1;
		if(T==3) f3=1;
		if(T==4) f4=1;
		if(T==5) f5=1;
		if(T==6) f6=1;
		
		//exit(0);
	}
	// place your codes for other keys here
}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
	*/
void iSpecialKeyboard(unsigned char key)
{

	if (key == GLUT_KEY_END)
	{
		exit(0);
	}
	else if (key == GLUT_KEY_LEFT && posx >= 0 && posy != 0)
	{
		posx -= 1;
		//int check=0;

		 
		if(leftshift()==1){
			posx += 1;
		}
		
	}
	else if (key == GLUT_KEY_RIGHT && posy != 0)
	{
	
		posx += 1;
		
		if(rightshift()==1){
			posx -= 1;
		}
		

	}
	else if (key == GLUT_KEY_DOWN)
	{
		int y=posy,check=0;
		while(y>=0){
			y--;
		 for (int j = 0; j < 4; j++)
		{
			for (int i = 0; i < 4; i++)
			{
				if ( (Tetris[T][i][j]!=0 && Window[i + posx][j + y]!=0 ))
				{
					check=1;
				}
			}
		}
		if(check==1){
			y++;
			posy=y;
			break;
		}
		if(y==0) posy=0;
		}
	}
	// place your codes for other keys here
}



void Fall()
{
	if(gameState==2)
	{
			
			for(int i=0;i<15;i++){
				if(Window[i][12]!=0 || Window[i][13]!=0 || Window[i][14]!=0) {
					printf("GAME OVER4\n");
					//flag = 1;
					
					//test=1;
                     gameState=7;
				}
			}
  int check;
   //if(check==0) return;

	if(Window[7][11] !=0 || Window[8][11] !=0){
		printf("GAME OVER\n");
		 check=0;
		// flag = 1;
		//  if(score>high)
		// 			high=score;
		//exit(0);
		gameState=7;;
	}
		
	//int col;
		//posy -= 1;
		 col= collision(posy);
		if(col==0) {
			posy -= 1;
		//  col= collision(posy);
		printf("%d\n",col);
		}
	

	 //if (col==1)
	else {
		//posy +=1;
         if ( T == 0)
		{
			if(f0==0)
			{
			Window[1 + posx][0+posy] = 1;
			Window[1 + posx][1+posy] = 1;
			Window[1 + posx][2+posy] = 1;
			Window[2 + posx][2+posy] = 1;
			}
			else{
			Window[t[0] + posx][t[1]+posy] = 1;
			Window[t[2] + posx][t[3]+posy] = 1;
			Window[t[4] + posx][t[5]+posy] = 1;
			Window[t[6] + posx][t[7]+posy] = 1;
			}
			f0=0;
		}

		if ( T == 1)
		{
			if(f1==0){
			Window[1 + posx][0+posy] = 2;
			Window[1 + posx][1+posy] = 2;
			Window[1 + posx][2+posy] = 2;
			Window[2 + posx][1+posy] = 2;
			}
			else{
			Window[t[0] + posx][t[1]+posy] = 2;
			Window[t[2] + posx][t[3]+posy] = 2;
			Window[t[4] + posx][t[5]+posy] = 2;
			Window[t[6] + posx][t[7]+posy] = 2;
			}
			f1=0;
		}

		if ( T == 2)
		{
			if(f2==0){
			Window[1 + posx][0+posy] = 3;
			Window[1 + posx][1+posy] = 3;
			Window[2 + posx][1+posy] = 3;
			Window[2 + posx][2+posy] = 3;
			}
			else{
			Window[t[0] + posx][t[1]+posy] = 3;
			Window[t[2] + posx][t[3]+posy] = 3;
			Window[t[4] + posx][t[5]+posy] = 3;
			Window[t[6] + posx][t[7]+posy] = 3;
			}
			f2=0;
		}

		if ( T == 3)
		{
			if(f3==0){
			Window[2 + posx][0+posy] = 4;
			Window[2 + posx][1+posy] = 4;
			Window[1 + posx][1+posy] = 4;
			Window[1 + posx][2+posy] = 4;
			}
			else{
			Window[t[0] + posx][t[1]+posy] = 4;
			Window[t[2] + posx][t[3]+posy] = 4;
			Window[t[4] + posx][t[5]+posy] = 4;
			Window[t[6] + posx][t[7]+posy] = 4;
			}
			f3=0;
		}

		if ( T == 4)
		{
			if(f4==0){
			Window[1 + posx][0+posy] = 5;
			Window[1 + posx][1+posy] = 5;
			Window[2 + posx][0+posy] = 5;
			Window[2 + posx][1+posy] = 5;
			}
			else{
			Window[t[0] + posx][t[1]+posy] = 5;
			Window[t[2] + posx][t[3]+posy] = 5;
			Window[t[4] + posx][t[5]+posy] = 5;
			Window[t[6] + posx][t[7]+posy] = 5;
			}
			f4=0;
		}

		if (T == 5)
		{
			if(f5==0){
			Window[1 + posx][0+posy] = 6;
			Window[1 + posx][1+posy] = 6;
			Window[1 + posx][2+posy] = 6;
			Window[1 + posx][3+posy] = 6;
			}
		else{
			Window[t[0] + posx][t[1]+posy] = 6;
			Window[t[2] + posx][t[3]+posy] = 6;
			Window[t[4] + posx][t[5]+posy] = 6;
			Window[t[6] + posx][t[7]+posy] = 6;
			}
			f5=0;
		}

		if ( T == 6)
		{
			if(f6==0){
			Window[2 + posx][0+posy] = 7;
			Window[2 + posx][1+posy] = 7;
			Window[2 + posx][2+posy] = 7;
			Window[1 + posx][2+posy] = 7;
			}
			else{
			Window[t[0] + posx][t[1]+posy] = 7;
			Window[t[2] + posx][t[3]+posy] = 7;
			Window[t[4] + posx][t[5]+posy] = 7;
			Window[t[6] + posx][t[7]+posy] = 7;
			}
			f6=0;
		}

		posx = 6;
			T = rand() % 7;
			posy = 12;
			//col=0;

        //int q=0;
		for(int q=0;q<12;q++)
		{
			int test=0;
			for(int p=0;p<15;p++)
			{
				if(Window[p][q]==0) test=1;
			}
			//q++;
			if(test==0)
			{
				for(int r=q;r<13;r++)
				{
					for(int s=0;s<15;s++){
						Window[s][r] = Window[s][r+1];
					}
				}
				score+=20;
				//q--;
			}
			test=0;
			for(int p=0;p<15;p++)
			{
				if(Window[p][q]==0) test=1;
			}
			if(test==0)
			{
				for(int r=q;r<13;r++)
				{
					for(int s=0;s<15;s++){
						Window[s][r] = Window[s][r+1];
					}
				}
				score+=20;
				//q--;
			}
		}	
	}

}
}

void cover()
{
	iPauseTimer(1);
	gameState=1;
}

void GL()
{
	iPauseTimer(0);
	gamelevel=0;
}

int main()
{
	
	
	 iSetTimer(600, Fall);
	
	 iSetTimer(3000, cover);

    if(music)
	PlaySound("D:\\1-1\\CSE102\\Igraphics\\TETRIS CLONE _ MAIN\\assests\\audio.wav", NULL, SND_LOOP | SND_ASYNC);
	//else PlaySound(0,0,0);
	
	// place your own initialization codes here.
	iInitialize(800, 480, "Tetris Clone");
	return 0;
}
