/**
 * @file sphinx.hpp
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

#ifndef SPEECHD_PLUGIN_SPHINX_HPP
#define SPEECHD_PLUGIN_SPHINX_HPP

/// @bug This shouldn't be defined here; it should be done via command-line. But I'm not sure how we can get pkg-config to do that in a digressible manner.
#define MODELDIR "/usr/share/speechd/model"

#include <input.hpp>
#include <pocketsphinx.h>

namespace Wintermute {
    namespace Voice {
        struct SphinxRecognizer;

        class SphinxRecognizer : public AbstractRecognizer {
            Q_OBJECT
            Q_DISABLE_COPY(SphinxRecognizer)

            public:
                SphinxRecognizer();
                virtual~SphinxRecognizer();
                virtual const QString& waitToListen () const;

            private:
                mutable ps_decoder_t* ps;
                mutable cmd_ln_t* config;
                void initialize() const;
                void deinitialize() const;
                virtual void run() const;

            public slots:
                virtual void beginListening () const;
                virtual void stopListening (QString&) const;
        };
    }
}

#endif // end SPEECHD_PLUGIN_SPHINX_HPP
