/*
  ==============================================================================

    ViewWindow.h
    Created: 23 Jul 2018 11:26:08pm
    Author:  root

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "MainComponent.h"

class ViewWindow    : public DocumentWindow
{
public:
    ViewWindow (String name)  : DocumentWindow ("VCA",
                                Desktop::getInstance().getDefaultLookAndFeel()
                                                      .findColour (ResizableWindow::backgroundColourId),
                                                       DocumentWindow::allButtons)
    {
        setUsingNativeTitleBar (true);
        
        setContentOwned (&mainComponent, true);
        centreWithSize (getWidth(), getHeight());
        setVisible (true);
        setResizable (true, true);
    }

    void closeButtonPressed() override
    {
        delete this;
    }

    //OpenGLDemoClasses::OpenGLDemo openGLDemo;
    MainComponent mainComponent;
    
    private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ViewWindow)
};