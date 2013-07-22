#include "glwidget.h"

#include <QCoreApplication>
#include <QKeyEvent>

#include "zpkutils.h"

typedef void (*PglGenVertexArrays) (GLsizei n,  GLuint *arrays);
typedef void (*PglBindVertexArray) (GLuint array);

GLWidget::GLWidget( QWidget* parent )
    : QGLWidget(QGLFormat(QGL::SampleBuffers), parent),
      _shader(),
      _vertexBuffer( QOpenGLBuffer::VertexBuffer ),
      _projMatrix(),
      _modelMatrix(),
      _rotationMatrix(),
      _color(),
      _renderTime(),
      _iteration(5),
      _isBufferAllocated(false),
      _xPressedPos(0),
      _yPressedPos(0),
      _deltaX(0),
      _deltaY(0),
      _leftPressed(false),
      _zoom(1.0),
      _blend(false),
      _showPoints(0),
      _fogDistance(3.0),
      _doClearBackground(true),
      _isDepthTestDisabled(false),
      _fpsAvarage(10)
{
    // Core profile doesn't work with QPainter!!

 /*
    // Specify an OpenGL 3.2 format using the Core profile.
    // That is, no old-school fixed pipeline functionality
    QGLFormat glFormat(QGL::SampleBuffers);
    glFormat.setVersion( 3, 2 );
    glFormat.setProfile( QGLFormat::CoreProfile ); // Requires >=Qt-4.8.0
    //glFormat.setProfile( QGLFormat::CompatibilityProfile );
    QGLContext* context = new QGLContext(glFormat);
    this->setContext(context);
*/
}

GLWidget::~GLWidget()
{
}

void GLWidget::initializeGL()
{
    // get context opengl-version
    qDebug() << "Widget OpenGl: " << format().majorVersion() << "." << format().minorVersion();
    qDebug() << "Context valid: " << context()->isValid();
    qDebug() << "Really used OpenGl: " << context()->format().majorVersion() << "." << context()->format().minorVersion();
    qDebug() << "OpenGl information: VENDOR:       " << (const char*)glGetString(GL_VENDOR);
    qDebug() << "                    RENDERDER:    " << (const char*)glGetString(GL_RENDERER);
    qDebug() << "                    VERSION:      " << (const char*)glGetString(GL_VERSION);
    qDebug() << "                    GLSL VERSION: " << (const char*)glGetString(GL_SHADING_LANGUAGE_VERSION);

    QGLFormat glFormat = QGLWidget::format();
    if ( !glFormat.sampleBuffers() )
        qWarning() << "Could not enable sample buffers";

    // Prepare a complete shader program...
    if ( !prepareShaderProgram( ":/simple.vert", ":/simple.frag" ) )
        return;

    _vertexBuffer.create();
    _vertexBuffer.setUsagePattern( QOpenGLBuffer::StaticDraw );

    _renderTime.start();
}

void GLWidget::resizeGL( int w, int h )
{
    // Set the viewport to window dimensions
    glViewport( 0, 0, w, qMax( h, 1 ) );

    // Establish the clipping volume by setting up an perspective projection
    double aspectRatio = double( w ) / double( qMax(h,1) );
    double verticalViewingAngle = 45.0;
    _projMatrix = QMatrix4x4(); // identity
    _projMatrix.perspective(verticalViewingAngle, aspectRatio, 0.1, 10.0);
}

void GLWidget::paintEvent(QPaintEvent*)
{
  //QPainter painter(this);
  //showGL();
  QPainter painter(this);
  showGL();
  showFPS(painter);
  update();
}

void GLWidget::showFPS(QPainter& painter)
{
  int ms = _renderTime.elapsed();
  _fpsAvarage.add(ms);
  QString text("fps: ");
  text+= QString::number( int(1000.0/_fpsAvarage.getAvarage()) );

  QFontMetrics metrics = QFontMetrics(font());
  int border = qMax(2, metrics.leading());

  QRect rect = metrics.boundingRect(0, 0, width() - 2*border, int(height()*0.125),
                                 Qt::AlignCenter | Qt::TextWordWrap, text);

  painter.setRenderHint(QPainter::TextAntialiasing);
  painter.setPen(Qt::white);
  painter.fillRect(QRect(0, 0, rect.width()+ 2*border, rect.height() + 2*border), QColor(0, 0, 0, 127));
  painter.drawText(border, border, rect.width(), rect.height(),
                    Qt::AlignCenter | Qt::TextWordWrap, text);

  _renderTime.restart();
}

