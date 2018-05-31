#pragma once

#include "abstractimage.h"
#include <memory>

namespace cl {

    class Image : public AbstractImage
    {
        public:
            Image(const int width, const int height);
            unsigned char* data() const;
            int width() const;
            int height() const;
            int step() const;

        private:
            int m_width;
            int m_height;
            int m_step;
            std::unique_ptr<unsigned char[]> m_data;
    };

}
