static DataArray lvlArray;
static DataArray maxLvlArray;
static DataArray expArray;
static DataArray expTableArray;
static DataArray fwdLvlChangeArray;


methodmap ExpData __nullable__ < SlotData {
  public ExpData() {
    SlotData slotData = new SlotData();

    lvlArray = new DataArray();
    maxLvlArray = new DataArray();
    expArray = new DataArray();
    expTableArray = new DataArray(MAX_LVL_VALUE + 1);
    fwdLvlChangeArray = new DataArray();
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
};
