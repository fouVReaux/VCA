#ifndef MAINCOMPONENT_H_INCLUDED
#define MAINCOMPONENT_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "WavefrontObjParser.h"
#include "TextureTextButton.cpp"
#include "RingBuffer.h"
#define RING_BUFFER_READ_SIZE 256
/*
 This Class display a 3D obj animation with audio input that change the size of the object
 It use the OpenGLAppComponent class on JUCE programing.
 with a set of setter the user can change the medium size, the texture and the object display on the visualizator
*/

//==============================================================================
/*
 
 Terminology used in OpenGL and in particular for Juce's implementation
 of OpenGL support includes:
 - Vertex (plur. vertices):

 Shader Notta:
 The Vertex Shader defines the actions executed by the GPU to define vertex attributes 
 (e.g. each vertex coordinates, color, etc.).
 The Fragment Shader, which is executed after the Vertex Shader, defines the
 attributes of all the pixels other than those corresponding to the vertices. (render)

*/

// This will be used to color the obj at starting Time
#define COLOR_BY_CPU Colour(0xC080FF80)

// This will be used if the programmer whant to change the starting Color
#define COLOR_BY_GPU_RED 0.95
#define COLOR_BY_GPU_GREEN 0.57
#define COLOR_BY_GPU_BLUE 0.03
#define COLOR_BY_GPU_ALPHA 0.7
// Define this color for the CPU code
#define COLOR_BY_GPU_USED_BY_CPU Colour((uint8)(COLOR_BY_GPU_RED*255),(uint8)(COLOR_BY_GPU_GREEN*255),(uint8)(COLOR_BY_GPU_BLUE*255),(float)COLOR_BY_GPU_ALPHA)*/
// Define this color for the GPU code (shader) string. See fragment shader below.
// (This is pretty ugly define code, but it works... If you have a better solution, please use it!)
#define STRINGER(x) #x
#define TO_STRING(x) STRINGER(x)
#define COLOR_BY_GPU_STRING TO_STRING(COLOR_BY_GPU_RED) "," TO_STRING(COLOR_BY_GPU_GREEN) "," TO_STRING(COLOR_BY_GPU_BLUE) "," TO_STRING(COLOR_BY_GPU_ALPHA)

// This will load all the texture in BinaryData in order to be used when the user set on of theses texture
#define PRG_USE_TEXTURE 1 // the prg use texture and no color rendering 
#define TEXTURE_DATA_A BinaryData::A_jpg,BinaryData::A_jpgSize
#define TEXTURE_DATA_B BinaryData::B_jpg,BinaryData::B_jpgSize
#define TEXTURE_DATA_C BinaryData::C_jpg,BinaryData::C_jpgSize
#define TEXTURE_DATA_D BinaryData::D_jpg,BinaryData::D_jpgSize
#define TEXTURE_DATA_E BinaryData::E_jpg,BinaryData::E_jpgSize
#define TEXTURE_DATA_F BinaryData::F_jpg,BinaryData::F_jpgSize
#define TEXTURE_DATA_G BinaryData::G_jpg,BinaryData::G_jpgSize
#define TEXTURE_DATA_H BinaryData::H_jpg,BinaryData::H_jpgSize

//==================================================================================
class ObjRotation   : public OpenGLAppComponent// Juce Open GL Class
{
public:
    //==============================================================================
    ObjRotation(RingBuffer<GLfloat> * ringBuffer) : readBuffer (2, RING_BUFFER_READ_SIZE)
    {
        setSize (800, 600);
        objizer = OBJ_A;
        
        //save of the Ring buffer (audio buffer)
        this->ringBuffer = ringBuffer;
    }

    ~ObjRotation()
    {
        // Release ringBuffer
        ringBuffer = nullptr;
        // Release OpenGL resources
        shutdownOpenGL();
    }
    //==============================================================================
    void start()
    {
        openGLContext.setContinuousRepainting (true);
    }
    
