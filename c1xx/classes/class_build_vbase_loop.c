void __cdecl class_build_vbase_loop(c1_symbol *sym,int *mem_initializers)

{
  c1_vbase_vector *pcVar1;
  c1_symbol *cls;
  c1_node *labelref;
  c1_node *pcVar2;
  c1_node *right;
  int iVar3;
  c1_node *pcVar4;
  char emit;
  int dtor_kind;
  char register_dtor;
  uint jump_if_true;
  c1_vbase_vector *local_18;
  short local_14;
  
  labelref = label_new(0x1e);
  pcVar2 = expr_lookup_name_expression(PTR_104d162c);
  pcVar1 = ((sym->detail).cls)->vbases;
  if (pcVar1 != (c1_vbase_vector *)0x0) {
    local_14 = 0;
    local_18 = pcVar1;
  }
  jump_if_true = 1;
  pcVar4 = labelref;
  right = tree_new_int_constant(0);
  pcVar2 = expr_build_builtin_binary(';',pcVar2,right);
  stmt_emit_condition(pcVar2,pcVar4,jump_if_true);
  class_mark_member_list_used_all(sym);
  while (((pcVar1 != (c1_vbase_vector *)0x0 && (local_18 != (c1_vbase_vector *)0x0)) &&
         (iVar3 = (int)local_14, iVar3 < (int)(uint)local_18->count))) {
    local_14 = local_14 + 1;
    cls = local_18->data[iVar3]->base;
    iVar3 = local_18->data[iVar3]->offset;
    pcVar2 = init_take_base_initializer(mem_initializers,&cls->kind);
    register_dtor = '\x01';
    dtor_kind = 0;
    emit = '\0';
    pcVar4 = expr_this_plus_offset((int)cls,0,iVar3);
    pcVar2 = expr_build_call_of((c1_symbol *)0x0,cls,pcVar4,pcVar2,emit,dtor_kind,register_dtor);
    eh_mark_state_nodes_in_tree(pcVar2);
    pcVar2 = expr_full_expression_guarded(pcVar2,0);
    if (pcVar2 != (c1_node *)0x0) {
      stmt_emit_expression(pcVar2);
    }
  }
  label_emit_definition(labelref);
  return;
}

