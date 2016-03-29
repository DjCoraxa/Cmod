static WeaponData data;
static WeaponMan man;

enum Weapon {
  Weapon_Invalid = -1
};

methodmap Weapon __nullable__ {
  property SlotStatus status {
    public get() {
      return data.weaponRankArray.getSlotStatus(view_as<Slot>(this));
    }

    public set(SlotStatus status) {
      data.weaponRankArray.setSlotStatus(view_as<Slot>(this), status);
    }
  }

  public void setName(char[] name) {
    data.weaponNameArray.setString(view_as<int>(this), name);
  }

  public void setPtr(char[] key) {
    data.weaponPtr.SetValue(key, this);
  }

  public void getName(char[] buffer, int maxLength) {
    data.weaponNameArray.getString(view_as<int>(this), buffer, maxLength);
  }

  public Weapon(char[] name) {
    Weapon weapon = view_as<Weapon>(man.getWeaponIndex(name));
    if (weapon != Weapon_Invalid)
      return weapon;

    weapon = view_as<Weapon>(data.weaponRankArray.findSlot(SlotStatus_Free));

    if (weapon == Weapon_Invalid) {
      data.weaponRankArray.resizeAndSetValue(data.weaponRankArray.length + RESIZE_BACKUP, 0, MAXPLAYERS);
      data.weaponGiveRankArray.resizeAndSetValue(data.weaponGiveRankArray.length + RESIZE_BACKUP, 0, MAXPLAYERS);
      weapon = view_as<Weapon>(data.weaponRankArray.findSlot(SlotStatus_Free));
    }

    weapon.status = SlotStatus_Use;
    weapon.setName(name);
    weapon.setPtr(name);

    return weapon;
  }
};
