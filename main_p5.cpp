//Semestre 2017 - 2
//************************************************************//
//************************************************************//
//************** Alumno (s): *********************************//
//*************											******//
//*************											******//
//************************************************************//
#include "Main.h"

float transZ = -5.0f;
float transX = 0.0f;
float angleX = 0.0f;
float angleY = 0.0f;
int screenW = 0.0;
int screenH = 0.0;
float angCodo = 0.0f;
float angMu = 0.0f;
float angF1 = 0.0f;
float angF2 = 0.0f;
float angF3 = 0.0f;


GLfloat Position[]= { 0.0f, 3.0f, 0.0f, 1.0f };			// Light Position
GLfloat Position2[]= { 0.0f, 0.0f, -5.0f, 1.0f };			// Light Position

void InitGL ( void )     // Inicializamos parametros
{

	glShadeModel(GL_SMOOTH);							// Habilitamos Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo
	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing

	//Configuracion luz
	glLightfv(GL_LIGHT0, GL_POSITION, Position);
	glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, Position2);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);


	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glEnable ( GL_COLOR_MATERIAL );
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void prisma(void)
{
	GLfloat vertice [8][3] = {
				{0.5 ,-0.5, 0.5},    //Coordenadas Vértice 0 V0
				{-0.5 ,-0.5, 0.5},    //Coordenadas Vértice 1 V1
				{-0.5 ,-0.5, -0.5},    //Coordenadas Vértice 2 V2
				{0.5 ,-0.5, -0.5},    //Coordenadas Vértice 3 V3
				{0.5 ,0.5, 0.5},    //Coordenadas Vértice 4 V4
				{0.5 ,0.5, -0.5},    //Coordenadas Vértice 5 V5
				{-0.5 ,0.5, -0.5},    //Coordenadas Vértice 6 V6
				{-0.5 ,0.5, 0.5},    //Coordenadas Vértice 7 V7
				};

		glBegin(GL_POLYGON);	//Front
			glNormal3f( 0.0f, 0.0f, 1.0f);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[4]);
			glVertex3fv(vertice[7]);
			glVertex3fv(vertice[1]);
		glEnd();

		glBegin(GL_POLYGON);	//Right
			glNormal3f( 1.0f, 0.0f, 0.0f);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[3]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[4]);
		glEnd();

		glBegin(GL_POLYGON);	//Back
			glNormal3f( 0.0f, 0.0f, -1.0f);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[3]);
			glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Left
			glNormal3f( -1.0f, 0.0f, 0.0f);
			glVertex3fv(vertice[1]);
			glVertex3fv(vertice[7]);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Bottom
			glNormal3f( 0.0f, -1.0f, 0.0f);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[1]);
			glVertex3fv(vertice[2]);
			glVertex3fv(vertice[3]);
		glEnd();

		glBegin(GL_POLYGON);  //Top
			glNormal3f( 0.0f, 1.0f, 0.0f);
			glVertex3fv(vertice[4]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[7]);
		glEnd();
}

void display(void)   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Limiamos pantalla y Depth Buffer
	//glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glTranslatef(transX, 0.0f, transZ);
	glRotatef(angleY, 0.0, 1.0, 0.0);
	glRotatef(angleX, 1.0, 0.0, 0.0);
	//Poner Código Aquí.
	
	glPushMatrix();
		glPushMatrix();
			//hombro
			glColor3f(1,1,0);
			prisma();
		glPopMatrix();

		glTranslatef(1.5,0,0);

		glPushMatrix();
			//bicep
			glColor3f(1, 0, 0);
			glScalef(2,1,1);
			prisma();
		glPopMatrix();

		glTranslatef(1, 0, 0);
		glRotatef(angCodo,0,1,0);
		glTranslatef(1, 0, 0);

		glPushMatrix();
			//antebrazo
			glColor3f(0, 1, 0);
			glScalef(2, 1, 1);
			prisma();
		glPopMatrix();

		glTranslatef(1,0,0);
		glRotatef(angMu, 0, 1, 0);
		glTranslatef(0.5, 0, 0);


		glPushMatrix();
			//muñeca
			glColor3f(0, 0, 1);
			glScalef(1, 1, 0.2);
			prisma();
		glPopMatrix();
		//dedo gordo
		glPushMatrix();

			glTranslatef(-.4, .5, 0);
			glRotatef(angF1, 1, 0, 0);
			glTranslatef(0, 0.1, 0);

			glPushMatrix();
				//falange1
				glColor3f(0, 0.3, 0.3);
				glScalef(0.2, 0.2, 0.2);
				prisma();
			glPopMatrix();

			glTranslatef(0, .1, 0);
			glRotatef(angF1*0.3, 1, 0, 0);
			glTranslatef(0, 0.1, 0);


			glPushMatrix();
				//falange2
				glColor3f(0, 0.1, 0.7);
				glScalef(0.2, 0.2, 0.2);
				prisma();
			glPopMatrix();
		glPopMatrix();

		//dedo índice
			glTranslatef(.55, .4, 0);
			glRotatef(angF2, 0, 1, 0);
			glTranslatef(0.1, 0, 0);

			glPushMatrix();
			//falange1
				glColor3f(0.3, 0.3, 0.3);
				glScalef(0.3, 0.2, 0.2);
				prisma();
			glPopMatrix();

			glTranslatef(.15,0, 0);
			glRotatef(angF2*1.5, 0, 1, 0);
			glTranslatef(0.15, 0, 0);

			glPushMatrix();
				//falange2
				glColor3f(0, 0.3, 0.7);
				glScalef(0.3, 0.2, 0.2);
				prisma();
			glPopMatrix();

			glTranslatef(0, -.2, 0);
			glRotatef(angF3, 0, 1, 0);
			glTranslatef(-0.2, 0, 0);

			glPushMatrix();
			//falange1
			glColor3f(0.3, 0.3, 0.3);
			glScalef(0.4, 0.2, 0.2);
			prisma();
			glPopMatrix();

			glTranslatef(.2, 0, 0);
			glRotatef(angF3*1.5, 0, 1, 0);
			glTranslatef(0.2, 0, 0);

			glPushMatrix();
			//falange2
			glColor3f(0, 0.3, 0.7);
			glScalef(0.4, 0.2, 0.2);
			prisma();
			glPopMatrix();

	glPopMatrix();




	////cubo del centro
	//glScalef(3, 3, 3);
	//prisma();
	////cubo a la derecha
	//glScalef(.3, .3, .3);
	//glTranslatef(7, 0, 0);
	//glScalef(5, 5, 5);
	//prisma();

	////cubo a la izquierda
	//glScalef(.2, .2, .2);
	//glTranslatef(-17, 0, 0);
	//glScalef(8,8,8);
	//prisma();


		
  											
	glutSwapBuffers ( );
  // Swap The Buffers
}

