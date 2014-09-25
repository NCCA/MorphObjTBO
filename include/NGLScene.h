#ifndef NGLSCENE_H__
#define NGLSCENE_H__
#include "OpenGLWindow.h"
#include <ngl/Camera.h>
#include <ngl/Colour.h>
#include <ngl/Light.h>
#include <ngl/Obj.h>
#include <ngl/Text.h>
#include <QTimer>
//----------------------------------------------------------------------------------------------------------------------
/// @file NGLScene.h
/// @brief this class inherits from the Qt OpenGLWindow and allows us to use NGL to draw OpenGL
/// @author Jonathan Macey
/// @version 1.0
/// @date 10/9/13
/// Revision History :
/// This is an initial version used for the new NGL6 / Qt 5 demos
/// @class NGLScene
/// @brief our main glwindow widget for NGL applications all drawing elements are
/// put in this file
//----------------------------------------------------------------------------------------------------------------------

class NGLScene : public OpenGLWindow
{
  Q_OBJECT
  public:
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief ctor for our NGL drawing class
    /// @param [in] parent the parent window to the class
    //----------------------------------------------------------------------------------------------------------------------
    NGLScene(QWindow *_parent=0);
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief dtor must close down ngl and release OpenGL resources
    //----------------------------------------------------------------------------------------------------------------------
    ~NGLScene();
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief the initialize class is called once when the window is created and we have a valid GL context
    /// use this to setup any default GL stuff
    //----------------------------------------------------------------------------------------------------------------------
    void initialize();
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief this is called everytime we want to draw the scene
    //----------------------------------------------------------------------------------------------------------------------
    void render();

private:
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief used to store the x rotation mouse value
    //----------------------------------------------------------------------------------------------------------------------
    int m_spinXFace;
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief used to store the y rotation mouse value
    //----------------------------------------------------------------------------------------------------------------------
    int m_spinYFace;
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief flag to indicate if the mouse button is pressed when dragging
    //----------------------------------------------------------------------------------------------------------------------
    bool m_rotate;
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief flag to indicate if the Right mouse button is pressed when dragging
    //----------------------------------------------------------------------------------------------------------------------
    bool m_translate;
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief the previous x mouse value
    //----------------------------------------------------------------------------------------------------------------------
    int m_origX;
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief the previous y mouse value
    //----------------------------------------------------------------------------------------------------------------------
    int m_origY;
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief the previous x mouse value for Position changes
    //----------------------------------------------------------------------------------------------------------------------
    int m_origXPos;
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief the previous y mouse value for Position changes
    //----------------------------------------------------------------------------------------------------------------------
    int m_origYPos;
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief used to store the global mouse transforms
    //----------------------------------------------------------------------------------------------------------------------
    ngl::Mat4 m_mouseGlobalTX;
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief Our Camera
    //----------------------------------------------------------------------------------------------------------------------
    ngl::Camera *m_cam;
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief the model position for mouse movement
    //----------------------------------------------------------------------------------------------------------------------
    ngl::Vec3 m_modelPos;
    enum Weights{POSE1,POSE2};
    enum Direction{UP,DOWN};
    void changeWeight(Weights _w,Direction _d );

    inline void toggleAnimation(){m_animation^=true;}
    void punchLeft();
    void punchRight();
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief our model
    //----------------------------------------------------------------------------------------------------------------------
    std::vector<ngl::Obj *> m_meshes;
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief text for rendering
    //----------------------------------------------------------------------------------------------------------------------
    ngl::Text *m_text;
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief the weight of pose one
    //----------------------------------------------------------------------------------------------------------------------
    ngl::Real m_weight1;
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief the weight of pose two
    //----------------------------------------------------------------------------------------------------------------------
    ngl::Real m_weight2;
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief the mesh with all the data in it
    //----------------------------------------------------------------------------------------------------------------------
    ngl::VertexArrayObject *m_vaoMesh;
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief left animation timer
    //----------------------------------------------------------------------------------------------------------------------
    QTimer *m_timerLeft;
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief right animation timer
    //----------------------------------------------------------------------------------------------------------------------
    QTimer *m_timerRight;
    //----------------------------------------------------------------------------------------------------------------------
    /// animation flag for timers
    //----------------------------------------------------------------------------------------------------------------------
    bool m_animation;
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief flag to indicate if punching left
    //----------------------------------------------------------------------------------------------------------------------
    bool m_punchLeft;
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief flag to indicate if punching right
    //----------------------------------------------------------------------------------------------------------------------
    bool m_punchRight;
    /// @brief the id for the texture buffer object
    GLuint m_tboID;
    //----------------------------------------------------------------------------------------------------------------------
    /// do our morphing for the 3 meshes
    //----------------------------------------------------------------------------------------------------------------------
    void createMorphMesh();

    //----------------------------------------------------------------------------------------------------------------------
    /// @brief method to load transform matrices to the shader
    //----------------------------------------------------------------------------------------------------------------------
    void loadMatricesToShader();
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief Qt Event called when the window is re-sized
    /// @param [in] _event the Qt event to query for size etc
    //----------------------------------------------------------------------------------------------------------------------
    void resizeEvent(QResizeEvent *_event);
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief Qt Event called when a key is pressed
    /// @param [in] _event the Qt event to query for size etc
    //----------------------------------------------------------------------------------------------------------------------
    void keyPressEvent(QKeyEvent *_event);
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief this method is called every time a mouse is moved
    /// @param _event the Qt Event structure
    //----------------------------------------------------------------------------------------------------------------------
    void mouseMoveEvent (QMouseEvent * _event );
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief this method is called everytime the mouse button is pressed
    /// inherited from QObject and overridden here.
    /// @param _event the Qt Event structure
    //----------------------------------------------------------------------------------------------------------------------
    void mousePressEvent ( QMouseEvent *_event);
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief this method is called everytime the mouse button is released
    /// inherited from QObject and overridden here.
    /// @param _event the Qt Event structure
    //----------------------------------------------------------------------------------------------------------------------
    void mouseReleaseEvent ( QMouseEvent *_event );

    //----------------------------------------------------------------------------------------------------------------------
    /// @brief this method is called everytime the mouse wheel is moved
    /// inherited from QObject and overridden here.
    /// @param _event the Qt Event structure
    //----------------------------------------------------------------------------------------------------------------------
    void wheelEvent( QWheelEvent *_event);
  private slots :
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief the timers are connected to slots to trigger the events
    //----------------------------------------------------------------------------------------------------------------------
    void updateLeft();
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief the timers are connected to slots to trigger the events
    //----------------------------------------------------------------------------------------------------------------------
    void updateRight();


};



#endif