void GLWidget::showGL()
{
    // we need a VAO in core!
    static PglGenVertexArrays glGenVertexArrays = (PglGenVertexArrays) context()->getProcAddress("glGenVertexArrays");
    static PglBindVertexArray glBindVertexArray = (PglBindVertexArray) context()->getProcAddress("glBindVertexArray");

    GLuint VAO;
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    if ( !_vertexBuffer.bind() )
    {
        qWarning() << "Could not bind vertex buffer to the context";
        return;
    }

    // Bind the shader program so that we can associate variables from
    // our application to the shaders
    if ( !_shader.bind() )
    {
        qWarning() << "Could not bind shader program to context";
        return;
    }

    // Enable the "vertex" attribute to bind it to our currently bound
    // vertex buffer.
    _shader.setAttributeBuffer( "vertex", GL_FLOAT, 0, 3 );
    _shader.enableAttributeArray( "vertex" );

    if (!_isBufferAllocated)
    {
       std::auto_ptr<std::vector<zpk::Point3D> > points(zpk::getUnityCube(_iteration));
       _vertexBuffer.allocate( &(*points)[0], points->size() * sizeof(zpk::Point3D) );
       _isBufferAllocated = true;
       _showPoints = zpk::getNumberOfPointsForIteration(_iteration);
    }

    // Set the clear color to black
    if (_doClearBackground)
      glClearColor( 0.0f, 0.0f, 0.0f, 1.0f );

    // Clear the buffer with the current clearing color
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    if (!_isDepthTestDisabled)
      glEnable(GL_DEPTH_TEST);

    // Draw stuff
    QMatrix4x4 rotation;
    rotation.rotate(_deltaY, 1.0, 0.0);
    rotation.rotate(_deltaX, 0.0, 1.0);
    _rotationMatrix = rotation*_rotationMatrix;
    if (_leftPressed)
      _deltaX = _deltaY = 0;

    _modelMatrix = QMatrix4x4();
    _modelMatrix.translate(-0.0, -0.0, -2.0);
    _modelMatrix*= _rotationMatrix;
    _modelMatrix.scale(_zoom, _zoom, _zoom);
    _modelMatrix.translate(-0.5, -0.5, -0.5);

    _shader.setUniformValue( "proj_matrix", _projMatrix );
    _shader.setUniformValue( "model_matrix", _modelMatrix );
    _shader.setUniformValue( "fog_end", _fogDistance );
    _shader.setUniformValue( "model_color", _color );

    if (_showPoints < zpk::getNumberOfPointsForIteration(_iteration))
      ++_showPoints;
    glDrawArrays( GL_LINE_STRIP, 0, _showPoints );

    glDisable(GL_DEPTH_TEST);
    _shader.release();
    _vertexBuffer.release();

    glBindVertexArray(0);
}

void GLWidget::setIteration(int iteration)
{
  _iteration = iteration;
  _isBufferAllocated = false;
}

void GLWidget::setFogDistance(int distance)
{
  _fogDistance = float(distance)/10.0;
}

void GLWidget::setRchannel(int r)
{
  _color.setRed(r);
}

void GLWidget::setGchannel(int g)
{
  _color.setGreen(g);
}

void GLWidget::setBchannel(int b)
{
  _color.setBlue(b);
}

void GLWidget::setClearBackground(bool clearbg)
{
  _doClearBackground = clearbg;
}

void GLWidget::setDisableDepthTest(bool disableDepth)
{
  _isDepthTestDisabled = disableDepth;
}

void GLWidget::animate()
{
  _showPoints = 0;
}

void GLWidget::keyPressEvent( QKeyEvent* e )
{
    switch ( e->key() )
    {
        case Qt::Key_Escape:
            QCoreApplication::instance()->quit();
            break;

        default:
            QGLWidget::keyPressEvent( e );
    }
}

void GLWidget::mousePressEvent(QMouseEvent *e)
{
  if (Qt::LeftButton == e->button())
  {
    _xPressedPos = e->x();
    _yPressedPos = e->y();
    _leftPressed = true;
  }
}
void GLWidget::mouseReleaseEvent(QMouseEvent *e)
{
  if (_leftPressed && Qt::LeftButton == e->button())
  {
    _leftPressed = false;
  }
}
void GLWidget::mouseMoveEvent(QMouseEvent *e)
{
  if (_leftPressed)
  {
    _deltaX = (e->x()-_xPressedPos);
    _deltaY = (e->y()-_yPressedPos);

    _xPressedPos = e->x();
    _yPressedPos = e->y();
  }
  update();
}

void GLWidget::wheelEvent(QWheelEvent* e)
{
  _zoom*= (1.0 + 0.001*e->delta());
}

bool GLWidget::prepareShaderProgram( const QString& vertexShaderPath,
                                     const QString& fragmentShaderPath )
{
    // First we load and compile the vertex shader...
    bool result = _shader.addShaderFromSourceFile( QOpenGLShader::Vertex, vertexShaderPath );
    if ( !result )
        qWarning() << _shader.log();

    // ...now the fragment shader...
    result = _shader.addShaderFromSourceFile( QOpenGLShader::Fragment, fragmentShaderPath );
    if ( !result )
        qWarning() << _shader.log();

    // ...and finally we link them to resolve any references.
    result = _shader.link();
    if ( !result )
        qWarning() << "Could not link shader program:" << _shader.log();

    return result;
}
