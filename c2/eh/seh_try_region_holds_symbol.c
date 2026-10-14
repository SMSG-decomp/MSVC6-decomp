int __fastcall seh_try_region_holds_symbol(c2_symbol *s)

{
  c2_seh_try_scope *pcVar1;
  void *pvVar2;
  
  pcVar1 = seh_current_scope_record();
  while( true ) {
    if (pcVar1 == (c2_seh_try_scope *)0x0) {
      return 0;
    }
    if ((pcVar1->written_symbols != (c2_seh_symbol_cell **)0x0) &&
       (pvVar2 = seh_hash_lookup(pcVar1->written_symbols,s->id), pvVar2 != (void *)0x0)) break;
    pcVar1 = seh_find_try_record(g_seh_try_records,pcVar1->enclosing_level);
  }
  return 1;
}

