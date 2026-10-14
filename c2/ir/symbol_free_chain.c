void __fastcall symbol_free_chain(c2_symbol *chain)

{
  c2_symbol *pcVar1;
  
  if (chain->cls == '\x03') {
    if (chain != (c2_symbol *)0x0) {
      do {
        pcVar1 = chain;
        (pcVar1->u28).free_next = g_temp_symbol_free;
        pcVar1->cls = '\x10';
        g_temp_symbol_free = pcVar1;
        chain = pcVar1->part_next;
      } while (pcVar1->part_next != (c2_symbol *)0x0);
      return;
    }
  }
  else {
    while (pcVar1 = chain, pcVar1 != (c2_symbol *)0x0) {
      chain = pcVar1->part_next;
      bitset_clear(g_local_symbol_ids,pcVar1->id);
      pcVar1->cls = '\x10';
      (pcVar1->u28).free_next = g_local_symbol_free;
      g_local_symbol_free = pcVar1;
    }
  }
  return;
}

