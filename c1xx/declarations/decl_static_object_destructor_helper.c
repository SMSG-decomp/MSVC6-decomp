void __cdecl decl_static_object_destructor_helper(c1_symbol *sym)

{
  c1_symbol *pcVar1;
  fe_name *pfVar2;
  byte bVar3;
  
  pcVar1 = sym_class_needing_init(sym);
  if (pcVar1 != (c1_symbol *)0x0) {
    if ((pcVar1->flags2 & 4) == 0) {
      tmpl_instantiate_if_needed(pcVar1);
    }
    if (((((pcVar1->detail).cls)->implicit_state41 & 0x10) == 0) &&
       ((((pcVar1->detail).cls)->implicit_state43 & 0x10) == 0)) {
      diag_error(0x106,sym);
      return;
    }
    pcVar1 = func_new_dynamic_initializer();
    pfVar2 = name_intern_decorated_in_scope_2(sym,pcVar1,'\0');
    pcVar1->name = pfVar2;
    pcVar1->flags1 = pcVar1->flags1 & 0xfe | 2;
    bVar3 = pcVar1->storage & 0xf8 ^ 1;
    pcVar1->storage = bVar3;
    pcVar1->storage = bVar3 | 0x40;
    pcVar1->flags21 = pcVar1->flags21 | 1;
    func_body_begin_generated((c1_symbol *)0x0);
    func_emit_atexit_registration(pcVar1);
    func_definition_end('\x01');
    sym_queue_destructible_object(sym);
    sym_queue_destructible_object(pcVar1);
  }
  return;
}

