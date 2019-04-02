/*
  ==============================================================================

    AmpDistortionFlowComponent.h
    Created: 25 Feb 2019 8:09:19pm
    Author:  frot

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "GlobalIncludes.h"
#include "Knob.h"
#include "GlasDropdown.h"

#define AMP_GAIN_POS_X (400 - 275)
#define AMP_GAIN_POS_Y (222 - 175)
#define AMP_PAN_POS_X (465 - 275)
#define AMP_PAN_POS_Y (212 - 175)
#define AMP_VEL_POS_X (335 - 275)
#define AMP_VEL_POS_Y (212 - 175)
#define BIAS_POS_X (330 - 275)
#define BIAS_POS_Y (286 - 175)
#define THRESHOLD_POS_X (470 - 275)
#define THRESHOLD_POS_Y (286 - 175)
#define DISTORTION_POS_X 93
#define DISTORTION_POS_Y 87

#define FLOW_RIGHT_POS_X 0
#define FLOW_LEFT_POS_X 226
#define FLOW_POS_Y 2

#define DIST_ALGO_POS_X 92
#define DIST_ALGO_POS_Y 114

#define THRESHOLD_DEFAULT 0.7
#define DRYWET_DIST_DEFAULT 1
#define AMP_GAIN_MIN -20
#define AMP_GAIN_MAX 12
#define AMP_GAIN_DEFAULT 0
#define PAN_MIN -1
#define PAN_MAX 1
#define PAN_DEFAULT 0

//==============================================================================
/*
 */
class AmpDistortionFlowComponent : public Component {
public:
  AmpDistortionFlowComponent(AudioProcessorValueTreeState& vts);
  ~AmpDistortionFlowComponent();

  void paint(Graphics &) override {}
  void resized() override;

private:
  Knob m_amp_gain;
  Knob m_amp_pan;
  Knob m_amp_vel;
  Knob m_threshold;
  Knob m_dry_wet;

  juce::DrawableButton m_flow_left;
  juce::DrawableButton m_flow_right;
  juce::DrawableButton m_distortion;

  GlasDropdown m_distortion_algo;

  AudioProcessorValueTreeState& m_value_tree;

  std::unique_ptr<SliderAttachment> m_amp_pan_attach;
  std::unique_ptr<SliderAttachment> m_amp_gain_attach;
  std::unique_ptr<SliderAttachment> m_amp_vel_attach;
  std::unique_ptr<SliderAttachment> m_dist_threshold_attach;
  std::unique_ptr<SliderAttachment> m_dist_drywet_attach;

  std::unique_ptr<ButtonAttachment> m_dist_on_attach;
  std::unique_ptr<ButtonAttachment> m_fil1_to_amp_attach;
  std::unique_ptr<ButtonAttachment> m_fil2_to_amp_attach;

  std::unique_ptr<ComboBoxAttachment> m_dist_algo_attach;
  JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(AmpDistortionFlowComponent)
};