void reshape ( int width , int height )   // Creamos funcion Reshape
{
  if (height==0)										// Prevenir division entre cero
	{
		height=1;
	}

	glViewport(0,0,width,height);	

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Tipo de Vista
	//glOrtho(-5,5,-5,5,0.2,20);	
	glFrustum (-0.1, 0.1,-0.1, 0.1, 0.1, 50.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	//glLoadIdentity();									
}

void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{
	switch ( key ) {
		case 'w':
		case 'W':
			transZ +=0.2f;
			break;
		case 's':
		case 'S':
			transZ -=0.2f;
			break;
		case 'a':
		case 'A':
			transX +=0.2f;
			break;
		case 'd':
		case 'D':
			transX -=0.2f;
			break;
		case 27:        // Cuando Esc es presionado...
			exit ( 0 );   // Salimos del programa
		break;        
		default:        // Cualquier otra
		break;

		case 'r':
			if (angCodo <=150) {
				angCodo += 1;
				break;
			}
		case 'R':
			if (angCodo > 0) {
				angCodo -= 1;
				break;
			}

		case 't':
			if (angMu <= 90) {
				angMu += 1;
				break;
			}
		case 'T':
			if (angMu > 0) {
				angMu -= 1;
				break;
			}

		case 'y':
			if (angF1 >= -90 and angF1 <=0) {
				angF1 += 1;
				break;
			}
		case 'Y':
			if (angF1 >-90) {
				angF1 -= 1;
				break;
			}

		case 'f':
			if (angF2 <= 90) {
				angF2 += 1;
				break;
			}
		case 'F':
			if (angF2 > 0) {
				angF2 -= 1;
				break;
			}
		case 'g':
			if (angF3 <= 90) {
				angF3 += 1;
				break;
			}
		case 'G':
			if (angF3 > 0) {
				angF3 -= 1;
				break;
			}
		
  }
	glutPostRedisplay();
}

void arrow_keys ( int a_keys, int x, int y )  // Funcion para manejo de teclas especiales (arrow keys)
{
  switch ( a_keys ) {
    case GLUT_KEY_UP:		// Presionamos tecla ARRIBA...
		angleX +=2.0f;
		break;
    case GLUT_KEY_DOWN:		// Presionamos tecla ABAJO...
		angleX -=2.0f;
		break;
	case GLUT_KEY_LEFT:
		angleY +=2.0f;
		break;
	case GLUT_KEY_RIGHT:
		angleY -=2.0f;
		break;
    default:
      break;
  }
  glutPostRedisplay();
}


int main ( int argc, char** argv )   // Main Function
{
  glutInit            (&argc, argv); // Inicializamos OpenGL
  glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
  screenW = glutGet(GLUT_SCREEN_WIDTH);
  screenH = glutGet(GLUT_SCREEN_HEIGHT);
  glutInitWindowSize  (500, 500);	// Tamaño de la Ventana
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("Practica 5"); // Nombre de la Ventana
  printf("Resolution H: %i \n", screenW);
  printf("Resolution V: %i \n", screenH);
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc    ( keyboard );	//Indicamos a Glut función de manejo de teclado
  glutSpecialFunc     ( arrow_keys );	//Otras
  glutMainLoop        ( );          // 

  return 0;
}



