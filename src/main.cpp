#include "../header/downVideoProcessor.hpp"
#include "../header/videoGroundTruthGenerator.hpp"
#include "../header/videoProcessor.hpp"

using namespace cv;
using namespace std;

int main(int argc, char *argv[]){
//VideoGroundTruthGenerator v("/home/mong/Desktop/robosub/opencv/sample videos/Pipe8xSpeed.avi");
//    v.processVideo();
//    v.writeResultToCSV("result/000Pipes_Result_Final.csv");
    cout << "unit test begin running" << endl;
    DownVideoProcessor v("/home/mong/Desktop/robosub/opencv/sample videos/Pipe32x.avi");
    v.loadExpectedValueFromCSV("/home/mong/Desktop/robosub/opencv/actual code/Robo_sub/result/000Pipes_Result_Final32x.csv");
    for(v.H_MIN = 0; v.H_MIN <= 20; v.H_MIN+=5){
        for(v.H_MAX = 40; v.H_MAX > v.H_MIN; v.H_MAX-=5){
            for(v.S_MIN = 0; v.S_MIN <= 225; v.S_MIN+=25){
                for(v.S_MAX = 255; v.S_MAX > v.S_MIN; v.S_MAX-=25){
                    for(v.V_MIN = 190; v.V_MIN < 250; v.V_MIN+=15){
                        for(v.V_MAX = 255; v.V_MAX > v.V_MIN; v.V_MAX-=15){
                            v.processVideo();
                            v.writeResultToCSV("/home/mong/Desktop/robosub/opencv/actual code/Robo_sub/result/000Pipes_Result_Final32x.csv");
                        }
                    }
                }
            }
        }
    }
//    VideoGroundTruthGenerator v("/home/mong/Desktop/robosub/opencv/sample videos/Pipe32x.avi");
//    v.processVideo();
//    v.writeResultToCSV("result/000Pipes_Result_Final32x.csv");



}
/**
h min 0-50
h max(which really controls the range of h)
s min
s max(which really controls the range of s)
v min
v max(which really controls the range of v)
erode & dilate size
erode & dilate repeats


**/


//int main(int argc, char *argv[]){
//    cout << "main.cpp running" << endl;
//    DownVideoProcessor v("/home/mong/Desktop/robosub/opencv/sample videos/Pipe.avi");
//    v.loadExpectedValueFromCSV("result/000Pipes_Result_Final.csv");
///**
//h min 160-50
//h max(which really controls the range of h)
//s min
//s max(which really controls the range of s)
//v min
//v max(which really controls the range of v)
//erode & dilate size
//erode & dilate repeats
//
//
//**/

//    int hBound = 180;
//    for(v.H_MIN = 160; v.H_MIN <= hBound; v.H_MIN++){
//        if(v.H_MIN >= 180){
//            v.H_MIN = 0;
//            hBound = 30;
//        }
//        for(v.H_MAX = 50; v.H_MAX >= 1; v.H_MAX--){
//            v.processVideo();
//            v.writeResultToCSV("result/000Pipes_Result_Final.csv");
//        }
//    }


//    VideoGroundTruthGenerator v("/home/mong/Desktop/robosub/opencv/sample videos/Pipe.avi");
//    v.processVideo();
//    v.writeResultToCSV("result/000Pipes_Result_Final.csv");

//    VideoProcessor v("/home/mong/Desktop/robosub/opencv/sample videos/Pipe.avi");
//    v.loadExpectedValue("result/Pipe_Data.txt");
//    int* old = v.expectedValues;
//    v.loadExpectedValueFromCSV("result/000Pipes_Result_Final.csv");
//    int* newE = v.expectedValues;
//    for(int i = 0; i < 4500; i++){
//        cout << i << ": " << (old[i] - newE[i]) << endl;
//    }





