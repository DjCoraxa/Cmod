static StatsData data;

void statsCoreStart() {
  data = new StatsData();
  RegPluginLibrary("Cmod_StatsCore");
}

void statsCoreNative() {
  CreateNative("StatsID.StatsID", native_StatsID_StatsID);
  CreateNative("StatsID.remove", native_StatsID_remove);
  CreateNative("StatsID.isValid", native_StatsID_isValid);
  CreateNative("StatsID.setName", native_StatsID_setName);
  CreateNative("StatsID.getName", native_StatsID_getName);
  CreateNative("StatsID.setDesc", native_StatsID_setDesc);
  CreateNative("StatsID.getDesc", native_StatsID_getDesc);
  CreateNative("StatsID.hookActivate", native_StatsID_hookActivate);
  CreateNative("StatsID.unhookActivate", native_StatsID_unhookActivate);
  CreateNative("StatsID.sendActivate", native_StatsID_sendActivate);

  CreateNative("CmodStats.hookCreateStats", native_CmodStats_hookCreateStats)
  CreateNative("CmodStats.unhookCreateStats", native_CmodStats_unhookCreateStats)
  CreateNative("CmodStats.hookRemoveStats", native_CmodStats_hookRemoveStats)
  CreateNative("CmodStats.unhookRemoveStats", native_CmodStats_unhookRemoveStats)
  CreateNative("CmodStats.maxNameLength.get", native_CmodStats_maxNameLength_get);
  CreateNative("CmodStats.maxDescLength.get", native_CmodStats_maxDescLength_get);
  CreateNative("CmodStats.getIDByName", native_CmodStats_getIDByName);
  CreateNative("CmodStats.maxID.get", native_CmodStats_maxID_get);
}

public int native_StatsID_StatsID(Handle plugin, int numParams) {
  char[] name = new char[MAX_SLOT_NAME_LENGTH + 1];
  GetNativeString(1, name, MAX_SLOT_NAME_LENGTH);
  return view_as<int>(new StatsID(name));
}

public int native_StatsID_remove(Handle plugin, int numParams) {
  StatsID statsID = GetNativeCell(1);
  statsID.remove();
}

public int native_StatsID_isValid(Handle plugin, int numParams) {
  StatsID statsID = GetNativeCell(1);
  return statsID.isValid();
}

public int native_StatsID_setName(Handle plugin, int numParams) {
  StatsID statsID = GetNativeCell(1);

  char[] name = new char[MAX_SLOT_NAME_LENGTH + 1];
  GetNativeString(2, name, MAX_SLOT_NAME_LENGTH);

  statsID.setName(name);
}

public int native_StatsID_getName(Handle plugin, int numParams) {
  StatsID statsID = GetNativeCell(1);

  char[] name = new char[MAX_SLOT_NAME_LENGTH + 1];
  statsID.getName(name, MAX_SLOT_NAME_LENGTH);

  SetNativeString(2, name, GetNativeCell(3));
}

public int native_StatsID_setDesc(Handle plugin, int numParams) {
  StatsID statsID = GetNativeCell(1);

  char[] desc = new char[MAX_SLOT_DESC_LENGTH + 1];
  GetNativeString(2, desc, MAX_SLOT_DESC_LENGTH);

  statsID.setDesc(desc);
}

public int native_StatsID_getDesc(Handle plugin, int numParams) {
  StatsID statsID = GetNativeCell(1);

  char[] desc = new char[MAX_SLOT_DESC_LENGTH + 1];
  statsID.getDesc(desc, MAX_SLOT_DESC_LENGTH);

  SetNativeString(2, desc, GetNativeCell(3));
}

public int native_StatsID_hookActivate(Handle plugin, int numParams) {
  StatsID statsID = GetNativeCell(1);
  return statsID.fwdActivate.hook(plugin, GetNativeCell(2));
}

public int native_StatsID_unhookActivate(Handle plugin, int numParams) {
  StatsID statsID = GetNativeCell(1);
  return statsID.fwdActivate.unhook(plugin, GetNativeCell(2));
}

public int native_StatsID_sendActivate(Handle plugin, int numParams) {
  StatsID statsID = GetNativeCell(1);
  statsID.fwdActivate.send(statsID, GetNativeCell(2), GetNativeCell(3));
}

public int native_CmodStats_hookCreateStats(Handle plugin, int numParams) {
  return data.fwdCreate.hook(plugin, GetNativeCell(2));
}

public int native_CmodStats_unhookCreateStats(Handle plugin, int numParams) {
  return data.fwdCreate.unhook(plugin, GetNativeCell(2));
}

public int native_CmodStats_hookRemoveStats(Handle plugin, int numParams) {
  return data.fwdRemove.hook(plugin, GetNativeCell(2));
}

public int native_CmodStats_unhookRemoveStats(Handle plugin, int numParams) {
  return data.fwdRemove.unhook(plugin, GetNativeCell(2));
}

public int native_CmodStats_maxNameLength_get(Handle plugin, int numParams) {
  return MAX_SLOT_NAME_LENGTH;
}

public int native_CmodStats_maxDescLength_get(Handle plugin, int numParams) {
  return MAX_SLOT_DESC_LENGTH;
}

public int native_CmodStats_getIDByName(Handle plugin, int numParams) {
  char[] name = new char[MAX_SLOT_NAME_LENGTH + 1];
  GetNativeString(1, name, MAX_SLOT_NAME_LENGTH);
  return data.nameArray.findString(name);
}

public int native_CmodStats_maxID_get(Handle plugin, int numParams) {
  return data.slotArray.length;
}
