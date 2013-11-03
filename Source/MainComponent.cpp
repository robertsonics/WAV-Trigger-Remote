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

//[Headers] You can add your own extra header files here...
#include "Serial.h"
#include "Communicator.h"
#include "Commands.h"
//[/Headers]

#include "MainComponent.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
MainComponent::MainComponent ()
{
    addAndMakeVisible (groupComponent3 = new GroupComponent ("new group",
                                                             "Track Control"));
    groupComponent3->setColour (GroupComponent::textColourId, Colours::white);

    addAndMakeVisible (groupComponent = new GroupComponent ("new group",
                                                            "Communications"));
    groupComponent->setColour (GroupComponent::textColourId, Colours::white);

    addAndMakeVisible (groupComponent2 = new GroupComponent ("new group",
                                                             "WAV Trigger System Info"));
    groupComponent2->setColour (GroupComponent::textColourId, Colours::white);

    addAndMakeVisible (volSlider = new Slider (String::empty));
    volSlider->setRange (-80, 10, 1);
    volSlider->setSliderStyle (Slider::RotaryVerticalDrag);
    volSlider->setTextBoxStyle (Slider::TextBoxRight, false, 50, 20);
    volSlider->addListener (this);

    addAndMakeVisible (portBoxlabel3 = new Label (String::empty,
                                                  "Gain (dB)"));
    portBoxlabel3->setFont (Font (16.00f, Font::plain));
    portBoxlabel3->setJustificationType (Justification::centred);
    portBoxlabel3->setEditable (false, false, false);
    portBoxlabel3->setColour (Label::textColourId, Colours::black);
    portBoxlabel3->setColour (TextEditor::textColourId, Colours::black);
    portBoxlabel3->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (portBoxlabel = new Label (String::empty,
                                                 "Serial Port:"));
    portBoxlabel->setFont (Font (16.00f, Font::plain));
    portBoxlabel->setJustificationType (Justification::centred);
    portBoxlabel->setEditable (false, false, false);
    portBoxlabel->setColour (Label::textColourId, Colours::black);
    portBoxlabel->setColour (TextEditor::textColourId, Colours::black);
    portBoxlabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (quitButton = new TextButton (String::empty));
    quitButton->setButtonText ("Quit");
    quitButton->addListener (this);

    addAndMakeVisible (portBox = new ComboBox (String::empty));
    portBox->setEditableText (false);
    portBox->setJustificationType (Justification::centredLeft);
    portBox->setTextWhenNothingSelected (String::empty);
    portBox->setTextWhenNoChoicesAvailable ("(no choices)");
    portBox->addListener (this);

    addAndMakeVisible (statusBar = new Label ("new label",
                                              String::empty));
    statusBar->setFont (Font (15.00f, Font::plain));
    statusBar->setJustificationType (Justification::centredLeft);
    statusBar->setEditable (false, false, false);
    statusBar->setColour (Label::backgroundColourId, Colour (0xff8da3da));
    statusBar->setColour (Label::textColourId, Colour (0xffad0101));
    statusBar->setColour (Label::outlineColourId, Colour (0x00000000));
    statusBar->setColour (TextEditor::textColourId, Colours::black);
    statusBar->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (helpButton = new TextButton (String::empty));
    helpButton->setButtonText ("Help");
    helpButton->addListener (this);

    addAndMakeVisible (baudBox = new ComboBox (String::empty));
    baudBox->setEditableText (false);
    baudBox->setJustificationType (Justification::centredLeft);
    baudBox->setTextWhenNothingSelected (String::empty);
    baudBox->setTextWhenNoChoicesAvailable ("(no choices)");
    baudBox->addListener (this);

    addAndMakeVisible (portBoxlabel2 = new Label (String::empty,
                                                  "Baudrate:"));
    portBoxlabel2->setFont (Font (16.00f, Font::plain));
    portBoxlabel2->setJustificationType (Justification::centred);
    portBoxlabel2->setEditable (false, false, false);
    portBoxlabel2->setColour (Label::textColourId, Colours::black);
    portBoxlabel2->setColour (TextEditor::textColourId, Colours::black);
    portBoxlabel2->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (playsoloButton1 = new TextButton (String::empty));
    playsoloButton1->setButtonText ("Play Solo");
    playsoloButton1->addListener (this);

    addAndMakeVisible (playmixButton1 = new TextButton (String::empty));
    playmixButton1->setButtonText ("Play Poly");
    playmixButton1->addListener (this);

    addAndMakeVisible (stopButton1 = new TextButton (String::empty));
    stopButton1->setButtonText ("Stop");
    stopButton1->addListener (this);

    addAndMakeVisible (loopToggle1 = new ToggleButton (String::empty));
    loopToggle1->setButtonText ("Loop");
    loopToggle1->addListener (this);

    addAndMakeVisible (pauseButton1 = new TextButton (String::empty));
    pauseButton1->setButtonText ("Pause");
    pauseButton1->addListener (this);

    addAndMakeVisible (resumeButton1 = new TextButton (String::empty));
    resumeButton1->setButtonText ("Resume");
    resumeButton1->addListener (this);

    addAndMakeVisible (trigText1 = new TextEditor (String::empty));
    trigText1->setMultiLine (false);
    trigText1->setReturnKeyStartsNewLine (false);
    trigText1->setReadOnly (false);
    trigText1->setScrollbarsShown (true);
    trigText1->setCaretVisible (true);
    trigText1->setPopupMenuEnabled (true);
    trigText1->setText ("1");

    addAndMakeVisible (versionText = new TextEditor (String::empty));
    versionText->setMultiLine (false);
    versionText->setReturnKeyStartsNewLine (false);
    versionText->setReadOnly (true);
    versionText->setScrollbarsShown (false);
    versionText->setCaretVisible (false);
    versionText->setPopupMenuEnabled (true);
    versionText->setText (String::empty);

    addAndMakeVisible (versionButton = new TextButton (String::empty));
    versionButton->setButtonText ("Get Info");
    versionButton->addListener (this);

    addAndMakeVisible (numVoicesText = new TextEditor (String::empty));
    numVoicesText->setMultiLine (false);
    numVoicesText->setReturnKeyStartsNewLine (false);
    numVoicesText->setReadOnly (true);
    numVoicesText->setScrollbarsShown (false);
    numVoicesText->setCaretVisible (false);
    numVoicesText->setPopupMenuEnabled (true);
    numVoicesText->setText (String::empty);

    addAndMakeVisible (numTracksText = new TextEditor (String::empty));
    numTracksText->setMultiLine (false);
    numTracksText->setReturnKeyStartsNewLine (false);
    numTracksText->setReadOnly (true);
    numTracksText->setScrollbarsShown (false);
    numTracksText->setCaretVisible (false);
    numTracksText->setPopupMenuEnabled (true);
    numTracksText->setText (String::empty);

    addAndMakeVisible (label = new Label ("new label",
                                          "Firmware Version:"));
    label->setFont (Font (15.00f, Font::plain));
    label->setJustificationType (Justification::centredLeft);
    label->setEditable (false, false, false);
    label->setColour (TextEditor::textColourId, Colours::black);
    label->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label2 = new Label ("new label",
                                           "Number of Stereo Voices:"));
    label2->setFont (Font (15.00f, Font::plain));
    label2->setJustificationType (Justification::centredLeft);
    label2->setEditable (false, false, false);
    label2->setColour (TextEditor::textColourId, Colours::black);
    label2->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label3 = new Label ("new label",
                                           "Number of WAV tracks:"));
    label3->setFont (Font (15.00f, Font::plain));
    label3->setJustificationType (Justification::centredLeft);
    label3->setEditable (false, false, false);
    label3->setColour (TextEditor::textColourId, Colours::black);
    label3->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (playsoloButton2 = new TextButton (String::empty));
    playsoloButton2->setButtonText ("Play Solo");
    playsoloButton2->addListener (this);

    addAndMakeVisible (playmixButton2 = new TextButton (String::empty));
    playmixButton2->setButtonText ("Play Poly");
    playmixButton2->addListener (this);

    addAndMakeVisible (stopButton2 = new TextButton (String::empty));
    stopButton2->setButtonText ("Stop");
    stopButton2->addListener (this);

    addAndMakeVisible (loopToggle2 = new ToggleButton (String::empty));
    loopToggle2->setButtonText ("Loop");
    loopToggle2->addListener (this);

    addAndMakeVisible (pauseButton2 = new TextButton (String::empty));
    pauseButton2->setButtonText ("Pause");
    pauseButton2->addListener (this);

    addAndMakeVisible (resumeButton2 = new TextButton (String::empty));
    resumeButton2->setButtonText ("Resume");
    resumeButton2->addListener (this);

    addAndMakeVisible (trigText2 = new TextEditor (String::empty));
    trigText2->setMultiLine (false);
    trigText2->setReturnKeyStartsNewLine (false);
    trigText2->setReadOnly (false);
    trigText2->setScrollbarsShown (true);
    trigText2->setCaretVisible (true);
    trigText2->setPopupMenuEnabled (true);
    trigText2->setText ("2");

    addAndMakeVisible (playsoloButton3 = new TextButton (String::empty));
    playsoloButton3->setButtonText ("Play Solo");
    playsoloButton3->addListener (this);

    addAndMakeVisible (playmixButton3 = new TextButton (String::empty));
    playmixButton3->setButtonText ("Play Poly");
    playmixButton3->addListener (this);

    addAndMakeVisible (stopButton3 = new TextButton (String::empty));
    stopButton3->setButtonText ("Stop");
    stopButton3->addListener (this);

    addAndMakeVisible (loopToggle3 = new ToggleButton (String::empty));
    loopToggle3->setButtonText ("Loop");
    loopToggle3->addListener (this);

    addAndMakeVisible (pauseButton3 = new TextButton (String::empty));
    pauseButton3->setButtonText ("Pause");
    pauseButton3->addListener (this);

    addAndMakeVisible (resumeButton3 = new TextButton (String::empty));
    resumeButton3->setButtonText ("Resume");
    resumeButton3->addListener (this);

    addAndMakeVisible (trigText3 = new TextEditor (String::empty));
    trigText3->setMultiLine (false);
    trigText3->setReturnKeyStartsNewLine (false);
    trigText3->setReadOnly (false);
    trigText3->setScrollbarsShown (true);
    trigText3->setCaretVisible (true);
    trigText3->setPopupMenuEnabled (true);
    trigText3->setText ("3");

    addAndMakeVisible (playsoloButton4 = new TextButton (String::empty));
    playsoloButton4->setButtonText ("Play Solo");
    playsoloButton4->addListener (this);

    addAndMakeVisible (playmixButton4 = new TextButton (String::empty));
    playmixButton4->setButtonText ("Play Poly");
    playmixButton4->addListener (this);

    addAndMakeVisible (stopButton4 = new TextButton (String::empty));
    stopButton4->setButtonText ("Stop");
    stopButton4->addListener (this);

    addAndMakeVisible (loopToggle4 = new ToggleButton (String::empty));
    loopToggle4->setButtonText ("Loop");
    loopToggle4->addListener (this);

    addAndMakeVisible (pauseButton4 = new TextButton (String::empty));
    pauseButton4->setButtonText ("Pause");
    pauseButton4->addListener (this);

    addAndMakeVisible (resumeButton4 = new TextButton (String::empty));
    resumeButton4->setButtonText ("Resume");
    resumeButton4->addListener (this);

    addAndMakeVisible (trigText4 = new TextEditor (String::empty));
    trigText4->setMultiLine (false);
    trigText4->setReturnKeyStartsNewLine (false);
    trigText4->setReadOnly (false);
    trigText4->setScrollbarsShown (true);
    trigText4->setCaretVisible (true);
    trigText4->setPopupMenuEnabled (true);
    trigText4->setText ("4");

    addAndMakeVisible (stopAllButton = new TextButton (String::empty));
    stopAllButton->setButtonText ("Stop All");
    stopAllButton->addListener (this);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (800, 620);


    //[Constructor] You can add your own custom stuff here..

	baudBox->addItem("1200 bps", 1);
	baudBox->addItem("2400 bps", 2);
	baudBox->addItem("9600 bps", 3);
	baudBox->addItem("19.2 kbps", 4);
	baudBox->addItem("38.4 kbps", 5);
	baudBox->addItem("57.6 kbps", 6);
	baudBox->setSelectedId(6);

	// For now, disable baudrate selection
	baudBox->setEnabled(false);

	trigText1->setInputRestrictions(3, "0123456789");
	trigText2->setInputRestrictions(3, "0123456789");
	trigText3->setInputRestrictions(3, "0123456789");
	trigText4->setInputRestrictions(3, "0123456789");

	pCom = new Communicator();
	pCom->addChangeListener(this);

    StringPairArray portlist = SerialPort::getSerialPortPaths();
	int j = 0;
	if(portlist.size()) {
		for (int i = 0; i < portlist.size(); i++) {

#ifdef WIN32
			if (portlist.getAllKeys()[i].contains("COM")) {
				j++;
				portBox->addItem(portlist.getAllKeys()[i], j);
            }
#else
            if (portlist.getAllKeys()[i].contains("usbserial")) {
				j++;
				portBox->addItem(portlist.getAllValues()[i], j);
			}
#endif
		}
	}

	if (j > 0) {

		// Use the first port to create a Communicator
		// SerialPort * pSP = new SerialPort(portlist.getAllValues()[0], SerialPortConfig(9600, 8, SerialPortConfig::SERIALPORT_PARITY_NONE, SerialPortConfig::STOPBITS_1, SerialPortConfig::FLOWCONTROL_NONE));
		m_portBoxItem = 1;
		portBox->setSelectedId(m_portBoxItem);
		String pN = portBox->getText();
		if (pCom->openPort(pN))
			statusBar->setText("  COM port opened successfully", dontSendNotification);
		else
			statusBar->setText("  COM port could not be opened!", dontSendNotification);
	}
	else {
		portBox->addItem("No USB Serial Devices!", 1);
		m_portBoxItem = 1;
		portBox->setSelectedId(m_portBoxItem);
		statusBar->setText("  No compatible COM ports found", dontSendNotification);
	}

    //[/Constructor]
}