    void stop()
    {
        //shutdownOpenGL();
        openGLContext.setContinuousRepainting (false);
    }
    //==============================================================================
    // --> /!\ : WARNING paint is not an OpenGL routine but a JUCE one
    void paint (Graphics& g) override
    {
    }
    //==============================================================================
    // --> /!\ : WARNING resized is not an OpenGL routine but a JUCE one
    // called when the size of the window change
    void resized() override
    {
        draggableOrientation.setViewport (getLocalBounds());
    }
    //==============================================================================
    // Called once when the OpenGL context is created
    void initialise() override
    {
        //init the class by loading the shader source in the memory
        createShaders();
        //--------------------------------------------------------------------------
        // get images from the memory data and save it in the class in images
        Image textureImageA = ImageCache::getFromMemory (TEXTURE_DATA_A);
        Image textureImageB = ImageCache::getFromMemory (TEXTURE_DATA_B);
        Image textureImageC = ImageCache::getFromMemory (TEXTURE_DATA_C);
        Image textureImageD = ImageCache::getFromMemory (TEXTURE_DATA_D);
        Image textureImageE = ImageCache::getFromMemory (TEXTURE_DATA_E);
        Image textureImageF = ImageCache::getFromMemory (TEXTURE_DATA_F);
        Image textureImageG = ImageCache::getFromMemory (TEXTURE_DATA_G);
        Image textureImageH = ImageCache::getFromMemory (TEXTURE_DATA_H);
        //--------------------------------------------------------------------------
        // verification if the size of the texture is a power of 2 (to be more efficient)
        // with the GPU arch - 
        // resized if not a power of 2
        if (! (isPowerOfTwo (textureImageA.getWidth()) && isPowerOfTwo (textureImageA.getHeight())))
            textureImageA = textureImageA.rescaled (jmin (1024, nextPowerOfTwo (textureImageA.getWidth())),
                                   jmin (1024, nextPowerOfTwo (textureImageA.getHeight())));
        textureA.loadImage(textureImageA);
        //--------------------------------------------------------------------------
        if (! (isPowerOfTwo (textureImageB.getWidth()) && isPowerOfTwo (textureImageB.getHeight())))
            textureImageB = textureImageB.rescaled (jmin (1024, nextPowerOfTwo (textureImageB.getWidth())),
                                   jmin (1024, nextPowerOfTwo (textureImageB.getHeight())));
        textureB.loadImage(textureImageB);
        //--------------------------------------------------------------------------
        if (! (isPowerOfTwo (textureImageC.getWidth()) && isPowerOfTwo (textureImageC.getHeight())))
            textureImageC = textureImageC.rescaled (jmin (1024, nextPowerOfTwo (textureImageC.getWidth())),
                                   jmin (1024, nextPowerOfTwo (textureImageC.getHeight())));
        textureC.loadImage(textureImageC);
        //--------------------------------------------------------------------------
        if (! (isPowerOfTwo (textureImageD.getWidth()) && isPowerOfTwo (textureImageD.getHeight())))
            textureImageD = textureImageD.rescaled (jmin (1024, nextPowerOfTwo (textureImageD.getWidth())),
                                   jmin (1024, nextPowerOfTwo (textureImageD.getHeight())));
        textureD.loadImage(textureImageD);
        //--------------------------------------------------------------------------
        if (! (isPowerOfTwo (textureImageE.getWidth()) && isPowerOfTwo (textureImageE.getHeight())))
            textureImageE = textureImageE.rescaled (jmin (1024, nextPowerOfTwo (textureImageE.getWidth())),
                                   jmin (1024, nextPowerOfTwo (textureImageE.getHeight())));
        textureE.loadImage(textureImageE);
        //--------------------------------------------------------------------------
        if (! (isPowerOfTwo (textureImageF.getWidth()) && isPowerOfTwo (textureImageF.getHeight())))
            textureImageF = textureImageF.rescaled (jmin (1024, nextPowerOfTwo (textureImageF.getWidth())),
                                   jmin (1024, nextPowerOfTwo (textureImageF.getHeight())));
        textureF.loadImage(textureImageF);
        //--------------------------------------------------------------------------
        if (! (isPowerOfTwo (textureImageG.getWidth()) && isPowerOfTwo (textureImageG.getHeight())))
            textureImageG = textureImageG.rescaled (jmin (1024, nextPowerOfTwo (textureImageG.getWidth())),
                                   jmin (1024, nextPowerOfTwo (textureImageG.getHeight())));
        textureG.loadImage(textureImageG);
        //--------------------------------------------------------------------------
        if (! (isPowerOfTwo (textureImageH.getWidth()) && isPowerOfTwo (textureImageH.getHeight())))
            textureImageH = textureImageH.rescaled (jmin (1024, nextPowerOfTwo (textureImageH.getWidth())),
                                   jmin (1024, nextPowerOfTwo (textureImageH.getHeight())));
        textureH.loadImage(textureImageH);
    }
    //==============================================================================
    // This will be called every time a button (attached to a listener) is "pressed"
    // in the controller part
    // ----> Texture setter
    void setTextureA(){colorizer = TEXTURE_A;}
    void setTextureB(){colorizer = TEXTURE_B;}
    void setTextureC(){colorizer = TEXTURE_C;}
    void setTextureD(){colorizer = TEXTURE_D;}    
    void setTextureE(){colorizer = TEXTURE_E;}
    void setTextureF(){colorizer = TEXTURE_F;}
    void setTextureG(){colorizer = TEXTURE_G;}
    void setTextureH(){colorizer = TEXTURE_H;}
    // ----> Object setter    
    void setObjA(){objizer = OBJ_A;}
    void setObjB(){objizer = OBJ_B;}
    void setObjC(){objizer = OBJ_C;}
    void setObjD(){objizer = OBJ_D;}    
    void setObjE(){objizer = OBJ_E;}
    void setObjF(){objizer = OBJ_F;}
    void setObjG(){objizer = OBJ_G;}
    void setObjH(){objizer = OBJ_H;}    
    void setObjI(){objizer = OBJ_I;}
    // ----> Scale setter
    void setScale(float val){this->BaseScale = val;}
    // ----> Avrage setter (for the low pass effect)
    void setAvr(int val){avrSlider = val;}
    //==============================================================================
    // function used to normalize a value between to point like in a mapping 
    // used to expand the resolution of the audio input
    double normalize(double min ,double max, double val)
    {
        return (max-min)*(val+1)+min;
    }
    //==============================================================================
    void shutdown() override
    {
        //release all the memory before shutdown
        usedShaderProgram = nullptr;
        shape = nullptr;
        attributes = nullptr;
        uniforms = nullptr;
        textureA.release();
        textureB.release();
        textureC.release();
        textureD.release();
        textureE.release();
        textureF.release();
        textureG.release();
        textureH.release();
    }
    //==============================================================================
    // Mouse events
    void mouseDown (const MouseEvent& e) override
    {
        this->draggableOrientation.mouseDown (e.getPosition());
    }
    void mouseDrag (const MouseEvent& e) override
    {
        this->draggableOrientation.mouseDrag (e.getPosition());
    }
    //==============================================================================
    // The ProjectionMatrix is used by the GPU to modify coordinates of each vertex 
    // based on the "frustum" ( = portion of the viewed solid)
    // the frustum is there a truncated horizontal pyramid
    
