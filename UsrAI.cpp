#include "UsrAI.h"
#include<set>
#include <iostream>
#include<unordered_map>
using namespace std;
tagGame tagUsrGame;
ins UsrIns;
//
//

tagInfo info;

void UsrAI::processData()
{
    info = getInfo();
    for (tagBuilding& building : info.buildings) {
    //如果市镇中心空闲，且有足够的食物，且农民数量小于人口上限，则生产农民
    if (building.Type == BUILDING_CENTER && building.Project == 0 &&
        info.Meat >= BUILDING_CENTER_CREATEFARMER_FOOD &&
        info.farmers.size() < info.Human_MaxNum) {
        BuildingAction(building.SN, BUILDING_CENTER_CREATEFARMER);
        break;
}
