static DataArray lvlArray;
static DataArray maxLvlArray;
static DataArray expArray;
static DataArray expTableArray;
static DataArray fwdLvlChangeArray;

#if defined RESERVE_EXPID_FOR_CLIENTS
  static ConVar cvarDefaultRatio;
  static ConVar cvarDefaultMaxLvl;
#endif

methodmap ExpData __nullable__ < SlotData {
  public ExpData() {
    SlotData slotData = new SlotData();

    lvlArray = new DataArray();
    maxLvlArray = new DataArray();
    expArray = new DataArray();
    expTableArray = new DataArray(MAX_LVL_VALUE + 1);
    fwdLvlChangeArray = new DataArray();

    #if defined RESERVE_EXPID_FOR_CLIENTS
      cvarDefaultRatio = CreateConVar("cmodexp_defaultratio", "35");
      cvarDefaultMaxLvl = CreateConVar("cmodexp_defaultmaxlvl", "201");
    #endif
  }

  property DataArray lvlArray {
    public get() {
      return lvlArray;
    }
  }

  property DataArray maxLvlArray {
    public get() {
      return maxLvlArray;
    }
  }

  property DataArray expArray {
    public get() {
      return expArray;
    }
  }

  property DataArray expTableArray {
    public get() {
      return expTableArray;
    }
  }

  property DataArray fwdLvlChangeArray {
    public get() {
      return fwdLvlChangeArray;
    }
  }

  #if defined RESERVE_EXPID_FOR_CLIENTS
    property ConVar cvarDefaultRatio {
      public get() {
        return cvarDefaultRatio;
      }
    }

    property ConVar cvarDefaultMaxLvl {
      public get() {
        return cvarDefaultMaxLvl;
      }
    }
  #endif
};
