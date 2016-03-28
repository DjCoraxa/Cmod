static ItemData data;

methodmap ItemID __nullable__ < NamedSlotID {
  property ForwardEnableSlotID fwdEnable {
    public get() {
      return data.fwdEnableArray.getValue(view_as<int>(this));
    }

    public set(ForwardEnableSlotID fwdEnable) {
      data.fwdEnableArray.setValue(view_as<int>(this), fwdEnable);
    }
  }

  property ForwardDisableSlotID fwdDisable {
    public get() {
      return data.fwdDisableArray.getValue(view_as<int>(this));
    }

    public set(ForwardDisableSlotID fwdDisable) {
      data.fwdDisableArray.setValue(view_as<int>(this), fwdDisable);
    }
  }

  property ForwardRunSlot fwdRun {
    public get() {
      return data.fwdRunArray.getValue(view_as<int>(this));
    }

    public set(ForwardRunSlot fwdRun) {
      data.fwdRunArray.setValue(view_as<int>(this), fwdRun);
    }
  }

  public ItemID(char[] name) {
    ItemID itemID = view_as<ItemID>(new NamedSlotID(name));

    if (itemID == ItemID_Invalid)
      return ItemID_Invalid;

    itemID.fwdEnable = new ForwardEnableSlotID();
    itemID.fwdDisable = new ForwardDisableSlotID();
    itemID.fwdRun = new ForwardRunSlot();

    return itemID;
  }

  public void remove() {
    NamedSlotID namedSlot = this;
    this.fwdEnable.remove();
    this.fwdDisable.remove();
    this.fwdRun.remove();
    this.fwdEnable = null;
    this.fwdDisable = null;
    this.fwdRun = null;
    namedSlot.remove();
  }
};
