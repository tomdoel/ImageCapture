#pragma once

#include <memory>

#include "image.h"

namespace cl {

    class Convert
    {
        public:
            static std::unique_ptr<Image> BGR2YCbCr(const Image& src);
            static std::unique_ptr<Image> YCbCr2BGR(const Image& src);
        private:
            Convert();
    };

}
