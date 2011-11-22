/**
 * @file    aboutdialog.cpp
 * @author  Wintermute Developers <wintermute-devel@lists.launchpad.net>
 * @date    8/23/2011 12:48 AM
 *
 * Copyright (C) 2011 by Wintermute Developers <wintermute-devel@lists.launchpad.net>
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

#include "aboutdialog.hpp"
#include "ui_aboutdialog.h"

namespace Wintermute {
    namespace Graphics {
        AboutDialog::AboutDialog(QWidget *parent) : QDialog(parent),
            ui(new Ui::AboutDialog) {
            ui->setupUi(this);
        }

        AboutDialog::~AboutDialog() { delete ui; }

        void AboutDialog::changeEvent(QEvent *e) {
            QDialog::changeEvent(e);
            switch (e->type()) {
            case QEvent::LanguageChange:
                ui->retranslateUi(this);
                break;
            default:
                break;
            }
        }
    }
}
// kate: indent-mode cstyle; space-indent on; indent-width 4;
