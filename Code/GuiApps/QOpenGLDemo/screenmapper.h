#pragma once

#include <memory>

namespace capture {

    class OutputDisplayController;
    class ScreenController;

    class ScreenMapper
    {
        public:
            ScreenMapper(std::shared_ptr<OutputDisplayController>, std::shared_ptr<ScreenController>);
            void orderScreens();

        private:
            std::shared_ptr<OutputDisplayController> m_output_display_controller;
            std::shared_ptr<ScreenController> m_screen_controller;
    };
}
