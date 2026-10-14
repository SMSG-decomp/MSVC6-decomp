void __fastcall reader_build_thunk_body(c2_reader_cell **stack,int depth,c2_function *fn)

{
  c2_function *fn_00;
  c2_tuple *pcVar1;
  c2_operand *pcVar2;
  c2_operand *pcVar3;
  c2_tuple *pcVar4;
  c2_operand *pcVar5;
  c2_insert_fn *insert_fn;
  c2_reader_cell *top;
  c2_operand *adjust;
  c2_operand *target;
  c2_reader_cell **stack_saved;
  int32_t slot_offset;
  c2_insert_fn *splice_fn;
  
  fn_00 = fn;
  top = *stack;
  fn->flags = fn->flags | 0x800;
  stack_saved = stack;
  pcVar1 = reader_pop(&top);
  pcVar3 = pcVar1->src;
  node_free((c2_node *)pcVar1);
  pcVar1 = tuple_new_block_boundary();
  fn = (c2_function *)0x0;
  il_read_tree(fn_00,(c2_reader_cell **)&fn,pcVar1,depth,0);
  node_free((c2_node *)pcVar1);
  pcVar2 = reader_new_this_operand();
  if (pcVar3 == (c2_operand *)0x1) {
    pcVar3 = reader_pop_owned_operand((c2_reader_cell **)&fn);
    pcVar5 = reader_pop_owned_operand((c2_reader_cell **)&fn);
    pcVar1 = tuple_new_binary(0x16e,0x3004,pcVar2,pcVar2,pcVar5,(c2_insert_fn *)0x0,(c2_tuple *)0x0)
    ;
    tuple_new_branch(0x186,'\0',(c2_node *)pcVar3,(c2_operand *)0x0,(c2_tuple *)0x0,
                     tuple_splice_after,pcVar1);
    reader_push(&top,(c2_node *)pcVar1);
    *stack_saved = top;
    return;
  }
  if (pcVar3 == (c2_operand *)0x3) {
    pcVar3 = reader_pop_owned_operand((c2_reader_cell **)&fn);
    slot_offset = (pcVar3->u18).lo;
    node_free((c2_node *)pcVar3);
    pcVar3 = operand_new_ecx_int();
    pcVar1 = (c2_tuple *)0x0;
    insert_fn = (c2_insert_fn *)0x0;
    if (pcVar2->kind == '\x01') {
      pcVar2 = operand_new_mem(0x14c,0x3004,(c2_symbol *)0x0,0,pcVar2,(c2_operand *)0x0,0);
      pcVar4 = tuple_new(0x15b,0x3004,pcVar3,pcVar2,insert_fn,pcVar1);
    }
    else {
      pcVar4 = tuple_new(0x15b,0x3004,pcVar3,pcVar2,(c2_insert_fn *)0x0,(c2_tuple *)0x0);
      splice_fn = tuple_splice_after;
      pcVar1 = pcVar4;
      pcVar2 = operand_new_mem(0x14c,0x3004,(c2_symbol *)0x0,0,pcVar3,(c2_operand *)0x0,0);
      tuple_new(0x15b,0x3004,pcVar3,pcVar2,splice_fn,pcVar1);
    }
    reader_push(&top,(c2_node *)pcVar4);
    pcVar3 = operand_new_mem(0x14c,0x3004,(c2_symbol *)0x0,slot_offset,pcVar3,(c2_operand *)0x0,0);
    pcVar1 = tuple_new_branch(0x186,'\0',(c2_node *)pcVar3,(c2_operand *)0x0,(c2_tuple *)0x0,
                              tuple_splice_after,top->tail);
    top->tail = pcVar1;
    *stack_saved = top;
    return;
  }
  if (pcVar3 != (c2_operand *)0x4) {
    ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\reader.c",0xf2b);
  }
  pcVar3 = reader_pop_owned_operand((c2_reader_cell **)&fn);
  slot_offset = (pcVar3->u18).lo;
  node_free((c2_node *)pcVar3);
  adjust = reader_pop_owned_operand((c2_reader_cell **)&fn);
  target = reader_pop_owned_operand((c2_reader_cell **)&fn);
  pcVar3 = reader_pop_owned_operand((c2_reader_cell **)&fn);
  if ((pcVar3->u18).reg != (c2_symbol *)0x0) {
    ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\reader.c",0xeb0);
  }
  node_free((c2_node *)pcVar3);
  if (pcVar2->kind == '\x01') {
    pcVar1 = (c2_tuple *)0x0;
    pcVar3 = pcVar2;
  }
  else {
    pcVar3 = operand_new_edx_int();
    pcVar1 = tuple_new(0x15b,0x3004,pcVar3,pcVar2,(c2_insert_fn *)0x0,(c2_tuple *)0x0);
  }
  pcVar5 = operand_new_mem(0x14c,0x3004,(c2_symbol *)0x0,slot_offset,pcVar3,(c2_operand *)0x0,0);
  pcVar4 = tuple_new_binary(0x16e,0x3004,pcVar3,pcVar3,pcVar5,
                            (c2_insert_fn *)(-(uint)(pcVar1 != (c2_tuple *)0x0) & 0x1070b315),pcVar1
                           );
  if (pcVar1 == (c2_tuple *)0x0) {
    pcVar1 = pcVar4;
  }
  reader_push(&top,(c2_node *)pcVar1);
  if ((adjust->u18).reg == (c2_symbol *)0x0) {
    node_free((c2_node *)adjust);
  }
  else {
    pcVar1 = tuple_new_binary(0x16e,0x3004,pcVar3,pcVar3,adjust,tuple_splice_after,top->tail);
    top->tail = pcVar1;
  }
  if (pcVar2 == pcVar3) {
    if ((pcVar2->flags & 0x10) == 0) {
      node_free((c2_node *)pcVar2);
    }
  }
  else {
    pcVar1 = tuple_new(0x15b,0x3004,pcVar2,pcVar3,tuple_splice_after,top->tail);
    top->tail = pcVar1;
  }
  pcVar1 = tuple_new_branch(0x186,'\0',(c2_node *)target,(c2_operand *)0x0,(c2_tuple *)0x0,
                            tuple_splice_after,top->tail);
  top->tail = pcVar1;
  *stack_saved = top;
  return;
}

