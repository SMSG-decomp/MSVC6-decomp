void __fastcall cfg_create(c2_function *fn,c2_tuple *boundary,c2_tuple *end,int arena)

{
  c2_cfg *pcVar1;
  
  g_block_count = 0;
  pcVar1 = cfg_new(arena);
  fn->cfg = pcVar1;
  block_new(fn,(c2_block *)0x0,boundary,end);
  return;
}

