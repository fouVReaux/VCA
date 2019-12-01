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

//[Headers] You can add your own extra header files here...
#include "ViewWindow.h"
//[/Headers]

#include "Controller.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
Controller::Controller ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    addAndMakeVisible(textureButtonA);  // Draw this as part of the main object
    textureButtonA.addListener(this);   // To call buttonClicked when pressed

    addAndMakeVisible(textureButtonB);  // Draw this as part of the main object
    textureButtonB.addListener(this);   // To call buttonClicked when pressed

    addAndMakeVisible(textureButtonC);  // Draw this as part of the main object
    textureButtonC.addListener(this);   // To call buttonClicked when pressed

    addAndMakeVisible(textureButtonD);  // Draw this as part of the main object
    textureButtonD.addListener(this);   // To call buttonClicked when pressed

    addAndMakeVisible(textureButtonE);  // Draw this as part of the main object
    textureButtonE.addListener(this);   // To call buttonClicked when pressed

    addAndMakeVisible(textureButtonF);  // Draw this as part of the main object
    textureButtonF.addListener(this);   // To call buttonClicked when pressed

    addAndMakeVisible(textureButtonG);  // Draw this as part of the main object
    textureButtonG.addListener(this);   // To call buttonClicked when pressed

    addAndMakeVisible(textureButtonH);  // Draw this as part of the main object
    textureButtonH.addListener(this);   // To call buttonClicked when pressed
    //[/Constructor_pre]

    OscilloscopeButton.reset (new TextButton ("Oscilloscope"));
    addAndMakeVisible (OscilloscopeButton.get());
    OscilloscopeButton->addListener (this);

    OscilloscopeButton->setBounds (24, 88, 280, 24);

    ObjButton.reset (new TextButton ("Object"));
    addAndMakeVisible (ObjButton.get());
    ObjButton->addListener (this);

    ObjButton->setBounds (24, 120, 280, 24);

    StartButton.reset (new TextButton ("Start"));
    addAndMakeVisible (StartButton.get());
    StartButton->addListener (this);
    StartButton->setColour (TextButton::buttonColourId, Colour (0xff5ca477));

    StartButton->setBounds (24, 32, 280, 24);

    Obj1.reset (new TextButton ("Obj1"));
    addAndMakeVisible (Obj1.get());
    Obj1->setButtonText (TRANS("Cat"));
    Obj1->addListener (this);
    Obj1->setColour (TextButton::buttonColourId, Colour (0xff5c65a4));

    Obj1->setBounds (24, 240, 88, 24);

    Obj3.reset (new TextButton ("Obj3"));
    addAndMakeVisible (Obj3.get());
    Obj3->setButtonText (TRANS("Goat"));
    Obj3->addListener (this);
    Obj3->setColour (TextButton::buttonColourId, Colour (0xff5c65a4));

    Obj3->setBounds (216, 240, 88, 24);

    Obj2.reset (new TextButton ("Obj2"));
    addAndMakeVisible (Obj2.get());
    Obj2->setButtonText (TRANS("Cow"));
    Obj2->addListener (this);
    Obj2->setColour (TextButton::buttonColourId, Colour (0xff5c65a4));

    Obj2->setBounds (120, 240, 88, 24);

    Obj4.reset (new TextButton ("Obj4"));
    addAndMakeVisible (Obj4.get());
    Obj4->setButtonText (TRANS("Deer"));
    Obj4->addListener (this);
    Obj4->setColour (TextButton::buttonColourId, Colour (0xff5c65a4));

    Obj4->setBounds (24, 272, 88, 24);

    Obj6.reset (new TextButton ("Obj6"));
    addAndMakeVisible (Obj6.get());
    Obj6->setButtonText (TRANS("Tiger"));
    Obj6->addListener (this);
    Obj6->setColour (TextButton::buttonColourId, Colour (0xff5c65a4));

    Obj6->setBounds (216, 272, 88, 24);

    Obj5.reset (new TextButton ("Obj5"));
    addAndMakeVisible (Obj5.get());
    Obj5->setButtonText (TRANS("Wolf"));
    Obj5->addListener (this);
    Obj5->setColour (TextButton::buttonColourId, Colour (0xff5c65a4));

    Obj5->setBounds (120, 272, 88, 24);

    Obj7.reset (new TextButton ("Obj7"));
    addAndMakeVisible (Obj7.get());
    Obj7->setButtonText (TRANS("Rat"));
    Obj7->addListener (this);
    Obj7->setColour (TextButton::buttonColourId, Colour (0xff5c65a4));

    Obj7->setBounds (24, 304, 88, 24);

    Obj9.reset (new TextButton ("Obj9"));
    addAndMakeVisible (Obj9.get());
    Obj9->setButtonText (TRANS("Human"));
    Obj9->addListener (this);
    Obj9->setColour (TextButton::buttonColourId, Colour (0xff5c65a4));

    Obj9->setBounds (216, 304, 88, 24);

    Obj8.reset (new TextButton ("Obj8"));
    addAndMakeVisible (Obj8.get());
    Obj8->setButtonText (TRANS("Face"));
    Obj8->addListener (this);
    Obj8->setColour (TextButton::buttonColourId, Colour (0xff5c65a4));

    Obj8->setBounds (120, 304, 88, 24);

    sizeSlider.reset (new Slider ("sizeSlider"));
    addAndMakeVisible (sizeSlider.get());
    sizeSlider->setRange (-3, 10, 0.0001);
    sizeSlider->setSliderStyle (Slider::LinearHorizontal);
    sizeSlider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    sizeSlider->addListener (this);

    sizeSlider->setBounds (96, 168, 216, 24);

    avrSlider.reset (new Slider ("avrSlider"));
    addAndMakeVisible (avrSlider.get());
    avrSlider->setRange (1, 256, 1);
    avrSlider->setSliderStyle (Slider::LinearHorizontal);
    avrSlider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    avrSlider->addListener (this);

    avrSlider->setBounds (104, 200, 208, 24);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (327, 480);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

