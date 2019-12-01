/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "Oscilloscope2D.h"
#include "ObjRotation.cpp"

//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class MainComponent : public AudioAppComponent
{
public:
    //==============================================================================
    MainComponent();
    ~MainComponent();

    void paint (Graphics&);
    void resized();
    
    void prepareToPlay (int samplesPerBlockExpected, double sampleRate) override;
    void releaseResources() override;
    void getNextAudioBlock (const AudioSourceChannelInfo& bufferToFill) override;

    void setVisibleOscilloscope2D(bool setVisible);
    void setVisibleObjRotation(bool setVisible);
    void setTextureObjRotation(int numTexture); //1=A; 2=B; ...
    void setObjObjRotation(int numObj); //1=A; 2=B; ...
    void setSizeObjRotation(float valSlider);// getter of the slider
    void setAvrObjRotation(int valSlider);// set the Avrage to do on the signal (low pass effect)
    
private:
    //==============================================================================
    // Your private member variables go here...
    // Audio File Reading Variables
    
    AudioDeviceSelectorComponent audioIOSelector;
    
    AudioFormatManager formatManager;
    ScopedPointer<AudioFormatReaderSource> audioReaderSource;
    
    // Audio & GL Audio Buffer
    RingBuffer<float> * ringBuffer;
    
    // Visualizers
    Oscilloscope2D * oscilloscope2D;
    ObjRotation * objRotation;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};