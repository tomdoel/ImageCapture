#include "convert.h"
#include "image.h"

namespace cl {

    std::unique_ptr<Image> Convert::BGR2YCbCr(const Image& src)
    {
        std::unique_ptr<Image> out_image(new Image(src.width(), src.height()));

        unsigned char* const in_data_start = src.data();
        unsigned char* const out_data_start = out_image->data();
        int cols = src.width();
        int rows = src.height();
        int step = src.step();
        unsigned char* in_pixel = in_data_start;
        unsigned char* out_pixel = out_data_start;

        for (int row = 0; row < rows; row++) {
            in_pixel = in_data_start + row*step;
            out_pixel = out_data_start + row*step;

            for (int col = 0; col < cols; col++) {
                int R = in_pixel[0];
                int G = in_pixel[1];
                int B = in_pixel[2];

                out_pixel[0] = 0 + 0.299*R + 0.587*G + 0.114*B;
                out_pixel[1] = 128 - 0.169*R - 0.331*G + 0.5*B;
                out_pixel[2] = 128 + 0.5*R - 0.419*G - 0.081*B;

                in_pixel += 3;
                out_pixel += 3;
            }
        }

        return out_image;
    }

    std::unique_ptr<Image> Convert::YCbCr2BGR(const Image& src)
    {
        std::unique_ptr<Image> out_image(new Image(src.width(), src.height()));

        unsigned char* const in_data_start = src.data();
        unsigned char* const out_data_start = out_image->data();
        int cols = src.width();
        int rows = src.height();
        int step = src.step();
        unsigned char* in_pixel = in_data_start;
        unsigned char* out_pixel = out_data_start;

        for (int row = 0; row < rows; row++) {
            in_pixel = in_data_start + row*step;
            out_pixel = out_data_start + row*step;
            for (int col = 0; col < cols; col++) {
                int Y = in_pixel[0];
                int Cb = in_pixel[1];
                int Cr = in_pixel[2];

                out_pixel[0] = Y + 1.4*(Cr-128);
                out_pixel[1] = Y - 0.343*(Cb-128) - 0.711*(Cr-128);
                out_pixel[2] = Y + 1.765*(Cb-128);

                in_pixel += 3;
                out_pixel += 3;
            }
        }

        return out_image;
    }

}
