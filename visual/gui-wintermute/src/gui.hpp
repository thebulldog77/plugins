/**
 * wntrgui.hpp
 * This file is part of Wintermute Graphics.
 *
 * Copyright (C) 2011 - Wintermute Developers <wintermute-devel@lists.launchpad.net>
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

#ifndef GUI_HPP
#define GUI_HPP

#include <QObject>
#include <QThread>
#include "mainwindow.hpp"

namespace Wintermute {
    namespace Graphics {
        struct Core;

        /**
         * @brief
         *
         * @class Core gui.hpp "gui/gui.hpp"
         */
        class Core : public QObject {
            Q_OBJECT
            public:
                /**
                 * @brief
                 *
                 * @fn Initialize
                 */
                static void start();
                /**
                 * @brief
                 *
                 * @fn Deinitialize
                 */
                static void stop();

            private:
                static MainWindow* s_wndw;
        };
    }
}

#endif /** GUI_HPP */

// kate: indent-mode cstyle; space-indent on; indent-width 4;
