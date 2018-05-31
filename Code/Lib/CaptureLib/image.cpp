#include "image.h"

namespace cl {
    Image::Image(const int width, const int height):
        m_width(width), m_height(height), m_step(width) {
        int array_size = m_step*m_height;
        m_data = std::unique_ptr<unsigned char[]>(new unsigned char[array_size]());
    }

    unsigned char* Image::data() const{
        return m_data.get();
    }

    int Image::width() const {
        return m_width;
    }

    int Image::height() const {
        return m_height;
    }

    int Image::step() const {
        return m_step;
    }
}
