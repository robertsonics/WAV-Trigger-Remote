/*
  ==============================================================================

  This is an automatically generated GUI class created by the Introjucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Introjucer version: 3.1.0

  ------------------------------------------------------------------------------

  The Introjucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright 2004-13 by Raw Material Software Ltd.

  ==============================================================================
*/

#ifndef __JUCE_HEADER_9002020A4DD09B20__
#define __JUCE_HEADER_9002020A4DD09B20__

//[Headers]     -- You can add your own extra header files here --
#include "../JuceLibraryCode/JuceHeader.h"
#include "Communicator.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Jucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class MainComponent  : public Component,
                       public ChangeListener,
                       public SliderListener,
                       public ButtonListener,
                       public ComboBoxListener
{
public:
    //==============================================================================
    MainComponent ();
    ~MainComponent();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
	void changeListenerCallback(ChangeBroadcaster *);
    //[/UserMethods]

    void paint (Graphics& g);
    void resized();
    void sliderValueChanged (Slider* sliderThatWasMoved);
    void buttonClicked (Button* buttonThatWasClicked);
    void comboBoxChanged (ComboBox* comboBoxThatHasChanged);



private:
    //[UserVariables]   -- You can add your own custom variables in this section.

	Communicator *pCom;		// Our Communicator

	int m_portBoxItem;		// Current portBox item index

    //[/UserVariables]

    //==============================================================================
    ScopedPointer<GroupComponent> groupComponent;
    ScopedPointer<GroupComponent> groupComponent2;
    ScopedPointer<Slider> volSlider;
    ScopedPointer<Label> portBoxlabel3;
    ScopedPointer<Label> portBoxlabel;
    ScopedPointer<TextButton> quitButton;
    ScopedPointer<ComboBox> portBox;
    ScopedPointer<Label> statusBar;
    ScopedPointer<TextButton> helpButton;
    ScopedPointer<ComboBox> baudBox;
    ScopedPointer<Label> portBoxlabel2;
    ScopedPointer<TextButton> playsoloButton1;
    ScopedPointer<TextButton> playmixButton1;
    ScopedPointer<TextButton> stopButton1;
    ScopedPointer<ToggleButton> loopToggle;
    ScopedPointer<TextButton> pauseButton1;
    ScopedPointer<TextButton> resumeButton1;
    ScopedPointer<TextEditor> trigText1;
    ScopedPointer<TextEditor> versionText;
    ScopedPointer<TextButton> versionButton;
    ScopedPointer<TextEditor> numVoicesText;
    ScopedPointer<TextEditor> numTracksText;
    ScopedPointer<GroupComponent> groupComponent3;
    ScopedPointer<Label> label;
    ScopedPointer<Label> label2;
    ScopedPointer<Label> label3;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_9002020A4DD09B20__
