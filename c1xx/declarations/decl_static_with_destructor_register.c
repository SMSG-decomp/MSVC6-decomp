void __cdecl decl_static_with_destructor_register(c1_symbol *sym)

{
  c1_u8 cVar1;
  byte bVar2;
  c1_symbol *pcVar3;
  c1_symbol *pcVar4;
  void *sym2;
  fe_name *pfVar5;
  
  pcVar3 = sym_class_needing_init(sym);
  if (pcVar3 != (c1_symbol *)0x0) {
    if ((pcVar3->flags2 & 4) == 0) {
      tmpl_instantiate_if_needed(pcVar3);
    }
    if (((((pcVar3->detail).cls)->implicit_state41 & 0x10) == 0) &&
       ((((pcVar3->detail).cls)->implicit_state43 & 0x10) == 0)) {
      diag_error(0x106,sym);
      label_emit_definition(g_static_guard_skip_label);
      return;
    }
    pcVar3 = func_new_dynamic_initializer();
    if (((g_current_function != (c1_symbol *)0x0) && ((g_current_function->flags21 & 1) != 0)) &&
       (((g_current_function->storage & 7) != 3 || ((g_current_function->flags1 & 4) != 0)))) {
      pcVar4 = pcVar3;
      sym2 = sym_inline_instance_of(sym);
      pfVar5 = name_intern_decorated_in_scope(sym2,pcVar4);
      pcVar3->name = pfVar5;
      pcVar3->flags1 = pcVar3->flags1 & 0xfe | 2;
      bVar2 = pcVar3->storage & 0xf8 ^ 1;
      pcVar3->storage = bVar2;
      pcVar3->storage = bVar2 | 0x40;
      pcVar3->flags21 = pcVar3->flags21 | 1;
    }
    func_emit_atexit_registration(pcVar3);
    cVar1 = g_block_depth;
    g_block_depth = '\0';
    pcVar4 = sym_inline_instance_of(sym);
    sym_queue_destructible_object(pcVar4);
    sym_queue_destructible_object(pcVar3);
    g_block_depth = cVar1;
  }
  label_emit_definition(g_static_guard_skip_label);
  return;
}

