/*
  ==============================================================================

    ImageTextButton.cpp
    Created: 5 Sep 2018 9:37:45am
    Author:  root

  ==============================================================================
*/
#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
//==================================================================================
/**
 This is a handy class which allows to completely customize a button, for instance
 using a graphics file as background, and text on it. Note that this is part of
 JUCE core graphics framework, NOT OpenGL...
*/
class TextureTextButton: public Button
{
public:
    TextureTextButton () : Button("ITBUTTON"), buttonFont(Font(14.0f)), fontColor(Colours::black), buttonLabel(""), width(0), height(0), xPos(0), yPos(0)
    {
    }
    TextureTextButton (String title, int x, int y, int w, int h, Image& image) : Button("ITBUTTON"), buttonFont(Font(14.0f)), fontColor(Colours::black), buttonLabel(title), backgroundImage(image), width(w), height(h), xPos(x), yPos(y)
    {
    }
    //==============================================================================
    // This is automatically called when the button needs be repainted.
    void paintButton(Graphics &g, bool isMouseOver, bool isButtonDown) override
    {
        // A path defines a series of graphics elements to draw something.
        // Here, its shape (a rounded rectangle) will be used as a mask
        // to get round angles around the image used as background.
        Path path;
        path.addRoundedRectangle(1.0f, 1.0f, (float)width-2.0f, (float)height-2.0f, (float)3.0f);
        
        if (buttonLabel == "") return;  // Don't draw anything if no label
        
        if (isMouseOver) {
            g.setOpacity(0.8f);
            if (isButtonDown) {
                g.setOpacity(0.5f);
            }
        } else {
            g.setOpacity(1.0f);
        }
        // If called with no specific dimensions, it will use the graphics image dimensions
        if ((height == 0) || (width == 0)) {
            g.drawImageAt (backgroundImage,0, 0);
            width = backgroundImage.getWidth();
            height = backgroundImage.getHeight();
        } else {
            // Otherwise it will use the given dimensions with rounded angles
            g.reduceClipRegion(path);
            g.drawImage(backgroundImage, 0, 0, width, height, 0, 0, backgroundImage.getWidth(), backgroundImage.getHeight());
            g.setColour(Colour(0x80FFFFFF));
            g.drawRect(0, 0, width, height,2);
        }
        // Now that the button background has been drawn, add text on top of it
        // We write it twice with a shift to make it display nicely on any background
        g.setColour(fontColor);
        g.setFont(buttonFont);
        g.drawText(buttonLabel,0,0,width,height,Justification::horizontallyCentred);
        g.setColour(fontColor.contrasting());
        g.drawText(buttonLabel,1,1,width,height,Justification::horizontallyCentred);
        
    }
    // We define those as public to simplify things in this small project
    Font buttonFont;
    Colour fontColor;
    String buttonLabel;
    Image backgroundImage;
    int width,height,xPos,yPos;
};
