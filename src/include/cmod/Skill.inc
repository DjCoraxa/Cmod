#if defined _cmodlib_skillcore_included
 #endinput
#endif
#define _cmodlib_skillcore_included

typeset SkillCreateCB {
  function void (SkillID skillID, char[] name);
}

typeset SkillRemoveCB {
  function void (SkillID skillID, char[] name);
}

typeset  SkillRequestCB {
  function void (SkillID skillID, char[] name);
}

typeset SkillStartCB {
  function void (SkillID skillID, PreparedSkill preparedSkill, int entity);
}

typeset SkillStopCB {
  function void (SkillID skillID, PreparedSkill preparedSkill, int entity);
}

typeset SkillPrepareCB {
  function void (SkillID skillID, PreparedSkill preparedSkill);
}

methodmap SkillID __nullable__ {
  public native SkillID(char[] name);

  public native void getName(char[] buffor, int maxLength);

  public native void setDesc(char[] desc);

  public native void getDesc(char[] buffer, int maxLength);

  public native void remove();

  public native bool isValid();

  // From Cmod_PreparedSkill:

  public native bool hookStart(SkillStartCB callback);

  public native bool unhookStart(SkillStartCB callback);

  public native bool hookStop(SkillStopCB callback);

  public native bool unhookStop(SkillStopCB callback);

  public native bool hookPrepare(SkillPrepareCB callback);

  public native bool unhookPrepare(SkillPrepareCB callback);
};

methodmap CmodSkill {

  // From Cmod_SkillCore:

  property int maxNameLength {
    public native get();
  }

  property int maxDescLength {
    public native get();
  }

  public native bool hookCreateSkill(SkillCreateCB callback);

  public native bool unhookCreateSkill(SkillCreateCB callback);

  public native bool hookRemoveSkill(SkillRemoveCB callback);

  public native bool unhookRemoveSkill(SkillRemoveCB callback);

  public native SkillID getIDByName(char[] name);

  public native void notifyWhenAvalible(char[] name, SkillRequestCB callback);
};
