



#pragma once
class Point3{
  public:
    Point3() { x = y = 0.0f;} // constructor 1
    Point3(float xx,float yy) { x = xx; y = yy;} // constructor 2
    void set(float xx,float yy) { x = xx; y = yy;} 
    float getX() { return x;}
    float getY() { return y;}
    void draw(void) 
    { 
		glPointSize(2.0);
		
		glEnable( GL_BLEND);
  		glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

  		glHint( GL_POINT_SMOOTH_HINT, GL_NICEST); 
 		glEnable( GL_POINT_SMOOTH);

		glBegin(GL_POINTS); // draw this point
			glVertex2f((GLfloat)x, (GLfloat)y);
		glEnd();

		glDisable( GL_POINT_SMOOTH);

    }// end draw
  private:
    float x, y;	
}; // end class Point2
void myTimer(int t)
{
   glutPostRedisplay();
	
	
   glutTimerFunc(1000,myTimer,1);			
  
 	
//glutPostRedisplay();
	
	}
class Ryo{
public:

	
	RGBApixmap pix[28]; // make six empty pixmaps, one for each side of cube
	enum State	{START0	,START1	,START2	,START3	,START4	,START5	,START6	,START7	,START8	,START9	,START10,START11	,START12	,START13	,START14,JUMPING0,JUMPING1,JUMPING2,JUMPING3,JUMPING4,JUMPING5,JUMPING6,RUNNING0,	RUNNING1, RUNNING2,	RUNNING3,RUNNING4,RUNNING5,	DIE	}state ;
	enum ModeType{	START, STAY,RUN,	R,	JUMP,	DEAD} mode;
    float pos_X, pos_Y;
 bool above;
	Ryo(Point3 pos)
		
	{
		pix[0].readBMPFile("Hero Ryo\\RyoE0.bmp",1);
	  
		pix[1].readBMPFile("Hero Ryo\\RyoE1.bmp",1);
		pix[2].readBMPFile("Hero Ryo\\RyoE2.bmp",1);
		pix[3].readBMPFile("Hero Ryo\\RyoE3.bmp",1);
		pix[4].readBMPFile("Hero Ryo\\RyoE4.bmp",1);
		
		pix[5].readBMPFile("Hero Ryo\\RyoE5.bmp",1);
	  
		pix[6].readBMPFile("Hero Ryo\\RyoE6.bmp",1);
		pix[7].readBMPFile("Hero Ryo\\RyoE7.bmp",1);
		pix[8].readBMPFile("Hero Ryo\\RyoE8.bmp",1);
		pix[9].readBMPFile("Hero Ryo\\RyoE9.bmp",1);
		
		pix[10].readBMPFile("Hero Ryo\\RyoE10.bmp",1);
	  
		pix[11].readBMPFile("Hero Ryo\\RyoE11.bmp",1);
		pix[12].readBMPFile("Hero Ryo\\RyoE12.bmp",1);
		pix[13].readBMPFile("Hero Ryo\\RyoE13.bmp",1);
		pix[14].readBMPFile("Hero Ryo\\RyoE14.bmp",1);
		
		
		
		
		pix[15].readBMPFile("Hero Ryo\\RyoJ0.bmp",1);
		pix[16].readBMPFile("Hero Ryo\\RyoJ1.bmp",1);
		pix[17].readBMPFile("Hero Ryo\\RyoJ2.bmp",1);
		pix[18].readBMPFile("Hero Ryo\\RyoJ3.bmp",1);
		pix[19].readBMPFile("Hero Ryo\\RyoJ4.bmp",1);
		pix[20].readBMPFile("Hero Ryo\\RyoJ5.bmp",1);
		pix[21].readBMPFile("Hero Ryo\\RyoJ6.bmp",1);
		pix[22].readBMPFile("Hero Ryo\\RyoW0.bmp",1);
		pix[23].readBMPFile("Hero Ryo\\RyoW1.bmp",1);
		pix[24].readBMPFile("Hero Ryo\\RyoW2.bmp",1);
		pix[25].readBMPFile("Hero Ryo\\RyoW3.bmp",1);
		pix[26].readBMPFile("Hero Ryo\\RyoW4.bmp",1);
		pix[27].readBMPFile("Hero Ryo\\RyoW5.bmp",1);
		
		for(int i=0;i<28;i++){
		
	
			pix[i].setChromaKey(255,255,255);


		}	
		
		
		this->pos_X =pos.getX();
		this->pos_Y =pos.getY();


 
	};
void setPosition(float x, float y)
	{
		
		this->pos_X=x;
		this->pos_Y=y;
	}
	void render();
	void changeMode(ModeType m);
	void run();	
	void run2();
	void die();
   void start();
 void 	stay(); 
 void jump();
 
 
 void changePosition(float dx, float dy)
	{
		
	}

};

void Ryo::render()
{
 switch(mode)
 {
 case START:
	// state=START0;
	 start();

	 break;
 case STAY:
	// state=START10;
	stay();
	 break;
	 case RUN:
		 run();
		 
		 break;

	 case JUMP:
		// state=JUMPING0;
			 jump();	 
	
			 break;
	 case R :
		 run2();
		 break;
 
 }


}
void Ryo::start(){
	switch(state){
	case START0:
		state=START1;
		break;
		case START1:
		state=START2;
		break;
		case START2:
		state=START3;
		break;
		case START3:
		state=START4;
		break;
		case START4:
		state=START5;
		break;case START5:
		state=START6;
		break;case START6:
		state=START7;
		break;case START7:
		state=START8;
		break;case START8:
		state=START9;
		break;case START9:
		state=START10;
		break;case START10:
		state=START11;
		break;case START11:
		state=START12;
		break;case START12:
		state=START13;
		break;case START13:
		state=START14;
		break;
		case START14:
		state=START10;
		break;
	}
	 glPixelZoom(2,2);
	 glRasterPos2i(this->pos_X,this->pos_Y);
	  pix[state].mDraw();
	//  glutPostRedisplay();
	  glutTimerFunc(900,myTimer,1);
	  //	glutPostRedisplay();

}

