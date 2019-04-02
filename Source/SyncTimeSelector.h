/*
  ==============================================================================

    SyncTimeSelector.h
    Created: 6 Mar 2019 10:31:49pm
    Author:  frot

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "GlasDisplay.h"
#include "GlobalIncludes.h"


//==============================================================================
/*
 */
class SyncTimeSelector : public Component {
public:
  SyncTimeSelector();
  ~SyncTimeSelector();

  void setValueLeft(int p_value) {
    if (p_value < m_left_values.size() && p_value > 0) {
      m_value_left = p_value;
      updateDisplay();
    }
  }

  void setValueRight(int p_value) {
    if (p_value < m_right_values.size() && p_value > 0) {
      m_value_right = p_value;
      updateDisplay();
    }
  }

  void setTooltip(const String p_text) { m_display.setTooltip(p_text); }

private:
  void updateDisplay() {
    m_display.setText(m_left_values[m_value_left] + "/" +
                      m_right_values[m_value_right]);
  }

  void incrementLeft() {
    if (m_value_left + 1 < m_left_values.size()) {
      ++m_value_left;
      updateDisplay();
    }
  }

  void incrementRight() {
    if (m_value_right + 1 < m_right_values.size()) {
      ++m_value_right;
      updateDisplay();
    }
  }

  void decrementLeft() {
    if (m_value_left > 0) {
      --m_value_left;
      updateDisplay();
    }
  }

  void decrementRight() {
    if (m_value_right > 0) {
      --m_value_right;
      updateDisplay();
    }
  }

  std::vector<std::string> m_right_values = {"1",  "2",   "4",  "8",  "8T",
                                             "16", "16T", "32", "32T"};
  std::vector<std::string> m_left_values = {"1", "2", "3", "4",
                                            "5", "6", "7", "8"};

  GlasDisplay m_display;

  juce::DrawableButton m_up_left;
  juce::DrawableButton m_down_left;
  juce::DrawableButton m_up_right;
  juce::DrawableButton m_down_right;

  int m_value_left = 0;
  int m_value_right = 0;

  JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SyncTimeSelector)
};