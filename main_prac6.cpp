//Semestre 2019-2
//************************************************************//
//************************************************************//
//************** Alumno (s): *********************************//
//*************				MUÑOZ SOTO DYLAN ALBERTO	******//
//*************											******//
//************************************************************//
#include "Main.h"


// Variables used to calculate frames per second: (Windows)
DWORD dwFrames = 0;
DWORD dwCurrentTime = 0;
DWORD dwLastUpdateTime = 0;
DWORD dwElapsedTime = 0;


//Variables used to create movement

int sol=0;
int mercurio = 0;
int venus = 0;
int tierra = 0;
int luna = 0;
int marte = 0;

float camaraZ = 0.0;
float camaraX = 0.0;

float angX = 0.0;

GLfloat SunDiffuse[]= { 1.0f, 1.0f, 1.0f, 1.0f };			// Diffuse Light Values
GLfloat SunSpecular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat SunPosition[]= { 0.0f, 0.0f, 0.0f, 1.0f };			// Light Position

GLfloat EarthDiffuse[]= { 0.2f, 0.2f, 1.0f, 1.0f };			// Tierra
GLfloat EarthSpecular[] = { 0.8, 0.8, 0.8, 1.0 };
GLfloat EarthShininess[] = { 50.0 };

GLfloat MoonDiffuse[]= { 0.8f, 0.8f, 0.8f, 1.0f };			// Luna
GLfloat MoonSpecular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat MoonShininess[] = { 50.0 };

GLfloat MarsDiffuse[]= { 0.8f, 0.4f, 0.1f, 1.0f };			// Marte
GLfloat MarsSpecular[] = { 1.0, 0.5, 0.0, 1.0 };
GLfloat MarsShininess[] = { 50.0 };

void InitGL ( GLvoid )     // Inicializamos parametros
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo

	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	
	
}

void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	glTranslatef(camaraX,0.0,-30.0+camaraZ);			//camara
	glRotatef(angX, 1, 0, 0);

	glPushMatrix();//sistema solar
		glPushMatrix();//sol
			glRotatef(sol,0.0,1.0,0.0);	//El Sol gira sobre su eje
			glColor3f( 1.0,1.0,0.0 );	//Sol amarillo
			glutSolidSphere(10,20,20);  //Draw Sun (radio,H,V);
		glPopMatrix();//sol
	
		glPushMatrix(); //Mercurio
			glRotatef(mercurio, 0.0, 1.0, 0.0);
			glTranslatef(15.0, 0, 0);
			glColor3f(0.7, 0.6, 0.6);
			glRotatef(mercurio, 0, 1, 0);
			glutSolidSphere(2, 15, 15);
		glPopMatrix();//Mercurio

		glPushMatrix(); //Venus
			glRotatef(venus, 0.0, 1.0, 0.0);
			glTranslatef(23.0, 0, 0);
			glColor3f(0.6, 0.3, 0.5);
			glRotatef(venus, 0, 1, 0);
			glutSolidSphere(3, 15, 15);
		glPopMatrix();//Venus

		glPushMatrix(); //Tierra
			glRotatef(tierra, 0.0, 1.0, 0.0);
			glTranslatef(30.0, 0, 0);
			glColor3f(0.1, 0.1, 0.5);
			glRotatef(tierra, 0, 1, 0);
			glutSolidSphere(3, 15, 15);
			glPushMatrix(); //Luna
				glRotatef(luna, 0.0, 1.0, 0.0);
				glTranslatef(5, 0, 0);
				glColor3f(0.8, 0.8, 0.8);
				glRotatef(luna, 0, 1, 0);
				glutSolidSphere(1, 8, 8);
			glPopMatrix(); //Luna
		glPopMatrix(); //Tierra

		glPushMatrix(); //Marte
			glRotatef(marte, 0.0, 1.0, 0.0);
			glTranslatef(40.0, 0, 0);
			glColor3f(0.8, 0.1, 0.1);
			glRotatef(marte, 0, 1, 0);
			glutSolidSphere(4, 15, 15);
		glPopMatrix();//Marte


	glPopMatrix();//sistema solar
	glutSwapBuffers ( );
}

void animacion()
{
	// Calculate the number of frames per one second:
	//dwFrames++;
	dwCurrentTime = GetTickCount(); // Even better to use timeGetTime()
	dwElapsedTime = dwCurrentTime - dwLastUpdateTime;

	if(dwElapsedTime >= 30)
	{
		sol = (sol - 5) % 360;
		mercurio = (mercurio - 5) % 360;
		venus = (venus - 4) % 360;
		tierra = (tierra - 3) % 360;
		luna = (luna - 4) % 360;
		marte = (marte -1);

		dwLastUpdateTime = dwCurrentTime;
	}

	glutPostRedisplay();
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
	
	glFrustum (-0.1, 0.1,-0.1, 0.1, 0.1, 100.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	//glLoadIdentity();
}

void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{
	switch ( key ) {
		case 'w':   //Movimientos de camara
		case 'W':
			camaraZ +=0.5f;
			break;
		case 's':
		case 'S':
			camaraZ -=0.5f;
			break;
		case 'a':
		case 'A':
			camaraX -= 0.5f;
			break;
		case 'd':
		case 'D':
			camaraX += 0.5f;
			break;

		case 'i':		//Movimientos de Luz
		case 'I':
			
			break;
		case 'k':
		case 'K':
			
			break;

		case 'l':   //Activamos/desactivamos luz
		case 'L':
			break;
		case 27:        // Cuando Esc es presionado...
			exit ( 0 );   // Salimos del programa
			break;        
		default:        // Cualquier otra
			break;
  }
	glutPostRedisplay();
}

void arrow_keys ( int a_keys, int x, int y )  // Funcion para manejo de teclas especiales (arrow keys)
{
  switch ( a_keys ) {
    case GLUT_KEY_UP:     // Presionamos tecla ARRIBA...
		angX = angX + 1;
		break;
    case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...
		angX = angX - 1;
		break;
	case GLUT_KEY_LEFT:
		
		break;
	case GLUT_KEY_RIGHT:
		
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
  glutInitWindowSize  (800, 800);	// Tamaño de la Ventana
  glutInitWindowPosition (20, 60);	//Posicion de la Ventana
  glutCreateWindow    ("Practica 6"); // Nombre de la Ventana
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc    ( keyboard );	//Indicamos a Glut función de manejo de teclado
  glutSpecialFunc     ( arrow_keys );	//Otras
  glutIdleFunc		  ( animacion );
  glutMainLoop        ( );          // 

  return 0;
}