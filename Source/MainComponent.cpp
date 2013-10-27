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
    addAndMakeVisible (groupComponent = new GroupComponent ("new group",
                                                            "Communications"));

    addAndMakeVisible (groupComponent2 = new GroupComponent ("new group",
                                                             "WAV Trigger System Info"));

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
    playmixButton1->setButtonText ("Play Mix");
    playmixButton1->addListener (this);

    addAndMakeVisible (stopButton1 = new TextButton (String::empty));
    stopButton1->setButtonText ("Stop");
    stopButton1->addListener (this);

    addAndMakeVisible (loopToggle = new ToggleButton (String::empty));
    loopToggle->setButtonText ("Loop");
    loopToggle->addListener (this);

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
    versionText->setReadOnly (false);
    versionText->setScrollbarsShown (true);
    versionText->setCaretVisible (true);
    versionText->setPopupMenuEnabled (true);
    versionText->setText (String::empty);

    addAndMakeVisible (versionButton = new TextButton (String::empty));
    versionButton->setButtonText ("Get Info");
    versionButton->addListener (this);

    addAndMakeVisible (numVoicesText = new TextEditor (String::empty));
    numVoicesText->setMultiLine (false);
    numVoicesText->setReturnKeyStartsNewLine (false);
    numVoicesText->setReadOnly (false);
    numVoicesText->setScrollbarsShown (true);
    numVoicesText->setCaretVisible (true);
    numVoicesText->setPopupMenuEnabled (true);
    numVoicesText->setText (String::empty);

    addAndMakeVisible (numTracksText = new TextEditor (String::empty));
    numTracksText->setMultiLine (false);
    numTracksText->setReturnKeyStartsNewLine (false);
    numTracksText->setReadOnly (false);
    numTracksText->setScrollbarsShown (true);
    numTracksText->setCaretVisible (true);
    numTracksText->setPopupMenuEnabled (true);
    numTracksText->setText (String::empty);

    addAndMakeVisible (groupComponent3 = new GroupComponent ("new group",
                                                             "Track Control"));

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

	trigText1->setInputRestrictions(3, "0123456789");

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
    loopToggle = nullptr;
    pauseButton1 = nullptr;
    resumeButton1 = nullptr;
    trigText1 = nullptr;
    versionText = nullptr;
    versionButton = nullptr;
    numVoicesText = nullptr;
    numTracksText = nullptr;
    groupComponent3 = nullptr;
    label = nullptr;
    label2 = nullptr;
    label3 = nullptr;


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
    groupComponent->setBounds (416, 24, 360, 160);
    groupComponent2->setBounds (24, 24, 360, 160);
    volSlider->setBounds (33, 488, 159, 81);
    portBoxlabel3->setBounds (134, 546, 72, 16);
    portBoxlabel->setBounds (442, 60, 88, 16);
    quitButton->setBounds (712, 544, 63, 24);
    portBox->setBounds (528, 56, 224, 24);
    statusBar->setBounds (0, getHeight() - 24, proportionOfWidth (1.0000f), 24);
    helpButton->setBounds (632, 544, 63, 24);
    baudBox->setBounds (647, 96, 104, 24);
    portBoxlabel2->setBounds (569, 101, 81, 16);
    playsoloButton1->setBounds (265, 248, 72, 24);
    playmixButton1->setBounds (353, 248, 72, 24);
    stopButton1->setBounds (617, 248, 72, 24);
    loopToggle->setBounds (182, 247, 64, 24);
    pauseButton1->setBounds (441, 248, 72, 24);
    resumeButton1->setBounds (529, 248, 72, 24);
    trigText1->setBounds (91, 248, 55, 24);
    versionText->setBounds (184, 56, 176, 24);
    versionButton->setBounds (48, 136, 63, 24);
    numVoicesText->setBounds (320, 96, 41, 24);
    numTracksText->setBounds (320, 136, 41, 24);
    groupComponent3->setBounds (32, 208, 744, 256);
    label->setBounds (60, 56, 128, 24);
    label2->setBounds (150, 97, 175, 24);
    label3->setBounds (163, 136, 163, 24);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void MainComponent::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == volSlider)
    {
        //[UserSliderCode_volSlider] -- add your slider handling code here..
        //[/UserSliderCode_volSlider]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}

void MainComponent::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
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

		AlertWindow::showMessageBoxAsync(AlertWindow::InfoIcon, "WTP Flasher Help",
			"Set the WAV Trigger Pro BOOT0 jumper, and then apply power while connected to the selected serial port.");

        //[/UserButtonCode_helpButton]
    }
    else if (buttonThatWasClicked == playsoloButton1)
    {
        //[UserButtonCode_playsoloButton1] -- add your button handler code here..
		iVal = trigText1->getText();
		pCom->controlTrack(TRACK_PLAY_SOLO, 1);
        //[/UserButtonCode_playsoloButton1]
    }
    else if (buttonThatWasClicked == playmixButton1)
    {
        //[UserButtonCode_playmixButton1] -- add your button handler code here..
        //[/UserButtonCode_playmixButton1]
    }
    else if (buttonThatWasClicked == stopButton1)
    {
        //[UserButtonCode_stopButton1] -- add your button handler code here..
        //[/UserButtonCode_stopButton1]
    }
    else if (buttonThatWasClicked == loopToggle)
    {
        //[UserButtonCode_loopToggle] -- add your button handler code here..
        //[/UserButtonCode_loopToggle]
    }
    else if (buttonThatWasClicked == pauseButton1)
    {
        //[UserButtonCode_pauseButton1] -- add your button handler code here..
        //[/UserButtonCode_pauseButton1]
    }
    else if (buttonThatWasClicked == resumeButton1)
    {
        //[UserButtonCode_resumeButton1] -- add your button handler code here..
        //[/UserButtonCode_resumeButton1]
    }
    else if (buttonThatWasClicked == versionButton)
    {
        //[UserButtonCode_versionButton] -- add your button handler code here..
		pCom->getDeviceInfo();
        //[/UserButtonCode_versionButton]
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
  <GROUPCOMPONENT name="new group" id="2cf21ac44d719d93" memberName="groupComponent"
                  virtualName="" explicitFocusOrder="0" pos="416 24 360 160" title="Communications"/>
  <GROUPCOMPONENT name="new group" id="faf9d7977149782a" memberName="groupComponent2"
                  virtualName="" explicitFocusOrder="0" pos="24 24 360 160" title="WAV Trigger System Info"/>
  <SLIDER name="" id="a4b37bd1b46fdb64" memberName="volSlider" virtualName=""
          explicitFocusOrder="0" pos="33 488 159 81" min="-80" max="10"
          int="1" style="RotaryVerticalDrag" textBoxPos="TextBoxRight"
          textBoxEditable="1" textBoxWidth="50" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="" id="b3b1c85b4500968f" memberName="portBoxlabel3" virtualName=""
         explicitFocusOrder="0" pos="134 546 72 16" textCol="ff000000"
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
              explicitFocusOrder="0" pos="265 248 72 24" buttonText="Play Solo"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="" id="51f8f1f4d874a866" memberName="playmixButton1" virtualName=""
              explicitFocusOrder="0" pos="353 248 72 24" buttonText="Play Mix"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="" id="c902ffad93176b2c" memberName="stopButton1" virtualName=""
              explicitFocusOrder="0" pos="617 248 72 24" buttonText="Stop"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TOGGLEBUTTON name="" id="403473bc1f1cbd0b" memberName="loopToggle" virtualName=""
                explicitFocusOrder="0" pos="182 247 64 24" buttonText="Loop"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <TEXTBUTTON name="" id="4300c5f8bc94f310" memberName="pauseButton1" virtualName=""
              explicitFocusOrder="0" pos="441 248 72 24" buttonText="Pause"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="" id="9865d9baf642eb5f" memberName="resumeButton1" virtualName=""
              explicitFocusOrder="0" pos="529 248 72 24" buttonText="Resume"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTEDITOR name="" id="349bf31d6a377790" memberName="trigText1" virtualName=""
              explicitFocusOrder="0" pos="91 248 55 24" initialText="1" multiline="0"
              retKeyStartsLine="0" readonly="0" scrollbars="1" caret="1" popupmenu="1"/>
  <TEXTEDITOR name="" id="d897b478ba180688" memberName="versionText" virtualName=""
              explicitFocusOrder="0" pos="184 56 176 24" initialText="" multiline="0"
              retKeyStartsLine="0" readonly="0" scrollbars="1" caret="1" popupmenu="1"/>
  <TEXTBUTTON name="" id="5ec42bc6370231ba" memberName="versionButton" virtualName=""
              explicitFocusOrder="0" pos="48 136 63 24" buttonText="Get Info"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTEDITOR name="" id="ae4c7ab7b0e1ec37" memberName="numVoicesText" virtualName=""
              explicitFocusOrder="0" pos="320 96 41 24" initialText="" multiline="0"
              retKeyStartsLine="0" readonly="0" scrollbars="1" caret="1" popupmenu="1"/>
  <TEXTEDITOR name="" id="4b638d8174953262" memberName="numTracksText" virtualName=""
              explicitFocusOrder="0" pos="320 136 41 24" initialText="" multiline="0"
              retKeyStartsLine="0" readonly="0" scrollbars="1" caret="1" popupmenu="1"/>
  <GROUPCOMPONENT name="new group" id="69229fd352cbc9b2" memberName="groupComponent3"
                  virtualName="" explicitFocusOrder="0" pos="32 208 744 256" title="Track Control"/>
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
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
