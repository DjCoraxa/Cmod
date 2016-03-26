static PreparedSkillData data;
static SkillCFGData skillData;
static CmodSkill cmodSkill;

void preparedSkillStart() {
  data = new PreparedSkillData();
  skillData = new SkillCFGData();

  cmodSkill.hookCreateSkill(onCreateSkill);
  cmodSkill.hookRemoveSkill(onRemoveSkill);
}

public void onCreateSkill(SkillID skillID) {
  SkillCFG skillCFG = new SkillCFG(skillID);
}

public void onRemoveSkill(SkillID skillID) {
  SkillCFG skillCFG = view_as<SkillCFG>(skillID);
  skillCFG.remove();
}

void preparedSkillNative() {
  CreateNative("PreparedSkill.PreparedSkill", native_PreparedSkill_PreparedSkill);
  CreateNative("PreparedSkill.remove", native_PreparedSkill_remove);
  CreateNative("PreparedSkill.isValid", native_PreparedSkill_isValid);
  CreateNative("PreparedSkill.setValue", native_PreparedSkill_setValue);
  CreateNative("PreparedSkill.setFloat", native_PreparedSkill_setFloat);
  CreateNative("PreparedSkill.setString", native_PreparedSkill_setString);
  CreateNative("PreparedSkill.setArray", native_PreparedSkill_setArray);
  CreateNative("PreparedSkill.getValue", native_PreparedSkill_getValue);
  CreateNative("PreparedSkill.getFloat", native_PreparedSkill_getFloat);
  CreateNative("PreparedSkill.getString", native_PreparedSkill_getString);
  CreateNative("PreparedSkill.getArray", native_PreparedSkill_getArray);
  CreateNative("PreparedSkill.getVarType", native_PreparedSkill_getVarType);
  CreateNative("PreparedSkill.start", native_PreparedSkill_start);
  CreateNative("PreparedSkill.stop", native_PreparedSkill_stop);

  CreateNative("SkillID.hookPrepare", native_SkillID_hookPrepare);
  CreateNative("SkillID.unhookPrepare", native_SkillID_unhookPrepare);
  CreateNative("SkillID.hookStart", native_SkillID_hookStart);
  CreateNative("SkillID.unhookStart", native_SkillID_unhookStart);
  CreateNative("SkillID.hookStop", native_SkillID_hookStop);
  CreateNative("SkillID.unhookStop", native_SkillID_unhookStop);

  CreateNative("CmodPrepared.hookCreatePrepared", native_CmodPrepared_hookCreatePrepared)
  CreateNative("CmodPrepared.unhookCreatePrepared", native_CmodPrepared_unhookCreatePrepared)
  CreateNative("CmodPrepared.hookRemovePrepared", native_CmodPrepared_hookRemovePrepared)
  CreateNative("CmodPrepared.unhookRemovePrepared", native_CmodPrepared_unhookRemovePrepared)
  CreateNative("CmodPrepared.maxKeyLength.get", native_CmodPrepared_maxKeyLength_get);
  CreateNative("CmodPrepared.maxStringLength.get", native_CmodPrepared_maxStringLength_get);
  CreateNative("CmodPrepared.maxArraySize.get", native_CmodPrepared_maxArraySize_get);
}

public int native_PreparedSkill_PreparedSkill(Handle plugin, int numParams) {
  return view_as<int>(new PreparedSkill(GetNativeCell(1)));
}

public int native_PreparedSkill_remove(Handle plugin, int numParams) {
  PreparedSkill preparedSkill = GetNativeCell(1);
  preparedSkill.remove();
}

public int native_PreparedSkill_isValid(Handle plugin, int numParams) {
  PreparedSkill preparedSkill = GetNativeCell(1);
  return preparedSkill.isValid();
}

public int native_PreparedSkill_setValue(Handle plugin, int numParams) {
  PreparedSkill preparedSkill = GetNativeCell(1);

  char[] key = new char[MAX_KEY_LENGTH + 1];
  GetNativeString(2, key, MAX_KEY_LENGTH);

  return preparedSkill.setValue(key, GetNativeCell(3), GetNativeCell(4));
}

public int native_PreparedSkill_setFloat(Handle plugin, int numParams) {
  PreparedSkill preparedSkill = GetNativeCell(1);

  char[] key = new char[MAX_KEY_LENGTH + 1];
  GetNativeString(2, key, MAX_KEY_LENGTH);

  return preparedSkill.setFloat(key, GetNativeCell(3), GetNativeCell(4));
}

public int native_PreparedSkill_setString(Handle plugin, int numParams) {
  PreparedSkill preparedSkill = GetNativeCell(1);

  char[] key = new char[MAX_KEY_LENGTH + 1];
  GetNativeString(2, key, MAX_KEY_LENGTH);

  char[] value = new char[MAX_STRING_LENGTH + 1];
  GetNativeString(3, value, MAX_STRING_LENGTH);

  return preparedSkill.setString(key, value, GetNativeCell(4));
}

public int native_PreparedSkill_setArray(Handle plugin, int numParams) {
  PreparedSkill preparedSkill = GetNativeCell(1);

  char[] key = new char[MAX_KEY_LENGTH + 1];
  GetNativeString(2, key, MAX_KEY_LENGTH);

  int arraySize = GetNativeCell(4);
  any[] array = new any[arraySize + 1];
  GetNativeArray(2, array, arraySize);

  return preparedSkill.setArray(key, array, arraySize, GetNativeCell(5));
}

