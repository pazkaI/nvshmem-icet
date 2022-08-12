#include <GL/glut.h>
#include <stdio.h>

int mx = 0, my = 0;
void display()
{
    glClearColor( 0, 0, 0, 1 );
    glClear( GL_COLOR_BUFFER_BIT );

    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    glOrtho( -10, 10, -10, 10, -1, 1 );

    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();

    glScalef( 5, 5, 5 );
    glBegin( GL_TRIANGLES );
    glColor3ub( 255, 0, 0 );
    glVertex2f( -1, -1 );
    glColor3ub( 0, 255, 0 );
    glVertex2f( 1, -1 );
    glColor3ub( 0, 0, 255 );
    glVertex2f( 0, 1 );
    glEnd();

    // 4 bytes per pixel (RGBA), 1x1 bitmap
    unsigned char pixels[ 1 * 1 * 4 ] = { 0 };
    glReadPixels( mx, my, 1, 1, GL_RGBA, GL_UNSIGNED_BYTE, pixels );

    printf("r: %d\n", pixels[0]);
    printf("g: %d\n", pixels[1]);
    printf("b: %d\n", pixels[2]);
    printf("a: %d\n", pixels[3]);

    /*std::cout << "r: " << static_cast< int >( pixels[ 0 ] ) << '\n';
    std::cout << "g: " << static_cast< int >( pixels[ 1 ] ) << '\n';
    std::cout << "b: " << static_cast< int >( pixels[ 2 ] ) << '\n';
    std::cout << "a: " << static_cast< int >( pixels[ 3 ] ) << '\n' << std::endl;*/

    glutSwapBuffers();
}

void mouse( int x, int y )
{
    mx = x;
    my = glutGet( GLUT_WINDOW_HEIGHT ) - y;
    glutPostRedisplay();
}

int main( int argc, char **argv )
{
    glutInit( &argc, argv );
    glutInitDisplayMode( GLUT_RGBA | GLUT_DOUBLE );
    glutInitWindowSize( 800, 600 );
    glutCreateWindow( "glReadPixels() example" );
    glutDisplayFunc( display );
    glutPassiveMotionFunc( mouse );
    glutMainLoop();
    return 0;
}