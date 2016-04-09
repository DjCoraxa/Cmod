static ExpData data;

void expCoreStart() {
  data = new ExpData();
  RegPluginLibrary("Cmod_ExpCore");
}

void expCoreNative() {
#if defined SLOT_CREATE_FORWARD
  CreateNative("CmodExp.hookCreateExpID", native_CmodExp_hookCreateExpID);
  CreateNative("CmodExp.unhookCreateExpID", native_CmodExp_unhookCreateExpID);
#endif

#if defined SLOT_REMOVE_FORWARD
  CreateNative("CmodExp.hookRemoveExpID", native_CmodExp_hookRemoveExpID);
  CreateNative("CmodExp.unhookRemoveExpID", native_CmodExp_unhookRemoveExpID);
#endif

  CreateNative("ExpID.ExpID", native_ExpID_ExpID);
  CreateNative("ExpID.remove", native_ExpID_remove);
  CreateNative("ExpID.lvl.get", native_ExpID_lvl_get);
  CreateNative("ExpID.lvl.set", native_ExpID_lvl_set);
  CreateNative("ExpID.exp.get", native_ExpID_exp_get);
  CreateNative("ExpID.exp.set", native_ExpID_exp_set);
  CreateNative("ExpID.maxLvl.get", native_ExpID_maxLvl_get);
  CreateNative("ExpID.hookLvlChange", native_ExpID_hookLvlChange);
  CreateNative("ExpID.unhookLvlChange", native_ExpID_unhookLvlChange);
  CreateNative("ExpID.checkLvl", native_ExpID_checkLvl);
  CreateNative("ExpID.getExpForLvl", native_ExpID_getExpForLvl);
  CreateNative("ExpID.isValid", native_ExpID_isValid);
}

#if defined SLOT_CREATE_FORWARD
public int native_CmodExp_hookCreateExpID(Handle plugin, int numParams) {
  return data.fwdCreate.hook(plugin, GetNativeCell(2));
}

public int native_CmodExp_unhookCreateExpID(Handle plugin, int numParams) {
  return data.fwdCreate.unhook(plugin, GetNativeCell(2));
}
#endif

#if defined SLOT_REMOVE_FORWARD
public int native_CmodExp_hookRemoveExpID(Handle plugin, int numParams) {
  return data.fwdRemove.hook(plugin, GetNativeCell(2));
}

public int native_CmodExp_unhookRemoveExpID(Handle plugin, int numParams) {
  return data.fwdRemove.unhook(plugin, GetNativeCell(2));
}
#endif

public int native_ExpID_ExpID(Handle plugin, int numParams) {
  return view_as<int>(new ExpID(GetNativeCell(1), GetNativeCell(2)));
}

public int native_ExpID_remove(Handle plugin, int numParams) {
  ExpID expID = GetNativeCell(1)
  expID.remove();
}

public int native_ExpID_lvl_get(Handle plugin, int numParams) {
  ExpID expID = GetNativeCell(1);
  return expID.lvl;
}

public int native_ExpID_lvl_set(Handle plugin, int numParams) {
  ExpID expID = GetNativeCell(1);
  expID.lvl = GetNativeCell(2);
}

public int native_ExpID_exp_get(Handle plugin, int numParams) {
  ExpID expID = GetNativeCell(1);
  return expID.exp;
}

public int native_ExpID_exp_set(Handle plugin, int numParams) {
  ExpID expID = GetNativeCell(1);
  expID.exp = GetNativeCell(2);
}

public int native_ExpID_maxLvl_get(Handle plugin, int numParams) {
  ExpID expID = GetNativeCell(1);
  return expID.maxLvl;
}

public int native_ExpID_hookLvlChange(Handle plugin, int numParams) {
  ExpID expID = GetNativeCell(1);
  return expID.fwdLvlChange.hook(plugin, GetNativeCell(2));
}

public int native_ExpID_unhookLvlChange(Handle plugin, int numParams) {
  ExpID expID = GetNativeCell(1);
  return expID.fwdLvlChange.unhook(plugin, GetNativeCell(2));
}

public int native_ExpID_checkLvl(Handle plugin, int numParams) {
  ExpID expID = GetNativeCell(1);
  expID.checkLvl();
}

public int native_ExpID_getExpForLvl(Handle plugin, int numParams) {
  ExpID expID = GetNativeCell(1);
  return expID.getExpForLvl(GetNativeCell(2));
}

public int native_ExpID_isValid(Handle plugin, int numParams) {
  ExpID expID = GetNativeCell(1);
  return expID.isValid();
}
