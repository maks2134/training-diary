#include "traningHooks.h"
#include "createTraning.h"
#include "checkTraining.h"
#include "systemTech.h"
#include "adviceTraining.h"

void createTraning(){
    ClearConsole();
    write_training();
}

void reportTraining(){
    ClearConsole();
    checkTraining();
}

void adviceTraning(){
    ClearConsole();
    generate_advice();
}