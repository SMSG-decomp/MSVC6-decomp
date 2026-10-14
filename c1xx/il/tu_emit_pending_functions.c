void __cdecl tu_emit_pending_functions(void)

{
  c1_symbol *fn;
  c1_type *pcVar1;
  int iVar2;
  bool bVar3;
  bool bVar4;
  byte bVar5;
  c1_symbol *cls;
  void *pvVar6;
  uint uVar7;
  c1_node *pcVar8;
  c1_symbol *in_ECX;
  c1_symbol *local_4;
  
  local_4 = in_ECX;
  iVar2 = g_pending_destructor_helpers;
  bVar4 = false;
  while (bVar3 = bVar4, iVar2 != 0) {
    g_pending_destructor_helpers = iVar2;
    list_pop_head(&g_pending_destructor_helpers);
    fn = *(c1_symbol **)(iVar2 + 4);
    bVar5 = fn->kind & 0x1f;
    if ((bVar5 == 7) || (bVar5 == 8)) {
      if (((byte)g_compile_flags_c4 & 0x20) != 0) {
        func_abandon_definition();
      }
      func_body_begin_generated(fn);
      iVar2 = g_pending_destructor_helpers;
      bVar4 = true;
    }
    else {
      cls = sym_class_type_of(fn);
      if ((((cls->detail).cls)->implicit_state41 & 0x10) == 0) {
        if ((cls->flags2 & 4) == 0) {
          tmpl_instantiate_if_needed(cls);
        }
        if (((((cls->detail).cls)->implicit_state41 & 0x10) != 0) ||
           ((((cls->detail).cls)->implicit_state43 & 0x10) != 0)) {
          pcVar1 = fn->type;
          if (((byte)g_compile_flags_c4 & 0x20) == 0) {
            func_body_begin_generated((c1_symbol *)0x0);
          }
          tmpl_prune_instance_list(fn);
          pvVar6 = symtab_14ac_lookup_by_name(fn);
          if (pvVar6 == (void *)0x0) {
            uVar7 = type_classify_class_form(fn->type,(int *)&local_4);
            if (uVar7 == 2) {
              pcVar8 = expr_reference_named_entity(fn,0);
              pcVar8 = expr_array_destroy_elements(pcVar8);
              stmt_emit_expression(pcVar8);
            }
            else {
              uVar7 = 4;
              pcVar8 = expr_reference_named_entity(fn,0);
              pcVar8 = expr_build_address_of(pcVar8,uVar7);
              pcVar8 = expr_build_destructor_call(local_4,pcVar8,3,1,0);
              stmt_emit_expression(pcVar8);
            }
          }
          else {
            tu_emit_guarded_static_destructor(fn);
          }
          fn->type = pcVar1;
        }
      }
      iVar2 = g_pending_destructor_helpers;
      bVar4 = false;
      if (bVar3) {
        func_definition_end('\0');
        iVar2 = g_pending_destructor_helpers;
        bVar4 = false;
      }
    }
  }
  g_pending_destructor_helpers = iVar2;
  return;
}

