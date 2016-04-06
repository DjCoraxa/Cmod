#include <sourcemod>
#include <cmod/version>
#include <cmod/Skill>

#include "Cmod/PreparedSkill/Config"

#include "Cmod/Utility/Data/DataArray"

#include "Cmod/Utility/Forward/ForwardBase"

#include "Cmod/Utility/Slot/Enum/Slot"
#include "Cmod/Utility/Slot/Enum/SlotStatus"
#include "Cmod/Utility/Slot/Forward/ForwardCreateSlotID"
#include "Cmod/Utility/Slot/Forward/ForwardRemoveSlotID"
#include "Cmod/Utility/Slot/SlotArray"
#include "Cmod/Utility/Slot/SlotData"
#include "Cmod/Utility/Slot/SlotID"

#include "Cmod/PreparedSkill/Enum/PreparedSkill"
#include "Cmod/PreparedSkill/Enum/PreparedArrayType"
#include "Cmod/PreparedSkill/Enum/PreparedVarType"
#include "Cmod/PreparedSkill/Forward/ForwardPrepareSkill"
#include "Cmod/PreparedSkill/Forward/ForwardStartSkill"
#include "Cmod/PreparedSkill/Forward/ForwardStopSkill"
#include "Cmod/PreparedSkill/SkillCFGData"
#include "Cmod/PreparedSkill/SkillCFG"
#include "Cmod/PreparedSkill/PreparedSkillData"
#include "Cmod/PreparedSkill/PreparedSkill"

#include "Cmod/PreparedSkill/Main"

public Plugin myinfo = {
  name = "Cmod_PreparedSkill",
  author = "plx211",
  description = "Prepared Skill system",
  version = CMOD_PLUGIN_VERSION,
  url = "https://github.com/plx211/Cmod"
};

public void OnLibraryAdded(const char[] name) {
  if (StrEqual(name, "Cmod_SkillCore"))
    preparedSkillStart();
}

public APLRes AskPluginLoad2(Handle myself, bool late, char[] error, int err_max) {
  preparedSkillNative();
  return APLRes_Success;
}