    Matrix3D<float> getProjectionMatrix() const
    {
        // All coordinate of a loaded object is multuplied by this matrice in order 
        // to know the visible position in a 2D world (projection)
        // 
        // the first 4 memmbers of the matrix defined the view size and 
        // the 2 last ones is for to know the depth of the view
        // 
        // theses values are empirical and depends on what you whant to show and how.
        // 
        // the baseScale value is there to center the oscilations due to music
        
        auto w = 1.0f / (scale + BaseScale + 0.1f);
        float h = w * getLocalBounds().toFloat().getAspectRatio (false);
        return Matrix3D<float>::fromFrustum (-w, w, -h, h, 4.0f, 100.0f);
        
    }

    //==============================================================================
    // RotationMatrix is used to rotate the loaded object
    // this matrix is a 3D vector and use Euler formulas
    // +1D for to get a homogeneous matrix
    
    Matrix3D<float> createRotationMatrix (Vector3D<float> eulerAngleRadians) const noexcept
    {
        const float cx = std::cos (eulerAngleRadians.x),  sx = std::sin (eulerAngleRadians.x),
        cy = std::cos (eulerAngleRadians.y),  sy = std::sin (eulerAngleRadians.y),
        cz = std::cos (eulerAngleRadians.z),  sz = std::sin (eulerAngleRadians.z);
        
        return Matrix3D<float> ((cy * cz) + (sx * sy * sz), cx * sz, (cy * sx * sz) - (cz * sy), 0.0f,
                         (cz * sx * sy) - (cy * sz), cx * cz, (cy * cz * sx) + (sy * sz), 0.0f,
                         cx * sy, -sx, cx * cy, 0.0f,
                         0.0f, 0.0f, 0.0f, 1.0f);
    }
    //==============================================================================
    // This matrix will be used upon each frame in order to modify the coordinates 
    // of each pixels based on the nanimation   
    Matrix3D<float> getViewMatrix() const
    {
        // View matrix is used to modify the vertex coordinate
        // to transform object coordinates as viewed-by-camera (or eye)
        auto viewMatrix = draggableOrientation.getRotationMatrix()
                          * Vector3D<float> (0.0f, 1.0f, -50.0f);

        Matrix3D<float> rotationMatrix
                        = createRotationMatrix (Vector3D<float> (-10.0f, 5.0f 
                          * std::sin (getFrameCounter() * 0.01f), 0.0f));

        return rotationMatrix * viewMatrix;
    }

