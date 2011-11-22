/**
 * @file    output.hpp
 * @author  Wintermute Developers <wintermute-devel@lists.launchpad.net>
 *
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
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

#ifndef SPEECHD_OUTPUT_HPP
#define SPEECHD_OUTPUT_HPP

#include <QList>
#include <QThread>

namespace Wintermute {
    namespace Voice {
        struct AbstractSynthesizer;
        struct SynthesizedVoice;

        /**
         * @brief Represents a list of Synthesizer objects.
         * @typedef SynthesizerList
         */
        typedef QList<AbstractSynthesizer*> SynthesizerList;
        /**
         * @brief Represents a list of Synthesizer voices.
         * @typedef SynthesizedVoiceList
         */
        typedef QList<SynthesizedVoice*> SynthesizedVoicesList;

        /**
         * @brief Represents a voice for a Synthesizer.
         * @class SynthesizedVoice output.hpp "src/output.hpp"
         */
        class SynthesizedVoice : public QObject {
            Q_OBJECT
            Q_PROPERTY(QString Locale READ locale WRITE setLocale)

            private:
                QString m_locale; /**< TODO */

            public:
                Q_DISABLE_COPY(SynthesizedVoice)
                /**
                 * @brief Default constructor.
                 * @fn SynthesizedVoice
                 * @param locale
                 */
                SynthesizedVoice(const QString& = QString::null);
                
                /**
                 * @brief Obtains the locale encapsulated by this voice.
                 * @fn locale
                 */
                const QString locale() const;
                
                /**
                 * @brief Changes the locale captured by this voice.
                 * @fn setLocale
                 * @param locale
                 */
                void setLocale(const QString&);
                static const SynthesizedVoice Null; /**< TODO */
        };

        /**
         * @brief Represents an object that can produce an audio stream basedon text.
         * @class Synthesizer output.hpp "src/output.hpp"
         */
        class AbstractSynthesizer : protected QThread {
            Q_OBJECT
            Q_DISABLE_COPY(AbstractSynthesizer)
            Q_PROPERTY(SynthesizedVoice Voice READ voice WRITE setVoice)

            signals:
                /**
                 * @brief Emits when speaking has completed.
                 * @fn speakingStopped
                 */
                void speakingStopped();
                
                /**
                 * @brief Emits when speaking has started.
                 * @fn speakingStarted
                 */
                void speakingStarted();
                
                /**
                 * @brief Emits when the voice changes.
                 * @fn voiceChanged
                 */
                void voiceChanged();
                
                /**
                 * @brief 
                 * @fn voiceChanged
                 * @param p_voice
                 */
                void voiceChanged(const SynthesizedVoice&);

            protected:
                SynthesizedVoice m_voice; /**< TODO */
                
                /**
                 * @brief 
                 * @fn run
                 */
                virtual void run() = 0;

            public:
                /**
                 * @brief
                 * @fn Synthesizer
                 * @param
                 */
                AbstractSynthesizer(const SynthesizedVoice& = SynthesizedVoice::Null);
                /**
                 * @brief
                 * @fn ~Synthesizer
                 */
                virtual ~AbstractSynthesizer();
                /**
                 * @brief
                 * @fn voice
                 */
                const SynthesizedVoice voice() const;
                /**
                 * @brief
                 *
                 * @fn setVoice
                 * @param
                 */
                void setVoice(const SynthesizedVoice&);
                /**
                 * @brief
                 *
                 * @fn waitWhileSpeaking
                 * @param
                 */
                virtual void waitWhileSpeaking(const QString&) const = 0;
                /**
                 * @brief
                 *
                 * @fn beginSpeaking
                 * @param
                 */
                virtual void beginSpeaking(const QString&) const = 0;
                /**
                 * @brief
                 *
                 * @fn stopSpeaking
                 */
                virtual void stopSpeaking() const = 0;
        };
    }
}

#endif // end SPEECHD_OUTPUT_HPP
