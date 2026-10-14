void __cdecl sym_emit_deferred_list(int *list)

{
  c1_symbol *sym;
  c1xx_function_record *rec;
  int *list_00;
  char cVar1;
  byte bVar2;
  
  sym_list_emit_deferred(list);
  while( true ) {
    if (g_deferred_symbols == (void *)0x0) {
      return;
    }
    sym = *(c1_symbol **)g_deferred_symbols;
    if (sym == (c1_symbol *)0x0) break;
    g_deferred_symbols = *(void **)((int)g_deferred_symbols + 4);
    cVar1 = sym_not_written_to_il(sym);
    if (cVar1 == '\0') {
      bVar2 = sym->kind & 0x1f;
      if ((((bVar2 == 7) || (bVar2 == 8)) || (bVar2 == 6)) &&
         (rec = (sym->tail).fn.record, rec != (c1xx_function_record *)0x0)) {
        func_emit_definition_record(rec);
        sym_list_emit_deferred((int *)((sym->tail).fn.record)->unk14);
      }
      else {
        il_emit_global_symbol((int *)&sym->name);
        if (((sym->kind & 0x1f) == 10) &&
           (list_00 = (sym->tail).data.dependents, list_00 != (int *)0x0)) {
          sym_emit_deferred_list(list_00);
          return;
        }
      }
    }
  }
  g_deferred_symbols = *(void **)((int)g_deferred_symbols + 4);
  return;
}