    //==============================================================================
    // by defaulr "render" is called every times that the GPU is rady to print
    void render() override
    {   
        // Make sure an OpenGL graphics context is defined
        jassert (OpenGLHelpers::isContextActive());

        // This allows to calculate correct pixel number by using
        // physical vs logical pixel number
        const float desktopScale = (float) openGLContext.getRenderingScale();
        
        // Clear the display every new frame 
        OpenGLHelpers::clear (Colour::greyLevel (0.1f));
        
        //set the texture to the render
        if (PRG_USE_TEXTURE) {
            // OpenGL methods to avoid displaying pixels behind front pixels
            glEnable (GL_DEPTH_TEST);   // Enable the test
            glDepthFunc (GL_LESS);      // Do not display back pixels
        
            openGLContext.extensions.glActiveTexture (GL_TEXTURE0); // Using texture #0
            glEnable (GL_TEXTURE_2D);   // It's a 2-D image texture
            // Tell the GPU to use that texture
            if (colorizer == TEXTURE_A)
                textureA.bind();
            if (colorizer == TEXTURE_B)
                textureB.bind();
            if (colorizer == TEXTURE_C)
                textureC.bind();
            if (colorizer == TEXTURE_D)
                textureD.bind();
            if (colorizer == TEXTURE_E)
                textureE.bind();
            if (colorizer == TEXTURE_F)
                textureF.bind();
            if (colorizer == TEXTURE_G)
                textureG.bind();
            if (colorizer == TEXTURE_H)
                textureH.bind();

            // OpenGL method to specify how the image is horizontally tiled
            glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
            // OpenGL method to specify how the image is vertically tiled
            glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        }
        // OpenGL method to blend the computed fragment color values with the values in the color buffers
        glEnable (GL_BLEND);
        // OpenGL method to specify how the red, green, blue, and alpha blending factors are computed.
        glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        // OpenGL method to specify viewport's x, y, width and height
        glViewport (0, 0, roundToInt (desktopScale * getWidth()), roundToInt (desktopScale * getHeight()));
        // This will call an OpenGL method to tell the GPU to use this program
        usedShaderProgram->use();
        
        if (uniforms->demoTexture != nullptr)
            uniforms->demoTexture->set ((GLint) 0);

        // not for texture but just for color (not used in user command)
        if (uniforms->textureType != nullptr) {
            switch (colorizer) {
                case COLOR_SET_BY_CPU:
                    uniforms->textureType->set ((GLfloat) 0.0);
                    break;
                case COLOR_SET_BY_GPU:
                    uniforms->textureType->set ((GLfloat) 1.0);
                    break;
                case TEXTURE_A:
                    uniforms->textureType->set ((GLfloat) 2.0);
                    break;
            }
        }
        // Modify the uniform (global) variable projectionMatrix that will be used by the GPU when executing the shaders
        if (uniforms->projectionMatrix != nullptr)
            // Update the projection matrix with the values given, 1 matrix, do not transpose
            uniforms->projectionMatrix->setMatrix4 (getProjectionMatrix().mat, 1, false);

        // Modify the uniform (global) variable viewMatrix that will be used by the GPU when executing the shaders
        if (uniforms->viewMatrix != nullptr)
            // Update the view matrix with the values given, 1 matrix, do not transpose
            uniforms->viewMatrix->setMatrix4 (getViewMatrix().mat, 1, false);

        // use the appropriate object in function of the user choce
        if (objizer == OBJ_A)
            shape->loadShape(openGLContext, 1);
        if (objizer == OBJ_B) 
            shape->loadShape(openGLContext, 2);
        if (objizer == OBJ_C)
            shape->loadShape(openGLContext, 3);
        if (objizer == OBJ_D) 
            shape->loadShape(openGLContext, 4);
        if (objizer == OBJ_E)
            shape->loadShape(openGLContext, 5);
        if (objizer == OBJ_F) 
            shape->loadShape(openGLContext, 6);
        if (objizer == OBJ_G)
            shape->loadShape(openGLContext, 7);
        if (objizer == OBJ_H) 
            shape->loadShape(openGLContext, 8);
        if (objizer == OBJ_I) 
            shape->loadShape(openGLContext, 9);
        
        // draw the shape
        shape->draw (openGLContext, *attributes);        

        // audio Processing ----------------------------------------------------------
        //get audio samples
        ringBuffer->readSamples (readBuffer, RING_BUFFER_READ_SIZE);
        avrVal = 0;
        
        // do the avrage (low pass effect)
        for (int i = 0;i<avrSlider;i++)
            avrVal = avrVal + (double)*readBuffer.getReadPointer(0, i);
        avrVal = avrVal/avrSlider;

        // set the scale in function of the avrage
        this->scale = normalize(-2,2,avrVal);
        
        // Reset the element buffers so child Components draw correctly
        openGLContext.extensions.glBindBuffer (GL_ARRAY_BUFFER, 0);
        openGLContext.extensions.glBindBuffer (GL_ELEMENT_ARRAY_BUFFER, 0);
    }

    //==============================================================================
    // routine that load the shader and also the object data (shape)
    // It call also call the OpenGL routines to compile and link the shader codes.
    
    // Comments of the shader code:
    // Attributes struct (pass variables to Vertex Shader)
    // Uniforms struct (share variables between the CPU code, V-shader and F-shader)
    // 
    // Notta: glPosition = vector containing the actual final position of the current vertex being drawn.