//
//struct RectSpecs {
////specifiy a type of data structure for the rectangle's specs
//    vector<vector<Point> > contour;
//    Point2f pXY;    Point2f cXY;
//    float width;    float height;       float angle;
//    double area;    float distance;     bool ignore;
//};
//
////set the saved result image's filename to record the result of different settings
//string settingTitle = "Default";
//string dataDir;
//
////UI key constant for visual debugging
//int ESCAPE = 1048603;
//int SPACE = 1048608;
//int RIGHT = 2555904;
//int LEFT = 2424832;
//
////Video file
//string videoFilePath = "../../sample videos/Pipe.avi";
//int videoFrameSize = 4964;
//int endVideoPos = 4964;    //500
//int expectedValue[4964];        //[videoFrameSize];
//
////expected value file
//string eVFilePath = "Pipe_Data.txt";
//int wrongContourNum = 0;
//
////values used for GUI manipulation
//int videoPos = 0; //1200  //1820
//bool isPaused = false;
//int slowMotionms = 1;   //1;   //200;
//
////set the resize ratio of the frames
//float resizeRatio = 1;
//
////predefined constant for identifying the orange color of pathmarker
//int H_MIN = 0;
//int H_MAX = 256;    //30
//int S_MIN = 0;
//int S_MAX = 256;
//int V_MIN = 0;//200;
//int V_MAX = 256;
//int erodeKernelSize = 11;
//Mat erodeDilateKernel = getStructuringElement( MORPH_RECT, Size(erodeKernelSize , erodeKernelSize));
//int erodeDilateRepeat;
//int ignoreRectDist = 10;
//int ignoreRectArea = 300;
//
////global objects used in main
//VideoCapture cap;
//Mat frame; //original one frame from video
//Mat hsvFrame; //segmented frame in hsv colorspace
//Mat binaryFrame; //black and white frame with white being the color of interest
//vector<vector<Point> > contours;
//vector<RectSpecs> pathMarkers;
//ofstream resultFile;
//ofstream dataFile;
//ifstream expectedValueFile;
////function header
//void drawPathMarkers(Mat&, vector<RectSpecs>);
//
//string convertInt(int number){
//    stringstream ss;//create a stringstream
//    ss << number;//add number to the stream
//    return ss.str();//return a string with the contents of the stream
//}
//
//int waitKeyTime = 30;
//void generateGUI(){
//    //create the windows
//    namedWindow( "Original", WINDOW_NORMAL );
//    namedWindow( "HSV", WINDOW_NORMAL );
//    namedWindow( "Binary", WINDOW_NORMAL );
//    namedWindow( "Playback", WINDOW_NORMAL );
//    namedWindow( "Control", WINDOW_NORMAL );
//    createTrackbar("Frame", "Playback", &videoPos, cap.get(CV_CAP_PROP_FRAME_COUNT));
//    createTrackbar("H min", "Control", &H_MIN, 180);
//    createTrackbar("H max", "Control", &H_MAX, 180);
//    createTrackbar("S min", "Control", &S_MIN, 255);
//    createTrackbar("S max", "Control", &S_MAX, 255);
//    createTrackbar("V min", "Control", &V_MIN, 255);
//    createTrackbar("V max", "Control", &V_MAX, 255);
//    createTrackbar("waitKeyTime", "Control", &waitKeyTime, 100);
//
//    //base width and height are derived from frame size, used to better position windows for debugging purpose
//    //resize the windows
//    int baseWidth, baseHeight;
//    baseWidth = (int)(cap.get(CV_CAP_PROP_FRAME_WIDTH)*0.8);
//    baseHeight = (int)(cap.get(CV_CAP_PROP_FRAME_HEIGHT)*0.8);
//    resizeWindow("Original", baseWidth, baseHeight);
//    resizeWindow("HSV", baseWidth, baseHeight);
//    resizeWindow("Binary", baseWidth, baseHeight);
//    resizeWindow("Playback", 800, 50);
//
//    //move the windows
//    moveWindow("Original", 0, 0);
//    moveWindow("HSV", baseWidth, 0);
//    moveWindow("Binary", baseWidth*2, 0);
//    moveWindow("Playback", 0, baseHeight+25);
//    moveWindow("Control", 800, baseHeight+25);
//}
//
//void updateGUI(){
//    //show the images in the windows
//    drawPathMarkers(frame, pathMarkers);
//    imshow("Original", frame);
//    imshow("HSV", hsvFrame);
//    imshow("Binary", binaryFrame);
//
//    //update time trackbar
//    if(cap.get(CV_CAP_PROP_POS_FRAMES)- videoPos != 1)
//    {
//        cap.set(CV_CAP_PROP_POS_FRAMES, videoPos);
//    }
//    else
//    {
//        videoPos++;
//        setTrackbarPos("Frame", "Playback", videoPos);
//    }
//}
//
//void SaveResult(){
//    //Open result file
//    if(!resultFile.is_open())
//    {
//        //Open the result text file
//        resultFile.open("Result.txt", ios_base::app);
//        //Create a data folder
//        dataDir = "Data-" + settingTitle;
//        string abc = "mkdir \"" + dataDir + "\"";
//        system((char*)abc.c_str());
//        //Create a data text file
//        abc = dataDir + "/Data-" + settingTitle + ".txt";
//        dataFile.open((char*)abc.c_str(), ios_base::app);
//    }
//
//    //save result images to jpg files for record
//    if (expectedValue[videoPos] != pathMarkers.size())        //every time the contour numbers don't match the expected value
//    {
//        imwrite(dataDir + "/" + convertInt(expectedValue[videoPos]) + " vs " + convertInt(pathMarkers.size()) + " at " + convertInt(videoPos) + " (" + settingTitle + ").jpg", frame);
//        wrongContourNum++;
//    }
//
//    //Save Result
//    dataFile << convertInt(pathMarkers.size()) << endl;
//
//    //Save Final Save Wrong Num Contour Results
//    if (videoPos == endVideoPos)
//    {
//        resultFile << settingTitle + " has wrong frames : " + convertInt(wrongContourNum) << endl;
//        wrongContourNum = 0;
//    }
//}
//
//void loadExpectedValue(){
//    //Open expected value file
//    expectedValueFile.open((char*)eVFilePath.c_str());
//    for (int j=0; j<=videoFrameSize; j++)
//        expectedValueFile >> expectedValue[j];
//}
//
//void setLabel(Mat im, string label, Point org){
//    int fontface = FONT_HERSHEY_SIMPLEX;
//    double scale = 0.4;
//    int thickness = 1;
//    int baseline = 0;
//    Size text = getTextSize(label, fontface, scale, thickness, &baseline);
//    rectangle(im, org + Point(0, baseline), org + Point(text.width, -text.height), CV_RGB(0,0,0), CV_FILLED);
//    putText(im, label, org, fontface, scale, CV_RGB(255,255,255), thickness, 8);
//}
//
//RectSpecs findRectSpec (vector<Point> rectContour){
//    //get the moments and centers of the contour
//    Moments mu = moments( rectContour, false );
//    Point2f cXY = Point2f(mu.m10/mu.m00, mu.m01/mu.m00);
//    cXY = Point2f(cXY.x / resizeRatio, cXY.y / resizeRatio);
//
//    //find the rotated rectangle & get its 4 vertices
//    RotatedRect minRect = minAreaRect( Mat(rectContour) );
//    Point2f rect_points[4];
//    minRect.points( rect_points );
//
//    //put the 4 vertices to create a contour for the minAreaRect
//    vector<Point> contr(4);
//    vector<vector<Point> > rectContours;
//    contr[0]=rect_points[0];
//    contr[1]=rect_points[1];
//    contr[2]=rect_points[2];
//    contr[3]=rect_points[3];
//    rectContours.push_back(contr);
//
//    //find the width & height of the rotated rectangle
//    float rectWidth = max(minRect.size.width,minRect.size.height) / resizeRatio ;
//    float rectHeight = min(minRect.size.width,minRect.size.height) / resizeRatio ;
//
//    //find the midpoints of the 4 sides of the rectangle
//    Point2f mp1 = Point2f((rect_points[0].x + rect_points[1].x) / 2, (rect_points[0].y + rect_points[1].y) / 2);
//    Point2f mp2 = Point2f((rect_points[2].x + rect_points[3].x) / 2, (rect_points[2].y + rect_points[3].y) / 2);
//    Point2f mp3 = Point2f((rect_points[1].x + rect_points[2].x) / 2, (rect_points[1].y + rect_points[2].y) / 2);
//    Point2f mp4 = Point2f((rect_points[3].x + rect_points[0].x) / 2, (rect_points[3].y + rect_points[0].y) / 2);
//
//    //compare the midpoints to find the one that will be used to calculate the angle of the rectangle
//    Point2f pXY;
//    if (sqrt(pow(mp2.y-mp1.y,2.0)+pow(mp2.x-mp1.x,2.0)) > sqrt(pow(mp4.y-mp3.y,2.0)+pow(mp4.x-mp3.x,2.0)))
//    {
//        if (mp1.y < mp2.y)
//            pXY = mp1;
//        else
//            pXY = mp2;
//    }
//    else
//    {
//        if (mp3.y<mp4.y)
//            pXY = mp3;
//        else
//            pXY = mp4;
//    }
//
//    //calculate the angle & add 180 degrees to any negative results caused by obtuse angle
//    float rectAngle = int(atan((cXY.y-pXY.y)/(pXY.x-cXY.x))*180/M_PI);
//    if (rectAngle < 0 )
//        rectAngle = rectAngle + 180;
//
//    //find the min distance of the contour to sides of the frame
//    float dst = max(frame.cols,frame.rows);
//    for (int j=0;j<4;j++)
//    {
//        if ( (rect_points[j].x - 0) < dst )
//            dst =rect_points[j].x - 0;
//        if ( (rect_points[j].y - 0) < dst )
//            dst =rect_points[j].y - 0;
//        if ( (frame.cols - rect_points[j].x) < dst )
//            dst =frame.cols - rect_points[j].x;
//        if ( (frame.rows - rect_points[j].y) < dst )
//            dst =frame.rows - rect_points[j].y;
//    }
//
//    //put all specs to a "rectSpecs" data structure
//    RectSpecs my_rect;
//    my_rect.contour = rectContours;
//    my_rect.width = rectWidth;
//    my_rect.height = rectHeight;
//    my_rect.area = contourArea(rectContours[0],false);
//    my_rect.angle = rectAngle;
//    my_rect.distance = dst;
//    my_rect.pXY = pXY;
//    my_rect.cXY = cXY;
//
//    //set to ignore the contour as a pathMarker
//    //if it's not near by the frame & the area of the contour is small
////    if (dst > ignoreRectDist && my_rect.area < ignoreRectArea)
////        my_rect.ignore = true;
////    else
////        my_rect.ignore = false;
//
//    //return the rectSpecs
//    return my_rect;
//}
//
//void drawPathMarkers(Mat &frame, vector<RectSpecs> pathMarkers){
//    for(int i = 0; i < pathMarkers.size(); i++)
//    {
//        //draw the rotated rectangle
//        drawContours(frame, pathMarkers[i].contour, -1, Scalar(0,0,255), 2);
//        //draw a small dot on the center
//        circle(frame, pathMarkers[i].cXY, 7, Scalar(0, 0, 255), -1);
//        //draw the horizontal line & angle line
//        line(frame, pathMarkers[i].pXY, pathMarkers[i].cXY, Scalar(0, 0, 255), 2, 8 );
//        line(frame, pathMarkers[i].cXY, Point2f(pathMarkers[i].cXY.x + 100,pathMarkers[i].cXY.y), Scalar(0, 0, 255), 2, 8 );
//        //note the center coordinates, width, height & angle of the rectangle
//        int textPosX = pathMarkers[i].cXY.x * resizeRatio + 10;
//        int textPosY = pathMarkers[i].cXY.y * resizeRatio + 20;
//        setLabel(frame, "Center: (" + convertInt(pathMarkers[i].cXY.x) + " , " + convertInt(pathMarkers[i].cXY.y) + ")", Point(textPosX,textPosY));
//        setLabel(frame, "Width: " + convertInt(pathMarkers[i].width) + " , Height: " + convertInt(pathMarkers[i].height) , Point(textPosX,textPosY+20));
//        setLabel(frame, "Angle (horizontal): " + convertInt(pathMarkers[i].angle) + " degrees", Point(textPosX,textPosY+40));
//        setLabel(frame, "Angle (to turn): " + convertInt(90-pathMarkers[i].angle) + " degrees", Point(textPosX,textPosY+60));
//        setLabel(frame, "Area: " + convertInt(pathMarkers[i].area), Point(textPosX,textPosY+80));
//        setLabel(frame, "Min distance to frame: " + convertInt(pathMarkers[i].distance), Point(textPosX,textPosY+100));
//    }
//}
//
//void processFrame(Mat &unprocessedFrame, Scalar lowerBoundHSV, Scalar upperBoundHSV, Mat &hsvFrame, Mat &binaryFrame, Mat &erodeDilateKernel, int erodeDilateRepeat, vector<vector<Point> > &unprocessedContours, vector<RectSpecs> &pathMarkers){
//    //resize the frame
//    //resize(frame,frame,Size(frame.cols * resizeRatio , frame.rows * resizeRatio ));
//    cvtColor(unprocessedFrame, hsvFrame, CV_BGR2HSV);
//    //special case for red in which the lower bound's hue is numerically higher than upper bound's hue, eg, 170 - 10
//    if(lowerBoundHSV[0] > upperBoundHSV[0]){
//        Mat temp;
//        inRange(hsvFrame,lowerBoundHSV,Scalar(180, upperBoundHSV[1], upperBoundHSV[2]),binaryFrame);
//        inRange(hsvFrame,Scalar(0, lowerBoundHSV[1], lowerBoundHSV[2]),upperBoundHSV,temp);
//        bitwise_or(temp, binaryFrame, binaryFrame);
//    }
//    else{
//        inRange(hsvFrame,lowerBoundHSV,upperBoundHSV,binaryFrame);
//    }
//
//    //repeat "erodeDilateRepeat" many times of eroding and dilating
//    for(int i = 0; i < erodeDilateRepeat; i++){
//        erode(binaryFrame, binaryFrame, erodeDilateKernel);
//        dilate(binaryFrame, binaryFrame, erodeDilateKernel);
//    }
//    findContours(binaryFrame.clone(), contours, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_SIMPLE);
//    pathMarkers.clear();
//    for(int i = 0; i < unprocessedContours.size(); i++)
//    {
//        vector<Point> pathMarker(4);
//        RectSpecs pathMarkerSpecs = findRectSpec(unprocessedContours[i]);
//        pathMarkers.push_back(pathMarkerSpecs);
//    }
//}
//
//void processVideo(){
//    cap =  VideoCapture(videoFilePath);     //input video file or from camera
//    if(!cap.isOpened()) {return;}
//    //open csv file to write to
//    ofstream cvsResultFile;
//    cvsResultFile.open("Pipes.cvs", ios::app);
//    int result[4964];
//    generateGUI();
//    int inputKey = -1;
//    int iii = 0;
//    //using read instead of >> operator because read return false if reached the end
//    while(cap.read(frame) && inputKey != ESCAPE && videoPos < endVideoPos){
//        processFrame(frame, Scalar(H_MIN,S_MIN,V_MIN),Scalar(H_MAX,S_MAX,V_MAX), hsvFrame, binaryFrame, erodeDilateKernel, erodeDilateRepeat, contours, pathMarkers);
//        updateGUI();
//        inputKey = waitKey(waitKeyTime);
//        if(inputKey == SPACE){//space key pressed, then video enter paused state
//            do{
//                inputKey = waitKey(0);
//                if(inputKey == RIGHT){//right key
//                    processFrame(frame, Scalar(H_MIN,S_MIN,V_MIN),Scalar(H_MAX,S_MAX,V_MAX), hsvFrame, binaryFrame, erodeDilateKernel, erodeDilateRepeat, contours, pathMarkers);
//                    updateGUI();
//                }else if(inputKey == LEFT && videoPos >= 0){
//                    videoPos--;
//                    processFrame(frame, Scalar(H_MIN,S_MIN,V_MIN),Scalar(H_MAX,S_MAX,V_MAX), hsvFrame, binaryFrame, erodeDilateKernel, erodeDilateRepeat, contours, pathMarkers);
//                    updateGUI();
//                }
//            }while(inputKey != SPACE && inputKey != ESCAPE);//space key pressed again to resume
//        }
//        result[iii] = pathMarkers.size();
//        iii++;
//    }
//    stringstream resultCVSString;
//        for(int i = 0; i < 4964; i++)
//            resultCVSString << "," << result[i];
//    cout << resultCVSString.str() << endl;
//    cvsResultFile << "H_MIN=" << H_MIN << ";H_MAX=" <<H_MAX << ";S_MIN=" <<
//    S_MIN<< ";S_MAX=" << S_MAX<<";V_MIN=" <<V_MIN<<";V_MAX="<<V_MAX<< ";erodeKernelSize="<<erodeKernelSize<<resultCVSString.str()<<endl;
//}
//
//int main(int argc, char *argv[]){
//    H_MIN = 0;
//    H_MAX = 30;
//    S_MIN = 0;
//    S_MAX = 255;
//    V_MIN = 200;
//    V_MAX = 255;
//    for(int i = 1; i < 4; i++)
//    {
//        erodeDilateRepeat = i;
//        processVideo();
//    }
//
//}
//
//
//
//
//
//
//
//
////each run takes around 345 seconds = 5.6 min


