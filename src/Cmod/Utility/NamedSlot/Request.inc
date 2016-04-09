NamedSlotData data;

methodmap Request {

  public ArrayStack getNamedSlotStack(char[] name) {
    ArrayStack stack;

    if (!data.waitList.GetValue(name, stack)) {
      stack = new ArrayStack();
      data.waitList.SetValue(name, stack);
    }

    return stack
  }

  public void send(ForwardRequestAvalible fwd, Slot slot, char[] name) {
    fwd.send(slot, name);
    fwd.remove();
  }

  public void addToRequest(char[] name, Handle plugin, Function callback) {
    ForwardRequestAvalible requestFwd = new ForwardRequestAvalible();
    Slot slot = view_as<Slot>(data.nameArray.findString(name));

    if (slot != Slot_Invalid) {
      this.send(requestFwd, slot, name);
      return;
    }

    ArrayStack stack = this.getNamedSlotStack(name);
    stack.Push(requestFwd);
  }

  public void sendToFwdsFromStack(ArrayStack stack, Slot slot, char[] name) {
    ForwardRequestAvalible fwd;
    while (!stack.Empty) {
      fwd = stack.Pop();
      this.send(fwd, slot, name);
    }
  }

  public void onNamedSlotCreate(Slot slot, char[] name) {
    ArrayStack stack = this.getNamedSlotStack(name);
    this.sendToFwdsFromStack(stack, slot, name);
  }
}
