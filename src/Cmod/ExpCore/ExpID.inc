static ExpData data;

methodmap ExpID __nullable__ < SlotID {
  property int lvl {
    public get() {
      return data.lvlArray.getValue(view_as<int>(this));
    }

    public set(int value) {
      data.lvlArray.setValue(view_as<int>(this), value);
    }
  }

  property int maxLvl {
    public get() {
      return data.maxLvlArray.getValue(view_as<int>(this));
    }

    public set(int value) {
      data.maxLvlArray.setValue(view_as<int>(this), value);
    }
  }

  property int exp {
    public get() {
      return data.expArray.getValue(view_as<int>(this));
    }

    public set(int value) {
      data.expArray.setValue(view_as<int>(this), value);
    }
  }

  property ForwardLvlChange fwdLvlChange {
    public get() {
      return data.fwdLvlChangeArray.getValue(view_as<int>(this));
    }

    public set(ForwardLvlChange fwdlvlUp) {
      data.fwdLvlChangeArray.setValue(view_as<int>(this), fwdlvlUp);
    }
  }

  public void generateExpTable(int maxLvl, int lvlRatio) {
    int[] expTable = new int[maxLvl + 1];

    for (int lvl = 0; lvl < maxLvl; ++lvl)
      expTable[lvl] = lvl * lvl * lvlRatio;

    data.expTableArray.setArray(view_as<int>(this), expTable, maxLvl);
    data.expTableArray.setArray(view_as<int>(this), expTable, maxLvl);
  }

  public int getExpForLvl(int lvl) {
    return data.expTableArray.getValue(view_as<int>(this), lvl);
  }

  public void checkLvl() {
    int nextLvl = this.lvl;
    bool lvlChange = false;

    while (this.exp > this.getExpForLvl(nextLvl) && nextLvl < this.maxLvl) {
      lvlChange = true;
      ++nextLvl;
    }

    while (this.exp < this.getExpForLvl(nextLvl - 1)) {
      lvlChange = true;
      --nextLvl;
    }

    int oldLvl = this.lvl;
    this.lvl = nextLvl

    if (lvlChange)
      this.fwdLvlChange.send(view_as<SlotID>(this), oldLvl, nextLvl);
  }

  public ExpID(int maxLvl, int lvlRatio) {
    if (maxLvl > MAX_LVL_VALUE)
      maxLvl = MAX_LVL_VALUE;

    ExpID expID = view_as<ExpID>(new SlotID());

    expID.lvl = 1;
    expID.maxLvl = maxLvl;
    expID.exp = 0;
    expID.generateExpTable(maxLvl, lvlRatio);
    expID.fwdLvlChange = new ForwardLvlChange();

    return expID;
  }

  public void remove() {
    SlotID slotID = this;
    slotID.remove();
    this.fwdLvlChange.remove();
  }
}
