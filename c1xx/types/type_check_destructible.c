void __cdecl type_check_destructible(c1_symbol *sym)

{
  byte bVar1;
  c1_symbol *cls;
  
  if (((g_error_count == 0) && ((sym->flags3 & 4) == 0)) && (g_block_depth == '\0')) {
    cls = sym_class_needing_init(sym);
    if (cls != (c1_symbol *)0x0) {
      if ((cls->flags2 & 4) == 0) {
        tmpl_instantiate_if_needed(cls);
      }
      bVar1 = ((cls->detail).cls)->implicit_state41 & 0x10;
      if ((bVar1 == 0) && ((((cls->detail).cls)->implicit_state43 & 0x10) == 0)) {
        diag_error(0x106,sym);
        sym->flags3 = sym->flags3 | 4;
      }
      else if (bVar1 == 0) {
        sym_queue_destructible_object(sym);
        return;
      }
    }
  }
  return;
}

