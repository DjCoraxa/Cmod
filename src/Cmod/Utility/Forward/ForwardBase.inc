#if defined _cmod_utility_forwardbase_included
 #endinput
#endif
#define _cmod_utility_forwardbase_included

methodmap ForwardBase < Handle {
  property Handle handle {
    public get() { return as<Handle>(this); }
  }

  public bool hook(Handle plugin, Function callback) {
    return AddToForward(this, plugin, callback);
  }

  public bool unhook(Handle plugin, Function callback) {
    return RemoveFromForward(this, plugin, callback);
  }

  public void remove() {
    CloseHandle(this);
  }
}