void Ryo::run2()
{/*
	 glRasterPos2i(this->pos_X,this->pos_Y);
	
	 for(int i =0;i< 4;i++){
	 pix[i].mDraw();
	 }
	 */

	switch(state){
	case RUNNING0:
		state=RUNNING5;
		break;case RUNNING1:
		state=RUNNING0;
		break;
		
	case RUNNING2:
		state=RUNNING1;
		break;
	case RUNNING3:
		state=RUNNING2;
		break;
		case RUNNING4:
		state=RUNNING3;
		break;
		case RUNNING5:
		state=RUNNING4;
		break;
	}
 glPixelZoom(2,2);
	 glRasterPos2i(this->pos_X,this->pos_Y);
	  pix[state].mDraw();
}
void Ryo::run()
{/*
	 glRasterPos2i(this->pos_X,this->pos_Y);
	
	 for(int i =0;i< 4;i++){
	 pix[i].mDraw();
	 }
	 */

	switch(state){
	case RUNNING0:
		state=RUNNING1;
		break;case RUNNING1:
		state=RUNNING2;
		break;
		
	case RUNNING2:
		state=RUNNING3;
		break;
	case RUNNING3:
		state=RUNNING4;
		case RUNNING4:
		state=RUNNING5;
		break;
		case RUNNING5:
		state=RUNNING0;
		break;
	}
 glPixelZoom(2,2);
	 glRasterPos2i(this->pos_X,this->pos_Y);
	  pix[state].mDraw();
	  	  glutTimerFunc(500,myTimer,1);
		 
}



void Ryo::stay(){
	
switch(state)
{
case START9:
	state=START10;
	break;
        case START10:
		state=START11;
		break;
		case START11:
		state=START12;
		break;
		case START12:
		state=START13;
		break;case START13:
		state=START14;
		break;
		case START14:
		state=START10;
		break;
}


	 glPixelZoom(2,2);
	 glRasterPos2i(this->pos_X,this->pos_Y);
	  pix[state].mDraw();
	 // glutPostRedisplay();
	//  glutTimerFunc(1000,myTimer,1);
//	  	glutPostRedisplay();

}
void Ryo::jump(){/*
	switch(state){
	case JUMPING0:
		state=JUMPING1;
		 glRasterPos2i(this->pos_X,this->pos_Y+=20);
			break;
	case JUMPING1:
		state=JUMPING2;

 glRasterPos2i(this->pos_X,this->pos_Y+=20);		break;
	case JUMPING2:
		state=JUMPING3;
		 glRasterPos2i(this->pos_X,this->pos_Y+=20);
			break;
		
		case JUMPING3:
		
			state=JUMPING4;
			 glRasterPos2i(this->pos_X,this->pos_Y-=30);
			break;
		case JUMPING4:

		state=JUMPING5;
		 glRasterPos2i(this->pos_X,this->pos_Y-=30);
			break;
		case JUMPING5:
		state=JUMPING6;
		 glRasterPos2i(this->pos_X,this->pos_Y-=30);
			break;
		case JUMPING6:
			state=JUMPING0;
			 glRasterPos2i(this->pos_X,this->pos_Y-=30);
		break;
	}
		 glPixelZoom(2,2);
	/*	 if(pos_Y<80)
	{	 glRasterPos2i(this->pos_X,this->pos_Y+=20);
		 }else{
		  glRasterPos2i(this->pos_X,this->pos_Y-=30);
		 }*/


	if(pos_Y>=20&&pos_Y<=30&&!above){state=JUMPING0; pos_Y++;}else 
	if(pos_Y>30&&pos_Y<60&&!above){state=JUMPING1;pos_Y++;}else
		
	if(pos_Y>=60&&pos_Y<=100&&!above){state=JUMPING2; pos_Y++; }else
	if(pos_Y<102&&pos_Y>80&&!above){state=JUMPING3; pos_Y--; above=true ; }else
		if(pos_Y<=100&&pos_Y>=80&&above){state=JUMPING4;pos_Y--; }else
		if(pos_Y<=80&&pos_Y>=50&&above){state=JUMPING5;pos_Y--; }else
		if(pos_Y<=50&&pos_Y>20&&above){state=JUMPING6;pos_Y--; }
		if(pos_Y==20&&above){state=JUMPING0;}
		
		
		 glPixelZoom(2,2);
	glRasterPos2i(this->pos_X,this->pos_Y);
		pix[state].mDraw();

	  //glutTimerFunc(100000,myTimer,2);
		glutPostRedisplay();
}
void Ryo::changeMode(ModeType m)
{
	if(mode==m) return;

	switch(m)	{

	case STAY:
		state=START9;
		stay();
		break;
	case R:
		state=RUNNING0;
		break;
	case RUN:
		state=RUNNING0;
		break;
		
	case JUMP:
		above=false;
		state=JUMPING0;
		jump();
		break;
	}
	mode=m;
}
