#include <stdio.h>
#include <iostream>

#include <Windows.h>
#include "wav.h"

#include <glut.h>
#include "RGBApixMap.h"
#include "Mario.h"
#include "Ryo.h"

RGBApixmap mypix[1];
int MarioX=20,MarioY=20;
Ryo myRyo(Point3 (MarioX,MarioY));


void releaseKeySpecial(int key, int x, int y)
{
    switch (key)
    {
    case GLUT_KEY_LEFT :
		myRyo.setPosition(MarioX,MarioY);
				myRyo.changeMode(myRyo.STAY);
	break;
    
	case GLUT_KEY_RIGHT :
		myRyo.setPosition(MarioX,MarioY);
				myRyo.changeMode(myRyo.STAY);
				//myRyo.render();
				//glutPostRedisplay();
	break;
	case GLUT_KEY_UP:
		myRyo.changeMode(myRyo.STAY);
		
		myRyo.setPosition(MarioX,20);

	break;
    
	case GLUT_KEY_DOWN :
	
	
	break;
    }
	glutPostRedisplay();

}

void pressKeySpecial(int key, int x, int y)
{
    switch (key)
    {
    case GLUT_KEY_LEFT :
		myRyo.changeMode(myRyo.R);
		MarioX-=12;
		myRyo.setPosition(MarioX,MarioY);
	
	
		break;
     
	case GLUT_KEY_RIGHT :
		myRyo.changeMode(myRyo.RUN);
		MarioX+=12;
		myRyo.setPosition(MarioX,MarioY);
	
	
		break;
    
	case GLUT_KEY_UP :
		
	
		myRyo.changeMode(myRyo.JUMP);
		
	
		break;
    
	case GLUT_KEY_DOWN :
		
	
		break;
    }
	glutPostRedisplay();

}

void myKB_Handler(unsigned char key, int mx, int my)
{
    switch(key)
	{
	  case 'r':
	   
		  
		  
		  break;
	  
	  case 's':
		 
		myRyo.changeMode(myRyo.START);
		myRyo.render();
		  myRyo.start();
			
		 break;
	 
	}
glutPostRedisplay();
} 


void display(void)
{
  
     glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  
	
	 glPixelZoom(2,3);
	 glRasterPos2i(0,0);
	 mypix[0].mDraw();

	 myRyo.render();
	
	glFlush();
  
}
void myInit(void)
{
  glClearColor(1.0f,1.0f,1.0f,1.0f);
  
 
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0,640,0,480);
  
  
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glEnable(GL_ALPHA_TEST);
  glAlphaFunc(GL_EQUAL,1.0);

  PlayBackgroundSound("backmusic.wav");

  
}

void main(int argc, char **argv){

	 glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH);
  glutInitWindowSize(1366,768);
  glutInitWindowPosition(10, 10);
  glutCreateWindow("MY STREET FIGHTER");
  
	
  
  glutDisplayFunc(display);
  glutSpecialFunc(pressKeySpecial);
  glutSpecialUpFunc(releaseKeySpecial);
  glutKeyboardFunc(myKB_Handler);
    myInit();
	mypix[0].readBMPFile("BGLevel1.bmp",1);

	

  //glutIdleFunc(display);
  glutTimerFunc(500,myTimer,1);
  glutMainLoop();

    


}