static ClientData data;
static LibraryMan lib;
static ExpID clientExpID[MAXPLAYERS + 1] = {ExpID_Invalid, ...};

enum Client {
  Client_Invalid = -1,
  Client_Server = 0,
  Client_First = 1,
  Client_Max = MAXPLAYERS
};

methodmap Client {
  property ExpID expID {
    public get() {
      return clientExpID[this];
    }
    public set(ExpID expID) {
      clientExpID[this] = expID;
    }
  }

  public void onPluginEnd() {
    if (lib.isExpCoreLoaded && this.expID.isValid())
      this.expID.remove();
  }

  public void onPutInServer() {
    if (lib.isExpCoreLoaded)
      this.expID = new ExpID(data.cvarMaxLvl.IntValue, data.cvarLvlRatio.IntValue);
  }

  public void onDisconnectPost() {
    this.onPluginEnd();
  }
};
