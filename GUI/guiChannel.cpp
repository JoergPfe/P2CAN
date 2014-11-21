/*
 * guiChannel.cpp
 *
 *  Created on: 24.09.2014
 *      Author: Hendrik Jung (openGL)
 *      Jannis Priesnitz (Refactoring Interface)
 *      
 */

#include "guiChannel.h"

#include <iostream>
#include <math.h>
#include <GL/glut.h>
#include "Zylinder.h"
#include "Triangle.h"
#include "Tankanzeige.h"
#include "Tacho.h"
#include "Verbrauch.h"
#include "Armaturenbrett.h"
#include <time.h>
#include <SOIL/SOIL.h>
#include <iostream>
#include <math.h>
#include <GL/glut.h>
#include "Zylinder.h"
#include "Triangle.h"
#include "Tankanzeige.h"
#include "Tacho.h"
#include "Verbrauch.h"
#include "Armaturenbrett.h"
#include "Skybox.h"

void runnerService();
void RenderScene(void);
void Reshape(int width, int height);
void Animate(int value);

int run(int argc, char** argv);

//Textur Variablen
//km Stand
GLuint boden_km_Stand;
GLuint deckel_km_Stand;
GLuint Mantel_km_Stand;
//Verbrauch
GLuint boden_Verbrauch;
GLuint deckel_Verbrauch;
GLuint Mantel_Verbrauch;
//Tank
GLuint boden_Tank;
GLuint deckel_Tank;
GLuint Mantel_Tank;
//Skybox
GLuint skybox;

int tankinhalt = 0;
int kmStand = 0;
int Geschwindigkeit = 0;
int Verbrauch_Auto = 0;
//blinker = 0 aus; blinker = 1 rechts; blinker = 2 links;

void loadTexture(GLuint* texture, char* path){
    *texture = SOIL_load_OGL_texture(path,
                                     SOIL_LOAD_AUTO,
                                     SOIL_CREATE_NEW_ID,
                                     SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_MULTIPLY_ALPHA
                                    );
    if(*texture == NULL){
        printf("[Texture loader] \"%s\" failed to load!\n", path);
    }
}

//TODO:
//wirte destructor with ptread join    // pthread_join(thread1, NULL);

guiChannel::guiChannel() {
    // TODO Auto-generated constructor stub
    char** argv = new char*;

    //Threading stuff
    const char *message = "GUIThread";
    int ret1 = pthread_create(&thread1, NULL, runnerService, (void*) message);
    if (ret1) {
        printf("Error");
    }

}

int guiChannel::send(int32_t id, int64_t value) {
//        printf("ID: %lx VALUE: %lx \n", id, value);

    if (id == 0x200) {
        //Geschwindigkeit

        int hbyte = value >> 24;
        hbyte = hbyte * 5;

        int lbyte = value >> 16;
        lbyte = lbyte & 0x0000FF;
        float flbyte = (float) lbyte * 5 / 255; // Datenbyte  3 und 5


        float erg = (float) hbyte + flbyte;

        //                printf("Highbyte: %i; lowbyte: %i, erg: %f  \n", hbyte, lbyte, erg);

        Geschwindigkeit = erg;
        //        //Call to the drawing function
        //        glutDisplayFunc(RenderScene);
        //        //Die sicht
        //        glutReshapeFunc(Reshape);
        //Hier wird das Fenster aktualisiert
//        glutTimerFunc(50, Animate, 4);
    } else if (id == 0x308) {
        //Drehzahl
        int byte = value >> (4 * 12);

        byte = byte & 0x00FF;
        byte = byte * 250;

        //        printf("Value: 0x%lx, RPM: %i; \n", value, byte);

        kmStand = byte;
//        glutTimerFunc(50, Animate, 4);

    } else if (id == 0x608) {
        //Tank
        int byte = value >> (8 * 7);
        byte = byte + 0x28;
//        printf("Value: 0x%lx, Tank: %i; \n", value, byte);
        tankinhalt = byte;

    }
        glutTimerFunc(50, Animate, 4);

    return 0;
}