public int native_PreparedSkill_getValue(Handle plugin, int numParams) {
  PreparedSkill preparedSkill = GetNativeCell(1);

  char[] key = new char[MAX_KEY_LENGTH + 1];
  GetNativeString(2, key, MAX_KEY_LENGTH);

  any value = 0;
  preparedSkill.varMap.GetValue(key, value);

  return value;
}

public int native_PreparedSkill_getFloat(Handle plugin, int numParams) {
  PreparedSkill preparedSkill = GetNativeCell(1);

  char[] key = new char[MAX_KEY_LENGTH + 1];
  GetNativeString(2, key, MAX_KEY_LENGTH);

  float value = 0.0;
  preparedSkill.varMap.GetValue(key, value);

  return view_as<int>(value);
}

public int native_PreparedSkill_getString(Handle plugin, int numParams) {
  PreparedSkill preparedSkill = GetNativeCell(1);

  char[] key = new char[MAX_KEY_LENGTH + 1];
  GetNativeString(2, key, MAX_KEY_LENGTH);

  char[] buffer = new char[MAX_STRING_LENGTH + 1];

  int result = preparedSkill.varMap.GetString(key, buffer, MAX_STRING_LENGTH);

  SetNativeString(3, buffer, GetNativeCell(4));

  return result;
}

public int native_PreparedSkill_getArray(Handle plugin, int numParams) {
  PreparedSkill preparedSkill = GetNativeCell(1);

  char[] key = new char[MAX_KEY_LENGTH + 1];
  GetNativeString(2, key, MAX_KEY_LENGTH);

  any[] buffer = new any[MAX_ARRAY_SIZE + 1];

  int result = preparedSkill.varMap.GetArray(key, buffer, MAX_ARRAY_SIZE);

  SetNativeArray(3, buffer, GetNativeCell(4));

  return result;
}

public int native_PreparedSkill_getVarType(Handle plugin, int numParams) {
  PreparedSkill preparedSkill = GetNativeCell(1);

  char[] key = new char[MAX_KEY_LENGTH + 1];
  GetNativeString(2, key, MAX_KEY_LENGTH);

  PreparedVarType varType = PreparedVar_Unknown;
  preparedSkill.varTypeMap.GetValue(key, varType);

  return view_as<int>(varType);
}

public int native_PreparedSkill_start(Handle plugin, int numParams) {
  PreparedSkill preparedSkill = GetNativeCell(1);
  SkillCFG skillCFG = view_as<SkillCFG>(preparedSkill.targetSkill);
  skillCFG.fwdStart.send(skillCFG, preparedSkill, GetNativeCell(2));
}

public int native_PreparedSkill_stop(Handle plugin, int numParams) {
  PreparedSkill preparedSkill = GetNativeCell(1);
  SkillCFG skillCFG = view_as<SkillCFG>(preparedSkill.targetSkill);
  skillCFG.fwdStop.send(skillCFG, preparedSkill, GetNativeCell(2));
}

public int native_SkillID_hookPrepare(Handle plugin, int numParams) {
  SkillCFG skillCFG = GetNativeCell(1);
  return skillCFG.fwdPrepare.hook(plugin, GetNativeCell(2));
}

public int native_SkillID_unhookPrepare(Handle plugin, int numParams) {
  SkillCFG skillCFG = GetNativeCell(1);
  return skillCFG.fwdPrepare.unhook(plugin, GetNativeCell(2));
}

public int native_SkillID_hookStart(Handle plugin, int numParams) {
  SkillCFG skillCFG = GetNativeCell(1);
  return skillCFG.fwdStart.hook(plugin, GetNativeCell(2));
}

public int native_SkillID_unhookStart(Handle plugin, int numParams) {
  SkillCFG skillCFG = GetNativeCell(1);
  return skillCFG.fwdStart.unhook(plugin, GetNativeCell(2));
}

public int native_SkillID_hookStop(Handle plugin, int numParams) {
  SkillCFG skillCFG = GetNativeCell(1);
  return skillCFG.fwdStop.hook(plugin, GetNativeCell(2));
}

public int native_SkillID_unhookStop(Handle plugin, int numParams) {
  SkillCFG skillCFG = GetNativeCell(1);
  return skillCFG.fwdStop.unhook(plugin, GetNativeCell(2));
}

public int native_CmodPrepared_hookCreatePrepared(Handle plugin, int numParams) {
  return data.fwdCreate.hook(plugin, GetNativeCell(2));
}

public int native_CmodPrepared_unhookCreatePrepared(Handle plugin, int numParams) {
  return data.fwdCreate.unhook(plugin, GetNativeCell(2));
}

public int native_CmodPrepared_hookRemovePrepared(Handle plugin, int numParams) {
  return data.fwdRemove.hook(plugin, GetNativeCell(2));
}

public int native_CmodPrepared_unhookRemovePrepared(Handle plugin, int numParams) {
  return data.fwdRemove.unhook(plugin, GetNativeCell(2));
}

public int native_CmodPrepared_maxKeyLength_get(Handle plugin, int numParams) {
  return MAX_KEY_LENGTH;
}

public int native_CmodPrepared_maxStringLength_get(Handle plugin, int numParams) {
  return MAX_STRING_LENGTH;
}

public int native_CmodPrepared_maxArraySize_get(Handle plugin, int numParams) {
  return MAX_ARRAY_SIZE;
}
