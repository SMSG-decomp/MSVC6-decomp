c1_symbol * __thiscall decl_declare_from_declarator(c1_declarator *d,byte *spec)

{
  c1_symbol *pcVar1;
  
  pcVar1 = decl_declare_and_check(d,spec);
  d->sym = pcVar1;
  if (pcVar1 == (c1_symbol *)0x0) {
    return (c1_symbol *)0x0;
  }
  if ((pcVar1->flags3 & 4) == 0) {
    if ((pcVar1->storage & 7) != 1) {
      pcVar1 = sym_class_needing_init(pcVar1);
      if (((pcVar1 != (c1_symbol *)0x0) && (g_opt_Zg == '\0')) &&
         ((g_compile_flags_cc & 0x200000) == 0)) {
        if ((d->sym->flags2 & 4) != 0) {
          init_set_target_symbol(d->sym);
          pcVar1 = (c1_symbol *)decl_begin_initialized_definition(d->sym);
          d->sym = pcVar1;
          decl_finish_initialization(pcVar1,(c1_node *)0x0);
        }
        type_check_destructible_2(d->sym);
      }
      pcVar1 = d->sym;
    }
    return pcVar1;
  }
  return (c1_symbol *)0x0;
}

