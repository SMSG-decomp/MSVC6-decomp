void __fastcall reader_read_conditional(c2_reader_cell **stack)

{
  byte bVar1;
  c2_reader_cell *pcVar2;
  c2_function *fn;
  uint8_t uVar3;
  uint16_t uVar4;
  int iVar5;
  c2_operand *pcVar6;
  undefined2 extraout_var;
  c2_tuple *pcVar8;
  c2_tuple *pcVar9;
  c2_fe_symbol *pcVar10;
  c2_tuple *pcVar11;
  c2_const_operand *pcVar12;
  c2_reader_cell *pcVar13;
  undefined2 uVar14;
  code *insert_fn_00;
  c2_reader_cell *arm_cell;
  c2_operand *true_arm;
  c2_operand *false_arm;
  c2_tuple *false_label;
  c2_operand *result;
  c2_operand *cond;
  uint32_t cc;
  int aggregate;
  uint32_t result_type;
  int volatile_bits;
  c2_tuple *arm_tuples;
  c2_insert_fn *insert_fn;
  c2_tuple *head;
  uint uVar7;
  
  false_label = (c2_tuple *)0x0;
  result = (c2_operand *)0x0;
  bVar1 = (*stack)->next->next->flags;
  if (((bVar1 & 1) != 0) && ((bVar1 & 2) != 0)) {
    reader_swap_top(stack);
  }
  pcVar2 = *stack;
  arm_cell = pcVar2;
  if (((pcVar2->tail->flags & 1) == 0) || (pcVar2->tail->type != 0x6000)) {
    false_arm = reader_pop_operand(pcVar2);
  }
  else {
    false_arm = (c2_operand *)0x0;
  }
  if ((((arm_cell->before != (c2_reader_cell *)0x0) || (arm_cell->after != (c2_reader_cell *)0x0))
      || (iVar5 = reader_operand_tree_unsafe((c2_node *)false_arm), iVar5 != 0)) ||
     (iVar5 = reader_operand_tree_unsafe((c2_node *)arm_cell->tail), iVar5 != 0)) {
    result = (c2_operand *)0x1;
  }
  arm_cell = arm_cell->next;
  if (((arm_cell->tail->flags & 1) == 0) || (arm_cell->tail->type != 0x6000)) {
    true_arm = reader_pop_operand(arm_cell);
  }
  else {
    true_arm = (c2_operand *)0x0;
  }
  if (((arm_cell->before != (c2_reader_cell *)0x0) || (arm_cell->after != (c2_reader_cell *)0x0)) ||
     ((iVar5 = reader_operand_tree_unsafe((c2_node *)true_arm), iVar5 != 0 ||
      (iVar5 = reader_operand_tree_unsafe((c2_node *)arm_cell->tail), pcVar13 = arm_cell, iVar5 != 0
      )))) {
    result = (c2_operand *)0x1;
    pcVar13 = arm_cell;
  }
  arm_cell = pcVar13->next;
  if ((arm_cell->flags & 1) == 0) {
    uVar3 = reader_test_value(&arm_cell);
    cc = CONCAT31(cc._1_3_,uVar3);
    pcVar13->next = arm_cell;
    g_reader_popping_tested_value = 1;
    pcVar6 = reader_pop_operand(arm_cell);
    g_reader_popping_tested_value = 0;
    cond = pcVar6;
    if (arm_cell->after != (c2_reader_cell *)0x0) {
      result = (c2_operand *)0x1;
      reader_flush_all_cells(arm_cell);
    }
  }
  else {
    false_label = (arm_cell->u10).label;
    pcVar6 = (c2_operand *)0x0;
    (arm_cell->u10).bitfield = (c2_operand *)0x0;
    cond = (c2_operand *)0x0;
    if (arm_cell->after != (c2_reader_cell *)0x0) {
      ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\reader.c",0xd5f);
    }
  }
  uVar14 = (undefined2)((uint)pcVar13 >> 0x10);
  if (true_arm == (c2_operand *)0x0) {
    uVar7 = CONCAT22(uVar14,false_arm->type);
    result_type = uVar7;
  }
  else if (false_arm == (c2_operand *)0x0) {
    uVar7 = CONCAT22(uVar14,true_arm->type);
    result_type = uVar7;
  }
  else {
    uVar4 = usual_arithmetic_type(true_arm->type,false_arm->type);
    uVar7 = CONCAT22(extraout_var,uVar4);
    result_type = uVar7;
    convert_operand(&false_arm,uVar4,&pcVar2->tail);
    reader_swap_top(stack);
    convert_operand(&true_arm,uVar4,&(*stack)->tail);
    reader_swap_top(stack);
  }
  uVar4 = (uint16_t)uVar7;
  if (((result == (c2_operand *)0x0) && (pcVar6 != (c2_operand *)0x0)) &&
     (iVar5 = select_is_profitable(uVar4,(int)pcVar6->sym->def,true_arm,false_arm,(uint8_t)cc,0),
     iVar5 != 0)) {
    pcVar9 = (*stack)->tail;
    pcVar8 = reader_pop(stack);
    if (pcVar8 == (c2_tuple *)0x0) {
      pcVar9 = (*stack)->tail;
      pcVar8 = reader_pop(stack);
    }
    else {
      pcVar11 = (*stack)->tail;
      if ((*stack)->head == pcVar11) {
        reader_pop(stack);
      }
      else {
        tuple_splice_after(pcVar11,pcVar8);
        pcVar8 = reader_pop(stack);
      }
    }
    pcVar2 = *stack;
    if (pcVar8 == (c2_tuple *)0x0) {
      pcVar9 = pcVar2->tail;
    }
    else {
      tuple_splice_after(pcVar2->tail,pcVar8);
    }
    pcVar9 = tuple_new_ternary_temp
                       (399,uVar4,cond,true_arm,false_arm,g_cond_inverse[cc & 0xff],
                        tuple_splice_after,pcVar9);
    pcVar2->tail = pcVar9;
    return;
  }
  if (((((uVar7 & 0xf000) == 0x5000) && (uVar4 != 0x5001)) &&
      ((uVar4 != 0x5002 && ((uVar4 != 0x5004 && (uVar4 != 0x5008)))))) &&
     (((true_arm == (c2_operand *)0x0 ||
       (((1 << (true_arm->kind & 0x1f) & 6U) == 0 || (true_arm->sym->cls != '\x03')))) &&
      ((false_arm == (c2_operand *)0x0 ||
       (((1 << (false_arm->kind & 0x1f) & 6U) == 0 || (false_arm->sym->cls != '\x03')))))))) {
    aggregate = 1;
    pcVar6 = operand_new_temp_sym(0x3004);
    if (((true_arm->flags & 0x40) != 0) || (volatile_bits = 0, (false_arm->flags & 0x40) != 0)) {
      volatile_bits = 1;
    }
    result = pcVar6;
    if (false_arm != (c2_operand *)0x0) {
      if (((1 << (false_arm->kind & 0x1f) & 6U) != 0) && (false_arm->sym->cls == '\x03')) {
        ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\reader.c",0xda6);
      }
      reader_push(stack,(c2_node *)false_arm);
      reader_address_of_top(*stack,0x3004);
      false_arm = (c2_operand *)reader_pop(stack);
      goto LAB_10742eab;
    }
  }
  else {
    aggregate = 0;
    if ((uVar4 == 0x5001) || (((uVar4 == 0x5002 || (uVar4 == 0x5004)) || (uVar4 == 0x5008)))) {
      pcVar10 = fe_symbol_new_local(g_reading_function->scope,6,uVar7 & 0xfff,1,1,'\x04',0);
      pcVar6 = operand_for_fe_symbol(pcVar10);
      result = pcVar6;
    }
    else {
      pcVar6 = operand_new_temp_sym(uVar4);
      result = pcVar6;
    }
LAB_10742eab:
    if (false_arm != (c2_operand *)0x0) {
      uVar4 = pcVar6->type;
      pcVar2 = *stack;
      if ((uVar4 & 0xf000) == 0x5000) {
        pcVar9 = pcVar2->tail;
        insert_fn_00 = tuple_splice_after;
        pcVar12 = operand_new_intconst
                            (0x1004,g_reader_aggregate_size,g_reader_aggregate_size >> 0x1f);
        pcVar9 = tuple_new_blockop(0x16b,uVar4,pcVar6,false_arm,pcVar12,insert_fn_00,pcVar9);
      }
      else {
        pcVar9 = tuple_new(0x15b,uVar4,pcVar6,false_arm,tuple_splice_after,pcVar2->tail);
      }
      pcVar2->tail = pcVar9;
    }
  }
  pcVar2 = *stack;
  if (pcVar2->before != (c2_reader_cell *)0x0) {
    reader_flush_cells_to_head(pcVar2);
  }
  if (pcVar2->after != (c2_reader_cell *)0x0) {
    reader_flush_all_cells(pcVar2);
  }
  if (false_label == (c2_tuple *)0x0) {
    pcVar10 = label_symbol_new_in_scope(g_reading_function);
    false_label = tuple_new_label(pcVar10);
  }
  head = pcVar2->head;
  pcVar9 = head->next;
  pcVar8 = (c2_tuple *)list_last((c2_link *)false_label);
  tuple_splice_after(pcVar8,pcVar9);
  fn = g_reading_function;
  head->next = false_label;
  pcVar10 = label_symbol_new_in_scope(fn);
  pcVar9 = tuple_new_label(pcVar10);
  tuple_splice_after(pcVar2->tail,pcVar9);
  pcVar2->tail = pcVar9;
  arm_tuples = reader_pop(stack);
  if (aggregate != 0) {
    if (true_arm == (c2_operand *)0x0) goto LAB_10742fa6;
    if (((1 << (true_arm->kind & 0x1f) & 6U) != 0) && (true_arm->sym->cls == '\x03')) {
      ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\reader.c",0xdd2);
    }
    reader_push(stack,(c2_node *)true_arm);
    reader_address_of_top(*stack,0x3004);
    true_arm = (c2_operand *)reader_pop(stack);
  }
  if (true_arm != (c2_operand *)0x0) {
    pcVar2 = *stack;
    uVar4 = result->type;
    pcVar8 = pcVar2->tail;
    insert_fn = tuple_splice_after;
    if ((uVar4 & 0xf000) == 0x5000) {
      pcVar12 = operand_new_intconst(0x1004,g_reader_aggregate_size,g_reader_aggregate_size >> 0x1f)
      ;
      pcVar8 = tuple_new_blockop(0x16b,uVar4,result,true_arm,pcVar12,insert_fn,pcVar8);
    }
    else {
      pcVar8 = tuple_new(0x15b,uVar4,result,true_arm,tuple_splice_after,pcVar8);
    }
    pcVar2->tail = pcVar8;
  }
LAB_10742fa6:
  pcVar2 = *stack;
  if (pcVar2->before != (c2_reader_cell *)0x0) {
    reader_flush_cells_to_head(pcVar2);
  }
  if (pcVar2->after != (c2_reader_cell *)0x0) {
    reader_flush_all_cells(pcVar2);
  }
  pcVar8 = tuple_new_branch(0x186,'\0',(c2_node *)pcVar9,(c2_operand *)0x0,(c2_tuple *)0x0,
                            tuple_splice_after,pcVar2->tail);
  pcVar2->tail = pcVar8;
  tuple_splice_after(pcVar8,arm_tuples);
  pcVar2->tail = pcVar9;
  pcVar8 = reader_pop(stack);
  pcVar2 = *stack;
  if ((pcVar2->flags & 1) == 0) {
    pcVar11 = pcVar2->tail;
    cond->flags11 = cond->flags11 & 0xf;
    pcVar11 = tuple_new_branch(0x185,(uint8_t)cc,(c2_node *)false_label,cond,cond->sym->def,
                               tuple_splice_after,pcVar11);
    pcVar2->tail = pcVar11;
  }
  else {
    pcVar2->flags = pcVar2->flags & 0xfe;
  }
  tuple_splice_after(pcVar2->tail,pcVar8);
  pcVar2->tail = pcVar9;
  reader_push_pending_list(pcVar2);
  if ((true_arm != (c2_operand *)0x0) || (false_arm != (c2_operand *)0x0)) {
    pcVar8 = (c2_tuple *)node_clone((c2_node *)result);
    pcVar2->tail = pcVar8;
    pcVar9 = pcVar2->head;
    pcVar8->prev = pcVar9;
    pcVar9->next = pcVar8;
    if (aggregate != 0) {
      reader_load_value(pcVar2,(uint16_t)result_type,0,volatile_bits);
    }
  }
  return;
}

