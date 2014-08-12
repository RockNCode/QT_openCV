#include "effects.h"

effects::effects(QWidget *parent) :
    QWidget(parent)
{
}
using namespace cv;
extern int bw_threshold;

int DELAY_CAPTION = 1500;
int DELAY_BLUR = 100;
int MAX_KERNEL_LENGTH = 15;

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

void homogeneous_blur(Mat src, Mat &dst){
    for ( int i = 1; i < MAX_KERNEL_LENGTH; i = i + 2 ){
        blur( src, dst, Size( i, i ), Point(-1,-1) );
    }
}

void gaussian_blur(Mat src, Mat &dst){
    for ( int i = 1; i < MAX_KERNEL_LENGTH; i = i + 2 )
    {
        GaussianBlur( src, dst, Size( i, i ), 0, 0 );
    }
}
