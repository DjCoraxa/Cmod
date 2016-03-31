static ConVar cvarMode;
static StringMap weaponPtr;
static SlotArray weaponRankArray;
static DataArray weaponGiveRankArray;
static DataArray weaponNameArray;

methodmap WeaponData __nullable__ {
  public WeaponData() {
    cvarMode = CreateConVar("cmodweapon_mode", "1", "0 - Client can use only allow weapons, other - Client can use all weapons without deny");
    weaponPtr = new StringMap();
    weaponRankArray = new SlotArray(MAXPLAYERS + 1);
    weaponGiveRankArray = new DataArray(MAXPLAYERS + 1);
    weaponNameArray = new DataArray(MAX_WEAPON_NAME_LENGTH + 1);
  }

  property StringMap weaponPtr {
    public get() {
      return weaponPtr;
    }
  }

  property SlotArray weaponRankArray {
    public get() {
      return weaponRankArray;
    }
  }

  property DataArray weaponGiveRankArray {
    public get() {
      return weaponGiveRankArray;
    }
  }

  property DataArray weaponNameArray {
    public get() {
      return weaponNameArray;
    }
  }

  property ConVar cvarMode {
    public get() {
      return cvarMode;
    }
  }
};