Controller::~Controller()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    OscilloscopeButton = nullptr;
    ObjButton = nullptr;
    StartButton = nullptr;
    Obj1 = nullptr;
    Obj3 = nullptr;
    Obj2 = nullptr;
    Obj4 = nullptr;
    Obj6 = nullptr;
    Obj5 = nullptr;
    Obj7 = nullptr;
    Obj9 = nullptr;
    Obj8 = nullptr;
    sizeSlider = nullptr;
    avrSlider = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    for (auto& window : windows)
        window.deleteAndZero();

    windows.clear();
    //[/Destructor]
}

//==============================================================================
void Controller::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff323e44));

    {
        int x = 92, y = 4, width = 140, height = 24;
        String text (TRANS("VCA - Controls"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font (15.0f, Font::plain));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 92, y = 60, width = 140, height = 24;
        String text (TRANS("Effects"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font (15.0f, Font::plain));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 16, y = 233, width = 296, height = 231;
        Colour fillColour = Colour (0xff323560);
        Colour strokeColour = Colour (0xff58a52a);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRect (x, y, width, height);
        g.setColour (strokeColour);
        g.drawRect (x, y, width, height, 5);

    }

    {
        int x = 20, y = 196, width = 84, height = 30;
        String text (TRANS("Low Pass"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font (15.0f, Font::plain));
        g.drawText (text, x, y, width, height,
                    Justification::centredLeft, true);
    }

    {
        int x = 20, y = 164, width = 52, height = 30;
        String text (TRANS("Zoom"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font (15.0f, Font::plain));
        g.drawText (text, x, y, width, height,
                    Justification::centredLeft, true);
    }

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void Controller::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    textureButtonA.setBounds(textureButtonA.xPos, textureButtonA.yPos, textureButtonA.width, textureButtonA.height); // TextureTextButtonA: use button-defined boundaries
    textureButtonB.setBounds(textureButtonB.xPos, textureButtonB.yPos, textureButtonB.width, textureButtonB.height); // TextureTextButtonB: use button-defined boundaries
    textureButtonC.setBounds(textureButtonC.xPos, textureButtonC.yPos, textureButtonC.width, textureButtonC.height); // TextureTextButtonB: use button-defined boundaries
    textureButtonD.setBounds(textureButtonD.xPos, textureButtonD.yPos, textureButtonD.width, textureButtonD.height); // TextureTextButtonB: use button-defined boundaries
    textureButtonE.setBounds(textureButtonE.xPos, textureButtonE.yPos, textureButtonE.width, textureButtonE.height); // TextureTextButtonA: use button-defined boundaries
    textureButtonF.setBounds(textureButtonF.xPos, textureButtonF.yPos, textureButtonF.width, textureButtonF.height); // TextureTextButtonB: use button-defined boundaries
    textureButtonG.setBounds(textureButtonG.xPos, textureButtonG.yPos, textureButtonG.width, textureButtonG.height); // TextureTextButtonB: use button-defined boundaries
    textureButtonH.setBounds(textureButtonH.xPos, textureButtonH.yPos, textureButtonH.width, textureButtonH.height); // TextureTextButtonB: use button-defined boundaries
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void Controller::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    if (buttonThatWasClicked == &textureButtonA)
    {
        bool buttonToggleState = !buttonThatWasClicked->getToggleState();
        buttonThatWasClicked->setToggleState (buttonToggleState, NotificationType::dontSendNotification);

        if (windows[0]!=nullptr){windows[0]->mainComponent.setTextureObjRotation(1);}
    }
    if (buttonThatWasClicked == &textureButtonB)
    {
        bool buttonToggleState = !buttonThatWasClicked->getToggleState();
        buttonThatWasClicked->setToggleState (buttonToggleState, NotificationType::dontSendNotification);

        if (windows[0]!=nullptr){windows[0]->mainComponent.setTextureObjRotation(2);}
    }
    if (buttonThatWasClicked == &textureButtonC)
    {
        bool buttonToggleState = !buttonThatWasClicked->getToggleState();
        buttonThatWasClicked->setToggleState (buttonToggleState, NotificationType::dontSendNotification);

        if (windows[0]!=nullptr){windows[0]->mainComponent.setTextureObjRotation(3);}
    }
    if (buttonThatWasClicked == &textureButtonD)
    {
        bool buttonToggleState = !buttonThatWasClicked->getToggleState();
        buttonThatWasClicked->setToggleState (buttonToggleState, NotificationType::dontSendNotification);

        if (windows[0]!=nullptr){windows[0]->mainComponent.setTextureObjRotation(4);}
    }
    if (buttonThatWasClicked == &textureButtonE)
    {
        bool buttonToggleState = !buttonThatWasClicked->getToggleState();
        buttonThatWasClicked->setToggleState (buttonToggleState, NotificationType::dontSendNotification);

        if (windows[0]!=nullptr){windows[0]->mainComponent.setTextureObjRotation(5);}
    }
    if (buttonThatWasClicked == &textureButtonF)
    {
        bool buttonToggleState = !buttonThatWasClicked->getToggleState();
        buttonThatWasClicked->setToggleState (buttonToggleState, NotificationType::dontSendNotification);

        if (windows[0]!=nullptr){windows[0]->mainComponent.setTextureObjRotation(6);}
    }
    if (buttonThatWasClicked == &textureButtonG)
    {
        bool buttonToggleState = !buttonThatWasClicked->getToggleState();
        buttonThatWasClicked->setToggleState (buttonToggleState, NotificationType::dontSendNotification);

        if (windows[0]!=nullptr){windows[0]->mainComponent.setTextureObjRotation(7);}
    }
    if (buttonThatWasClicked == &textureButtonH)
    {
        bool buttonToggleState = !buttonThatWasClicked->getToggleState();
        buttonThatWasClicked->setToggleState (buttonToggleState, NotificationType::dontSendNotification);

        if (windows[0]!=nullptr){windows[0]->mainComponent.setTextureObjRotation(8);}
    }
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == OscilloscopeButton.get())
    {
        //[UserButtonCode_OscilloscopeButton] -- add your button handler code here..
        bool buttonToggleState = !buttonThatWasClicked->getToggleState();
        buttonThatWasClicked->setToggleState (buttonToggleState, NotificationType::dontSendNotification);

        if (windows[0]!=nullptr){
            windows[0]->mainComponent.setVisibleOscilloscope2D(true);//<----- ON
            windows[0]->mainComponent.setVisibleObjRotation(false);
        }

        //[/UserButtonCode_OscilloscopeButton]
    }
    else if (buttonThatWasClicked == ObjButton.get())
    {
        //[UserButtonCode_ObjButton] -- add your button handler code here..
        bool buttonToggleState = !buttonThatWasClicked->getToggleState();
        buttonThatWasClicked->setToggleState (buttonToggleState, NotificationType::dontSendNotification);

        if (windows[0]!=nullptr){
            windows[0]->mainComponent.setVisibleOscilloscope2D(false);
            windows[0]->mainComponent.setVisibleObjRotation(true);//<----- ON
        }
        //[/UserButtonCode_ObjButton]
    }
    else if (buttonThatWasClicked == StartButton.get())
    {
        //[UserButtonCode_StartButton] -- add your button handler code here..
        auto* dw = new ViewWindow ("VCA - View");
        windows.add (dw);
        buttonThatWasClicked->setColour (TextButton::buttonColourId, Colour (0xFF865CA4));
        //[/UserButtonCode_StartButton]
    }
    else if (buttonThatWasClicked == Obj1.get())
    {
        //[UserButtonCode_Obj1] -- add your button handler code here..
        bool buttonToggleState = !buttonThatWasClicked->getToggleState();
        buttonThatWasClicked->setToggleState (buttonToggleState, NotificationType::dontSendNotification);

        if (windows[0]!=nullptr){windows[0]->mainComponent.setObjObjRotation(1);}
        Obj8->setToggleState (false, NotificationType::dontSendNotification);
        Obj2->setToggleState (false, NotificationType::dontSendNotification);
        Obj3->setToggleState (false, NotificationType::dontSendNotification);
        Obj4->setToggleState (false, NotificationType::dontSendNotification);
        Obj5->setToggleState (false, NotificationType::dontSendNotification);
        Obj6->setToggleState (false, NotificationType::dontSendNotification);
        Obj7->setToggleState (false, NotificationType::dontSendNotification);
        Obj9->setToggleState (false, NotificationType::dontSendNotification);
        //[/UserButtonCode_Obj1]
    }
    else if (buttonThatWasClicked == Obj3.get())
    {
        //[UserButtonCode_Obj3] -- add your button handler code here..
        bool buttonToggleState = !buttonThatWasClicked->getToggleState();
        buttonThatWasClicked->setToggleState (buttonToggleState, NotificationType::dontSendNotification);

        if (windows[0]!=nullptr){windows[0]->mainComponent.setObjObjRotation(3);}
        Obj1->setToggleState (false, NotificationType::dontSendNotification);
        Obj2->setToggleState (false, NotificationType::dontSendNotification);
        Obj8->setToggleState (false, NotificationType::dontSendNotification);
        Obj4->setToggleState (false, NotificationType::dontSendNotification);
        Obj5->setToggleState (false, NotificationType::dontSendNotification);
        Obj6->setToggleState (false, NotificationType::dontSendNotification);
        Obj7->setToggleState (false, NotificationType::dontSendNotification);
        Obj9->setToggleState (false, NotificationType::dontSendNotification);
        //[/UserButtonCode_Obj3]
    }
    else if (buttonThatWasClicked == Obj2.get())
    {
        //[UserButtonCode_Obj2] -- add your button handler code here..
        bool buttonToggleState = !buttonThatWasClicked->getToggleState();
        buttonThatWasClicked->setToggleState (buttonToggleState, NotificationType::dontSendNotification);

        if (windows[0]!=nullptr){windows[0]->mainComponent.setObjObjRotation(2);}
        Obj1->setToggleState (false, NotificationType::dontSendNotification);
        Obj8->setToggleState (false, NotificationType::dontSendNotification);
        Obj3->setToggleState (false, NotificationType::dontSendNotification);
        Obj4->setToggleState (false, NotificationType::dontSendNotification);
        Obj5->setToggleState (false, NotificationType::dontSendNotification);
        Obj6->setToggleState (false, NotificationType::dontSendNotification);
        Obj7->setToggleState (false, NotificationType::dontSendNotification);
        Obj9->setToggleState (false, NotificationType::dontSendNotification);
        //[/UserButtonCode_Obj2]
    }
    else if (buttonThatWasClicked == Obj4.get())
    {
        //[UserButtonCode_Obj4] -- add your button handler code here..
        bool buttonToggleState = !buttonThatWasClicked->getToggleState();
        buttonThatWasClicked->setToggleState (buttonToggleState, NotificationType::dontSendNotification);

        if (windows[0]!=nullptr){windows[0]->mainComponent.setObjObjRotation(4);}
        Obj1->setToggleState (false, NotificationType::dontSendNotification);
        Obj2->setToggleState (false, NotificationType::dontSendNotification);
        Obj3->setToggleState (false, NotificationType::dontSendNotification);
        Obj8->setToggleState (false, NotificationType::dontSendNotification);
        Obj5->setToggleState (false, NotificationType::dontSendNotification);
        Obj6->setToggleState (false, NotificationType::dontSendNotification);
        Obj7->setToggleState (false, NotificationType::dontSendNotification);
        Obj9->setToggleState (false, NotificationType::dontSendNotification);
        //[/UserButtonCode_Obj4]
    }
    else if (buttonThatWasClicked == Obj6.get())
    {
        //[UserButtonCode_Obj6] -- add your button handler code here..
        bool buttonToggleState = !buttonThatWasClicked->getToggleState();
        buttonThatWasClicked->setToggleState (buttonToggleState, NotificationType::dontSendNotification);

        if (windows[0]!=nullptr){windows[0]->mainComponent.setObjObjRotation(6);}
        Obj1->setToggleState (false, NotificationType::dontSendNotification);
        Obj2->setToggleState (false, NotificationType::dontSendNotification);
        Obj3->setToggleState (false, NotificationType::dontSendNotification);
        Obj4->setToggleState (false, NotificationType::dontSendNotification);
        Obj5->setToggleState (false, NotificationType::dontSendNotification);
        Obj8->setToggleState (false, NotificationType::dontSendNotification);
        Obj7->setToggleState (false, NotificationType::dontSendNotification);
        Obj9->setToggleState (false, NotificationType::dontSendNotification);
        //[/UserButtonCode_Obj6]
    }
    else if (buttonThatWasClicked == Obj5.get())
    {
        //[UserButtonCode_Obj5] -- add your button handler code here..
        bool buttonToggleState = !buttonThatWasClicked->getToggleState();
        buttonThatWasClicked->setToggleState (buttonToggleState, NotificationType::dontSendNotification);

        if (windows[0]!=nullptr){windows[0]->mainComponent.setObjObjRotation(5);}
        Obj1->setToggleState (false, NotificationType::dontSendNotification);
        Obj2->setToggleState (false, NotificationType::dontSendNotification);
        Obj3->setToggleState (false, NotificationType::dontSendNotification);
        Obj4->setToggleState (false, NotificationType::dontSendNotification);
        Obj8->setToggleState (false, NotificationType::dontSendNotification);
        Obj6->setToggleState (false, NotificationType::dontSendNotification);
        Obj7->setToggleState (false, NotificationType::dontSendNotification);
        Obj9->setToggleState (false, NotificationType::dontSendNotification);
        //[/UserButtonCode_Obj5]
    }
    else if (buttonThatWasClicked == Obj7.get())
    {
        //[UserButtonCode_Obj7] -- add your button handler code here..
        bool buttonToggleState = !buttonThatWasClicked->getToggleState();
        buttonThatWasClicked->setToggleState (buttonToggleState, NotificationType::dontSendNotification);

        if (windows[0]!=nullptr){windows[0]->mainComponent.setObjObjRotation(7);}
        Obj1->setToggleState (false, NotificationType::dontSendNotification);
        Obj2->setToggleState (false, NotificationType::dontSendNotification);
        Obj3->setToggleState (false, NotificationType::dontSendNotification);
        Obj4->setToggleState (false, NotificationType::dontSendNotification);
        Obj5->setToggleState (false, NotificationType::dontSendNotification);
        Obj6->setToggleState (false, NotificationType::dontSendNotification);
        Obj8->setToggleState (false, NotificationType::dontSendNotification);
        Obj9->setToggleState (false, NotificationType::dontSendNotification);
        //[/UserButtonCode_Obj7]
    }
    else if (buttonThatWasClicked == Obj9.get())
    {
        //[UserButtonCode_Obj9] -- add your button handler code here..
        bool buttonToggleState = !buttonThatWasClicked->getToggleState();
        buttonThatWasClicked->setToggleState (buttonToggleState, NotificationType::dontSendNotification);

        if (windows[0]!=nullptr){windows[0]->mainComponent.setObjObjRotation(9);}
        Obj1->setToggleState (false, NotificationType::dontSendNotification);
        Obj2->setToggleState (false, NotificationType::dontSendNotification);
        Obj3->setToggleState (false, NotificationType::dontSendNotification);
        Obj4->setToggleState (false, NotificationType::dontSendNotification);
        Obj5->setToggleState (false, NotificationType::dontSendNotification);
        Obj6->setToggleState (false, NotificationType::dontSendNotification);
        Obj7->setToggleState (false, NotificationType::dontSendNotification);
        Obj8->setToggleState (false, NotificationType::dontSendNotification);
        //[/UserButtonCode_Obj9]
    }
    else if (buttonThatWasClicked == Obj8.get())
    {
        //[UserButtonCode_Obj8] -- add your button handler code here..
        bool buttonToggleState = !buttonThatWasClicked->getToggleState();
        buttonThatWasClicked->setToggleState (buttonToggleState, NotificationType::dontSendNotification);

        if (windows[0]!=nullptr){windows[0]->mainComponent.setObjObjRotation(8);}
        Obj1->setToggleState (false, NotificationType::dontSendNotification);
        Obj2->setToggleState (false, NotificationType::dontSendNotification);
        Obj3->setToggleState (false, NotificationType::dontSendNotification);
        Obj4->setToggleState (false, NotificationType::dontSendNotification);
        Obj5->setToggleState (false, NotificationType::dontSendNotification);
        Obj6->setToggleState (false, NotificationType::dontSendNotification);
        Obj7->setToggleState (false, NotificationType::dontSendNotification);
        Obj9->setToggleState (false, NotificationType::dontSendNotification);
        //[/UserButtonCode_Obj8]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}

void Controller::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == sizeSlider.get())
    {
        //[UserSliderCode_sizeSlider] -- add your slider handling code here..
        windows[0]->mainComponent.setSizeObjRotation(sliderThatWasMoved->getValue());
        //[/UserSliderCode_sizeSlider]
    }
    else if (sliderThatWasMoved == avrSlider.get())
    {
        //[UserSliderCode_avrSlider] -- add your slider handling code here..
        windows[0]->mainComponent.setAvrObjRotation(sliderThatWasMoved->getValue());
        //[/UserSliderCode_avrSlider]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="Controller" componentName=""
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.33"
                 fixedSize="0" initialWidth="327" initialHeight="480">
  <BACKGROUND backgroundColour="ff323e44">
    <TEXT pos="92 4 140 24" fill="solid: ffffffff" hasStroke="0" text="VCA - Controls"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="92 60 140 24" fill="solid: ffffffff" hasStroke="0" text="Effects"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <RECT pos="16 233 296 231" fill="solid: ff323560" hasStroke="1" stroke="5, mitered, butt"
          strokeColour="solid: ff58a52a"/>
    <TEXT pos="20 196 84 30" fill="solid: ffffffff" hasStroke="0" text="Low Pass"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="33"/>
    <TEXT pos="20 164 52 30" fill="solid: ffffffff" hasStroke="0" text="Zoom"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="33"/>
  </BACKGROUND>
  <TEXTBUTTON name="Oscilloscope" id="4446b64c3c1570c3" memberName="OscilloscopeButton"
              virtualName="" explicitFocusOrder="0" pos="24 88 280 24" buttonText="Oscilloscope"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="Object" id="971500fc3639fb74" memberName="ObjButton" virtualName=""
              explicitFocusOrder="0" pos="24 120 280 24" buttonText="Object"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="Start" id="570f876fca500370" memberName="StartButton" virtualName=""
              explicitFocusOrder="0" pos="24 32 280 24" bgColOff="ff5ca477"
              buttonText="Start" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="Obj1" id="d4b8bcd17e6291e2" memberName="Obj1" virtualName=""
              explicitFocusOrder="0" pos="24 240 88 24" bgColOff="ff5c65a4"
              buttonText="Cat" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="Obj3" id="f90028cf7258f5d4" memberName="Obj3" virtualName=""
              explicitFocusOrder="0" pos="216 240 88 24" bgColOff="ff5c65a4"
              buttonText="Goat" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="Obj2" id="7d5e4411941c2b27" memberName="Obj2" virtualName=""
              explicitFocusOrder="0" pos="120 240 88 24" bgColOff="ff5c65a4"
              buttonText="Cow" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="Obj4" id="3ae55dc5f65ac2d3" memberName="Obj4" virtualName=""
              explicitFocusOrder="0" pos="24 272 88 24" bgColOff="ff5c65a4"
              buttonText="Deer" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="Obj6" id="46435e7319aa0725" memberName="Obj6" virtualName=""
              explicitFocusOrder="0" pos="216 272 88 24" bgColOff="ff5c65a4"
              buttonText="Tiger" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="Obj5" id="251027eb5b0e4a77" memberName="Obj5" virtualName=""
              explicitFocusOrder="0" pos="120 272 88 24" bgColOff="ff5c65a4"
              buttonText="Wolf" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="Obj7" id="5f6ae16990032b39" memberName="Obj7" virtualName=""
              explicitFocusOrder="0" pos="24 304 88 24" bgColOff="ff5c65a4"
              buttonText="Rat" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="Obj9" id="1ad7fdf597618762" memberName="Obj9" virtualName=""
              explicitFocusOrder="0" pos="216 304 88 24" bgColOff="ff5c65a4"
              buttonText="Human" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="Obj8" id="c1489632b3d5511d" memberName="Obj8" virtualName=""
              explicitFocusOrder="0" pos="120 304 88 24" bgColOff="ff5c65a4"
              buttonText="Face" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <SLIDER name="sizeSlider" id="5f869b427616b0fd" memberName="sizeSlider"
          virtualName="" explicitFocusOrder="0" pos="96 168 216 24" min="-3.0"
          max="10.0" int="0.0001" style="LinearHorizontal" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="avrSlider" id="191139ba07df0242" memberName="avrSlider"
          virtualName="" explicitFocusOrder="0" pos="104 200 208 24" min="1.0"
          max="256.0" int="1.0" style="LinearHorizontal" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
