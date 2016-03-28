static ClientStatsData data;

methodmap ClientStats {
  property int freePts {
    public get() {
      return data.getClientFreePts(view_as<int>(this));
    }

    public set(int value) {
      data.setClientFreePts(view_as<int>(this), value);
    }
  }

  public int getPts(StatsID statsID, ClientPtsType type) {
    return data.getStatsPtsArray(type).getValue(view_as<int>(statsID), view_as<int>(this));
  }

  public void setPts(StatsID statsID, int value, ClientPtsType type) {
    data.getStatsPtsArray(type).setValue(view_as<int>(statsID), value, view_as<int>(this));
  }

  public int getAllPts(StatsID statsID) {
    return data.clientAllPtsArray.getValue(view_as<int>(statsID), view_as<int>(this));
  }

  public int setAllPts(StatsID statsID, int value) {
    data.clientAllPtsArray.setValue(view_as<int>(statsID), value, view_as<int>(this));
  }

  public void recalculateAllPts(StatsID statsID) {
    int pts = 0;
    for (ClientPtsType type = ClientPts_General; type < ClientPts_Count; ++type)
      pts += this.getPts(statsID, type);

    this.setAllPts(statsID, pts);
  }

  public bool spendPts(StatsID statsID, int pts) {
    if (0 > pts || pts > this.freePts)
      return false;

    this.freePts -= pts;
    this.setPts(statsID, this.getPts(statsID, ClientPts_General) + pts, ClientPts_General);
    this.recalculateAllPts(statsID);

    return true;
  }

  public void resetPts(StatsID statsID) {
    this.freePts += this.getPts(statsID, ClientPts_General);
    this.setPts(statsID, 0, ClientPts_General);
  }

  public void resetAllPts() {
    for (StatsID statsID = view_as<StatsID>(0); statsID < view_as<StatsID>(data.clientAllPtsArray.length); ++statsID)
      if (statsID.isValid())
        this.resetPts(statsID);
  }
}
