/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 5.3.2

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library.
  Copyright (c) 2017 - ROLI Ltd.

  ==============================================================================
*/

#pragma once

//[Headers]     -- You can add your own extra header files here --
#include "../JuceLibraryCode/JuceHeader.h"
#include "ViewWindow.h"
#include "TextureTextButton.cpp"
//texture Load
#define TEXTURE_DATA_A BinaryData::A_jpg,BinaryData::A_jpgSize
#define TEXTURE_DATA_B BinaryData::B_jpg,BinaryData::B_jpgSize
#define TEXTURE_DATA_C BinaryData::C_jpg,BinaryData::C_jpgSize
#define TEXTURE_DATA_D BinaryData::D_jpg,BinaryData::D_jpgSize
#define TEXTURE_DATA_E BinaryData::E_jpg,BinaryData::E_jpgSize
#define TEXTURE_DATA_F BinaryData::F_jpg,BinaryData::F_jpgSize
#define TEXTURE_DATA_G BinaryData::G_jpg,BinaryData::G_jpgSize
#define TEXTURE_DATA_H BinaryData::H_jpg,BinaryData::H_jpgSize
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class Controller  : public Component,
                    public Button::Listener,
                    public Slider::Listener
{
public:
    //==============================================================================
    Controller ();
    ~Controller();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    enum Windows
    {
        dialog,
        document,
        alert,
        numWindows
    };
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void buttonClicked (Button* buttonThatWasClicked) override;
    void sliderValueChanged (Slider* sliderThatWasMoved) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    Array<Component::SafePointer<ViewWindow>> windows;

    Image imgA = ImageCache::getFromMemory (BinaryData::A_jpg, BinaryData::A_jpgSize);
    Image imgB = ImageCache::getFromMemory (BinaryData::B_jpg, BinaryData::B_jpgSize);
    Image imgC = ImageCache::getFromMemory (BinaryData::C_jpg, BinaryData::C_jpgSize);
    Image imgD = ImageCache::getFromMemory (BinaryData::D_jpg, BinaryData::D_jpgSize);
    Image imgE = ImageCache::getFromMemory (BinaryData::E_jpg, BinaryData::E_jpgSize);
    Image imgF = ImageCache::getFromMemory (BinaryData::F_jpg, BinaryData::F_jpgSize);
    Image imgG = ImageCache::getFromMemory (BinaryData::G_jpg, BinaryData::G_jpgSize);
    Image imgH = ImageCache::getFromMemory (BinaryData::H_jpg, BinaryData::H_jpgSize);

    TextureTextButton textureButtonA{" ",40,  336, 56, 56,imgA};
    TextureTextButton textureButtonB{" ",104, 336, 56, 56,imgB};
    TextureTextButton textureButtonC{" ",168, 336, 56, 56,imgC};
    TextureTextButton textureButtonD{" ",232, 336, 56, 56,imgD};
    TextureTextButton textureButtonE{" ",40,  400, 56, 56,imgE};
    TextureTextButton textureButtonF{" ",104, 400, 56, 56,imgF};
    TextureTextButton textureButtonG{" ",168, 400, 56, 56,imgG};
    TextureTextButton textureButtonH{" ",232, 400, 56, 56,imgH};
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<TextButton> OscilloscopeButton;
    std::unique_ptr<TextButton> ObjButton;
    std::unique_ptr<TextButton> StartButton;
    std::unique_ptr<TextButton> Obj1;
    std::unique_ptr<TextButton> Obj3;
    std::unique_ptr<TextButton> Obj2;
    std::unique_ptr<TextButton> Obj4;
    std::unique_ptr<TextButton> Obj6;
    std::unique_ptr<TextButton> Obj5;
    std::unique_ptr<TextButton> Obj7;
    std::unique_ptr<TextButton> Obj9;
    std::unique_ptr<TextButton> Obj8;
    std::unique_ptr<Slider> sizeSlider;
    std::unique_ptr<Slider> avrSlider;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Controller)
};

//[EndFile] You can add extra defines here...
//[/EndFile]
