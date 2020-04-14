#include <windows.h>
#include <GL/glut.h>
#include <math.h>
int n=3;
void initGL() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}
void display() {
   glClear(GL_COLOR_BUFFER_BIT);
   int v;
   float durs[100][2],ang,rad=6.2832/n;
   for(v=0;v<n;v++){
   ang=v*rad;
   durs[v][0]=cos(ang);
   durs[v][1]=sin(ang);
   }
   glBegin(GL_LINE_LOOP);
      for(v=0;v<n;v++)
            glVertex2fv(durs[v]);
   glEnd();

   glFlush();
}
void keyInput(unsigned char key,int x,int y){
    switch(key){
        case 'w':n++; display(); break;
        case 's':n--; display(); break;
        default:break;
    }
}

int main(int argc, char** argv) {
   glutInit(&argc, argv);
   glutCreateWindow("LAB 2");
   glutInitWindowSize(320, 320);
   glutInitWindowPosition(50, 50);
   glutDisplayFunc(display);
   glutKeyboardFunc(keyInput);
   initGL();
   glutMainLoop();
   return 0;
}
