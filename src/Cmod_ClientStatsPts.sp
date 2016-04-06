#include <sourcemod>
#include <sdkhooks>
#include <cmod/Stats>

#include "Cmod/ClientStatsPts/Config.inc"

#include "Cmod/Utility/Data/DataArray"

#include "Cmod/ClientStatsPts/Enum/ClientPtsType"
#include "Cmod/ClientStatsPts/ClientStatsData"
#include "Cmod/ClientStatsPts/ClientStats"

#include "Cmod/ClientStatsPts/Main.inc"

public void OnLibraryAdded(const char[] name) {
  if (StrEqual(name, "Cmod_StatsCore"))
    clientStatsPtsStart();
}

public APLRes AskPluginLoad2(Handle myself, bool late, char[] error, int err_max) {
  clientStatsPtsNative();
  return APLRes_Success;
}
