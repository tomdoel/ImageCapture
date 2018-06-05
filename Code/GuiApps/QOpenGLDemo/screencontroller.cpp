#include "screencontroller.h"

#include <QList>
#include <QScreen>
#include <QSet>
#include <QGuiApplication>
#include <set>

namespace capture {
    ScreenController::ScreenController() {
    }

    const std::pair<QScreen*, std::set<QScreen*> > ScreenController::getScreens() const {
        QList<QScreen*> screens = QGuiApplication::screens();
        QScreen* primary = QGuiApplication::primaryScreen();
        screens.removeAll(primary);
        std::list<QScreen*> screen_list = screens.toStdList();
        std::set<QScreen*> screen_set = std::set<QScreen*>(screen_list.begin(), screen_list.end());
        return std::pair<QScreen*, std::set<QScreen*> >(primary, screen_set);
    }
}