int blinker = 1;
// Defines für Tastaturtasten
// Jede Zahl steht für eine Tastaturtaste
#define ESC 27
#define LEFT 100
#define UP 101
#define RIGHT 102
#define DOWN 103
#define BILDUP 104
#define BILDDOWN 105

// Globale Variablen
double matrixPositionX = 0.0; // Positionsvariable für die gesamte Matrix (X-Achse)
double matrixPositionY = 0.0; // Positionsvariable für die gesamte Matrix (Y-Achse)
double matrixPositionZ = 0.0; // Positionsvariable für die gesamte Matrix (Z-Achse)
double matrixRotationX = 0.0; // Rotationsvariable für die gesamte Matrix (X-Achse)
double matrixRotationY = 0.0; // Rotationsvariable für die gesamte Matrix (Y-Achse)
/*void Tankanzeige(int Tankinhalt)
{
    Instrument((GLfloat)Tankinhalt);
}*/


//Zeichen Funktion

void RenderScene(void) {
    //Background color
    //glClearColor(0,1,0,1);


    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity(); // Aktuelle Model-/View-Transformations-Matrix zuruecksetzen
    glTranslatef(matrixPositionX, matrixPositionY, matrixPositionZ); // Matrix-Positionierung	
    glRotatef(matrixRotationX, 1.0, 0.0, 0.0); // Rotiere die gesamte Matrix (X-Achse)
    glRotatef(matrixRotationY, 0.0, 1.0, 0.0); // Rotiere die gesamte Matrix (Y-Achse)
    
    ITextur* km_Stand = new ITextur(boden_km_Stand,Mantel_km_Stand,deckel_km_Stand);
    ITextur* Tank = new ITextur(boden_Tank,Mantel_Tank,deckel_Tank);
    ITextur* Verbrauch = new ITextur(boden_Verbrauch,Mantel_Verbrauch,deckel_Verbrauch);
    
    Armaturenbrett(5, kmStand, Geschwindigkeit, blinker, tankinhalt,km_Stand,Tank,Verbrauch);
    
    glutSwapBuffers(); // gemeinsam mit GLUT_DOUBLE für Double-Buffering
    glFlush(); //Buffer leeren  

}

void Reshape(int width, int height) {
    // Hier finden die Reaktionen auf eine Veränderung der Größe des 
    // Graphikfensters statt
    // Matrix für Transformation: Frustum->viewport
    glMatrixMode(GL_PROJECTION);
    // Aktuelle Transformations-Matrix zuruecksetzen
    glLoadIdentity();
    // Viewport definieren
    glViewport(0, 0, width, height);

    // Frustum definieren (siehe unten)
    //glOrtho( GLdouble left, GLdouble right,
    //GLdouble bottom, GLdouble top,
    //GLdouble near, GLdouble far );
    //Das Frustum ist ein Quadrat mit der Kantenlänge von 2 
    //aus dem Ursprung wie zu erwarten sieht man den Würfel frontal
    //vom Ursprung, es hat sich nichts geändert
    //Der Z-Buffer funktioniert so das ein Tiefentest durchgeführt wird.
    //Wenn dieser Test nicht bestanden ist also das Objekt verdeckt wird,
    //dann wird nicht gezeichnet.
    // gluPerspective(senkr. Oeffnungsw., Seitenverh., zNear, zFar);
    gluPerspective(45.0, 1.0, 0.1, 145.0);
    //	glOrtho(-20.0, 20.0, -20.0, 20.0, 0.1, 100.0);

    // Kameraposition
    gluLookAt(0.0, 0.0, -60, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0); // Ausrichtung: Vor der Fläche

    // Matrix für Modellierung/Viewing
    glMatrixMode(GL_MODELVIEW);
}

void Animate(int value) {
    // Hier werden Berechnungen durchgeführt, die zu einer Animation der Szene  
    // erforderlich sind. Dieser Prozess läuft im Hintergrund und wird alle 
    // 10 msec aufgerufen. Der Parameter "value" wird einfach nur um eins 
    // inkrementiert und dem Callback wieder uebergeben.
    //tankinhalt++;


    glutPostRedisplay();

    // Timer wieder registrieren; Animate wird so nach 10 msec mit value+=1 aufgerufen
    glutTimerFunc(10, Animate, 0/*++value*/); // was macht value??
}

