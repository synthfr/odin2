/*
  ==============================================================================

    NumberSelector.h
    Created: 1 Mar 2019 9:29:33pm
    Author:  frot

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "GlobalIncludes.h"
#include "GlasDisplay.h"
//==============================================================================
/*
*/
class NumberSelector : public Component
{
public:
  NumberSelector(bool p_buttons_right);
  ~NumberSelector();

  void paint(Graphics &) override;
  void resized() override;

  void setColor(juce::Colour p_color){
    m_display.setColor(p_color);
  }


  void setRange(int p_min, int p_max){
    m_min = p_min;
    m_max = p_max;
  }

  virtual void setValue(int p_value)
  {
    if(p_value >= m_min && p_value <= m_max){
      m_value = p_value;
      m_display.setText(std::to_string(m_value));
    }
  }

  void setTooltip(const String p_text){
    m_display.setTooltip(p_text);
  }

  //void mouseEnter (const MouseEvent&)     { 
  //  showTooltip();
  //}

protected:
  void increment()
  {
    setValue(m_value + 1);
  }

  void decrement()
  {
    setValue(m_value - 1);
  }

  GlasDisplay m_display;
  int m_min = 1;
  int m_max = 1;

  juce::DrawableButton m_up;
  juce::DrawableButton m_down;

  int m_value = 1;
  bool m_buttons_right;
  int m_display_width;
  JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(NumberSelector)
};