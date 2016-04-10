static SlotArray requestContent;

methodmap RequestData __nullable__ < SlotData {
  public RequestData() {
    requestContent = new SlotArray(Request_Count);
  }

  property SlotStatus requestContent {
    public get() {
      return requestContent;
    }
  }
};
