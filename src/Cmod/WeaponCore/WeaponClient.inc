static WeaponData data;
static WeaponMan man;

methodmap WeaponClient __nullable__ {
  public int getWeaponRank(Weapon weaponID) {
    return data.weaponRankArray.getValue(view_as<int>(weaponID), view_as<int>(this));
  }

  public void setWeaponRank(Weapon weaponID, int value) {
    data.weaponRankArray.setValue(view_as<int>(weaponID), value, view_as<int>(this));
  }

  public int getWeaponGiveRank(Weapon weaponID) {
    return data.weaponGiveRankArray.getValue(view_as<int>(weaponID), view_as<int>(this));
  }

  public void setWeaponGiveRank(Weapon weaponID, int value) {
    data.weaponGiveRankArray.setValue(view_as<int>(weaponID), value, view_as<int>(this));
  }

  public void giveWeapons() {
    int size = data.weaponRankArray.length;
    char[] buffer = new char[MAX_WEAPON_NAME_LENGTH + 1];

    for (Weapon weapon = view_as<Weapon>(0); weapon < view_as<Weapon>(size); weapon++) {
      if (weapon.status == SlotStatus_Use) {
        if (this.getWeaponGiveRank(weapon)) {
          weapon.getName(buffer, MAX_WEAPON_NAME_LENGTH);
          GivePlayerItem(view_as<int>(this), buffer);
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

    return view_as<bool>(data.cvarMode.IntValue);
  }

  public bool checkWeaponPermByName(char[] weapon) {
    return this.checkWeaponPerm(view_as<Weapon>(man.getWeaponIndex(weapon)));
  }

  public void clear() {
    int size = data.weaponRankArray.length;
    for (Weapon weapon = view_as<Weapon>(0); weapon < view_as<Weapon>(size); weapon++) {
      if (weapon.status == SlotStatus_Use) {
        this.setWeaponRank(weapon, 0);
        this.setWeaponGiveRank(weapon, 0);
      }
    }
  }
};
