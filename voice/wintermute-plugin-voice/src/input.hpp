/**
 * @file    input.hpp
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

#ifndef POCKETSPHINX_INPUT_HPP
#define POCKETSPHINX_INPUT_HPP

#include <QObject>
#include <QThread>

namespace Wintermute {
    namespace Voice {
        struct AbstractRecognizer;

        typedef QList<AbstractRecognizer*> RecognizerList;

        class AbstractRecognizer : protected QThread {
            Q_OBJECT
            Q_DISABLE_COPY(AbstractRecognizer)

            signals:
                void textHeard(const QString&) const;

            public:
                AbstractRecognizer();
                virtual ~AbstractRecognizer();
                virtual const QString& waitToListen() const = 0;
                const bool isListening() const;

            protected:
                virtual void run () const = 0;

            public slots:
                virtual void beginListening() const = 0;
                virtual void stopListening(QString& ) const = 0;
        };
    }
}

#endif
