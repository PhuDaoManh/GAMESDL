#ifndef _GAME_H
#define _GAME_H
struct motion{
   int x,y;
   int dx=0,dy=0;
   int speed=3;
   void move(){
       x+=dx;
       y+=dy;
   }
   void turnRight(){
      dx=speed;
      dy=0;

   }
   void turnLeft(){
      dx=-speed;
      dy=0;
   }
   void goUp(){
      dx=0;
      dy=-speed;
   }
   void goDown(){
       dx=0;
       dy=speed;
   }


};


bool gameOver(const motion& mouse) {
    return mouse.x < 0 || mouse.x >= SCREEN_WIDTH ||
           mouse.y < 0 || mouse.y >= SCREEN_HEIGHT;
}




#endif // _GAME_H
