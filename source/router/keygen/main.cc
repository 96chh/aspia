//
// Aspia Project
// Copyright (C) 2020 Dmitry Chapyshev <dmitry@aspia.ru>
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program. If not, see <https://www.gnu.org/licenses/>.
//

#include "build/version.h"
#include "qt_base/application.h"
#include "router/keygen/main_window.h"

#if defined(QT_STATIC)

#include <QtPlugin>

#if defined(Q_OS_WIN)
Q_IMPORT_PLUGIN(QWindowsIntegrationPlugin);
Q_IMPORT_PLUGIN(QWindowsVistaStylePlugin);
#else
#error Platform support needed
#endif // defined(Q_OS_WIN)
#endif // defined(QT_STATIC)

int main(int argc, char *argv[])
{
    qt_base::Application application(argc, argv);

    qt_base::Application::setOrganizationName(QLatin1String("Aspia"));
    qt_base::Application::setApplicationName(QLatin1String("Keygen"));
    qt_base::Application::setApplicationVersion(QLatin1String(ASPIA_VERSION_STRING));
    qt_base::Application::setAttribute(Qt::AA_DisableWindowContextHelpButton, true);

    router::MainWindow main_window;
    main_window.show();
    main_window.activateWindow();

    return qt_base::Application::exec();
}
