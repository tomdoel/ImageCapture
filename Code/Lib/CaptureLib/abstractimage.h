#pragma once

namespace cl {

    class AbstractImage
    {
        public:
            virtual int width() const = 0;
            virtual int height() const = 0;
            virtual unsigned char* data() const = 0;
    };
}
