enum ClientPtsType {
  ClientPts_General = 0,
  ClientPts_Class,
  ClientPts_Item,
  ClientPts_Skill,
  ClientPts_Bonus,
  ClientPts_Count
};


methodmap Client {
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

  public native bool setClass(ClassID classID);
};
