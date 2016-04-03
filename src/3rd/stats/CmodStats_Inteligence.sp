#include <sourcemod>
#include <cmod>

static StatsID statsID;

public void OnAllPluginsLoaded() {
  statsID = new StatsID("Inteligence");
  statsID.setDesc("Increse skill effect");
}

public void OnPluginEnd() {
  statsID.remove();
}
