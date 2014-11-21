//============================================================================
// Name        : testMain.cpp
// Author      : Andreas Schroll
// Version     :
// Copyright   :
// Description :
//============================================================================


#include "datamanager.h"
#include "canChannel.h"
#include "guiChannel.h"
#include "DeadlineTimer.h"
#include "pthread.h"
//
//// ++ GUI ++
//#include <iostream>
//#include <math.h>
//#include <GL/glut.h>
//
//#include "/home/bpse_sose14/NetBeansProjects/CppApplication_1/Zylinder.h"
//#include "/home/bpse_sose14/NetBeansProjects/CppApplication_1/Triangle.h"
//#include "/home/bpse_sose14/NetBeansProjects/CppApplication_1/Tankanzeige.h"
//#include "/home/bpse_sose14/NetBeansProjects/CppApplication_1/Tacho.h"
//#include "/home/bpse_sose14/NetBeansProjects/CppApplication_1/Verbrauch.h"
//#include "/home/bpse_sose14/NetBeansProjects/CppApplication_1/Armaturenbrett.h"
////--GUI --

//int run(int argc, char** argv);



int main() {


   

    //ch.send(0x124,0x1122334455667788);
    datamanager dm;
    guiChannel guich;

    canChannel ch("can0", &dm);
    
    dm.add_dp(0x200);

    dm.add_dp_chan(0x200, &guich, 50);
    dm.add_dp_chan(0x200, &ch,0); //0 = nur empfangen 
    
    while(1) {
        sleep(1);
    }
//    dm.add_dp_chan(0x123, &ch, 50);
//    dm.update_val(0x123, 0x11223344);
//    dm.send_val(0x123);
//    dm.add_dp(0x124);
//    dm.add_dp_chan(0x124, &ch, 50);
//    dm.add_dp_chan(0x124, &guich, 50);
//    dm.update_val(0x200, 0x20000000);
//    dm.send_val(0x200);
    //--        dt.stop();

}
//
//
//int tankinhalt = tankinhalt;
//int kmStand = tankinhalt;
//int Geschwindigkeit = tankinhalt;
//int Verbrauch_Auto = tankinhalt;
////blinker = 0 aus; blinker = 1 rechts; blinker = 2 links;
//int blinker = tankinhalt;
//// Defines für Tastaturtasten
//// Jede Zahl steht für eine Tastaturtaste
//#define ESC 27
//#define LEFT 100
//#define UP 101
//#define RIGHT 102
//#define DOWN 103
//#define BILDUP 104
//#define BILDDOWN 105
//
//// Globale Variablen
//double matrixPositionX = 0.0; // Positionsvariable für die gesamte Matrix (X-Achse)
//double matrixPositionY = 0.0; // Positionsvariable für die gesamte Matrix (Y-Achse)
//double matrixPositionZ = 0.0; // Positionsvariable für die gesamte Matrix (Z-Achse)
//double matrixRotationX = 0.0; // Rotationsvariable für die gesamte Matrix (X-Achse)
//double matrixRotationY = 0.0; // Rotationsvariable für die gesamte Matrix (Y-Achse)
///*void Tankanzeige(int Tankinhalt)
//{
//    Instrument((GLfloat)Tankinhalt);
//}*/
//
//
//
////Zeichen Funktion
//void RenderScene(void)
//{
////Background color
////glClearColor(0,1,0,1);
// 
//   
//glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//glLoadIdentity(); // Aktuelle Model-/View-Transformations-Matrix zuruecksetzen
//glTranslatef(matrixPositionX, matrixPositionY, matrixPositionZ); // Matrix-Positionierung	
//glRotatef(matrixRotationX, 1.0, 0.0, 0.0); // Rotiere die gesamte Matrix (X-Achse)
//glRotatef(matrixRotationY, 0.0, 1.0, 0.0); // Rotiere die gesamte Matrix (Y-Achse)
////Instrument((GLfloat)tankinhalt);
////Tankanzeige(0);
////Triangle(1,0.5);
////Zylinder(3);
////int h = tankinhalt;
////Tankanzeige((GLfloat)tankinhalt);
////Zylinder(13);
//Armaturenbrett(tankinhalt,tankinhalt,tankinhalt,tankinhalt,tankinhalt);
////gluCylinder()
////glRotatef(180,1,0,0);
//
////Tankanzeige(10);
////Instrument(10);
////Draw order
//glutSwapBuffers(); // gemeinsam mit GLUT_DOUBLE für Double-Buffering
//glFlush(); //Buffer leeren  
//
//}
//
//void Reshape(int width,int height)
//{
//   // Hier finden die Reaktionen auf eine Veränderung der Größe des 
//   // Graphikfensters statt
//	// Matrix für Transformation: Frustum->viewport
//	glMatrixMode(GL_PROJECTION);
//	// Aktuelle Transformations-Matrix zuruecksetzen
//	glLoadIdentity();
//	// Viewport definieren
//	glViewport(0, 0, width, height);
//	
//	// Frustum definieren (siehe unten)
//	//glOrtho( GLdouble left, GLdouble right,
//	//GLdouble bottom, GLdouble top,
//	//GLdouble near, GLdouble far );
//	//Das Frustum ist ein Quadrat mit der Kantenlänge von 2 
//	//aus dem Ursprung wie zu erwarten sieht man den Würfel frontal
//	//vom Ursprung, es hat sich nichts geändert
//	//Der Z-Buffer funktioniert so das ein Tiefentest durchgeführt wird.
//	//Wenn dieser Test nicht bestanden ist also das Objekt verdeckt wird,
//	//dann wird nicht gezeichnet.
//	// gluPerspective(senkr. Oeffnungsw., Seitenverh., zNear, zFar);
//	gluPerspective(45.0, 1.0, 0.1, 145.0);
////	glOrtho(-20.0, 20.0, -20.0, 20.0, 0.1, 100.0);
//
//	// Kameraposition
//	gluLookAt(0.0, 0.0, -60, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0); // Ausrichtung: Vor der Fläche
//
//	// Matrix für Modellierung/Viewing
//	glMatrixMode(GL_MODELVIEW);
//}
//
//void Animate (int value)    
//{
//	// Hier werden Berechnungen durchgeführt, die zu einer Animation der Szene  
//	// erforderlich sind. Dieser Prozess läuft im Hintergrund und wird alle 
//	// 10 msec aufgerufen. Der Parameter "value" wird einfach nur um eins 
//	// inkrementiert und dem Callback wieder uebergeben.
//        tankinhalt++;
//        
//    
//        glutPostRedisplay();
//        
//	// Timer wieder registrieren; Animate wird so nach 10 msec mit value+=1 aufgerufen
//	glutTimerFunc(10, Animate, ++value);          
//}
//
//void Init()	
//{
//    glDepthMask(true);
//	glEnable(GL_DEPTH_TEST);
//	glClearDepth(1.0);
//	glClearColor( 0.72, 0.65, 1.0, 1.0 ); // Blauer Hintergrund
//	
//	//Array mit der Bewegung der Schaukel beschreiben
//		
//   // Hier finden jene Aktionen statt, die zum Programmstart einmalig 
//   // durchgeführt werden müssen
//}
//
//
//// Funktion die die Matrix nach Links dreht
//// Wird mittels Tastaturtaste aufgerufen
//void dreheMatrixLinks() {
//	matrixRotationY -= 1.0;
//	// RenderScene aufrufen, damit die Bildfläche neu aufgebaut wird
//	glutPostRedisplay();
//}
//
//// Funktion die die Matrix nach Rechts dreht
//// Wird mittels Tastaturtaste aufgerufen
//void dreheMatrixRechts() {
//	matrixRotationY += 1.0;
//	// RenderScene aufrufen, damit die Bildfläche neu aufgebaut wird
//	glutPostRedisplay();
//}
//
//// Funktion die die Matrix nach Oben dreht
//// Wird mittels Tastaturtaste aufgerufen
//void dreheMatrixOben() {
//	matrixRotationX += 1.0;
//	// RenderScene aufrufen, damit die Bildfläche neu aufgebaut wird
//	glutPostRedisplay();
//}
//
//// Funktion die die Matrix nach Unten dreht
//// Wird mittels Tastaturtaste aufgerufen
//void dreheMatrixUnten() {
//	matrixRotationX -= 1.0;
//	// RenderScene aufrufen, damit die Bildfläche neu aufgebaut wird
//	glutPostRedisplay();
//}
//
//void zoomReinMatrix() {
//	matrixPositionZ += 0.2;
//}
//
//void zoomRausMatrix() {
//	matrixPositionZ -= 0.2;
//}
//
//void Tastatur(unsigned char key, int x, int y) {
//	switch (key) {
//		// Programm beenden mit ESC oder q
//		case 'q':
//		case ESC:
//			exit(0);
//			break;
//
//		// w a s d = Rotiere
//		case 'w':
//			dreheMatrixOben();
//			break;
//		case 'a':
//			dreheMatrixLinks();
//			break;
//		case 's':
//			dreheMatrixUnten();
//			break;
//		case 'd':
//			dreheMatrixRechts();
//			break;
//
//		// m n = Zoome rein und raus
//		case 'm':
//			zoomReinMatrix();
//			break;
//		case 'n':
//			zoomRausMatrix();
//			break;
//	};
//}
//
///*
// * 
// */
//int run(int argc, char** argv) {
//    glutInit(&argc, argv);
//    //Simple buffer
//    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
//    glutInitWindowPosition(50,25);
//    glutInitWindowSize(1200,1200);
//    glutCreateWindow("Green window");
//    //Call to the drawing function
//    glutDisplayFunc(RenderScene); 
//    //Die sicht
//    glutReshapeFunc( Reshape );
//    //Hier wird das Fenster aktualisiert
//    glutTimerFunc( 1, Animate, 4);   
//    glutKeyboardFunc(Tastatur); // Initialisiere Tastaturtasten
//    
//    Init();
//    glutMainLoop(); 
//    return 0;
//}
//
