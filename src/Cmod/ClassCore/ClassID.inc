static ClassData data;

methodmap ClassID __nullable__ < NamedSlotID {
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

  public ClassID(char[] name) {
    ClassID classID = view_as<ClassID>(new NamedSlotID(name));

    if (classID == ClassID_Invalid)
      return ClassID_Invalid;

    classID.fwdEnable = new ForwardEnableSlotID();
    classID.fwdDisable = new ForwardDisableSlotID();
    classID.fwdRun = new ForwardRunSlot();

    return classID;
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
