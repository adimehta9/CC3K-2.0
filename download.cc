#include "download.h"

Download::Download() { }

void Download::useAbility(Player & p){
    if(p.getAb()->getType() == 'V'){
        p.incVirus();
    } else{
        p.incData();
    }
    p.getAb()->kill();
    p.getAb()->setC('.');
}