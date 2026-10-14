void __fastcall clear_block_flag18_bit1(c2_function *fn)

{
  c2_block *pcVar1;
  
  for (pcVar1 = fn->cfg->first; pcVar1 != (c2_block *)0x0; pcVar1 = pcVar1->next) {
    pcVar1->flags = pcVar1->flags & 0xfffffffd;
  }
  return;
}

