static ClientData data;
static LibraryMan lib;
static ExpID clientExpID[MAXPLAYERS + 1] = {ExpID_Invalid, ...};
static ClassID clientClass[MAXPLAYERS + 1] = {ClassID_Invalid, ...};
static ItemID clientItem[MAXPLAYERS + 1] = {ItemID_Invalid, ...};

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

  public ClassID getClass() {
    return clientClass[this];
  }

  public void setClass(ClassID classID) {
    if (clientClass[this].isValid())
      clientClass[this].sendDisable(view_as<int>(this));

    clientClass[this] = classID;

    if (clientClass[this].isValid())
      classID.sendEnable(view_as<int>(this));
  }

  public ItemID getItem() {
    return clientItem[this];
  }

  public void setItem(ItemID itemID) {
    if (clientItem[this].isValid())
      clientItem[this].sendDisable(view_as<int>(this));

    clientItem[this] = itemID;

    if (clientItem[this].isValid())
      itemID.sendEnable(view_as<int>(this));
  }

  public void onPluginEnd() {
    if (lib.isExpCoreLoaded && this.expID.isValid())
      this.expID.remove();

    if (lib.isClassCoreLoaded)
      this.setClass(ClassID_Invalid);

    if (lib.isItemCoreLoaded)
      this.setItem(ItemID_Invalid);
  }

  public void onPutInServer() {
    if (lib.isExpCoreLoaded)
      this.expID = new ExpID(data.cvarMaxLvl.IntValue, data.cvarLvlRatio.IntValue);
  }

  public void onDisconnect() {
    if (lib.isClassCoreLoaded)
      this.setClass(ClassID_Invalid);

    if (lib.isItemCoreLoaded)
      this.setItem(ItemID_Invalid);
  }

  public void onDisconnectPost() {
    if (lib.isExpCoreLoaded && this.expID.isValid())
      this.expID.remove();
  }
};