    // glFragColor used to interpolate colors (stater way)
    // textureType used to defined the coloring to use. 
    // -------------> /!\ use '<' comparisons and not '==' because float value precision syndroms!
    
    void createShaders()
    {
        vertexShader =
            "attribute vec4 position;\n"
            "uniform float audioSampleData[256];\n"
            "attribute vec4 sourceColour;\n"
            "attribute vec2 textureCoordIn;\n"
            "\n"
            "uniform mat4 projectionMatrix;\n"
            "uniform mat4 viewMatrix;\n"
            "\n"
            "varying vec4 destinationColour;\n"
            "varying vec2 textureCoordOut;\n"
            "\n"
            "void main()\n"
            "{\n"
            "    destinationColour = sourceColour;\n"
            "    textureCoordOut = textureCoordIn;\n"
            "    gl_Position = projectionMatrix * viewMatrix * position;\n"
            "}\n";

        fragmentShader =
#if JUCE_OPENGL_ES
            "precision lowp float;\n"
            "varying lowp vec4 destinationColour;\n"
            "varying lowp vec2 textureCoordOut;\n"
#else
            "varying vec4 destinationColour;\n"
            "varying vec2 textureCoordOut;\n"
#endif
            "\n"
            "uniform sampler2D demoTexture;\n"
            "uniform float textureType;\n"
            "\n"
            "void main()\n"
            "{\n"
            "    if (textureType < 0.1)\n"
            "        gl_FragColor = destinationColour;\n"
            "    else if (textureType < 1.1)\n"
            "        gl_FragColor = vec4(" COLOR_BY_GPU_STRING ");\n"
            "    else if (textureType < 2.1)\n"
            "     gl_FragColor = texture2D (demoTexture, textureCoordOut);\n"
            "}\n";

        // An OpenGLShaderProgram is a combination of shaders which are compiled and linked together
        ScopedPointer<OpenGLShaderProgram> newShaderProgram (new OpenGLShaderProgram (openGLContext));

        String statusText;  // Can be used to give a success or failure message after GLSL compilation

        // Create the program that combines Vertex and Fragment shaders
        if (newShaderProgram->addVertexShader (OpenGLHelpers::translateVertexShaderToV3 (vertexShader))
              && newShaderProgram->addFragmentShader (OpenGLHelpers::translateFragmentShaderToV3 (fragmentShader))
              && newShaderProgram->link())
        {
            // Do the following to be in a known state in case problems occur
            shape = nullptr;
            attributes = nullptr;
            uniforms = nullptr;

            // Tell the GPU that this program is the one to be used for next frame
            usedShaderProgram = newShaderProgram;

            // Load the object that will be used to defined vertices and fragments
            shape      = new Shape ();                             // The object itself
            attributes = new Attributes (openGLContext, *usedShaderProgram);    // The object attributes
            uniforms   = new Uniforms (openGLContext, *usedShaderProgram);      // The global data to be shared between
                                                                                // the CPU code and the GPU shaders

            statusText = "GLSL: v" + String (OpenGLShaderProgram::getLanguageVersion(), 2); // Not used in this class
        }
        else
        {
            statusText = newShaderProgram->getLastError();                 // Not used in this class
        }
    }


private:
    //==============================================================================
    struct Vertex
    {
        float position[3];  // To define vertex x,y,z coordinates
        float normal[3];    // Orthogonal vector for the light impact on the texture color
        float colour[4];    // Color used for the vertex.
        float texCoord[2];  // A graphic image (file) can be used to define the texture of the drawn object.
                            // This 2-D vector gives the coordinates in the 2-D image file corresponding to
                            // the pixel color to be drawn
    };

    //==============================================================================
    // This class just manages the attributes that the shaders use.
    // attribute is a special variable type modifier which allows to pass information
    // from the CPU code to the shaders.
    struct Attributes
    {
        Attributes (OpenGLContext& openGLContext, OpenGLShaderProgram& shaderProgram)
        {
            position      = createAttribute (openGLContext, shaderProgram, "position");
            normal        = createAttribute (openGLContext, shaderProgram, "normal");
            sourceColour  = createAttribute (openGLContext, shaderProgram, "sourceColour");
            textureCoordIn = createAttribute (openGLContext, shaderProgram, "textureCoordIn");
        }

