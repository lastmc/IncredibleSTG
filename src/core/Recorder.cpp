#include "Recorder.h"
#include <QDir>

namespace STG {

    Recorder::Recorder(bool read):read(read){
        if(read){
            data.clear();
            file.setFileName("./record/record.txt");
            file.open(QIODevice::ReadOnly|QIODevice::Text);
            tS.setDevice(&file);
            while(!tS.atEnd()){
                int time;
                int keyUp,keyDown,keyLeft,keyRight,keyShift,keyZ;
                tS>>time>>keyUp>>keyDown>>keyLeft>>keyRight>>keyShift>>keyZ;
                data[time]=keyboardRecord(keyUp,keyDown,keyLeft,keyRight,keyShift,keyZ);
            }
            file.close();
        }
    }

    void Recorder::setRead(bool read){
        this->read=read;
        if(read){
            data.clear();
            file.setFileName("./record/record.txt");
            file.open(QIODevice::ReadOnly|QIODevice::Text);
            tS.setDevice(&file);
            while(!tS.atEnd()){
                int time;
                int keyUp,keyDown,keyLeft,keyRight,keyShift,keyZ;
                tS>>time>>keyUp>>keyDown>>keyLeft>>keyRight>>keyShift>>keyZ;
                data[time]=keyboardRecord(keyUp,keyDown,keyLeft,keyRight,keyShift,keyZ);
            }
            file.close();
        }
    }

    void Recorder::writeFrame(int time,keyboardRecord r){
        data[time]=r;
    }

    keyboardRecord Recorder::getFrame(int time){
        if(data.count(time)) return data[time];
        return keyboardRecord(0,0,0,0,0,0);
    }

    void Recorder::writeToFile(){
        file.setFileName("./record/record.txt");
        file.open(QIODevice::WriteOnly|QIODevice::Text);
        tS.setDevice(&file);
        for(auto t=data.begin();t!=data.end();t++){
            tS<<t.key()<<" "
             <<t.value().keyUp<<" "
            <<t.value().keyDown<<" "
            <<t.value().keyLeft<<" "
            <<t.value().keyRight<<" "
            <<t.value().keyShift<<" "
            <<t.value().keyZ<<"\n";
        }
        file.close();
    }

}
