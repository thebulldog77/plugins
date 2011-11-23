/**
 * @file plugin.hpp
 *
 * Wintermute Linguistics is free software; you can redistribute it and/or modify
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

#ifndef SYNTHESIZER_HPP
#define SYNTHESIZER_HPP

#include <QObject>
#include <output.hpp>

using namespace Wintermute::Voice;

namespace Wintermute {
    namespace SpeechDispatcher {
        class Synthesizer : public AbstractSynthesizer {
            Q_OBJECT
            Q_DISABLE_COPY(Synthesizer)

            public:
                Synthesizer();
                explicit Synthesizer(const SynthesizedVoice& = SynthesizedVoice::Null);

            signals:

            public slots:

        };
    }
}

#endif // SYNTHESIZER_HPP
