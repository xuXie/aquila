/**
 * @file SineSynthesizer.cpp
 *
 * Simple sine tone synthesis.
 *
 * This file is part of the Aquila DSP library.
 * Aquila is free software, licensed under the MIT/X11 License. A copy of
 * the license is provided with the library in the LICENSE file.
 *
 * @package Aquila
 * @version 3.0.0-dev
 * @author Zbigniew Siciarz
 * @date 2007-2013
 * @license http://www.opensource.org/licenses/mit-license.php MIT
 * @since 3.0.0
 */

#include "SineSynthesizer.h"
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <cstddef>

namespace Aquila
{
    /**
     * Plays a tone at given frequency.
     *
     * @param note frequency of the generated sound
     * @param duration beep duration in milliseconds
     */
    void SineSynthesizer::playFrequency(FrequencyType frequency,
                                        unsigned int duration)
    {
        std::size_t numSamples = static_cast<std::size_t>(m_sampleFrequency * duration / 1000);
        m_generator.setFrequency(frequency).generate(numSamples);
        m_buffer.LoadFromSignalSource(m_generator);
        sf::Sound sound(m_buffer);
        sound.Play();
        // the additional 50 ms is an intentional pause between tones
        sf::Sleep(duration / 1000.0f + 0.05f);
    }
}
