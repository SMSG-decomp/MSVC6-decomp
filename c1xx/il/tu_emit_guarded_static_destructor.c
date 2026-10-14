void __cdecl tu_emit_guarded_static_destructor(c1_symbol *sym)

{
  c1_symbol *sym_00;
  uint uVar1;
  c1_node *pcVar2;
  
  sym_00 = sym;
  init_static_guard_begin();
  uVar1 = type_classify_class_form(sym_00->type,(int *)&sym);
  if (uVar1 != 2) {
    uVar1 = 4;
    pcVar2 = expr_reference_named_entity(sym_00,0);
    pcVar2 = expr_build_address_of(pcVar2,uVar1);
    pcVar2 = expr_build_destructor_call(sym,pcVar2,3,1,0);
    stmt_emit_expression(pcVar2);
    label_emit_definition(g_static_guard_skip_label);
    return;
  }
  pcVar2 = expr_reference_named_entity(sym_00,0);
  pcVar2 = expr_array_destroy_elements(pcVar2);
  stmt_emit_expression(pcVar2);
  label_emit_definition(g_static_guard_skip_label);
  return;
}

