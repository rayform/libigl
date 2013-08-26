#include "view_axis.h"

#if __APPLE__
#  include <OpenGL/gl.h>
#elif defined(_WIN32)
#    define NOMINMAX
#    include <Windows.h>
#    undef NOMINMAX
#    include <GL/glew.h>
#    include <GL/gl.h>
#else
#  define GL_GLEXT_PROTOTYPES
#  include <GL/gl.h>
#  include <GL/glext.h>
#endif

IGL_INLINE void igl::view_axis(double * x, double * y, double * z)
{
  double mv[16];
  glGetDoublev(GL_MODELVIEW_MATRIX, mv);
  igl::view_axis(mv,x,y,z);
}

IGL_INLINE void igl::view_axis(const double * mv, double * x, double * y, double * z)
{
  *x = -mv[0*4+2];
  *y = -mv[1*4+2];
  *z = -mv[2*4+2];
}