        // This method calls openGL functions to tell the GPU that some attributes will be used
        void enable (OpenGLContext& openGLContext)
        {
            if (position != nullptr)
            {
                // Tell the GPU that the first attribute will be the position attribute
                openGLContext.extensions.glVertexAttribPointer (position->attributeID, 3, GL_FLOAT, GL_FALSE, sizeof (Vertex), 0);
                openGLContext.extensions.glEnableVertexAttribArray (position->attributeID);
            }

            if (normal != nullptr)
            {
                // Tell the GPU that the next attribute will be the normal attribute
                openGLContext.extensions.glVertexAttribPointer (normal->attributeID, 3, GL_FLOAT, GL_FALSE, sizeof (Vertex), (GLvoid*) (sizeof (float) * 3));
                openGLContext.extensions.glEnableVertexAttribArray (normal->attributeID);
            }

            if (sourceColour != nullptr)
            {
                // Tell the GPU that the next attribute will be the color attribute
                openGLContext.extensions.glVertexAttribPointer (sourceColour->attributeID, 4, GL_FLOAT, GL_FALSE, sizeof (Vertex), (GLvoid*) (sizeof (float) * 6));
                openGLContext.extensions.glEnableVertexAttribArray (sourceColour->attributeID);
            }

            if (textureCoordIn != nullptr)
            {
                // Tell the GPU that the next attribute will be the texture coordinate attribute
                openGLContext.extensions.glVertexAttribPointer (textureCoordIn->attributeID, 2, GL_FLOAT, GL_FALSE, sizeof (Vertex), (GLvoid*) (sizeof (float) * 10));
                openGLContext.extensions.glEnableVertexAttribArray (textureCoordIn->attributeID);
            }
        }

        // GPU release the resources previously used in attributes
        void disable (OpenGLContext& openGLContext)
        {
            if (position != nullptr)       openGLContext.extensions.glDisableVertexAttribArray (position->attributeID);
            if (normal != nullptr)         openGLContext.extensions.glDisableVertexAttribArray (normal->attributeID);
            if (sourceColour != nullptr)   openGLContext.extensions.glDisableVertexAttribArray (sourceColour->attributeID);
            if (textureCoordIn != nullptr)  openGLContext.extensions.glDisableVertexAttribArray (textureCoordIn->attributeID);
        }

        ScopedPointer<OpenGLShaderProgram::Attribute> position, normal, sourceColour, textureCoordIn;

    private:
        // Allow to link a variable in the CPU code to one in the GPU (GLSL) shader.
        static OpenGLShaderProgram::Attribute* createAttribute (OpenGLContext& openGLContext,
                                                                OpenGLShaderProgram& shaderProgram,
                                                                const char* attributeName)
        {
            // Get the ID
            if (openGLContext.extensions.glGetAttribLocation (shaderProgram.getProgramID(), attributeName) < 0)
                return nullptr; // Return if error
            // Create the atttribute variable
            return new OpenGLShaderProgram::Attribute (shaderProgram, attributeName);
        }
    };

    //==============================================================================
    // This class just manages the uniform val for the shaders use.
    // "uniform" is a special variable type modifier in the shaders which allows to pass global
    // variables between the CPU code and the shaders.
    struct Uniforms
    {
        Uniforms (OpenGLContext& openGLContext, OpenGLShaderProgram& shaderProgram)
        {
            // Here we define 2 global variables (matrices)
            projectionMatrix = createUniform (openGLContext, shaderProgram, "projectionMatrix");
            viewMatrix       = createUniform (openGLContext, shaderProgram, "viewMatrix");
            demoTexture      = createUniform (openGLContext, shaderProgram, "demoTexture");
            textureType      = createUniform (openGLContext, shaderProgram, "textureType");
            
            audioSampleData     = createUniform (openGLContext, shaderProgram, "audioSampleData");
        }

        ScopedPointer<OpenGLShaderProgram::Uniform> projectionMatrix, viewMatrix, demoTexture, textureType, audioSampleData;

    private:
        // Allow to link a variable in the CPU code to one in the GPU (GLSL) shaders.
        // Note that the variable can be a scalar, a vector, a matrix, etc.
        static OpenGLShaderProgram::Uniform* createUniform (OpenGLContext& openGLContext,
                                                            OpenGLShaderProgram& shaderProgram,
                                                            const char* uniformName)
        {
            // Get the ID
            if (openGLContext.extensions.glGetUniformLocation (shaderProgram.getProgramID(), uniformName) < 0)
                return nullptr; // Return if error
            // Create the uniform variable
            return new OpenGLShaderProgram::Uniform (shaderProgram, uniformName);
        }
    };

    //==============================================================================
    // This loads a 3D model from an OBJ file and converts it into some vertex buffers
    // that we can draw.
    // (see WaveFrontObjParser.h)
    
    struct Shape
    {
        Shape ()
        {
        }

