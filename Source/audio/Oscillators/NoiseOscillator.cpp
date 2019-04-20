#include "../JuceLibraryCode/JuceHeader.h"
#include "NoiseOscillator.h"
#include "stdlib.h"


NoiseOscillator::NoiseOscillator(){
    m_lowpass.m_freq_base = FILTER_FC_MAX;
    m_lowpass.setLP();
    
    m_highpass.m_freq_base = FILTER_FC_MIN;
    m_highpass.setHP();
}


NoiseOscillator::~NoiseOscillator(){}

float NoiseOscillator::doNoise(){
    //if(!m_note_on){
    //    return 0.f;
    //}

    m_lowpass.update();
    m_highpass.update();

    float white_noise = (float)rand();
	white_noise          = 2 * (white_noise / RAND_MAX) - 1;

    //do 2nd order like this?
    white_noise = m_lowpass.doFilter(white_noise);
    white_noise = m_highpass.doFilter(white_noise);
    return white_noise;

}   

void NoiseOscillator::setFilterFreqs(float p_lowpass_freq, float p_highpass_freq){
    m_lowpass.m_freq_base = p_lowpass_freq;
    m_highpass.m_freq_base = p_highpass_freq;
}

void NoiseOscillator::setHPFreq(float p_freq){
    m_highpass.m_freq_base = p_freq;
}

void NoiseOscillator::setLPFreq(float p_freq){
    m_lowpass.m_freq_base = p_freq;
}

