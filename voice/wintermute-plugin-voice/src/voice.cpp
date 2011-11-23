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
        System* System::s_inst = NULL;

        System::System() : AbstractFramework(Factory::currentPlugin()), m_voices(), m_recogs() {
            s_inst = this;
        }

        System::~System () { }

        System* System::instance () {
            if (!s_inst)
                s_inst = new System;

            return s_inst;
        }

        void System::initialize() {
            emit s_inst->started ();
        }

        void System::deinitialize() {
            emit s_inst->stopped ();
        }
    }
}

