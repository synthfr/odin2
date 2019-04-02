#include "VectorOscillator.h"

VectorOscillator::VectorOscillator()
{
    m_nr_of_wavetables = 4;
}

VectorOscillator::~VectorOscillator()
{
}

void VectorOscillator::selectWavetable(int p_wavetable_index, int p_vector_point)
{
    if (p_wavetable_index < m_nr_of_wavetables)
    {
        //todo not the most beatiful solution
        switch (p_vector_point)
        {
        case 0:
            m_wavetable_index_0 = p_wavetable_index;
            break;
        case 1:
            m_wavetable_index_1 = p_wavetable_index;
            break;
        case 2:
            m_wavetable_index_2 = p_wavetable_index;
            break;
        case 3:
            m_wavetable_index_3 = p_wavetable_index;
            break;
        default:
            break;
        }
    }
}

float VectorOscillator::doOscillate()
{
    if (!m_note_on)
    {
        return 0.f;
    }
    return doVectortable();
}

void VectorOscillator::update()
{
    Oscillator::update();

    m_wavetable_inc = WAVETABLE_LENGTH * m_increment;
    m_sub_table_index = getTableIndex();

    m_current_table_vec_0 = m_wavetable_pointers[m_wavetable_index_0][m_sub_table_index];
    m_current_table_vec_1 = m_wavetable_pointers[m_wavetable_index_1][m_sub_table_index];
    m_current_table_vec_2 = m_wavetable_pointers[m_wavetable_index_2][m_sub_table_index];
    m_current_table_vec_3 = m_wavetable_pointers[m_wavetable_index_3][m_sub_table_index];
}

void VectorOscillator::loadWavetables()
{
    setWavetablePointer(0, WavetableContainer::getInstance().getWavetablePointers("ChiptuneTriangle"));
    setWavetablePointer(1, WavetableContainer::getInstance().getWavetablePointers("Saw"));
    setWavetablePointer(2, WavetableContainer::getInstance().getWavetablePointers("FatSaw"));
    setWavetablePointer(3, WavetableContainer::getInstance().getWavetablePointers("ChiptuneSkyline"));
}

float VectorOscillator::doVectortable()
{
    //prepare both sides and interpol value
    int read_index_trunc = (int) m_read_index;
    float fractional = m_read_index - (float)read_index_trunc;
    int read_index_next = read_index_trunc + 1 >= WAVETABLE_LENGTH ? 0 : read_index_trunc + 1;

    // do linear interpolation 
    float output_0 = linearInterpolation(m_current_table_vec_0[read_index_trunc], m_current_table_vec_0[read_index_next], fractional);
    float output_1 = linearInterpolation(m_current_table_vec_1[read_index_trunc], m_current_table_vec_1[read_index_next], fractional);
    float output_2 = linearInterpolation(m_current_table_vec_2[read_index_trunc], m_current_table_vec_2[read_index_next], fractional);
    float output_3 = linearInterpolation(m_current_table_vec_3[read_index_trunc], m_current_table_vec_3[read_index_next], fractional);

    // 1---2
    // |   |
    // 0---3

    //reuse 0 as "lower" and 1 as "upper"
    output_0 = (1.f - m_XY_pad_x) * output_0 + m_XY_pad_x * output_3;
    output_1 = (1.f - m_XY_pad_x) * output_1 + m_XY_pad_x * output_2;

    m_read_index += m_wavetable_inc;
    checkWrapIndex(m_read_index);

    //return interpolation between "upper" and "lower"
    return (1.f - m_XY_pad_y) * output_0 + m_XY_pad_y * output_1;
}