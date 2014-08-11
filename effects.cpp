#include "effects.h"

effects::effects(QWidget *parent) :
    QWidget(parent)
{
}
using namespace cv;
extern int bw_threshold;

void convert_to_grayscale(Mat frameReference, Mat& gray_image, int *delay){
    *delay = 35;
    cvtColor( frameReference, gray_image, CV_BGR2GRAY,0 );
}

void convert_to_bw(Mat &frameReference, int *delay){
    *delay = 35;
    for( int y = 0; y < frameReference.rows; y++ )
    {
        for( int x = 0; x < frameReference.cols; x++ )
        {

            Vec3b color = frameReference.at<Vec3b>(Point(x,y));
            // ... do something to the color ....
            int ave_rgb = ( color[0] + color [1] + color[2] )/ 3;
            if(ave_rgb > bw_threshold)
            {
                color[0] = 255;
                color[1] = 255;
                color[2] = 255;
            }
            else{
                color[0] = 0;
                color[1] = 0;
                color[2] = 0;
            }
            // set pixel
            frameReference.at<Vec3b>(Point(x,y)) = color;
        }
    }
}
