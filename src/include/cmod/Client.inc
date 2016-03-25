methodmap Client {
  public native void allowWeapon(char[] weapon);

  public native void denyWeapon(char[] weapon);

  public native void setWeaponRank(char[] weapon, int rank);

  public native int getWeaponRank(char[] weapon);

  public native void addWeaponToGiveList(char[] weapon);

  public native void removeWeaponFromGiveList(char[] weapon);

  public native void giveWeapons();

  public native bool checkWeaponPerm(char[] weapon);
}
