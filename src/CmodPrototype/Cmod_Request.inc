#include <sourcemod>
#include <cmod>
#include <cmod/version>

#include "Cmod/Request/Config"

#include "Cmod/Utility/Data/DataArray"
#include "Cmod/Utility/Slot/Enum/Slot"
#include "Cmod/Utility/Slot/Enum/SlotStatus"
#include "Cmod/Utility/Slot/SlotArray"
#include "Cmod/Utility/Slot/SlotData"
#include "Cmod/Utility/Slot/SlotID"
#include "Cmod/Utility/LibraryMan/LibraryMan"

#include "Cmod/Request/Enum/RequestDataType"
#include "Cmod/Request/Forward/ForwardRequestComplete"
#include "Cmod/Request/RequestData"
#include "Cmod/Request/Request"

static LibraryMan lib;
static CmodClass cmodClass;
static CmodItem cmodItem;
static CmodSkill cmodSkill;
static CmodStats cmodStats;
static RequestData data;

public void OnPluginStart() {
  data = new RequestData();
}

public void OnLibraryAdded(const char[] name) {
  CmodLibType libType = lib.onLibraryAdded(name);

  int length = data.slotArray.length;
  for (Request req = 0; req < length; ++req)
    if (req.isValid())
      req.check(name, RequestData_Library);

  switch (libType) {
    case CmodLib_ClassCore:
      cmodClass.hookCreateClass(onClassCreate);
    case CmodLib_ItemCore:
      cmodItem.hookCreateItem(onItemCreate);
    case CmodLib_SkillCore:
      cmodSkill.hookCreateSkill(onSkillCreate);
    case CmodLib_StatsCore:
      cmodStats.hookCreateStats(onStatsCreate);
  }
}

public void onClassCreate(ClassID classID, char[] name) {
  int length = data.slotArray.length;
  for (Request req = 0; req < length; ++req)
    if (req.isValid())
      req.check(name, RequestData_Class);
}

public void onItemCreate(ItemID itemID, char[] name) {
  int length = data.slotArray.length;
  for (Request req = 0; req < length; ++req)
    if (req.isValid())
      req.check(name, RequestData_Item);
}

public void onSkillCreate(SkillID skillID, char[] name) {
  int length = data.slotArray.length;
  for (Request req = 0; req < length; ++req)
    if (req.isValid())
      req.check(name, RequestData_Skill);
}

public void onStatsCreate(statsID statsID, char[] name) {
  int length = data.slotArray.length;
  for (Request req = 0; req < length; ++req)
    if (req.isValid())
      req.check(name, RequestData_Stats);
}
