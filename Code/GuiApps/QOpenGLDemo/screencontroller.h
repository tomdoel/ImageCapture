#pragma once

#include <set>
#include <utility>

class QScreen;

namespace capture {
    class ScreenController
    {
        public:
            ScreenController();
            const std::pair<QScreen*, std::set<QScreen*> > getScreens() const;
    };
}
