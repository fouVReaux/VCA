/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/
#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent():audioIOSelector(deviceManager, 1, 2, 0, 0, false, false, true, true)
{
    // Setup Audio
    formatManager.registerBasicFormats();
    setAudioChannels (2, 2); // Initially Stereo Input to Stereo Output

    //setup size
    setSize(981, 480);
}

MainComponent::~MainComponent()
{
    shutdownAudio();
}

//==============================================================================
void MainComponent::paint (Graphics& g)
{
    g.fillAll (Colour (0xFF252831));
}

void MainComponent::resized()
{
    const int w = getWidth();
    const int h = getHeight();
    
    if (oscilloscope2D != nullptr)
        oscilloscope2D->setBounds(0,0,w,h);
        
    if (objRotation != nullptr)
        objRotation->setBounds(0,0,w,h);
}

void MainComponent::prepareToPlay (int samplesPerBlockExpected, double sampleRate)
{
    // Setup Ring Buffer of GLfloat's for the visualizer to use
    // Uses two channels stereo
    ringBuffer = new RingBuffer<GLfloat> (2, samplesPerBlockExpected * 10);
    
    // Allocate all Visualizers
    oscilloscope2D = new Oscilloscope2D (ringBuffer);
    addChildComponent (oscilloscope2D);
    
    objRotation = new ObjRotation (ringBuffer);
    addChildComponent (objRotation);
        
}
void MainComponent::releaseResources()
{
    // Delete all visualizer allocations
    if (oscilloscope2D != nullptr)
    {
        oscilloscope2D->stop();
        removeChildComponent (oscilloscope2D);
        delete oscilloscope2D;
    }
    if (objRotation != nullptr)
    {
        objRotation->stop();
        removeChildComponent (objRotation);
        delete objRotation;
    }
    
    delete ringBuffer;
}
void MainComponent::getNextAudioBlock (const AudioSourceChannelInfo& bufferToFill)
{
    // Write to Ring Buffer
    ringBuffer->writeSamples (*bufferToFill.buffer, bufferToFill.startSample, bufferToFill.numSamples);
        
    // If using mic input, clear the output so the mic input is not audible
    bufferToFill.clearActiveBufferRegion();
}

void MainComponent::setVisibleOscilloscope2D(bool setVisible)
{
    //set visible of not the Oscilloscope2D
    if(setVisible){
        oscilloscope2D->setVisible(true);
        oscilloscope2D->start();
    }
    if(!setVisible){
        oscilloscope2D->setVisible(false);
        oscilloscope2D->stop();    
    }
}

void MainComponent::setVisibleObjRotation(bool setVisible)
{
    //set visible of not the ObjRotation
    if(setVisible){
        objRotation->setVisible(true);
        objRotation->start();
    }
    if(!setVisible){
        objRotation->setVisible(false);
        objRotation->stop();    
    }
}

void MainComponent::setTextureObjRotation(int numTexture)
{
    //set the texture of not the ObjRotation
    if(numTexture==1){
        objRotation->setTextureA();
    }
    if(numTexture==2){
        objRotation->setTextureB();
    }
    if(numTexture==3){
        objRotation->setTextureC();
    }
    if(numTexture==4){
        objRotation->setTextureD();
    }
    if(numTexture==5){
        objRotation->setTextureE();
    }
    if(numTexture==6){
        objRotation->setTextureF();
    }
    if(numTexture==7){
        objRotation->setTextureG();
    }
    if(numTexture==8){
        objRotation->setTextureH();
    }
}
void MainComponent::setObjObjRotation(int numObj)
{
    //set the object of not the ObjRotation
    if(numObj==1){
        objRotation->setObjA();
    }
    if(numObj==2){
        objRotation->setObjB();
    }
    if(numObj==3){
        objRotation->setObjC();
    }
    if(numObj==4){
        objRotation->setObjD();
    }
    if(numObj==5){
        objRotation->setObjE();
    }
    if(numObj==6){
        objRotation->setObjF();
    }
    if(numObj==7){
        objRotation->setObjG();
    }
    if(numObj==8){
        objRotation->setObjH();
    }
    if(numObj==9){
        objRotation->setObjI();
    }
}
void MainComponent::setSizeObjRotation(float valSlider)
{
    //set size of the object of the ObjRotation
    objRotation->setScale(valSlider);
}
void MainComponent::setAvrObjRotation(int valSlider)
{
    //set the avrage (low pass) of the object of the ObjRotation
    objRotation->setAvr(valSlider);
}