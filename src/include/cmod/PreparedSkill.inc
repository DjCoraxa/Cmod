enum PreparedVarType {
  PreparedVar_Unknown = -1,
  PreparedVar_Value,
  PreparedVar_Float,
  PreparedVar_String,
  PreparedVar_Array,
  PreparedVar_Count
};

methodmap PreparedSkill __nullable__ {
  public native PreparedSkill(SkillID targetSkill);

  public native void remove();

  public native bool isValid();

  public native bool setValue(char[] key, any value, bool replace = false);

  public native bool setFloat(char[] key, float value, bool replace = false);

  public native bool setString(char[] key, char[] value, bool replace = false);

  public native bool setArray(char[] key, any[] array, int numItems, bool replace = false);

  public native any getValue(char[] key);

  public native float getFloat(char[] key);

  public native bool getString(char[] key, char[] buffer, int maxLength);

  public native bool getArray(char[] key, any[] array, int maxSize);

  public native PreparedVarType getVarType(char[] key);

  public native void start(int entity);

  public native void stop(int entity);
}

typeset PreparedCreateCB {
  function void (PreparedSkill preparedSkill);
}

typeset PreparedRemoveCB {
  function void (PreparedSkill preparedSkill);
}

methodmap CmodPrepared {
  property int maxKeyLength {
    public native get();
  }

  property int maxStringLength {
    public native get();
  }

  property int maxArraySize {
    public native get();
  }

  public native bool hookCreatePrepared(PreparedCreateCB callback);

  public native bool unhookCreatePrepared(PreparedCreateCB callback);

  public native bool hookRemovePrepared(PreparedRemoveCB callback);

  public native bool unhookRemovePrepared(PreparedRemoveCB callback);
}
