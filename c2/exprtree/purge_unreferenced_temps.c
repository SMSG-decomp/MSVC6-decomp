int __fastcall purge_unreferenced_temps(c2_function *fn)

{
  bool bVar1;
  c2_symbol_chunk **ppcVar2;
  c2_symbol *pcVar3;
  int iVar4;
  c2_symbol *chain;
  c2_symbol_chunk *pcVar5;
  
  iVar4 = 0;
  mark_referenced_symbols((c2_node *)fn->cfg->first->head);
  pcVar5 = g_symbol_chunks;
  if (g_symbol_chunks == (c2_symbol_chunk *)0x0) {
    return 0;
  }
  do {
    chain = pcVar5->syms;
    if (chain < pcVar5->cursor) {
      do {
        if (((chain->cls != '\x10') && (chain->cls == '\x03')) && (chain->storage == chain)) {
          bVar1 = false;
          pcVar3 = chain;
          if (chain != (c2_symbol *)0x0) {
            do {
              if ((pcVar3->flags6 & 2) != 0) {
                bVar1 = true;
                pcVar3->flags6 = pcVar3->flags6 & 0xfd;
              }
              pcVar3 = pcVar3->part_next;
            } while (pcVar3 != (c2_symbol *)0x0);
            if (bVar1) goto LAB_1070b8e0;
          }
          iVar4 = iVar4 + 1;
          symbol_free_chain(chain);
        }
LAB_1070b8e0:
        chain = chain + 1;
      } while (chain < pcVar5->cursor);
    }
    ppcVar2 = &pcVar5->next;
    pcVar5 = *ppcVar2;
    if (*ppcVar2 == (c2_symbol_chunk *)0x0) {
      return iVar4;
    }
  } while( true );
}

