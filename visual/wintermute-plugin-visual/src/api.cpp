/*
 * @file api.cpp
 * This file is part of Wintermute Visual
 *
 * Copyright (C) 2011 - Jacky Alcine
 *
 * Wintermute Visual is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * Wintermute Visual is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */

#include "api.hpp"
#include "aboutdialog.hpp"

#include <QDebug>
#include <wntr/core.hpp>
#include <wntr/plugins.hpp>

using Wintermute::Plugins::Factory;

namespace Wintermute {
    namespace Visual {
        Framework* Framework::s_inst = 0;

        Framework::Framework(QObject *p_prnt) : AbstractFramework(Factory::currentPlugin(),p_prnt) {

        }

        void Framework::initialize() {
            qDebug() << "(Visual) [Visual] Starting backends..";

            foreach (AbstractBackend* l_bcknd, this->m_bckndLst.values())
                l_bcknd->start();

            qDebug() << "(Visual) [Visual] Backends started.";
        }

        void Framework::deinitialize() {
            qDebug() << "(Visual) [Visual] Stopping backends..";
            foreach (AbstractBackend* l_bcknd, this->m_bckndLst.values())
                l_bcknd->stop();
            qDebug() << "(Visual) [Visual] Backends stopped..";
        }

        void Framework::showAboutDialog() {
            AboutDialog* l_abtDlg = new AboutDialog;
            l_abtDlg->exec();
        }

        void Framework::sendResponse(const QString &p_str) {
            emit instance()->responseDisplayed(p_str);
        }

        void Framework::displayAlert(const AlertLevel &p_lvl, const QString &p_str) {
            emit instance()->alertDisplayed(p_lvl,p_str);
        }

        Framework* Framework::instance() {
            if (!s_inst)
                s_inst = new Framework(Core::instance());

            return s_inst;
        }

        Framework::~Framework() { }
    }
}
