#ifndef SCENEINFO_H
#define SCENEINFO_H

#include <vector>
namespace STG {

    class SceneInfo{
    public:
        double heroX;
        double heroY;
        double heroLife;
        std::vector<double> enemyX;
        std::vector<double> enemyY;
        std::vector<double> enemyHitR;
        std::vector<double> enemyLife;
    };

}

#endif // SCENEINFO_H
