static ItemData data;

methodmap ItemID __nullable__ < NamedSlotID {
  property ForwardEnableSlotID fwdEnable {
    public get() {
      return data.fwdEnableArray.getValue(as<int>(this));
    }

    public set(ForwardEnableSlotID fwdEnable) {
      data.fwdEnableArray.setValue(as<int>(this), fwdEnable);
    }
  }

  property ForwardDisableSlotID fwdDisable {
    public get() {
      return data.fwdDisableArray.getValue(as<int>(this));
    }

    public set(ForwardDisableSlotID fwdDisable) {
      data.fwdDisableArray.setValue(as<int>(this), fwdDisable);
    }
  }

  public ItemID(char[] name) {
    ItemID itemID = as<ItemID>(new NamedSlotID(name));

    if (itemID == ItemID_Invalid)
      return ItemID_Invalid;

    itemID.fwdEnable = new ForwardEnableSlotID();
    itemID.fwdDisable = new ForwardDisableSlotID();

    return itemID;
  }

  public void remove() {
    NamedSlotID namedSlot = this;
    this.fwdEnable.remove();
    this.fwdDisable.remove();
    this.fwdEnable = null;
    this.fwdDisable = null;
    namedSlot.remove();
  }
};
