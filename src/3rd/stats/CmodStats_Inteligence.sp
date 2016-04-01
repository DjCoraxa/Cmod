#include <sourcemod>
#include <cmod>

static StatsID statsID;

public void OnPluginStart() {
  statsID = new StatsID("Inteligence");
  statsID.setDesc("Increse skill effect");
}
