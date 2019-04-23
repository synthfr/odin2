#pragma once

#include "../Filters/VAOnePoleFilter.h"

class NoiseOscillator
{
public:
	NoiseOscillator();
	~NoiseOscillator();

	float doNoise();   

	void setFilterFreqs(float p_lowpass_freq, float p_highpass_freq);
	void setHPFreq(float p_freq);
	void setLPFreq(float p_freq);
	void setVolModPointer(float* p_pointer){
		m_vol_mod = p_pointer;
	}
	//inline void startOscillator(){
	//	m_note_on = true;
	//}
	
	//inline void stopOscillator(){
	//	m_note_on = false;
	//}

protected:

	float* m_vol_mod;

	VAOnePoleFilter m_lowpass;
	VAOnePoleFilter m_highpass;
};

