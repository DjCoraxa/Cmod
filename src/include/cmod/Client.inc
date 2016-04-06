enum ClientPtsType {
  ClientPts_General = 0,
  ClientPts_Class,
  ClientPts_Item,
  ClientPts_Skill,
  ClientPts_Bonus,
  ClientPts_Count
};

enum ClientID {
  ClientID_Invalid = -1,
  ClientID_Server = 0,
  ClientID_Max = MAXPLAYERS
};


methodmap ClientID {
  // From Cmod_WeaponCore

  public native void allowWeapon(char[] weapon);

  public native void denyWeapon(char[] weapon);

  public native void setWeaponRank(char[] weapon, int rank);

  public native int getWeaponRank(char[] weapon);

  public native void addWeaponToGiveList(char[] weapon);

  public native void removeWeaponFromGiveList(char[] weapon);

  public native void giveWeapons();

  public native bool checkWeaponPerm(char[] weapon);

  // From Cmod_ClientStatsPts

  property int freeStatsPts {
    public native get();
    public native set(int value);
  }

  public native int getStatsPts(StatsID statsID, ClientPtsType type = ClientPts_General);

  public native int setStatsPts(StatsID statsID, int value, ClientPtsType type = ClientPts_General);

  public native int getStatsAllPts(StatsID statsID);

  public native void recalculateStatsAllPts(StatsID statsID);

  public native bool spendStatsPts(StatsID statsID, int value);

  public native void resetStatsPts(StatsID statsID);

  public native void resetAllStatsPts();

  // From Cmod_ClientClass

  public native ClassID getClass();

  public native void setClass(ClassID classID);

  // From Cmod_ClientItem

  public native ItemID getItem();

  public native void setItem(ItemID itemID);

  // From Cmod_ClientExp

  property ExpID expID {
    public native get();
  }
};

methodmap CmodClient {
  // From Cmod_ClientExp

  public native Client getClientByExpID(ExpID expID);
};
