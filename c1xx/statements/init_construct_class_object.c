void __cdecl init_construct_class_object(c1_symbol *sym,int args)

{
  byte bVar1;
  c1_type *pcVar2;
  c1_symbol *obj_type;
  c1_node *pcVar3;
  c1_node *pcVar4;
  void *pvVar5;
  uint mode;
  
  obj_type = sym_class_needing_init(sym);
  pcVar2 = sym->type;
  sym->flags4 = sym->flags4 & 0xfb;
  if ((((byte)g_compile_flags_cc & 1) == 0) || ((g_compile_flags_c4 & 0x20000) != 0)) {
    if (((args == 0) && (bVar1 = ((obj_type->detail).cls)->implicit_state41, (bVar1 & 2) != 0)) &&
       ((bVar1 & 0x10) != 0)) {
      eh_pop_array_init_state();
      return;
    }
    init_begin_dynamic_initializer(sym);
    pcVar3 = init_collect_destructible_item(obj_type,(c1_node *)args);
    tmpl_prune_instance_list(sym);
    mode = 4;
    pcVar4 = expr_reference_named_entity(sym,0);
    pcVar4 = expr_build_address_of(pcVar4,mode);
    pcVar3 = expr_build_new('\0',0,sym,(int)pcVar3,pcVar4,0);
    pcVar3 = expr_full_expression_guarded(pcVar3,2);
    if (pcVar3 != pcVar4) {
      stmt_emit_expression(pcVar3);
    }
    eh_pop_array_init_state();
    sym->type = pcVar2;
    if ((((g_compile_flags_c4 & 0x20000) != 0) && ((g_compile_flags_c4 & 0x20) == 0)) &&
       ((sym->storage & 7) == 3)) {
      decl_static_with_destructor_register(sym);
    }
  }
  else {
    pvVar5 = symtab_14ac_lookup_by_name(sym);
    if (pvVar5 != (void *)0x0) {
      func_define_dynamic_initializer(sym,(int)obj_type,(c1_node *)args);
      sym->type = pcVar2;
      decl_static_object_destructor_helper(sym);
      return;
    }
  }
  return;
}

