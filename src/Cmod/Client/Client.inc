static ClientData data;
static LibraryMan lib;
static CmodStats cmodStats;

static ExpID clientExpID[MAXPLAYERS + 1] = {ExpID_Invalid, ...};
static ClassID clientClass[MAXPLAYERS + 1] = {ClassID_Invalid, ...};
static ItemID clientItem[MAXPLAYERS + 1] = {ItemID_Invalid, ...};
static int clientFreeStatsPts[MAXPLAYERS + 1];

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

  property int freeStatsPts {
    public get() {
      return clientFreeStatsPts[this];
    }
    public set(int pts) {
      clientFreeStatsPts[this] = pts;
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

  public int getStatsPts(StatsID statsID, ClientPtsType type) {
    return data.getStatsPtsArray(type).getValue(view_as<int>(statsID), view_as<int>(this));
  }

  public void setStatsPts(StatsID statsID, int value, ClientPtsType type) {
    data.getStatsPtsArray(type).setValue(view_as<int>(statsID), value, view_as<int>(this));
  }

  public int getStatsAllPts(StatsID statsID) {
    return data.clientAllPtsArray.getValue(view_as<int>(statsID), view_as<int>(this));
  }

  public int setStatsAllPts(StatsID statsID, int value) {
    data.clientAllPtsArray.setValue(view_as<int>(statsID), value, view_as<int>(this));
  }

  public void recalculateStatsAllPts(StatsID statsID) {
    int pts = 0;
    for (ClientPtsType type = ClientPts_General; type < ClientPts_Count; ++type)
      pts += this.getStatsPts(statsID, type);

    this.setStatsAllPts(statsID, pts);
  }

  public bool spendStatsPts(StatsID statsID, int pts) {
    if (0 > pts || pts > this.freeStatsPts)
      return false;

    this.freeStatsPts -= pts;
    this.setStatsPts(statsID, this.getStatsPts(statsID, ClientPts_General) + pts, ClientPts_General);
    this.recalculateStatsAllPts(statsID);

    return true;
  }

  public void resetStatsPts(StatsID statsID) {
    this.freeStatsPts += this.getStatsPts(statsID, ClientPts_General);
    this.setStatsPts(statsID, 0, ClientPts_General);
  }

  public void resetAllStatsPts() {
    for (StatsID statsID = view_as<StatsID>(0); statsID < view_as<StatsID>(data.clientAllPtsArray.length); ++statsID)
      if (statsID.isValid())
        this.resetStatsPts(statsID);
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

  public void onSpawn() {
    if (lib.isStatsCoreLoaded) {
      StatsID maxID = cmodStats.maxID;
      for (StatsID statsID = view_as<StatsID>(0); statsID < maxID; ++statsID) {
        if (statsID.isValid()) {
          statsID.sendActivate(view_as<int>(this), this.getStatsAllPts(statsID));
        }
      }
    }
  }

  public void onStatsCreate(StatsID statsID) {
    for (ClientPtsType type = ClientPts_General; type < ClientPts_Count; ++type)
      this.setStatsPts(statsID, 0, type);

    this.setStatsAllPts(statsID, 0);
    this.recalculateStatsAllPts(statsID);
  }
};
