#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <assert.h>

#include <unistd.h>
#include <EGL/egl.h>
#include <GL/gl.h>

static EGLint const attributeList[] = {
    EGL_RED_SIZE, 1,
    EGL_GREEN_SIZE, 1,
    EGL_BLUE_SIZE, 1,
    EGL_NONE,
};

int const width = 512;
int const height = 512;

int main(int argc, char **argv)
{
    EGLDisplay display = eglGetDisplay(EGL_DEFAULT_DISPLAY);

    eglInitialize(display, NULL, NULL);

    EGLConfig config;
    EGLint numConfig;

    eglChooseConfig(display, attributeList, &config, 1, &numConfig);

    EGLContext context = eglCreateContext(display, config, EGL_NO_CONTEXT, NULL);

    eglMakeCurrent(display, EGL_NO_SURFACE, EGL_NO_SURFACE, context);

    // draw sth
    glViewport(0, 0, width, height);
    glClearColor(1.0, 1.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    //glFlush();

    // read pixels to file
    int dumpbuf_fd = open("/tmp/fbodump.rgb", O_CREAT | O_SYNC | O_RDWR, S_IRUSR | S_IWUSR);
    printf("file descriptor %d\n", dumpbuf_fd);
    assert(-1 != dumpbuf_fd);
    void *dumpbuf = malloc(width * height * 3);
    assert(dumpbuf);

    glReadBuffer(GL_COLOR_ATTACHMENT0);
    glReadPixels(0, 0, width, height, GL_RGB, GL_UNSIGNED_BYTE, dumpbuf);
    lseek(dumpbuf_fd, SEEK_SET, 0);
    write(dumpbuf_fd, dumpbuf, width * height * 3);

    eglTerminate(display);

    return 0;
}