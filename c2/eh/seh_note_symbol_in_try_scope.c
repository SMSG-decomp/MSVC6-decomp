void __fastcall seh_note_symbol_in_try_scope(c2_symbol *s)

{
  c2_seh_try_scope *pcVar1;
  c2_seh_symbol_cell **ppcVar2;
  void *pvVar3;
  int iVar4;
  
  pcVar1 = seh_current_scope_record();
  if (pcVar1 != (c2_seh_try_scope *)0x0) {
    while ((pcVar1->marker_op != 0x196 && (pcVar1->marker_op != 0x194))) {
      pcVar1 = seh_find_try_record(g_seh_try_records,pcVar1->enclosing_level);
      if (pcVar1 == (c2_seh_try_scope *)0x0) {
        return;
      }
    }
    if (pcVar1->written_symbols == (c2_seh_symbol_cell **)0x0) {
      ppcVar2 = arena_alloc(4,0x40);
      pcVar1->written_symbols = ppcVar2;
      for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
        *ppcVar2 = (c2_seh_symbol_cell *)0x0;
        ppcVar2 = ppcVar2 + 1;
      }
    }
    ppcVar2 = pcVar1->written_symbols;
    pvVar3 = seh_hash_lookup(ppcVar2,s->id);
    if (pvVar3 == (void *)0x0) {
      seh_hash_insert(ppcVar2,s);
    }
  }
  return;
}

