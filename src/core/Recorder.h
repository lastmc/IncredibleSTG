#ifndef RECORDER_H
#define RECORDER_H

#include <QFile>
#include <QTextStream>
#include <QMap>

namespace STG {

    struct keyboardRecord{
        bool keyUp,keyDown,keyLeft,keyRight,keyShift,keyZ;
        keyboardRecord(bool keyUp=false,bool keyDown=false,bool keyLeft=false,bool keyRight=false,bool keyShift=false,bool keyZ=false):
           keyUp(keyUp),keyDown(keyDown),keyLeft(keyLeft),keyRight(keyRight),keyShift(keyShift),keyZ(keyZ){}
    };

    class Recorder{
    private:
        bool read;
        QMap<int,keyboardRecord> data;
        QFile file;
        QTextStream tS;
    public:
        Recorder(bool read=false);
        void setRead(bool read);
        void writeFrame(int time,keyboardRecord r);
        keyboardRecord getFrame(int time);
        void writeToFile();
    };

}

#endif // RECORDER_H
