int __fastcall iv_def_dominated_by(void *blk,c2_symbol *iv)

{
  c2_list_cell *pcVar1;
  uint32_t uVar2;
  
  pcVar1 = iv->defs;
  while( true ) {
    if (pcVar1 == (c2_list_cell *)0x0) {
      return 0;
    }
    uVar2 = block_range_dominated((pcVar1->u04).tuple,blk);
    if (uVar2 != 0) break;
    pcVar1 = pcVar1->next;
  }
  return 1;
}

