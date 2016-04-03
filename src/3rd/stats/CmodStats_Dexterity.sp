#include <sourcemod>
#include <cmod>

const float speedMultipy = 0.005;

static StatsID dex;

public void OnAllPluginsLoaded() {
  dex = new StatsID("Dexterity");
  dex.setDesc("Increse player moved speed");
  dex.hookActivate(onActivate);
}

public void OnPluginEnd() {
  dex.remove();
}

public void onActivate(StatsID statsID, int client, int points) {
  SetEntPropFloat(client, Prop_Send, "m_flLaggedMovementValue", 1.0 + float(points) * speedMultipy);
}
