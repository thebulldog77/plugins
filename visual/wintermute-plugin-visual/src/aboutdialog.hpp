/**
 * @file    aboutdialog.hpp
 * @author  Wintermute Developers <wintermute-devel@lists.launchpad.net>
 * @date 8/23/2011
 *
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

#ifndef ABOUTDIALOG_HPP
#define ABOUTDIALOG_HPP

#include <QtGui/QDialog>

namespace Ui { class AboutDialog; } //forward decl.

namespace Wintermute {
    namespace Visual {
        class AboutDialog : public QDialog {
            Q_OBJECT

            public:
                explicit AboutDialog(QWidget *parent = 0);
                ~AboutDialog();

            protected:
                void changeEvent(QEvent *e);

            private:
                Ui::AboutDialog *ui;
        };
    }
}

#endif // ABOUTDIALOG_HPP
// kate: indent-mode cstyle; space-indent on; indent-width 4;
