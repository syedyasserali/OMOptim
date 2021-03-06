#ifndef MODPLUSOMEXECTRL_H
#define MODPLUSOMEXECTRL_H

#include "ModPlusExeCtrl.h"

class Project;
class ModelPlus;
class ModPlusCtrl;
class QString;
class QDir;



class ModPlusOMExeCtrl: public ModPlusExeCtrl
{
public:
    ModPlusOMExeCtrl(Project* project,ModelPlus* model);
    ~ModPlusOMExeCtrl(void);

    ModPlusCtrl *clone();


    QString name();
    bool useMat();
    QString resFile();
    QString resMatFile();
    QString resCsvFile();
    ModPlusCtrl::Type type() const;

    virtual bool readInitialVariables(MOVector<Variable> *, QFileInfoList filesToCopy,bool forcerecompile, QString initFile="");

    bool simulate(QDir tempFolder, MOVector<Variable> *inputVars, MOVector<Variable> *outputVars, QFileInfoList filesToCopy, QFileInfoList moDependencies);
    bool start(QString exeFile,int maxnsec);
    bool readOutputVariables(MOVector<Variable> *,QString resFile="");

    bool setStopTime(double time);
};

#endif // MODPLUSOMEXECTRL_H
