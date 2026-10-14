c1_symbol * __cdecl sym_clone_with_new_id(c1_thunk_key *thunk_key)

{
  byte bVar1;
  c1_symbol *pcVar2;
  c1_symbol *pcVar3;
  c1_node *pcVar4;
  int value;
  byte bVar5;
  uint uVar6;
  int iVar7;
  c1_node *pcVar8;
  
  if (((((g_block_depth == '\0') || (-1 < g_class_depth)) ||
       ((g_compile_flags_c8 & 0x10000000) != 0)) ||
      ((((g_compile_flags_c8 & 0x40000000) != 0 && (((byte)g_compile_flags_cc & 8) == 0)) &&
       ((g_compile_flags_c4 & 0x200) == 0)))) || (((byte)g_compile_flags_cc & 0x50) != 0)) {
    iVar7 = 0;
  }
  else {
    iVar7 = 4;
  }
  pcVar3 = thunk_key->target;
  pcVar2 = arena_alloc(g_arenas + iVar7,g_symbol_size_table[pcVar3->kind & 0x1f] + 3 & 0xfffffffc);
  if (pcVar2 == (c1_symbol *)0x0) {
    pcVar3 = (c1_symbol *)0x0;
  }
  else {
    pcVar3 = sym_copy_unlinked(pcVar2,pcVar3,iVar7);
  }
  if (g_next_entity_id < 0x7fffffff) {
    uVar6 = pcVar3->entity ^ g_next_entity_id;
    bVar5 = *(byte *)((int)&pcVar3->tail + 10);
    g_next_entity_id = g_next_entity_id + 1;
    pcVar3->entity = uVar6 & 0xffffff ^ pcVar3->entity;
    *(byte *)((int)&pcVar3->tail + 10) = bVar5 & 0xf1;
    pcVar3->next = (c1_symbol *)0x0;
    sym_set_or_clear_attribute(pcVar3,(void *)thunk_key->delta);
    pcVar3->detail = (c1_symbol_detail)thunk_key->vtordisp;
    bVar5 = *(byte *)((int)&pcVar3->tail + 9);
    bVar1 = ((((byte)thunk_key->kind & 7) != 1) + '\x01') * '\x04';
    pcVar3->flags2 = pcVar3->flags2 | 4;
    *(byte *)((int)&pcVar3->tail + 9) = bVar1 | bVar5 & 0xf3;
    *(byte *)((int)&pcVar3->tail + 9) = bVar1 | bVar5 & 0xf1;
    bVar5 = pcVar3->storage & 0xf8 ^ 1;
    pcVar3->storage = bVar5;
    pcVar3->storage = '\0';
    pcVar3->flags21 = '\0';
    pcVar3->flags22 = '\0';
    pcVar3->flags23 = '\0';
    bVar5 = (pcVar3->storage ^ bVar5 & 7) & 7 ^ pcVar3->storage;
    pcVar3->storage = bVar5;
    pcVar3->storage = bVar5 | 0x40;
    pcVar3->flags21 = pcVar3->flags21 | 2;
    if ((thunk_key->target->flags23 & 1) != 0) {
      pcVar2 = sym_segment_record(thunk_key->target);
      sym_set_segment_checked(pcVar3,pcVar2);
    }
    pcVar3->key_ref = pcVar3->key_ref & 7;
    if (g_c9il_mode == '\0') {
      il_symbol_key_assign(pcVar3);
    }
    il_begin_function_body(1);
    func_record_alloc(pcVar3);
    g_function_parameter_scope = (c1_sym_list *)0x0;
    il_emit_tuple(0x53,(node *)0x0);
    pcVar8 = (c1_node *)0x0;
    pcVar4 = tree_new_symbol_ref(pcVar3,'\x01');
    pcVar4 = tree_new_binary('l',pcVar4,pcVar8);
    il_emit_expression_tree(pcVar4);
    iVar7 = 2;
    if (((byte)thunk_key->kind & 7) == 4) {
      pcVar4 = tree_new_int_constant(thunk_key->vtordisp);
      pcVar4 = tree_append_list_item((c1_node *)0x0,pcVar4,iVar7);
      iVar7 = 2;
      pcVar8 = tree_new_int_constant(thunk_key->delta);
      pcVar4 = tree_append_list_item(pcVar4,pcVar8,iVar7);
      iVar7 = 2;
      pcVar8 = tree_new_symbol_ref(thunk_key->target,'\x01');
      pcVar4 = tree_append_list_item(pcVar4,pcVar8,iVar7);
      iVar7 = 2;
      value = sym_clone_return_null();
      pcVar8 = tree_new_int_constant(value);
    }
    else {
      pcVar4 = tree_new_symbol_ref(thunk_key->target,'\x01');
      pcVar4 = tree_append_list_item((c1_node *)0x0,pcVar4,iVar7);
      iVar7 = 2;
      pcVar8 = tree_new_int_constant(thunk_key->delta);
    }
    pcVar4 = tree_append_list_item(pcVar4,pcVar8,iVar7);
    pcVar8 = tree_new_int_constant(thunk_key->kind);
    pcVar4 = tree_new_binary(0x9d,pcVar8,pcVar4);
    il_emit_expression_tree(pcVar4);
    il_emit_tuple(0x47,(node *)0x0);
    pcVar4 = tree_new_int_constant(0);
    il_emit_tuple(0x54,pcVar4);
    func_end_emit_il(pcVar3);
    return pcVar3;
  }
  diag_fatal_simple(0x37);
}

