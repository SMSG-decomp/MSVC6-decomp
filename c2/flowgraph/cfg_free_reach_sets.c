void __fastcall cfg_free_reach_sets(c2_function *fn)

{
  c2_block *pcVar1;
  
  for (pcVar1 = fn->cfg->first; pcVar1 != (c2_block *)0x0; pcVar1 = pcVar1->next) {
    pcVar1->x64 = 0;
  }
  arena_reset(4);
  return;
}

