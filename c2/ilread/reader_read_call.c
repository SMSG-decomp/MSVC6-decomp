void __fastcall
reader_read_call(c2_reader_cell **stack,c2_reader_op *op,int depth,c2_function *fn,int this_mode)

{
  uint8_t uVar1;
  byte bVar2;
  c2_reader_cell *pcVar3;
  uint32_t uVar4;
  c2_tuple *pcVar5;
  int iVar6;
  c2_operand *pcVar7;
  c2_tuple *first;
  c2_symbol *pcVar8;
  c2_fe_symbol *pcVar9;
  c2_fe_symbol *pcVar10;
  c2_function *pcVar11;
  ushort uVar12;
  ushort type;
  uint16_t id;
  c2_reader_cell *local_28;
  c2_operand *local_24;
  c2_reader_cell *local_20;
  c2_operand *local_1c;
  c2_reader_op *local_18;
  uint32_t local_14;
  c2_operand *local_10;
  c2_operand *local_c;
  c2_tuple *local_8;
  c2_reader_cell **local_4;
  
  local_28 = *stack;
  pcVar3 = local_28->before;
  type = op->type;
  local_10 = (c2_operand *)0x0;
  local_18 = op;
  local_4 = stack;
  if ((((pcVar3 == (c2_reader_cell *)0x0) || (pcVar5 = pcVar3->tail, (pcVar5->flags & 1) == 0)) ||
      (pcVar5->op != 0x1a1)) || (pcVar3->head->next != pcVar5)) {
    local_8 = (c2_tuple *)0x0;
  }
  else {
    local_8 = reader_pop(&local_28->before);
  }
  if (this_mode == 0) {
    local_24 = reader_pop_operand(local_28);
  }
  else if (this_mode == 1) {
    reader_pop_two_merge(&local_28,&local_24,&local_1c,0);
    pcVar5 = tuple_new_unary_temp(0x15a,0x3004,local_1c,tuple_splice_after,local_28->tail);
    local_10 = pcVar5->dst;
    local_28->tail = pcVar5;
  }
  else {
    pcVar7 = reader_duplicate_operand(local_28);
    reader_push(&local_28,(c2_node *)pcVar7);
    reader_load_value(local_28,0x3004,0,0);
    reader_pop_two_merge(&local_28,&local_1c,&local_c,0);
    tuple_splice_after(local_28->tail,(c2_tuple *)local_c);
    local_28->tail = (c2_tuple *)local_c;
    reader_binary_op(&local_28,0x16d);
    reader_load_value(local_28,0x3004,0,0);
    local_24 = reader_pop_operand(local_28);
    local_24->flags = local_24->flags | 0x80;
    pcVar5 = tuple_new_unary_temp(0x15a,0x3004,local_1c,tuple_splice_after,local_28->tail);
    local_10 = pcVar5->dst;
    local_28->tail = pcVar5;
  }
  pcVar11 = fn;
  if (op->op == 0x40) {
    uVar4 = (local_24->u18).lo;
    local_14 = uVar4;
    node_free((c2_node *)local_24);
    id = (uint16_t)uVar4;
    pcVar5 = tuple_new_intrinsic_result
                       (400,type,(c2_operand *)0x0,(c2_operand *)0x0,(c2_operand *)0x0,
                        (c2_operand *)0x0,id,tuple_splice_after,local_28->tail);
    local_28->tail = pcVar5;
    iVar6 = intrinsic_id_is_a5_aa_d8(id);
    if (iVar6 != 0) {
      if ((id == 0xde) || (id == 0xdf)) {
        pcVar9 = fe_symbol_new_local(g_reading_function->scope,6,type & 0xfff,1,1,'\x04',0);
        pcVar11 = (c2_function *)operand_for_fe_symbol(pcVar9);
      }
      else {
        pcVar11 = (c2_function *)operand_new_temp_sym(type);
      }
      tuple_replace_dst(local_28->tail,local_28->tail->dst,(c2_operand *)pcVar11);
    }
  }
  else {
    local_14 = 0;
    if ((local_24->kind == '\x04') &&
       (pcVar9 = (c2_fe_symbol *)local_24->sym, ((byte)pcVar9->attrs & 0xc) == 0xc)) {
      uVar1 = (pcVar9->u4a).function.cor_type;
      bVar2 = (byte)local_18->arg;
      if ((bVar2 & 3) != 0) {
        (pcVar9->u4a).function.cor_type = '\0';
        *(byte *)&local_18->arg = bVar2 & 0xfc;
      }
      pcVar10 = cor_helper_symbol(pcVar9,0);
      (pcVar9->u4a).function.cor_type = uVar1;
      local_24->sym = (c2_symbol *)pcVar10;
      tuple_splice_after(local_28->tail,(c2_tuple *)local_24);
      local_28->tail = (c2_tuple *)local_24;
      reader_load_value(local_28,g_ptr_type,0,0);
      local_24 = reader_pop_operand(local_28);
      op = local_18;
    }
    uVar12 = op->type & 0xf000;
    if (uVar12 == 0x5000) {
      this_mode = op->size;
      g_reader_aggregate_size = this_mode;
    }
    else {
      this_mode = op->type & 0xfff;
    }
    if (type == 0x6000) {
      pcVar5 = tuple_new_call(0x184,0x6000,(c2_operand *)0x0,local_24,(uint8_t)op->arg,
                              tuple_splice_after,local_28->tail);
      local_28->tail = pcVar5;
      pcVar11 = (c2_function *)0x0;
    }
    else if ((uVar12 == 0x5000) &&
            (((this_mode == 0 || (8 < this_mode)) || ((this_mode & this_mode - 1U) != 0)))) {
      type = 0x3004;
    }
    pcVar5 = reader_new_call_tuple
                       (0x184,type,local_24,(uint8_t)op->arg,tuple_splice_after,local_28->tail);
    local_28->tail = pcVar5;
  }
  if (local_10 != (c2_operand *)0x0) {
    tuple_append_src(local_28->tail,local_10);
  }
  pcVar5 = tuple_new_block_boundary();
  local_20 = (c2_reader_cell *)0x0;
  il_read_tree(fn,&local_20,pcVar5,depth,0);
  if ((local_28->tail->op == 400) &&
     ((g_intrinsic_desc[(local_28->tail->u20).intrinsic.id].x87_flags & 0x20) != 0)) {
    local_20 = (c2_reader_cell *)list_reverse((c2_link *)local_20);
  }
  node_free((c2_node *)pcVar5);
  if (local_20 != (c2_reader_cell *)0x0) {
    tuple_append_src(local_28->tail,local_20->tail->dst);
    pcVar3 = local_20->next;
    while (pcVar3 != (c2_reader_cell *)0x0) {
      reader_pop_two_merge(&local_20,&local_1c,&local_24,0);
      tuple_append_src(local_28->tail,local_1c);
      pcVar3 = local_20->next;
    }
    if (local_20->after != (c2_reader_cell *)0x0) {
      reader_flush_all_cells(local_20);
    }
    local_20->next = local_28->next;
    local_28->next = local_20;
    reader_pop_two_merge(&local_28,&local_1c,&local_24,1);
  }
  if ((op->type & 0xf000) == 0x5000) {
    g_reader_aggregate_size = this_mode;
  }
  local_24 = (c2_operand *)local_28->tail;
  if (local_24->op == 400) {
    pcVar5 = reader_lower_intrinsic_call(fn,local_28->tail);
    local_28->tail = pcVar5;
    if ((short)local_14 == 0x151) {
      pcVar5 = tuple_new_branch(0x18c,'\0',(c2_node *)g_return_label,(c2_operand *)0x0,
                                (c2_tuple *)0x0,(c2_insert_fn *)0x0,(c2_tuple *)0x0);
      reader_push(&local_28->after,(c2_node *)pcVar5);
      g_return_label_used = '\x01';
    }
    goto LAB_107322c0;
  }
  pcVar7 = (local_24->u18).children;
  if (pcVar7->kind == 4) {
    pcVar9 = (c2_fe_symbol *)pcVar7->sym;
LAB_10732297:
    if ((pcVar9 != (c2_fe_symbol *)0x0) && (((uint)pcVar9->attrs & 0x80) != 0)) {
      pcVar5 = tuple_new_branch(0x18c,'\0',(c2_node *)g_return_label,(c2_operand *)0x0,
                                (c2_tuple *)0x0,(c2_insert_fn *)0x0,(c2_tuple *)0x0);
      reader_push(&local_28->after,(c2_node *)pcVar5);
      g_return_label_used = '\x01';
    }
  }
  else {
    op = local_18;
    if ((((1 << (pcVar7->kind & 0x1f) & 0x1eU) != 0) &&
        (pcVar9 = pcVar7->sym->storage->fe, pcVar9 != (c2_fe_symbol *)0x0)) &&
       ((pcVar9->storage & 0x1000) != 0)) goto LAB_10732297;
  }
  iVar6 = reader_type_is_simple_scalar((uint)(byte)op->arg,op->type,this_mode);
  if (iVar6 != 0) {
    pcVar11 = (c2_function *)reader_struct_return_temp(fn,local_28->tail,this_mode);
    local_28->tail = (c2_tuple *)pcVar11;
  }
LAB_107322c0:
  if (local_8 != (c2_tuple *)0x0) {
    pcVar5 = local_28->tail;
    if (pcVar5->kind != '\x0e') {
      pcVar5 = pcVar5->prev;
    }
    first = reader_count_live_eh_objects(local_8,pcVar5,fn);
    if (first != (c2_tuple *)0x0) {
      tuple_splice_after(pcVar5->prev,first);
    }
  }
  iVar6 = intrinsic_id_is_a5_aa_d8((int16_t)local_14);
  if (iVar6 != 0) {
    reader_push_pending_list(local_28);
    if (pcVar11 == (c2_function *)0x0) {
      pcVar11 = (c2_function *)operand_new_temp_sym(0x1004);
    }
    if (*(uint8_t *)&pcVar11->cfg == '\x06') {
      pcVar8 = ((c2_operand *)pcVar11->x28)->sym;
    }
    else {
      pcVar8 = (c2_symbol *)pcVar11->seh_try_scopes;
    }
    pcVar8->flags7 = pcVar8->flags7 | 3;
    pcVar5 = (c2_tuple *)node_clone((c2_node *)pcVar11);
    tuple_splice_after(local_28->head,pcVar5);
    local_28->tail = local_28->head->next;
    *local_4 = local_28;
    return;
  }
  *local_4 = local_28;
  return;
}

