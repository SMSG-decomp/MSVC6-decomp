void __cdecl pragma_init_seg_set_atexit(int name)

{
  byte bVar1;
  c1_lookup_result *pcVar2;
  c1_lookup_entry *pcVar3;
  c1_symbol *sym;
  
  if (g_atexit_symbol != (c1_symbol *)0x0) {
LAB_1046e3e1:
    pcVar2 = (*g_current_scope->global_scope->vtbl->lookup)
                       (g_current_scope->global_scope,(void *)name,1);
    if (pcVar2 != (c1_lookup_result *)0x0) {
      pcVar3 = lookup_check_ambiguous_symbol(pcVar2,'\x01');
      if (pcVar3 != (c1_lookup_entry *)0x0) {
        sym = pcVar3->sym;
        bVar1 = sym->kind & 0x1f;
        if ((((bVar1 == 0x10) || (bVar1 == 7)) ||
            (((bVar1 == 6 || ((bVar1 == 0x11 || (bVar1 == 8)))) || (bVar1 == 0x1b)))) ||
           ((bVar1 == 0x1a &&
            ((((bVar1 = **(byte **)sym->type & 0x1f, bVar1 == 0x10 || (bVar1 == 7)) || (bVar1 == 6))
             || (((bVar1 == 0x11 || (bVar1 == 8)) || (bVar1 == 0x1b)))))))) {
          sym = (c1_symbol *)
                ovl_find_function_with_type
                          (sym,g_atexit_symbol->type,0,0,(c1_symbol *)0x0,(c1_declarator *)0x0,0);
        }
        if (((sym != (c1_symbol *)0x0) && ((sym->kind & 0x1f) == 7)) &&
           (sym->type == g_atexit_symbol->type)) {
          g_init_seg_atexit_function = sym;
          return;
        }
      }
    }
    diag_error(0x165,name,g_atexit_symbol->type);
    return;
  }
  pcVar2 = (*g_current_scope->global_scope->vtbl->lookup)
                     (g_current_scope->global_scope,g_atexit_name,1);
  if (pcVar2 != (c1_lookup_result *)0x0) {
    pcVar3 = lookup_check_ambiguous_symbol(pcVar2,'\x01');
    if (pcVar3 != (c1_lookup_entry *)0x0) {
      g_atexit_symbol = pcVar3->sym;
      bVar1 = g_atexit_symbol->kind & 0x1f;
      if ((((((bVar1 == 0x10) || (bVar1 == 7)) || (bVar1 == 6)) || ((bVar1 == 0x11 || (bVar1 == 8)))
           ) || (bVar1 == 0x1b)) ||
         ((bVar1 == 0x1a &&
          (((bVar1 = **(byte **)g_atexit_symbol->type & 0x1f, bVar1 == 0x10 || (bVar1 == 7)) ||
           ((bVar1 == 6 || (((bVar1 == 0x11 || (bVar1 == 8)) || (bVar1 == 0x1b)))))))))) {
        g_atexit_symbol = sym_first_function_of_overload_set(g_atexit_symbol,'\x01');
      }
      goto LAB_1046e3e1;
    }
  }
  diag_fatal(1,".\\funcs.c",0x3af);
}

