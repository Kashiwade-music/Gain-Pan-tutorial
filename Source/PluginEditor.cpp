/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
GainPantutorialAudioProcessorEditor::GainPantutorialAudioProcessorEditor (
    GainPantutorialAudioProcessor& p, juce::AudioProcessorValueTreeState& vts)
    : AudioProcessorEditor (&p), audioProcessor (p), valueTreeState(vts)
{
    addAndMakeVisible(gainSlider);
    gainSliderAttachment.reset(new SliderAttachment(valueTreeState, "gain", gainSlider));
    addAndMakeVisible(panAngleSlider);
    panAngleSliderAttachment.reset(new SliderAttachment(valueTreeState, "panangle", panAngleSlider));
    addAndMakeVisible(panRuleBox);
    panRuleBoxAttachment.reset(new ComboBoxAttachment(valueTreeState, "panrule", panRuleBox));
    panRuleBox.addItemList(
        juce::StringArray("linear", "balanced", "sin3dB", "sin4.5dB", "sin6dB",
            "sqrt3dB", "sqrt4.5dB"),
        1);
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 300);
}

GainPantutorialAudioProcessorEditor::~GainPantutorialAudioProcessorEditor()
{
}

//==============================================================================
void GainPantutorialAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::white);
    g.setFont (15.0f);
    g.drawFittedText ("Hello World!", getLocalBounds(), juce::Justification::centred, 1);
}

void GainPantutorialAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    gainSlider.setBounds(10, 10, 200, 30);
    panAngleSlider.setBounds(10, 40, 200, 30);
    panRuleBox.setBounds(10, 70, 200, 30);

}