MainComponent::~MainComponent()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
	if (pCom != nullptr) {
		pCom->closePort();
		pCom->removeChangeListener(this);
		delete pCom;
	}
    //[/Destructor_pre]

    groupComponent3 = nullptr;
    groupComponent = nullptr;
    groupComponent2 = nullptr;
    volSlider = nullptr;
    portBoxlabel3 = nullptr;
    portBoxlabel = nullptr;
    quitButton = nullptr;
    portBox = nullptr;
    statusBar = nullptr;
    helpButton = nullptr;
    baudBox = nullptr;
    portBoxlabel2 = nullptr;
    playsoloButton1 = nullptr;
    playmixButton1 = nullptr;
    stopButton1 = nullptr;
    loopToggle1 = nullptr;
    pauseButton1 = nullptr;
    resumeButton1 = nullptr;
    trigText1 = nullptr;
    versionText = nullptr;
    versionButton = nullptr;
    numVoicesText = nullptr;
    numTracksText = nullptr;
    label = nullptr;
    label2 = nullptr;
    label3 = nullptr;
    playsoloButton2 = nullptr;
    playmixButton2 = nullptr;
    stopButton2 = nullptr;
    loopToggle2 = nullptr;
    pauseButton2 = nullptr;
    resumeButton2 = nullptr;
    trigText2 = nullptr;
    playsoloButton3 = nullptr;
    playmixButton3 = nullptr;
    stopButton3 = nullptr;
    loopToggle3 = nullptr;
    pauseButton3 = nullptr;
    resumeButton3 = nullptr;
    trigText3 = nullptr;
    playsoloButton4 = nullptr;
    playmixButton4 = nullptr;
    stopButton4 = nullptr;
    loopToggle4 = nullptr;
    pauseButton4 = nullptr;
    resumeButton4 = nullptr;
    trigText4 = nullptr;
    stopAllButton = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void MainComponent::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff2a4dba));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void MainComponent::resized()
{
    groupComponent3->setBounds (24, 208, 752, 272);
    groupComponent->setBounds (416, 24, 360, 160);
    groupComponent2->setBounds (24, 24, 360, 160);
    volSlider->setBounds (8, 496, 159, 81);
    portBoxlabel3->setBounds (120, 552, 72, 16);
    portBoxlabel->setBounds (442, 60, 88, 16);
    quitButton->setBounds (712, 544, 63, 24);
    portBox->setBounds (528, 56, 224, 24);
    statusBar->setBounds (0, getHeight() - 24, proportionOfWidth (1.0000f), 24);
    helpButton->setBounds (632, 544, 63, 24);
    baudBox->setBounds (647, 96, 104, 24);
    portBoxlabel2->setBounds (569, 101, 81, 16);
    playsoloButton1->setBounds (265, 240, 72, 24);
    playmixButton1->setBounds (353, 240, 72, 24);
    stopButton1->setBounds (617, 240, 72, 24);
    loopToggle1->setBounds (182, 239, 64, 24);
    pauseButton1->setBounds (441, 240, 72, 24);
    resumeButton1->setBounds (529, 240, 72, 24);
    trigText1->setBounds (91, 240, 55, 24);
    versionText->setBounds (184, 56, 176, 24);
    versionButton->setBounds (48, 136, 63, 24);
    numVoicesText->setBounds (320, 96, 41, 24);
    numTracksText->setBounds (320, 136, 41, 24);
    label->setBounds (60, 56, 128, 24);
    label2->setBounds (150, 97, 175, 24);
    label3->setBounds (163, 136, 163, 24);
    playsoloButton2->setBounds (265, 289, 72, 24);
    playmixButton2->setBounds (353, 289, 72, 24);
    stopButton2->setBounds (617, 289, 72, 24);
    loopToggle2->setBounds (182, 288, 64, 24);
    pauseButton2->setBounds (441, 289, 72, 24);
    resumeButton2->setBounds (529, 289, 72, 24);
    trigText2->setBounds (91, 289, 55, 24);
    playsoloButton3->setBounds (265, 338, 72, 24);
    playmixButton3->setBounds (353, 338, 72, 24);
    stopButton3->setBounds (617, 338, 72, 24);
    loopToggle3->setBounds (182, 337, 64, 24);
    pauseButton3->setBounds (441, 338, 72, 24);
    resumeButton3->setBounds (529, 338, 72, 24);
    trigText3->setBounds (91, 338, 55, 24);
    playsoloButton4->setBounds (265, 386, 72, 24);
    playmixButton4->setBounds (353, 386, 72, 24);
    stopButton4->setBounds (617, 386, 72, 24);
    loopToggle4->setBounds (182, 385, 64, 24);
    pauseButton4->setBounds (441, 386, 72, 24);
    resumeButton4->setBounds (529, 386, 72, 24);
    trigText4->setBounds (91, 386, 55, 24);
    stopAllButton->setBounds (616, 432, 72, 24);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void MainComponent::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
	int iVal;
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == volSlider)
    {
        //[UserSliderCode_volSlider] -- add your slider handling code here..
		iVal = (int)volSlider->getValue();
		pCom->volume(iVal);
        //[/UserSliderCode_volSlider]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}

void MainComponent::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
	String sVal;
	int iVal;
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == quitButton)
    {
        //[UserButtonCode_quitButton] -- add your button handler code here..

        JUCEApplication::quit();

        //[/UserButtonCode_quitButton]
    }
    else if (buttonThatWasClicked == helpButton)
    {
        //[UserButtonCode_helpButton] -- add your button handler code here..

		AlertWindow::showMessageBoxAsync(AlertWindow::InfoIcon, "WTP Remote Help",
			"No help yet!");

        //[/UserButtonCode_helpButton]
    }
    else if (buttonThatWasClicked == playsoloButton1)
    {
        //[UserButtonCode_playsoloButton1] -- add your button handler code here..
		sVal = trigText1->getText();
		iVal = sVal.getIntValue();
		pCom->controlTrack(TRACK_CONTROL_PLAY_SOLO, iVal);
        //[/UserButtonCode_playsoloButton1]
    }
    else if (buttonThatWasClicked == playmixButton1)
    {
        //[UserButtonCode_playmixButton1] -- add your button handler code here..
 		sVal = trigText1->getText();
		iVal = sVal.getIntValue();
		pCom->controlTrack(TRACK_CONTROL_PLAY_POLY, iVal);
        //[/UserButtonCode_playmixButton1]
    }
    else if (buttonThatWasClicked == stopButton1)
    {
        //[UserButtonCode_stopButton1] -- add your button handler code here..
 		sVal = trigText1->getText();
		iVal = sVal.getIntValue();
		pCom->controlTrack(TRACK_CONTROL_STOP, iVal);
        //[/UserButtonCode_stopButton1]
    }
    else if (buttonThatWasClicked == loopToggle1)
    {
        //[UserButtonCode_loopToggle1] -- add your button handler code here..
		sVal = trigText1->getText();
		iVal = sVal.getIntValue();
		if (loopToggle1->getToggleState())
			pCom->controlTrack(TRACK_CONTROL_LOOP_ON, iVal);
		else
			pCom->controlTrack(TRACK_CONTROL_LOOP_OFF, iVal);
        //[/UserButtonCode_loopToggle1]
    }
    else if (buttonThatWasClicked == pauseButton1)
    {
        //[UserButtonCode_pauseButton1] -- add your button handler code here..
 		sVal = trigText1->getText();
		iVal = sVal.getIntValue();
		pCom->controlTrack(TRACK_CONTROL_PAUSE, iVal);
        //[/UserButtonCode_pauseButton1]
    }
    else if (buttonThatWasClicked == resumeButton1)
    {
        //[UserButtonCode_resumeButton1] -- add your button handler code here..
  		sVal = trigText1->getText();
		iVal = sVal.getIntValue();
		pCom->controlTrack(TRACK_CONTROL_RESUME, iVal);
        //[/UserButtonCode_resumeButton1]
    }
    else if (buttonThatWasClicked == versionButton)
    {
        //[UserButtonCode_versionButton] -- add your button handler code here..
		pCom->getDeviceInfo();
        //[/UserButtonCode_versionButton]
    }
    else if (buttonThatWasClicked == playsoloButton2)
    {
        //[UserButtonCode_playsoloButton2] -- add your button handler code here..
		sVal = trigText2->getText();
		iVal = sVal.getIntValue();
		pCom->controlTrack(TRACK_CONTROL_PLAY_SOLO, iVal);
        //[/UserButtonCode_playsoloButton2]
    }
    else if (buttonThatWasClicked == playmixButton2)
    {
        //[UserButtonCode_playmixButton2] -- add your button handler code here..
		sVal = trigText2->getText();
		iVal = sVal.getIntValue();
		pCom->controlTrack(TRACK_CONTROL_PLAY_POLY, iVal);
        //[/UserButtonCode_playmixButton2]
    }
    else if (buttonThatWasClicked == stopButton2)
    {
        //[UserButtonCode_stopButton2] -- add your button handler code here..
		sVal = trigText2->getText();
		iVal = sVal.getIntValue();
		pCom->controlTrack(TRACK_CONTROL_STOP, iVal);
        //[/UserButtonCode_stopButton2]
    }
    else if (buttonThatWasClicked == loopToggle2)
    {
        //[UserButtonCode_loopToggle2] -- add your button handler code here..
		sVal = trigText2->getText();
		iVal = sVal.getIntValue();
		if (loopToggle2->getToggleState())
			pCom->controlTrack(TRACK_CONTROL_LOOP_ON, iVal);
		else
			pCom->controlTrack(TRACK_CONTROL_LOOP_OFF, iVal);
        //[/UserButtonCode_loopToggle2]
    }
    else if (buttonThatWasClicked == pauseButton2)
    {
        //[UserButtonCode_pauseButton2] -- add your button handler code here..
 		sVal = trigText2->getText();
		iVal = sVal.getIntValue();
		pCom->controlTrack(TRACK_CONTROL_PAUSE, iVal);
        //[/UserButtonCode_pauseButton2]
    }
    else if (buttonThatWasClicked == resumeButton2)
    {
        //[UserButtonCode_resumeButton2] -- add your button handler code here..
		sVal = trigText2->getText();
		iVal = sVal.getIntValue();
		pCom->controlTrack(TRACK_CONTROL_RESUME, iVal);
        //[/UserButtonCode_resumeButton2]
    }
    else if (buttonThatWasClicked == playsoloButton3)
    {
        //[UserButtonCode_playsoloButton3] -- add your button handler code here..
 		sVal = trigText3->getText();
		iVal = sVal.getIntValue();
		pCom->controlTrack(TRACK_CONTROL_PLAY_SOLO, iVal);
        //[/UserButtonCode_playsoloButton3]
    }
    else if (buttonThatWasClicked == playmixButton3)
    {
        //[UserButtonCode_playmixButton3] -- add your button handler code here..
		sVal = trigText3->getText();
		iVal = sVal.getIntValue();
		pCom->controlTrack(TRACK_CONTROL_PLAY_POLY, iVal);
        //[/UserButtonCode_playmixButton3]
    }
    else if (buttonThatWasClicked == stopButton3)
    {
        //[UserButtonCode_stopButton3] -- add your button handler code here..
		sVal = trigText3->getText();
		iVal = sVal.getIntValue();
		pCom->controlTrack(TRACK_CONTROL_STOP, iVal);
        //[/UserButtonCode_stopButton3]
    }
    else if (buttonThatWasClicked == loopToggle3)
    {
        //[UserButtonCode_loopToggle3] -- add your button handler code here..
		sVal = trigText3->getText();
		iVal = sVal.getIntValue();
		if (loopToggle3->getToggleState())
			pCom->controlTrack(TRACK_CONTROL_LOOP_ON, iVal);
		else
			pCom->controlTrack(TRACK_CONTROL_LOOP_OFF, iVal);
        //[/UserButtonCode_loopToggle3]
    }
    else if (buttonThatWasClicked == pauseButton3)
    {
        //[UserButtonCode_pauseButton3] -- add your button handler code here..
		sVal = trigText3->getText();
		iVal = sVal.getIntValue();
		pCom->controlTrack(TRACK_CONTROL_PAUSE, iVal);
        //[/UserButtonCode_pauseButton3]
    }
    else if (buttonThatWasClicked == resumeButton3)
    {
        //[UserButtonCode_resumeButton3] -- add your button handler code here..
		sVal = trigText3->getText();
		iVal = sVal.getIntValue();
		pCom->controlTrack(TRACK_CONTROL_RESUME, iVal);
        //[/UserButtonCode_resumeButton3]
    }
    else if (buttonThatWasClicked == playsoloButton4)
    {
        //[UserButtonCode_playsoloButton4] -- add your button handler code here..
		sVal = trigText4->getText();
		iVal = sVal.getIntValue();
		pCom->controlTrack(TRACK_CONTROL_PLAY_SOLO, iVal);
        //[/UserButtonCode_playsoloButton4]
    }
    else if (buttonThatWasClicked == playmixButton4)
    {
        //[UserButtonCode_playmixButton4] -- add your button handler code here..
		sVal = trigText4->getText();
		iVal = sVal.getIntValue();
		pCom->controlTrack(TRACK_CONTROL_PLAY_POLY, iVal);
        //[/UserButtonCode_playmixButton4]
    }
    else if (buttonThatWasClicked == stopButton4)
    {
        //[UserButtonCode_stopButton4] -- add your button handler code here..
		sVal = trigText4->getText();
		iVal = sVal.getIntValue();
		pCom->controlTrack(TRACK_CONTROL_STOP, iVal);
        //[/UserButtonCode_stopButton4]
    }
    else if (buttonThatWasClicked == loopToggle4)
    {
        //[UserButtonCode_loopToggle4] -- add your button handler code here..
		sVal = trigText4->getText();
		iVal = sVal.getIntValue();
		if (loopToggle4->getToggleState())
			pCom->controlTrack(TRACK_CONTROL_LOOP_ON, iVal);
		else
			pCom->controlTrack(TRACK_CONTROL_LOOP_OFF, iVal);
        //[/UserButtonCode_loopToggle4]
    }
    else if (buttonThatWasClicked == pauseButton4)
    {
        //[UserButtonCode_pauseButton4] -- add your button handler code here..
 		sVal = trigText4->getText();
		iVal = sVal.getIntValue();
		pCom->controlTrack(TRACK_CONTROL_PAUSE, iVal);
        //[/UserButtonCode_pauseButton4]
    }
    else if (buttonThatWasClicked == resumeButton4)
    {
        //[UserButtonCode_resumeButton4] -- add your button handler code here..
		sVal = trigText4->getText();
		iVal = sVal.getIntValue();
		pCom->controlTrack(TRACK_CONTROL_RESUME, iVal);
        //[/UserButtonCode_resumeButton4]
    }
    else if (buttonThatWasClicked == stopAllButton)
    {
        //[UserButtonCode_stopAllButton] -- add your button handler code here..
		pCom->stopAll();
        //[/UserButtonCode_stopAllButton]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}

void MainComponent::comboBoxChanged (ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]
    //[/UsercomboBoxChanged_Pre]

    if (comboBoxThatHasChanged == portBox)
    {
        //[UserComboBoxCode_portBox] -- add your combo box handling code here..

		if (portBox->getSelectedId() != m_portBoxItem) {
			m_portBoxItem = portBox->getSelectedId();
			String pN = portBox->getText();
			if (pCom->isPortOpen())
				pCom->closePort();
			if (pCom->openPort(pN)) {
				statusBar->setText("  COM port opened successfully", dontSendNotification);
				//connectButton->setEnabled(true);
			}
			else {
				statusBar->setText("  COM port could not be opened!", dontSendNotification);
				//connectButton->setEnabled(false);
			}
		}

        //[/UserComboBoxCode_portBox]
    }
    else if (comboBoxThatHasChanged == baudBox)
    {
        //[UserComboBoxCode_baudBox] -- add your combo box handling code here..
        //[/UserComboBoxCode_baudBox]
    }

    //[UsercomboBoxChanged_Post]
    //[/UsercomboBoxChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...

void MainComponent::changeListenerCallback(ChangeBroadcaster *)
{

int dState;
int msgLen;
int iVal;
unsigned char msgBuff[MAX_MESSAGE_LENGTH + 8];
String sVal = "";

	dState = pCom->getState();
	if (pCom->isMsgReady()) {
		msgLen = pCom->getMessage(msgBuff);
		pCom->clearMsgReady();
		if (msgLen > 0) {
			switch (msgBuff[0]) {

				case VERSION_STRING:
					msgBuff[msgLen] = 0;
					{ String ver((const char *)&msgBuff[1]);
					versionText->setText(ver, dontSendNotification); }
				break;

				case SYSTEM_INFO:
					sVal += (unsigned char)msgBuff[1];
					numVoicesText->setText(sVal, dontSendNotification);
					iVal = msgBuff[3];
					iVal = (iVal << 8) + msgBuff[2];
					sVal = "";
					sVal += iVal;
					numTracksText->setText(sVal, dontSendNotification);
				break;
			}
		}
	}
	else {
		if (dState == COMM_STARTED)
			statusBar->setText("  COM thread started", dontSendNotification);
	}

}

//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Introjucer information section --

    This is where the Introjucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="MainComponent" componentName=""
                 parentClasses="public Component, public ChangeListener" constructorParams=""
                 variableInitialisers="" snapPixels="8" snapActive="1" snapShown="1"
                 overlayOpacity="0.330" fixedSize="1" initialWidth="800" initialHeight="620">
  <BACKGROUND backgroundColour="ff2a4dba"/>
  <GROUPCOMPONENT name="new group" id="69229fd352cbc9b2" memberName="groupComponent3"
                  virtualName="" explicitFocusOrder="0" pos="24 208 752 272" textcol="ffffffff"
                  title="Track Control"/>
  <GROUPCOMPONENT name="new group" id="2cf21ac44d719d93" memberName="groupComponent"
                  virtualName="" explicitFocusOrder="0" pos="416 24 360 160" textcol="ffffffff"
                  title="Communications"/>
  <GROUPCOMPONENT name="new group" id="faf9d7977149782a" memberName="groupComponent2"
                  virtualName="" explicitFocusOrder="0" pos="24 24 360 160" textcol="ffffffff"
                  title="WAV Trigger System Info"/>
  <SLIDER name="" id="a4b37bd1b46fdb64" memberName="volSlider" virtualName=""
          explicitFocusOrder="0" pos="8 496 159 81" min="-80" max="10"
          int="1" style="RotaryVerticalDrag" textBoxPos="TextBoxRight"
          textBoxEditable="1" textBoxWidth="50" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="" id="b3b1c85b4500968f" memberName="portBoxlabel3" virtualName=""
         explicitFocusOrder="0" pos="120 552 72 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="Gain (dB)" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="16" bold="0" italic="0" justification="36"/>
  <LABEL name="" id="be4f6f2e5725a063" memberName="portBoxlabel" virtualName=""
         explicitFocusOrder="0" pos="442 60 88 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="Serial Port:" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="16" bold="0" italic="0" justification="36"/>
  <TEXTBUTTON name="" id="bcf4f7b0888effe5" memberName="quitButton" virtualName=""
              explicitFocusOrder="0" pos="712 544 63 24" buttonText="Quit"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <COMBOBOX name="" id="a9377a9d1326182e" memberName="portBox" virtualName=""
            explicitFocusOrder="0" pos="528 56 224 24" editable="0" layout="33"
            items="" textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <LABEL name="new label" id="ef8d15cc5a4b63c3" memberName="statusBar"
         virtualName="" explicitFocusOrder="0" pos="0 0Rr 100% 24" bkgCol="ff8da3da"
         textCol="ffad0101" outlineCol="0" edTextCol="ff000000" edBkgCol="0"
         labelText="" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="33"/>
  <TEXTBUTTON name="" id="d687ab0ae7e4a720" memberName="helpButton" virtualName=""
              explicitFocusOrder="0" pos="632 544 63 24" buttonText="Help"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <COMBOBOX name="" id="2c59ca67fae45d22" memberName="baudBox" virtualName=""
            explicitFocusOrder="0" pos="647 96 104 24" editable="0" layout="33"
            items="" textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <LABEL name="" id="eb7446e9391f0d79" memberName="portBoxlabel2" virtualName=""
         explicitFocusOrder="0" pos="569 101 81 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="Baudrate:" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="16" bold="0" italic="0" justification="36"/>
  <TEXTBUTTON name="" id="dbbab70ff7e44452" memberName="playsoloButton1" virtualName=""
              explicitFocusOrder="0" pos="265 240 72 24" buttonText="Play Solo"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="" id="51f8f1f4d874a866" memberName="playmixButton1" virtualName=""
              explicitFocusOrder="0" pos="353 240 72 24" buttonText="Play Poly"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="" id="c902ffad93176b2c" memberName="stopButton1" virtualName=""
              explicitFocusOrder="0" pos="617 240 72 24" buttonText="Stop"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TOGGLEBUTTON name="" id="403473bc1f1cbd0b" memberName="loopToggle1" virtualName=""
                explicitFocusOrder="0" pos="182 239 64 24" buttonText="Loop"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <TEXTBUTTON name="" id="4300c5f8bc94f310" memberName="pauseButton1" virtualName=""
              explicitFocusOrder="0" pos="441 240 72 24" buttonText="Pause"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="" id="9865d9baf642eb5f" memberName="resumeButton1" virtualName=""
              explicitFocusOrder="0" pos="529 240 72 24" buttonText="Resume"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTEDITOR name="" id="349bf31d6a377790" memberName="trigText1" virtualName=""
              explicitFocusOrder="0" pos="91 240 55 24" initialText="1" multiline="0"
              retKeyStartsLine="0" readonly="0" scrollbars="1" caret="1" popupmenu="1"/>
  <TEXTEDITOR name="" id="d897b478ba180688" memberName="versionText" virtualName=""
              explicitFocusOrder="0" pos="184 56 176 24" initialText="" multiline="0"
              retKeyStartsLine="0" readonly="1" scrollbars="0" caret="0" popupmenu="1"/>
  <TEXTBUTTON name="" id="5ec42bc6370231ba" memberName="versionButton" virtualName=""
              explicitFocusOrder="0" pos="48 136 63 24" buttonText="Get Info"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTEDITOR name="" id="ae4c7ab7b0e1ec37" memberName="numVoicesText" virtualName=""
              explicitFocusOrder="0" pos="320 96 41 24" initialText="" multiline="0"
              retKeyStartsLine="0" readonly="1" scrollbars="0" caret="0" popupmenu="1"/>
  <TEXTEDITOR name="" id="4b638d8174953262" memberName="numTracksText" virtualName=""
              explicitFocusOrder="0" pos="320 136 41 24" initialText="" multiline="0"
              retKeyStartsLine="0" readonly="1" scrollbars="0" caret="0" popupmenu="1"/>
  <LABEL name="new label" id="373041437cee60c6" memberName="label" virtualName=""
         explicitFocusOrder="0" pos="60 56 128 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Firmware Version:" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="bd160dcc811ead8b" memberName="label2" virtualName=""
         explicitFocusOrder="0" pos="150 97 175 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Number of Stereo Voices:" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="204edbed6a3aa8bf" memberName="label3" virtualName=""
         explicitFocusOrder="0" pos="163 136 163 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Number of WAV tracks:" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="33"/>
  <TEXTBUTTON name="" id="7f0e6681b9cd0f73" memberName="playsoloButton2" virtualName=""
              explicitFocusOrder="0" pos="265 289 72 24" buttonText="Play Solo"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="" id="5b12b9288609c1c3" memberName="playmixButton2" virtualName=""
              explicitFocusOrder="0" pos="353 289 72 24" buttonText="Play Poly"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="" id="db164cb87a73ee5" memberName="stopButton2" virtualName=""
              explicitFocusOrder="0" pos="617 289 72 24" buttonText="Stop"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TOGGLEBUTTON name="" id="6bd56188c0903ee2" memberName="loopToggle2" virtualName=""
                explicitFocusOrder="0" pos="182 288 64 24" buttonText="Loop"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <TEXTBUTTON name="" id="1642d5e074a6111e" memberName="pauseButton2" virtualName=""
              explicitFocusOrder="0" pos="441 289 72 24" buttonText="Pause"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="" id="3e4d4c740ddd1bc3" memberName="resumeButton2" virtualName=""
              explicitFocusOrder="0" pos="529 289 72 24" buttonText="Resume"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTEDITOR name="" id="2b590d01f2235d90" memberName="trigText2" virtualName=""
              explicitFocusOrder="0" pos="91 289 55 24" initialText="2" multiline="0"
              retKeyStartsLine="0" readonly="0" scrollbars="1" caret="1" popupmenu="1"/>
  <TEXTBUTTON name="" id="d73e3cf999c54579" memberName="playsoloButton3" virtualName=""
              explicitFocusOrder="0" pos="265 338 72 24" buttonText="Play Solo"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="" id="3ee79d9e92738b5f" memberName="playmixButton3" virtualName=""
              explicitFocusOrder="0" pos="353 338 72 24" buttonText="Play Poly"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="" id="bdd21d937427de45" memberName="stopButton3" virtualName=""
              explicitFocusOrder="0" pos="617 338 72 24" buttonText="Stop"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TOGGLEBUTTON name="" id="31a413cdebdb1e8b" memberName="loopToggle3" virtualName=""
                explicitFocusOrder="0" pos="182 337 64 24" buttonText="Loop"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <TEXTBUTTON name="" id="f4dbf44b658c9e30" memberName="pauseButton3" virtualName=""
              explicitFocusOrder="0" pos="441 338 72 24" buttonText="Pause"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="" id="249ead5e9b5d4a0" memberName="resumeButton3" virtualName=""
              explicitFocusOrder="0" pos="529 338 72 24" buttonText="Resume"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTEDITOR name="" id="7da7f44767016f2f" memberName="trigText3" virtualName=""
              explicitFocusOrder="0" pos="91 338 55 24" initialText="3" multiline="0"
              retKeyStartsLine="0" readonly="0" scrollbars="1" caret="1" popupmenu="1"/>
  <TEXTBUTTON name="" id="a90629870d2b8c10" memberName="playsoloButton4" virtualName=""
              explicitFocusOrder="0" pos="265 386 72 24" buttonText="Play Solo"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="" id="2ac5ec9cfa4d4951" memberName="playmixButton4" virtualName=""
              explicitFocusOrder="0" pos="353 386 72 24" buttonText="Play Poly"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="" id="ed70635b82008bdf" memberName="stopButton4" virtualName=""
              explicitFocusOrder="0" pos="617 386 72 24" buttonText="Stop"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TOGGLEBUTTON name="" id="62772798a04fa3de" memberName="loopToggle4" virtualName=""
                explicitFocusOrder="0" pos="182 385 64 24" buttonText="Loop"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <TEXTBUTTON name="" id="697fd215367a3f8b" memberName="pauseButton4" virtualName=""
              explicitFocusOrder="0" pos="441 386 72 24" buttonText="Pause"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="" id="d1e44c4da5163d80" memberName="resumeButton4" virtualName=""
              explicitFocusOrder="0" pos="529 386 72 24" buttonText="Resume"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTEDITOR name="" id="fa324c00c2f845ca" memberName="trigText4" virtualName=""
              explicitFocusOrder="0" pos="91 386 55 24" initialText="4" multiline="0"
              retKeyStartsLine="0" readonly="0" scrollbars="1" caret="1" popupmenu="1"/>
  <TEXTBUTTON name="" id="be0f5cd3d7919846" memberName="stopAllButton" virtualName=""
              explicitFocusOrder="0" pos="616 432 72 24" buttonText="Stop All"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
