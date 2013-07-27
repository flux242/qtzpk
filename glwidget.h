#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QGLWidget>

#include <QOpenGLBuffer>
#include <QOpenGLShaderProgram>
#include <QTime>

/*
 * @brief This class is used to smooth shown fps
 */
class RunningAverage
{
public:
    RunningAverage(int size) : _vector(), _size(size), _summ(0.0) {}
    ~RunningAverage() {}

    void add(int value)
    {
        while (_vector.size()<_size)
        {
           // initialization
          _vector.push_front(value);
          _summ+=float(value)/_size;
        }

        _summ+=(float(value)/_size - float(_vector.last())/_size);
        _vector.pop_back();
        _vector.push_front(value);
    }
    int getAverage()
    {
      return int(_summ);
    }
private:
    QVector<int> _vector;
    int _size;
    float _summ;
};


class GLWidget : public QGLWidget
{
    Q_OBJECT
public:
    GLWidget( QWidget* parent = 0 );
    virtual ~GLWidget();
public slots:
    void setIteration(int);
    void setFogDistance(int);
    void setRchannel(int);
    void setGchannel(int);
    void setBchannel(int);
    void setClearBackground(bool);
    void setDisableDepthTest(bool);
    void animate();
protected:
    virtual void initializeGL();
    virtual void resizeGL( int w, int h );

    virtual void paintEvent(QPaintEvent*);

    virtual void keyPressEvent    (QKeyEvent*   e);
    virtual void mousePressEvent  (QMouseEvent* e);
    virtual void mouseReleaseEvent(QMouseEvent* e);
    virtual void mouseMoveEvent   (QMouseEvent* e);
    virtual void wheelEvent       (QWheelEvent* e);

private:
    bool prepareShaderProgram( const QString& vertexShaderPath,
                               const QString& fragmentShaderPath );

    void showGL();
    void showFPS(QPainter&);

    QOpenGLShaderProgram _shader;
    QOpenGLBuffer _vertexBuffer;
    QMatrix4x4 _projMatrix;
    QMatrix4x4 _modelMatrix;
    QMatrix4x4 _rotationMatrix;
    QColor     _color;
    QTime      _renderTime;
    int _iteration;
    bool _isBufferAllocated;
    int _xPressedPos;
    int _yPressedPos;
    int _deltaX;
    int _deltaY;
    bool _leftPressed;
    float _zoom;
    bool _blend;
    int _showPoints;
    float _fogDistance;
    bool _doClearBackground;
    bool _isDepthTestDisabled;
    RunningAverage _fpsAverage;
};

#endif // GLWIDGET_H
