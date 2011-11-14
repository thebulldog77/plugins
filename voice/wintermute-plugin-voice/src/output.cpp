/**
 * @file    output.cpp
 * @author  Wintermute Developers <wintermute-devel@lists.launchpad.net>
 *
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * Wintermute Linguistics is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Wintermute Linguistics; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor,
 * Boston, MA  02110-1301  USA
 */

#include "output.hpp"

namespace Wintermute {
    namespace Voice {
        SynthesizedVoice::SynthesizedVoice(const QString &p_lcl) : m_locale(p_lcl){ }

        SynthesizedVoice::SynthesizedVoice(const SynthesizedVoice &p_voice) : m_locale(p_voice.m_locale) { }

        SynthesizedVoice& SynthesizedVoice::operator = (const SynthesizedVoice& p_voice) { m_locale = p_voice.m_locale; }

        const QString SynthesizedVoice::locale () const { return m_locale; }

        void SynthesizedVoice::setLocale (const QString &p_locale) { m_locale = p_locale; }

        AbstractSynthesizer::AbstractSynthesizer(const AbstractSynthesizer &p_synth) : m_voice(p_synth.m_voice) { }

        AbstractSynthesizer::~AbstractSynthesizer () { }

        AbstractSynthesizer::AbstractSynthesizer(const SynthesizedVoice &p_voice) : m_voice(p_voice) { }

        const SynthesizedVoice AbstractSynthesizer::voice () const { return m_voice; }

        void AbstractSynthesizer::setVoice (const SynthesizedVoice &p_voice) {
            m_voice = p_voice;
            emit voiceChanged ();
            emit voiceChanged (m_voice);
        }
    }
}
