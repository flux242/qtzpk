#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QGLWidget>

#include <QOpenGLBuffer>
#include <QOpenGLShaderProgram>
#include <QTime>

/*
 * @brief This class is used to smooth shown fps
 */
class RunningAvarage
{
public:
    RunningAvarage(int size) : _vector(size), _size(size) {}
    ~RunningAvarage() {}

    void add(int value)
    {
        if (_vector.size()>=_size) _vector.pop_back();
        _vector.push_front(value);
    }
    int getAvarage()
    {
        int summ = 0;
        for (int i = 0; i < _vector.size(); ++i)
          summ+=_vector.at(i);

        return int(summ/_vector.size());
    }
private:
    QVector<int> _vector;
    int _size;
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
    RunningAvarage _fpsAvarage;
};

#endif // GLWIDGET_H
