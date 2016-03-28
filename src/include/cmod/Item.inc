enum ItemID {
  ItemID_Invalid = -1
};

typeset ItemEnableCB {
  function void (ItemID itemID, int client);
};

typeset ItemDisableCB {
  function void (ItemID itemID, int client);
};

typeset ItemRunCB {
  function void (ItemID itemID, int client);
};

methodmap ItemID __nullable__ {
  public native ItemID(char[] name);

  public native void setName(char[] name);

  public native void getName(char[] buffor, int maxLength);

  public native void setDesc(char[] desc);

  public native void getDesc(char[] buffer, int maxLength);

  public native void remove();

  public native bool isValid();

  public native bool hookEnable(ItemEnableCB callback);

  public native bool unhookEnable(ItemEnableCB callback);

  public native bool hookDisable(ItemDisableCB callback);

  public native bool unhookDisable(ItemDisableCB callback);

  public native void sendEnable(int client);

  public native void sendDisable(int client);

  public native bool hookRun(ItemRunCB callback);

  public native bool unhookRun(ItemRunCB callback);

  public native void sendRun(int client);
};

typeset ItemCreateCB {
  function void (ItemID itemID);
};

typeset ItemRemoveCB {
  function void (ItemID itemID);
}

methodmap CmodItem {
  property int maxNameLength {
    public native get();
  }

  property int maxDescLength {
    public native get();
  }

  public native bool hookCreateItem(ItemCreateCB callback);

  public native bool unhookCreateItem(ItemCreateCB callback);

  public native bool hookRemoveItem(ItemRemoveCB callback);

  public native bool unhookRemoveItem(ItemRemoveCB callback);

  public native ItemID getIDByName(char[] name);
}