void Init() {
    glDepthMask(true);
	glEnable(GL_DEPTH_TEST);
	glClearDepth(1.0);
	glClearColor( 0.72, 0.65, 1.0, 1.0 ); // Blauer Hintergrund
	 
        
        //Texturen Laden
        //km_Stand
        loadTexture(&boden_km_Stand, "PalisanderSantos_Holz.JPG");
        loadTexture(&deckel_km_Stand, "PalisanderSantos_Holz.JPG");
        loadTexture(&Mantel_km_Stand,"PalisanderSantos_Holz.JPG");
        //Tank
        loadTexture(&boden_Verbrauch, "PalisanderSantos_Holz.JPG");
        loadTexture(&deckel_Verbrauch, "PalisanderSantos_Holz.JPG");
        loadTexture(&Mantel_Verbrauch,"PalisanderSantos_Holz.JPG");
        //Verbrauch
        loadTexture(&boden_Tank, "PalisanderSantos_Holz.JPG");
        loadTexture(&deckel_Tank, "PalisanderSantos_Holz.JPG");
        loadTexture(&Mantel_Tank,"PalisanderSantos_Holz.JPG");
        //Skybox
        loadTexture(&skybox,"2013_Porsche_911_Carrera_4S_(991)_(9626546987).jpg");
    //Array mit der Bewegung der Schaukel beschreiben

    // Hier finden jene Aktionen statt, die zum Programmstart einmalig 
    // durchgeführt werden müssen
}


// Funktion die die Matrix nach Links dreht
// Wird mittels Tastaturtaste aufgerufen

void dreheMatrixLinks() {
    matrixRotationY -= 1.0;
    // RenderScene aufrufen, damit die Bildfläche neu aufgebaut wird
    glutPostRedisplay();
}

// Funktion die die Matrix nach Rechts dreht
// Wird mittels Tastaturtaste aufgerufen

void dreheMatrixRechts() {
    matrixRotationY += 1.0;
    // RenderScene aufrufen, damit die Bildfläche neu aufgebaut wird
    glutPostRedisplay();
}

// Funktion die die Matrix nach Oben dreht
// Wird mittels Tastaturtaste aufgerufen

void dreheMatrixOben() {
    matrixRotationX += 1.0;
    // RenderScene aufrufen, damit die Bildfläche neu aufgebaut wird
    glutPostRedisplay();
}

// Funktion die die Matrix nach Unten dreht
// Wird mittels Tastaturtaste aufgerufen

void dreheMatrixUnten() {
    matrixRotationX -= 1.0;
    // RenderScene aufrufen, damit die Bildfläche neu aufgebaut wird
    glutPostRedisplay();
}

void zoomReinMatrix() {
    matrixPositionZ += 0.2;
}

void zoomRausMatrix() {
    matrixPositionZ -= 0.2;
}

void Tastatur(unsigned char key, int x, int y) {
    switch (key) {
            // Programm beenden mit ESC oder q
        case 'q':
        case ESC:
            exit(0);
            break;

            // w a s d = Rotiere
        case 'w':
            dreheMatrixOben();
            break;
        case 'a':
            dreheMatrixLinks();
            break;
        case 's':
            dreheMatrixUnten();
            break;
        case 'd':
            dreheMatrixRechts();
            break;

            // m n = Zoome rein und raus
        case 'm':
            zoomReinMatrix();
            break;
        case 'n':
            zoomRausMatrix();
            break;
    };
}

void runnerService() {
    char** argv = new char*;
    run(0, argv);

}

/*
 * 
 */
int run(int argc, char** argv) {
    glutInit(&argc, argv);
    //Simple buffer
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowPosition(50, 25);
    glutInitWindowSize(1200, 1200);
    glutCreateWindow("Green window");
    //Call to the drawing function
    glutDisplayFunc(RenderScene);
    //Die sicht
    glutReshapeFunc(Reshape);
    //Hier wird das Fenster aktualisiert
    //glutTimerFunc(10, Animate, 4);
    glutKeyboardFunc(Tastatur); // Initialisiere Tastaturtasten

    Init();
    glutMainLoop();
    return 0;
}

