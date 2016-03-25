static WeaponData data;

methodmap WeaponClient __nullable__ {
  public int getWeaponRank(Weapon weaponID) {
    return data.weaponRankArray.getValue(weaponID, this);
  }

  public void setWeaponRank(Weapon weaponID, int value) {
    data.weaponRankArray.setValue(weaponID, value, this);
  }

  public int getWeaponGiveRank(Weapon weaponID) {
    return data.weaponGiveRankArray.getValue(weaponID, this);
  }

  public void setWeaponGiveRank(Weapon weaponID, int value) {
    data.weaponGiveRankArray.setValue(weaponID, value, this);
  }

  public void giveWeapons() {
    int size = data.weaponRankArray.length;
    char[] buffer = new char[MAX_WEAPON_NAME_LENGTH + 1];

    for (Weapon weapon = 0; weapon < size; weapon++) {
      if (weapon.status == SlotStatus_Use) {
        if (this.getWeaponGiveRank(weapon)) {
          weapon.getName(buffer, MAX_WEAPON_NAME_LENGTH);
          GivePlayerItem(this, buffer);
        }
      }
    }
  }

  public bool checkWeaponPerm(Weapon weaponID) {
    int weaponRank = this.getWeaponRank(weaponID);

    if (weaponRank > 0)
      return true;
    else if (weaponRank < 0)
      return false;

    return data.cvarMode.IntValue;
  }
};