        void loadShape(OpenGLContext& openGLContext,int numOfShape)
        {
            // clear the vertex buffer (multiple obj)
            vertexBuffers.clear();
            // set the correct obj in function of the user choice
            if (numOfShape==1)
                if (shapeFile.load (BinaryData::Cat_obj).wasOk())
                    for (int i = 0; i < shapeFile.shapes.size(); ++i)
                        vertexBuffers.add (new VertexBuffer (openGLContext, *shapeFile.shapes.getUnchecked(i)));

            if (numOfShape==2)
                if (shapeFile.load (BinaryData::Cow_obj).wasOk())
                    for (int i = 0; i < shapeFile.shapes.size(); ++i)
                        vertexBuffers.add (new VertexBuffer (openGLContext, *shapeFile.shapes.getUnchecked(i)));
                        
            if (numOfShape==3)
                if (shapeFile.load (BinaryData::Goat_obj).wasOk())
                    for (int i = 0; i < shapeFile.shapes.size(); ++i)
                        vertexBuffers.add (new VertexBuffer (openGLContext, *shapeFile.shapes.getUnchecked(i)));
                        
            if (numOfShape==4)
                if (shapeFile.load (BinaryData::Deer_obj).wasOk())
                    for (int i = 0; i < shapeFile.shapes.size(); ++i)
                        vertexBuffers.add (new VertexBuffer (openGLContext, *shapeFile.shapes.getUnchecked(i)));
                        
            if (numOfShape==5)
                if (shapeFile.load (BinaryData::Wolf_obj).wasOk())
                    for (int i = 0; i < shapeFile.shapes.size(); ++i)
                        vertexBuffers.add (new VertexBuffer (openGLContext, *shapeFile.shapes.getUnchecked(i)));
                        
            if (numOfShape==6)
                if (shapeFile.load (BinaryData::Tiger_obj).wasOk())
                    for (int i = 0; i < shapeFile.shapes.size(); ++i)
                        vertexBuffers.add (new VertexBuffer (openGLContext, *shapeFile.shapes.getUnchecked(i)));
                        
            if (numOfShape==7)
                if (shapeFile.load (BinaryData::Rat_obj).wasOk())
                    for (int i = 0; i < shapeFile.shapes.size(); ++i)
                        vertexBuffers.add (new VertexBuffer (openGLContext, *shapeFile.shapes.getUnchecked(i)));
                        
            if (numOfShape==8)
                if (shapeFile.load (BinaryData::Face_obj).wasOk())
                    for (int i = 0; i < shapeFile.shapes.size(); ++i)
                        vertexBuffers.add (new VertexBuffer (openGLContext, *shapeFile.shapes.getUnchecked(i)));
                        
            if (numOfShape==9)
                if (shapeFile.load (BinaryData::Human_obj).wasOk())
                    for (int i = 0; i < shapeFile.shapes.size(); ++i)
                        vertexBuffers.add (new VertexBuffer (openGLContext, *shapeFile.shapes.getUnchecked(i)));
        }
        // Send the buffer to the GPU to execute the vertex shader
        void draw (OpenGLContext& openGLContext, Attributes& glAttributes)
        {
            // Only one buffer used in this example (vertexBuffers.size() = 1)
            for (int i = 0; i < vertexBuffers.size(); ++i)
            {
                VertexBuffer& vertexBuffer = *vertexBuffers.getUnchecked (i);
                // Tell the GPU this is the buffer to be used
                vertexBuffer.bind();

                // Use the attributes that we have defined for each vertex
                glAttributes.enable (openGLContext);
                // Draw triangles (atomic graphic structure for OpenGL)
                // using the vertices stored in the vertexBuffer
                glDrawElements (GL_TRIANGLES, vertexBuffer.numIndices, GL_UNSIGNED_INT, 0);
                glAttributes.disable (openGLContext);   // Done
            }
        }
        
    private:
        struct VertexBuffer
        {
            VertexBuffer (OpenGLContext& context, WavefrontObjFile::Shape& aShape) : openGLContext (context)
            {
                // Indices are used to be more efficient. They allow for instance to define less vertices
                // when they are used more than once. For instance to draw a square using triangles (the
                // most basic shape used by GPUs)
                numIndices = aShape.mesh.indices.size();
                
                // These will call OpenGL routines to create a vertex buffer (VBO)
                openGLContext.extensions.glGenBuffers (1, &vertexBuffer);
                openGLContext.extensions.glBindBuffer (GL_ARRAY_BUFFER, vertexBuffer);

                Array<Vertex> vertices;
                
                // Fill in the vertex buffer with the vertex info data Stored in the OBJ file
                createVertexListFromMesh (aShape.mesh, vertices, COLOR_BY_CPU);
                openGLContext.extensions.glBufferData (GL_ARRAY_BUFFER,
                                                       static_cast<GLsizeiptr> (static_cast<size_t> (vertices.size()) * sizeof (Vertex)),
                                                       vertices.getRawDataPointer(), GL_STATIC_DRAW);

                // These will call OpenGL routines to create a buffer and store the indices in it
                openGLContext.extensions.glGenBuffers (1, &indexBuffer);
                openGLContext.extensions.glBindBuffer (GL_ELEMENT_ARRAY_BUFFER, indexBuffer);
                openGLContext.extensions.glBufferData (GL_ELEMENT_ARRAY_BUFFER,
                                                       static_cast<GLsizeiptr> (static_cast<size_t> (numIndices) * sizeof (juce::uint32)),
                                                       aShape.mesh.indices.getRawDataPointer(), GL_STATIC_DRAW);
            }

