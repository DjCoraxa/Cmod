static RequestData data;

methodmap Request __nullable__ < SlotID {
  property bool isReady {
    public get() {
      return data.requestContent.getValue(this, RequestData_ReadyStatus);
    }
    public set(bool status) {
      data.requestContent.setValue(this, status, RequestData_ReadyStatus);
    }
  }

  property ForwardRequestComplete fwd {
    public get() {
      return data.requestContent.getValue(this, RequestData_PluginForward);
    }
    public set(ForwardRequestComplete fwd) {
      data.requestContent.setValue(this, fwd, RequestData_PluginForward);
    }
  }

  property bool isEmpty {
    public get() {
      for (RequestDataType type = RequestData_Library; type < RequestData_Count; ++type)
        if (this.getRequestArray(type).length)
          return false;
      return true;
    }
  }

  public DataArray getRequestArray(RequestDataType type) {
    return data.requestContent.getValue(this, type);
  }

  public void addRequest(char[] name, RequestDataType type) {
    DataArray array = this.getRequestArray(type);
    int index = array.findString(name);

    if (index == -1)
      array.pushString(name);
  }

  public void check(char[] name, RequestDataType type) {
    DataArray array = this.getRequestArray(type);
    int index = array.findString(name);

    if (index != -1)
      array.erase(index);

    if (this.isEmpty && this.isReady)
      this.remove();
  } 

  public Request() {
    Request req = new SlotID();
    req.isReady = false;
    req.fwd = new ForwardRequestComplete();

    for (RequestDataType type = RequestData_Library; type < RequestData_Count; ++type)
      data.requestContent.setValue(req, new DataArray(MAX_NAME_LENGTH + 1), type);

    return req;
  }

  public void remove() {
    this.fwd.send(this);
    this.fwd.remove();

    for (RequestDataType type = RequestData_Library; type < RequestData_Count; ++type)
      this.getRequestArray(type).Close();

    Slot slot = this;
    slot.remove();
  }
}
