static WeaponData data;

methodmap WeaponMan {
  public int getWeaponIndex(char[] classname) {
    int weaponID = -1;
    data.weaponPtr.GetValue(classname, weaponID);
    return weaponID;
  }
};
