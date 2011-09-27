/**
 * @file    output.hpp
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

#ifndef POCKETSPHINX_OUTPUT_HPP
#define POCKETSPHINX_OUTPUT_HPP

#include <QObject>
#include <QList>

namespace Wintermute {
    namespace Voice {
        struct Synthesizer;
        struct SynthesizedVoice;

        typedef QList<Synthesizer*> SynthesizerList;
        typedef QList<SynthesizedVoice*> SynthesizedVoiceList;

        class SynthesizedVoice : public QObject {
            Q_OBJECT
            Q_PROPERTY(QString Locale READ locale WRITE setLocale)

            private:
                QString m_locale;

            public:
                Q_DISABLE_COPY(SynthesizedVoice)
                SynthesizedVoice(const QString& = QString::null);
                const QString locale() const;
                void setLocale(const QString&);
                static const SynthesizedVoice Null;
        };

        class Synthesizer : public QObject {
            Q_OBJECT
            Q_DISABLE_COPY(Synthesizer)
            Q_PROPERTY(SynthesizedVoice Voice READ voice WRITE setVoice)

            private:
                SynthesizedVoice m_voice;

            public:
                Synthesizer(const SynthesizedVoice& = SynthesizedVoice::Null);
                const SynthesizedVoice voice() const;
                void setVoice(const SynthesizedVoice&);
        };
    }
}

#endif // end POCKETSPHINX_OUTPUT_HPP
