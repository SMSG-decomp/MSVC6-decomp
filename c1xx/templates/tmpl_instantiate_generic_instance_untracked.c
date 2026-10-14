c1_symbol * __cdecl tmpl_instantiate_generic_instance_untracked(c1_symbol *tmpl)

{
  c1xx_emitter_suspend *pcVar1;
  c1_symbol *pcVar2;
  int iVar3;
  
  pcVar1 = g_emitter_suspend;
  if (g_emitter_suspend->depth == 0) {
    g_emitter_suspend->saved = g_il_emitter;
    g_il_emitter = il_emitter_get_default();
    pcVar1->enabled = '\0';
  }
  pcVar1->depth = pcVar1->depth + 1;
  if (g_minimal_rebuild_tracker != (c1_mre_tracker *)0x0) {
    g_minimal_rebuild_tracker->current->minrebuild_off = 1;
  }
  pcVar2 = tmpl_instantiate_generic_instance(tmpl);
  if (g_minimal_rebuild_tracker != (c1_mre_tracker *)0x0) {
    g_minimal_rebuild_tracker->current->minrebuild_off = 0;
  }
  pcVar1 = g_emitter_suspend;
  iVar3 = g_emitter_suspend->depth + -1;
  g_emitter_suspend->depth = iVar3;
  if (iVar3 == 0) {
    g_il_emitter = pcVar1->saved;
    pcVar1->enabled = '\x01';
  }
  return pcVar2;
}

