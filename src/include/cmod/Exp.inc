enum ExpID {
  ExpID_Invalid = -1
};

typeset LvlChangeCB {
  function void (ExpID expID, int oldLvl, int newLvl);
}

methodmap ExpID __nullable__ {
  public native ExpID(int maxLvl = 100, int lvlRatio = 35);

  public native void remove();

  property int lvl {
    public native get();
    public native set(int value);
  }

  property int exp {
    public native get();
    public native set(int value);
  }

  property int maxLvl {
    public native get();
  }

  public native bool hookLvlChange(LvlChangeCB callback);

  public native bool unhookLvlChange(LvlChangeCB callback);

  public native void checkLvl();

  public native int getExpForLvl(int lvl);

  public native bool isValid();
}

typeset CreateExpIDCB {
  function void (ExpID expID);
};

typeset RemoveExpIDCB {
  function void (ExpID expID);
}

methodmap CmodExp {
  public native bool hookCreateExpID(CreateExpIDCB callback);

  public native bool unhookCreateExpID(CreateExpIDCB callback);

  public native bool hookRemoveExpID(RemoveExpIDCB callback);

  public native bool unhookRemoveExpID(RemoveExpIDCB callback);
};
