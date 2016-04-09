enum StatsID {
  StatsID_Invalid = -1
};

typeset StatsActivateCB {
  function void (StatsID statsID, int client, int points);
};

methodmap StatsID __nullable__ {
  public native StatsID(char[] name);

  public native void setName(char[] name);

  public native void getName(char[] buffor, int maxLength);

  public native void setDesc(char[] desc);

  public native void getDesc(char[] buffer, int maxLength);

  public native void remove();

  public native bool isValid();

  public native bool hookActivate(StatsActivateCB callback);

  public native bool unhookActivate(StatsActivateCB callback);

  public native void sendActivate(int client, int points);
};

typeset StatsCreateCB {
  function void (StatsID statsID, char[] name);
};

typeset StatsRemoveCB {
  function void (StatsID statsID, char[] name);
}

typeset  StatsRequestCB {
  function void (StatsID statsID, char[] name);
}

methodmap CmodStats {
  property int maxNameLength {
    public native get();
  }

  property int maxDescLength {
    public native get();
  }

  public native bool hookCreateStats(StatsCreateCB callback);

  public native bool unhookCreateStats(StatsCreateCB callback);

  public native bool hookRemoveStats(StatsRemoveCB callback);

  public native bool unhookRemoveStats(StatsRemoveCB callback);

  public native StatsID getIDByName(char[] name);

  property StatsID maxID {
    public native get();
  }

  public native void notifyWhenAvalible(char[] name, StatsRequestCB callback);  
};
