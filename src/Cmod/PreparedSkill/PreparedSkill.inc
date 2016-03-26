static PreparedSkillData data;

methodmap PreparedSkill __nullable__ < SlotID {
  property SkillID targetSkill {
    public get() {
      return data.preparedArray.getValue(view_as<int>(this), view_as<int>(PreparedArray_TargetSkill));
    }

    public set(SkillID skillID) {
      return data.preparedArray.setValue(view_as<int>(this), skillID, view_as<int>(PreparedArray_TargetSkill));
    }
  }

  property StringMap varMap {
    public get() {
      return data.preparedArray.getValue(view_as<int>(this), view_as<int>(PreparedArray_VarMap));
    }

    public set(StringMap map) {
      data.preparedArray.setValue(view_as<int>(this), map, view_as<int>(PreparedArray_VarMap));
    }
  }

  property StringMap varTypeMap {
    public get() {
      return data.preparedArray.getValue(view_as<int>(this), view_as<int>(PreparedArray_VarTypeMap));
    }

    public set(StringMap map) {
      data.preparedArray.setValue(view_as<int>(this), map, view_as<int>(PreparedArray_VarTypeMap));
    }
  }

  public bool setVarType(char[] key, PreparedVarType varType, bool replace = false) {
    this.varTypeMap.SetValue(key, varType, replace);
  }

  public bool setValue(char[] key, any value, bool replace = false) {
    this.setVarType(key, PreparedVar_Value, replace);
    return this.varMap.SetValue(key, value, replace);
  }

  public bool setFloat(char[] key, float value, bool replace = false) {
    this.setVarType(key, PreparedVar_Float, replace);
    this.varMap.SetValue(key, value, replace);
  }

  public bool setString(char[] key, char[] value, bool replace = false) {
    this.setVarType(key, PreparedVar_String, replace);
    this.varMap.SetString(key, value, replace);
  }

  public bool setArray(char[] key, any[] array, int numItems, bool replace = false) {
    this.setVarType(key, PreparedVar_Array, replace);
    this.varMap.SetArray(key, array, numItems, replace);
  }

  public PreparedSkill(SkillCFG targetSkill) {
    PreparedSkill preparedSkill = view_as<PreparedSkill>(new SlotID());

    preparedSkill.targetSkill = targetSkill;
    preparedSkill.varMap = new StringMap();
    preparedSkill.varTypeMap = new StringMap();

    targetSkill.fwdPrepare.send(targetSkill, view_as<int>(preparedSkill));

    return preparedSkill;
  }

  public void remove() {
    SlotID slotID = this;
    slotID.remove();
    this.varMap.Close();
    this.varTypeMap.Close();
    this.varMap = null;
    this.varTypeMap = null;
  }
};
