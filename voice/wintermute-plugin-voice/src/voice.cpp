/**
 * @file    voice.cpp
 * @author  Wintermute Developers <wintermute-devel@lists.launchpad.net>
 *
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

#include "input.hpp"
#include "output.hpp"
#include "voice.hpp"
#include <wntr/plugins.hpp>

using Wintermute::Plugins::Factory;

namespace Wintermute {
    namespace Voice {
        const SynthesizedVoice SynthesizedVoice::Null = SynthesizedVoice();
        Framework* Framework::s_inst = NULL;

        Framework::Framework() : AbstractFramework(Factory::currentPlugin()), m_voices(), m_recogs() {
            s_inst = this;
        }

        Framework::~Framework () { }

        Framework* Framework::instance () {
            if (!s_inst)
                s_inst = new Framework;

            return s_inst;
        }

        void Framework::start() {
            AbstractFramework::start();
            foreach (Backends::AbstractBackend* l_bcknd, this->defaultBackend())
                l_bcknd->start();
        }

        void Framework::stop() {

        }

        void Framework::initialize() {
            start();
            emit s_inst->started ();
        }

        void Framework::deinitialize() {
            stop();
            emit s_inst->stopped ();
        }
    }
}

