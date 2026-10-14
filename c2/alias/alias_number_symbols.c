uint32_t __fastcall alias_number_symbols(c2_bitset *addressed,c2_bitset *params)

{
  uint8_t uVar1;
  c2_symbol_chunk **ppcVar2;
  c2_symbol_chunk *pcVar3;
  c2_symbol *pcVar4;
  uint32_t n;
  
  n = 1;
  pcVar3 = g_symbol_chunks;
  if (g_symbol_chunks == (c2_symbol_chunk *)0x0) {
    return 1;
  }
  do {
    pcVar4 = pcVar3->syms;
    if (pcVar4 < pcVar3->cursor) {
      do {
        uVar1 = pcVar4->cls;
        if (uVar1 != '\x10') {
          if (uVar1 == '\x04') {
            if ((pcVar4->flags5 & 2) != 0) {
              bitset_set(addressed,n);
            }
            (pcVar4->u34).refs = n;
            n = n + 1;
          }
          else if (uVar1 == '\x05') {
            if ((pcVar4->flags5 & 2) == 0) {
              pcVar4->flags6 = pcVar4->flags6 | 4;
              bitset_set(params,n);
              (pcVar4->u34).refs = n;
              n = n + 1;
            }
            else {
              bitset_set(addressed,n);
              bitset_set(params,n);
              (pcVar4->u34).refs = n;
              n = n + 1;
            }
          }
          else {
            (pcVar4->u34).refs = 0;
          }
        }
        pcVar4 = pcVar4 + 1;
      } while (pcVar4 < pcVar3->cursor);
    }
    ppcVar2 = &pcVar3->next;
    pcVar3 = *ppcVar2;
  } while (*ppcVar2 != (c2_symbol_chunk *)0x0);
  return n;
}

