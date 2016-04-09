enum ClassID {
  ClassID_Invalid = -1
};

typeset ClassEnableCB {
  function void (ClassID classID, int client);
};

typeset ClassDisableCB {
  function void (ClassID classID, int client);
};

typeset ClassRunCB {
  function void (ClassID classID, int client);
};

methodmap ClassID __nullable__ {
  public native ClassID(char[] name);

  public native void setName(char[] name);

  public native void getName(char[] buffor, int maxLength);

  public native void setDesc(char[] desc);

  public native void getDesc(char[] buffer, int maxLength);

  public native void remove();

  public native bool isValid();

  public native bool hookEnable(ClassEnableCB callback);

  public native bool unhookEnable(ClassEnableCB callback);

  public native bool hookDisable(ClassDisableCB callback);

  public native bool unhookDisable(ClassDisableCB callback);

  public native void sendEnable(int client);

  public native void sendDisable(int client);

  public native bool hookRun(ClassRunCB callback);

  public native bool unhookRun(ClassRunCB callback);

  public native void sendRun(int client);
};

typeset ClassCreateCB {
  function void (ClassID classID, char[] name);
};

typeset ClassRemoveCB {
  function void (ClassID classID, char[] name);
}

methodmap CmodClass {
  property int maxNameLength {
    public native get();
  }

  property int maxDescLength {
    public native get();
  }

  public native bool hookCreateClass(ClassCreateCB callback);

  public native bool unhookCreateClass(ClassCreateCB callback);

  public native bool hookRemoveClass(ClassRemoveCB callback);

  public native bool unhookRemoveClass(ClassRemoveCB callback);

  public native ClassID getIDByName(char[] name);

  property ClassID maxID {
    public native get();
  }
}
