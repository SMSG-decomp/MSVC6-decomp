void __fastcall il_emitter_suspend_enter(char *state)

{
  if (*(int *)(state + 4) == 0) {
    *(c1_il_emitter **)(state + 8) = g_il_emitter;
    g_il_emitter = il_emitter_get_default();
    *state = '\0';
  }
  *(int *)(state + 4) = *(int *)(state + 4) + 1;
  return;
}

