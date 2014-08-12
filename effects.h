#ifndef EFFECTS_H
#define EFFECTS_H

#include <QWidget>
#include <opencv2/core/core.hpp>        // Basic OpenCV structures (cv::Mat, Scalar)
#include <opencv2/imgproc/imgproc.hpp>  // Gaussian Blur
#include <opencv2/highgui/highgui.hpp>  // OpenCV window I/O

class effects : public QWidget
{
    Q_OBJECT
public:
    explicit effects(QWidget *parent = 0);

signals:

public slots:

};

using namespace cv;
void convert_to_grayscale(Mat frameReference, Mat& gray_image, int *delay);
void convert_to_bw(Mat &frameReference, int *delay);
void homogeneous_blur(Mat src, Mat &dst);
void gaussian_blur(Mat src, Mat &dst);

#endif // EFFECTS_H
