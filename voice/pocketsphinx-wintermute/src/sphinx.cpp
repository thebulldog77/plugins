/**
 * @file sphinx.cpp
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

#include "sphinx.hpp"
#include <QDebug>

 namespace Wintermute {
    namespace Voice {
        SphinxRecognizer::SphinxRecognizer() : AbstractRecognizer() {

        }

        SphinxRecognizer::~SphinxRecognizer() {

        }

        void SphinxRecognizer::initialize() const {
            config = cmd_ln_init (NULL,ps_args(),TRUE,
                                  "-hmm" , MODELDIR "/hmm/en_US/hub4wsj_sc_8k",
                                  "-lm"  , MODELDIR "/lm/en/turtle.DMP",
                                  "-dict", MODELDIR "/lm/en/turtle.dic",
                                  NULL);

            if (config == NULL){
                qDebug() << "(voice) [PocketSphinx] Unable to load configuration.";
                return;
            }

            ps = ps_init (config);

            if (ps == NULL){
                qDebug() << "(voice) [PocketSphinx] Unable to initialize decoder.";
                return;
            }
        }

        void SphinxRecognizer::run () const {

        }

        void SphinxRecognizer::beginListening () const {

        }

        void SphinxRecognizer::stopListening (QString& p_str) const {

        }

        const QString& SphinxRecognizer::waitToListen () const{
            initialize ();
        }
    }
 }

