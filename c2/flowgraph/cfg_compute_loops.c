void __fastcall cfg_compute_loops(c2_function *fn)

{
  c2_block *pcVar1;
  
  cfg_compute_reach_sets(fn);
  cfg_find_loops(fn,0);
  for (pcVar1 = fn->cfg->first; pcVar1 != (c2_block *)0x0; pcVar1 = pcVar1->next) {
    pcVar1->x64 = 0;
  }
  arena_reset(4);
  return;
}

