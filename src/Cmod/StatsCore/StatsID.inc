static StatsData data;

methodmap StatsID __nullable__ < NamedSlotID {
  property ForwardActivateSlotID fwdActivate {
    public get() {
      return data.fwdActivateArray.getValue(as<int>(this));
    }

    public set(ForwardActivateSlotID fwdActivate) {
      data.fwdActivateArray.setValue(as<int>(this), fwdActivate);
    }
  }

  public StatsID(char[] name) {
    StatsID statsID = as<StatsID>(new NamedSlotID(name));

    if (statsID == StatsID_Invalid)
      return StatsID_Invalid;

    statsID.fwdActivate = new ForwardActivateSlotID();

    return statsID;
  }

  public void remove() {
    NamedSlotID namedSlot = this;
    this.fwdActivate.remove();
    this.fwdActivate = null;
    namedSlot.remove();
  }
};