            ~VertexBuffer()
            {
                openGLContext.extensions.glDeleteBuffers (1, &vertexBuffer);
                openGLContext.extensions.glDeleteBuffers (1, &indexBuffer);
            }
            void bind()
            {
                // Tell the GPU to use the specified vertex and index buffers for next frame
                openGLContext.extensions.glBindBuffer (GL_ARRAY_BUFFER, vertexBuffer);
                openGLContext.extensions.glBindBuffer (GL_ELEMENT_ARRAY_BUFFER, indexBuffer);
            }
            
            GLuint vertexBuffer, indexBuffer;
            int numIndices;
            OpenGLContext& openGLContext;

            JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (VertexBuffer)
        };

        WavefrontObjFile shapeFile;
        OwnedArray<VertexBuffer> vertexBuffers;

        // This will fill in the vertex buffer with the vertex info data that was stored in the OBJ file.
        static void createVertexListFromMesh (const WavefrontObjFile::Mesh& mesh, Array<Vertex>& list, Colour colour)
        {
            // Should be overwritten by the OBJ file data
            WavefrontObjFile::TextureCoord defaultTexCoord = { 0.5f, 0.5f };
            WavefrontObjFile::Vertex defaultNormal = { 0.5f, 0.5f, 0.5f };

            // Read each vertex data information and save it as a vertex in the vertex buffer
            for (int i = 0; i < mesh.vertices.size(); ++i)
            {
                const WavefrontObjFile::Vertex& v = mesh.vertices.getReference (i);

                const WavefrontObjFile::Vertex& n
                        = i < mesh.normals.size() ? mesh.normals.getReference (i) : defaultNormal;

                const WavefrontObjFile::TextureCoord& tc
                        = i < mesh.textureCoords.size() ? mesh.textureCoords.getReference (i) : defaultTexCoord;
                // Create the vertex attributes: position, normal vector, color, texture coordinate for that point
                Vertex vert =
                {
                    { v.x,  v.y, v.z },
                    {  n.x,  n.y, n.z },
                    { colour.getFloatRed(), colour.getFloatGreen(), colour.getFloatBlue(), colour.getFloatAlpha() },
                    { tc.x, tc.y }
                };
                // Add this vertex info to the vertex list
                list.add (vert);
            }
        }
    };
    
    // Shader Source Code
    const char* vertexShader;   // Source code for the vertx shader
    const char* fragmentShader; // Source code for the fragment shader

    //declarations of used classes
    ScopedPointer<OpenGLShaderProgram> usedShaderProgram;   // Set of vertex + fragment shaders
    ScopedPointer<Shape> shape;                     // Object providing the parameters of each vertex
    ScopedPointer<Attributes> attributes;           // Variables sent to the vertex shader
    ScopedPointer<Uniforms> uniforms;               // Variables sent to both the vertex and fragment shaders
    
    // Texture 
    OpenGLTexture texture;      // texture object filled with graphic file data that will be sent to the GPU
    OpenGLTexture textureA;     
    OpenGLTexture textureB;     
    OpenGLTexture textureC;     
    OpenGLTexture textureD;     
    OpenGLTexture textureE;     
    OpenGLTexture textureF;     
    OpenGLTexture textureG;     
    OpenGLTexture textureH;     

    // used to set the oj dragabble by the mouse
    Draggable3DOrientation draggableOrientation;
      
    //Scale of the object
    double BaseScale = 0.5f;
    double scale = 0;
    
    // Non-OpenGL stuff : enum used in the setter 
    enum {COLOR_SET_BY_CPU,COLOR_SET_BY_GPU,TEXTURE_A,TEXTURE_B,TEXTURE_C,TEXTURE_D,TEXTURE_E,TEXTURE_F,TEXTURE_G,TEXTURE_H} colorizer;
    enum {OBJ_A,OBJ_B,OBJ_C,OBJ_D,OBJ_E,OBJ_F,OBJ_G,OBJ_H,OBJ_I} objizer;
    
    //Audio Vals
    RingBuffer<GLfloat> * ringBuffer;
    AudioBuffer<GLfloat> readBuffer;    // Stores data read from ring buffer
    GLfloat visualizationBuffer [RING_BUFFER_READ_SIZE];    // Single channel to visualize
    
    //low pass avr mode variables
    int avrSlider = 1;
    double avrVal = 0;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ObjRotation)
};


#endif  // MAINCOMPONENT_H_INCLUDED
