c2_tuple *
il_read_tree_case_42
          (c2_function *fn,c2_tuple *list,void *zero,c2_switch_case_range *case_tail,
          c2_reader_cell *top,c2_tuple *node,c2_operand *opnd,c2_operand *opnd2,
          c2_reader_cell *cells,c2_function *fn_saved,c2_tuple *asm_last,c2_tuple *asm_block,
          int this_mode,int done,uint8_t cond,c2_reader_cell **stack,c2_reader_op op,
          c2_tuple *list_saved,int depth,int top_level)

{
  c2_reader_cell *pcVar1;
  c2_fe_symbol *pcVar2;
  c2_reader_op op_00;
  uint16_t uVar3;
  uint16_t uVar4;
  c2_function *pcVar5;
  int32_t id;
  byte bVar6;
  c2_tuple *pcVar7;
  c2_tuple *pcVar8;
  c2_tuple *pcVar9;
  c2_switch_case_range *pcVar10;
  c2_reader_op *pcVar11;
  uint uVar12;
  int iVar13;
  c2_symbol *pcVar14;
  uint uVar15;
  c2_fe_symbol *pcVar16;
  c2_const_operand *pcVar17;
  c2_tuple_u14 cVar18;
  c2_operand *pcVar19;
  c2_cond_cell *pcVar20;
  ushort uVar21;
  c2_tuple **anchor;
  uint32_t part_offset;
  c2_operand *this_arg;
  bool bVar22;
  undefined3 in_stack_0000003d;
  code *insert_fn_00;
  c2_insert_fn *insert_fn;
  
code_r0x1072fd8b:
  reader_read_conditional(&top);
  pcVar16 = g_reader_basic_error_label;
  pcVar2 = (c2_fe_symbol *)this_mode;
switchD_1072fb80_caseD_1:
  this_mode = (int)pcVar2;
  g_reader_basic_error_label = pcVar16;
  if ((op.op == 0x4b) || (((&g_il_op_attr_high)[op.op * 2] & 0x10) != 0)) {
    if ((void *)done != zero) goto LAB_107300d8;
    if (top != zero) {
      if ((g_reader_new_locals != zero) && ((void *)top_level != zero)) {
        node = tuple_new_marker(0x1b4);
        (node->u14).scope_locals = g_reader_new_locals;
        node->flags12 = '\x01';
        tuple_splice_after(list,node);
        list = node;
      }
      cells = top->before;
      while (cells != zero) {
        list = reader_flush_cell_tuples(cells,list);
        reader_pop(&cells);
      }
      top->before = zero;
      list_saved = reader_flush_cell_tuples(top,list);
      cells = top->after;
      while (cells != zero) {
        list_saved = reader_flush_cell_tuples(cells,list_saved);
        reader_pop(&cells);
      }
      top->after = zero;
      reader_pop(&top);
      list = list_saved;
      if ((g_reader_new_locals != zero) && ((void *)top_level != zero)) {
        node = tuple_new_marker(0x1b5);
        (node->u14).scope_locals = g_reader_new_locals;
        node->flags12 = '\x01';
        tuple_splice_after(list_saved,node);
        list_saved = node;
        list = node;
        g_reader_new_locals = zero;
      }
    }
  }
  else if ((void *)done != zero) {
LAB_107300d8:
    *stack = top;
    return (c2_tuple *)(c2_fe_symbol *)list;
  }
  il_read_op(fn,&op);
  if (&stack0x00000000 == (undefined1 *)0xffffffbc) {
    ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\reader.c",0x2a8);
  }
  if (((((&g_il_op_attr_high)[op.op * 2] & 0x80) != 0) && (top != zero)) &&
     ((c2_fe_symbol *)top->after != zero)) {
    if ((op.op == 0x38) || (op.op == 0x39)) {
      reader_test_value(&top);
      g_reader_popping_tested_value = 1;
    }
    opnd = reader_pop_operand(top);
    if ((((op.op == 0x3b) || (op.op == 0x3e)) ||
        (g_reader_popping_tested_value = (int)zero, op.op == 0x40)) &&
       ((((1 << (opnd->kind & 0x1f) & 6U) == 0 || (opnd->sym->cls != '\x03')) ||
        (g_reader_popping_tested_value = (int)zero, (c2_fe_symbol *)opnd->sym->def != zero)))) {
      g_reader_popping_tested_value = (int)zero;
      opnd2 = operand_new_temp_sym(opnd->type);
      opnd2->sym->flags7 = opnd2->sym->flags7 | 2;
      pcVar7 = tuple_new(0x15b,opnd->type,opnd2,opnd,tuple_splice_after,top->tail);
      top->tail = pcVar7;
      opnd = opnd2;
    }
    if (((1 << (opnd->kind & 0x1f) & 6U) == 0) || (opnd->sym->cls != '\x03')) {
      uVar21 = opnd->type;
      if ((uVar21 & 0xf000) == 0x5000) {
        if (((uVar21 == 0x5001) || (uVar21 == 0x5002)) || ((uVar21 == 0x5004 || (uVar21 == 0x5008)))
           ) {
          node = (c2_tuple *)operand_new_temp(uVar21);
        }
        else {
          pcVar16 = fe_symbol_new_local(g_reading_function->scope,6,uVar21 & 0xfff,1,1,'\x04',
                                        (uint32_t)zero);
          node = (c2_tuple *)operand_for_fe_symbol(pcVar16);
        }
        pcVar7 = top->tail;
        insert_fn = tuple_splice_after;
        pcVar17 = operand_new_intconst(0x1004,opnd->type & 0xfff,0);
        node = tuple_new_blockop(0x16b,uVar21,(c2_operand *)node,opnd,pcVar17,insert_fn,pcVar7);
        top->tail = node;
        opnd = top->tail->dst;
        if (((1 << (opnd->kind & 0x1f) & 6U) != 0) && ((c2_fe_symbol *)opnd->sym->def != zero)) {
          opnd->sym->def = top->tail;
        }
      }
      else {
        pcVar7 = tuple_new_unary_temp(0x15b,uVar21,opnd,tuple_splice_after,top->tail);
        top->tail = pcVar7;
        opnd = top->tail->dst;
      }
    }
    reader_flush_all_cells(top);
    tuple_splice_after(top->tail,(c2_tuple *)opnd);
    top->tail = (c2_tuple *)opnd;
  }
  pcVar16 = g_reader_basic_error_label;
  pcVar2 = (c2_fe_symbol *)this_mode;
  switch(op.op) {
  case 1:
  case 0x2a:
  case 0x2b:
  case 0x43:
    goto switchD_1072fb80_caseD_1;
  case 2:
    goto switchD_1072fb80_caseD_2;
  case 3:
    reader_binary_op(&top,0x16e);
    pcVar16 = g_reader_basic_error_label;
    pcVar2 = (c2_fe_symbol *)this_mode;
    goto switchD_1072fb80_caseD_1;
  case 4:
    reader_binary_op(&top,0x16f);
    pcVar16 = g_reader_basic_error_label;
    pcVar2 = (c2_fe_symbol *)this_mode;
    goto switchD_1072fb80_caseD_1;
  case 5:
    reader_binary_op(&top,0x175);
    pcVar16 = g_reader_basic_error_label;
    pcVar2 = (c2_fe_symbol *)this_mode;
    goto switchD_1072fb80_caseD_1;
  case 6:
    reader_binary_op(&top,0x176);
    pcVar16 = g_reader_basic_error_label;
    pcVar2 = (c2_fe_symbol *)this_mode;
    goto switchD_1072fb80_caseD_1;
  default:
    goto switchD_1072fb80_caseD_7;
  case 8:
    reader_unary_op(&top,0x161);
    pcVar16 = g_reader_basic_error_label;
    pcVar2 = (c2_fe_symbol *)this_mode;
    goto switchD_1072fb80_caseD_1;
  case 9:
    reader_binary_op(&top,0x171);
    pcVar16 = g_reader_basic_error_label;
    pcVar2 = (c2_fe_symbol *)this_mode;
    goto switchD_1072fb80_caseD_1;
  case 10:
    reader_binary_op(&top,0x177);
    pcVar16 = g_reader_basic_error_label;
    pcVar2 = (c2_fe_symbol *)this_mode;
    goto switchD_1072fb80_caseD_1;
  case 0xb:
    reader_binary_op(&top,0x172);
    pcVar16 = g_reader_basic_error_label;
    pcVar2 = (c2_fe_symbol *)this_mode;
    goto switchD_1072fb80_caseD_1;
  case 0xc:
    reader_binary_op(&top,0x173);
    pcVar16 = g_reader_basic_error_label;
    pcVar2 = (c2_fe_symbol *)this_mode;
    goto switchD_1072fb80_caseD_1;
  case 0xd:
    reader_binary_op(&top,0x174);
    pcVar16 = g_reader_basic_error_label;
    pcVar2 = (c2_fe_symbol *)this_mode;
    goto switchD_1072fb80_caseD_1;
  case 0xe:
    reader_unary_op(&top,0x160);
    pcVar16 = g_reader_basic_error_label;
    pcVar2 = (c2_fe_symbol *)this_mode;
    goto switchD_1072fb80_caseD_1;
  case 0xf:
    reader_assign_op(&top,0x16d,&op);
    pcVar16 = g_reader_basic_error_label;
    pcVar2 = (c2_fe_symbol *)this_mode;
    goto switchD_1072fb80_caseD_1;
  case 0x10:
    reader_assign_op(&top,0x16e,&op);
    pcVar16 = g_reader_basic_error_label;
    pcVar2 = (c2_fe_symbol *)this_mode;
    goto switchD_1072fb80_caseD_1;
  case 0x11:
    reader_assign_op(&top,0x16f,&op);
    pcVar16 = g_reader_basic_error_label;
    pcVar2 = (c2_fe_symbol *)this_mode;
    goto switchD_1072fb80_caseD_1;
  case 0x12:
    reader_assign_op(&top,0x175,&op);
    pcVar16 = g_reader_basic_error_label;
    pcVar2 = (c2_fe_symbol *)this_mode;
    goto switchD_1072fb80_caseD_1;
  case 0x13:
    reader_assign_op(&top,0x176,&op);
    pcVar16 = g_reader_basic_error_label;
    pcVar2 = (c2_fe_symbol *)this_mode;
    goto switchD_1072fb80_caseD_1;
  case 0x15:
    reader_assign_op(&top,0x171,&op);
    pcVar16 = g_reader_basic_error_label;
    pcVar2 = (c2_fe_symbol *)this_mode;
    goto switchD_1072fb80_caseD_1;
  case 0x16:
    reader_assign_op(&top,0x177,&op);
    pcVar16 = g_reader_basic_error_label;
    pcVar2 = (c2_fe_symbol *)this_mode;
    goto switchD_1072fb80_caseD_1;
  case 0x17:
    reader_assign_op(&top,0x172,&op);
    pcVar16 = g_reader_basic_error_label;
    pcVar2 = (c2_fe_symbol *)this_mode;
    goto switchD_1072fb80_caseD_1;
  case 0x18:
    reader_assign_op(&top,0x174,&op);
    pcVar16 = g_reader_basic_error_label;
    pcVar2 = (c2_fe_symbol *)this_mode;
    goto switchD_1072fb80_caseD_1;
  case 0x19:
    reader_assign_op(&top,0x173,&op);
    pcVar16 = g_reader_basic_error_label;
    pcVar2 = (c2_fe_symbol *)this_mode;
    goto switchD_1072fb80_caseD_1;
  case 0x1a:
    if ((top->flags & 1) == 0) {
      bVar6 = reader_test_value(&top);
      _cond = CONCAT31(in_stack_0000003d,bVar6);
      pcVar19 = top->tail->dst;
      pcVar19->flags11 = g_cond_inverse[bVar6] << 4 | pcVar19->flags11 & 0xf;
      pcVar16 = g_reader_basic_error_label;
      pcVar2 = (c2_fe_symbol *)this_mode;
    }
    else {
      top->flags = top->flags ^ 2;
      pcVar16 = g_reader_basic_error_label;
    }
    goto switchD_1072fb80_caseD_1;
  case 0x1b:
  case 0x1c:
    node = zero;
    if (((top->flags & 1) != 0) &&
       (((bVar6 = top->flags & 2, bVar6 != 0 && (op.op == 0x1b)) ||
        ((bVar6 == 0 && (op.op == 0x1c)))))) {
      node = (top->u10).label;
    }
    reader_swap_top(&top);
    reader_emit_conditional_branch(&top,node,&op);
    node = (top->u10).label;
    reader_swap_top(&top);
    reader_emit_conditional_branch(&top,node,&op);
    if (node != (top->u10).label) {
      tuple_splice_after(node,(top->u10).label);
    }
    (top->u10).bitfield = zero;
    reader_pop_two_merge(&top,&opnd,&opnd2,1);
    (top->u10).label = node;
    pcVar16 = g_reader_basic_error_label;
    pcVar2 = (c2_fe_symbol *)this_mode;
    goto switchD_1072fb80_caseD_1;
  case 0x1f:
    reader_binary_op(&top,0x17d);
    pcVar19 = top->tail->dst;
    pcVar19->flags11 = pcVar19->flags11 & 0xf | 0x20;
    pcVar16 = g_reader_basic_error_label;
    pcVar2 = (c2_fe_symbol *)this_mode;
    goto switchD_1072fb80_caseD_1;
  case 0x20:
    reader_binary_op(&top,0x17d);
    pcVar19 = top->tail->dst;
    pcVar19->flags11 = pcVar19->flags11 & 0xf | 0x10;
    pcVar16 = g_reader_basic_error_label;
    pcVar2 = (c2_fe_symbol *)this_mode;
    goto switchD_1072fb80_caseD_1;
  case 0x21:
    reader_binary_op(&top,0x17d);
    pcVar19 = top->tail->dst;
    pcVar19->flags11 = pcVar19->flags11 & 0xf | 0x40;
    pcVar16 = g_reader_basic_error_label;
    pcVar2 = (c2_fe_symbol *)this_mode;
    goto switchD_1072fb80_caseD_1;
  case 0x22:
    reader_binary_op(&top,0x17d);
    pcVar19 = top->tail->dst;
    pcVar19->flags11 = pcVar19->flags11 & 0xf | 0x60;
    pcVar16 = g_reader_basic_error_label;
    pcVar2 = (c2_fe_symbol *)this_mode;
    goto switchD_1072fb80_caseD_1;
  case 0x23:
    reader_binary_op(&top,0x17d);
    pcVar19 = top->tail->dst;
    pcVar19->flags11 = pcVar19->flags11 & 0xf | 0x30;
    pcVar16 = g_reader_basic_error_label;
    pcVar2 = (c2_fe_symbol *)this_mode;
    goto switchD_1072fb80_caseD_1;
  case 0x24:
    reader_binary_op(&top,0x17d);
    pcVar19 = top->tail->dst;
    pcVar19->flags11 = pcVar19->flags11 & 0xf | 0x50;
    pcVar16 = g_reader_basic_error_label;
    pcVar2 = (c2_fe_symbol *)this_mode;
    goto switchD_1072fb80_caseD_1;
  case 0x26:
    node = (c2_tuple *)operand_for_symbol_ref(op.sym);
    reader_push(&top,(c2_node *)node);
    if (((op.sym)->storage & 0x1000) != 0) {
      reader_load_value(top,g_ptr_type,(int)zero,(int)zero);
    }
    pcVar16 = g_reader_basic_error_label;
    pcVar2 = (c2_fe_symbol *)this_mode;
    if (((op.sym)->cls == '\x01') && (((op.sym)->attrs & 0x1000) != 0)) {
      reader_tls_address(top);
      pcVar16 = g_reader_basic_error_label;
      pcVar2 = (c2_fe_symbol *)this_mode;
    }
    goto switchD_1072fb80_caseD_1;
  case 0x27:
    reader_swap_top(&top);
    node = top->tail;
    if ((1 << (((c2_operand *)node)->kind & 0x1f) & 0xffeU) == 0) {
      node = (c2_tuple *)((c2_operand *)node)->tag;
    }
    if ((((c2_operand *)node)->type & 0xf000) == 0x5000) {
      node = (c2_tuple *)reader_address_of_top(top,0x3004);
    }
    reader_swap_top(&top);
    id = op.value;
    if ((void *)g_opt_dlp == zero) {
      if (node->kind != '\x03') goto switchD_1072fb80_caseD_2;
      reader_pop_two_merge(&top,&opnd,&opnd2,(int)zero);
      pcVar14 = opnd->sym;
      node_free((c2_node *)opnd);
      part_offset = (opnd2->u18).lo;
      node_free((c2_node *)opnd2);
      pcVar14 = symbol_get_part(pcVar14,0x5000,(uint32_t)zero,part_offset);
      node = (c2_tuple *)operand_new_symaddr(g_symbol_class_address_op[pcVar14->cls],pcVar14);
      ((c2_operand *)node)->type = g_ptr_type;
      tuple_splice_after(top->tail,node);
      top->tail = node;
      fn = fn_saved;
      list = list_saved;
      pcVar16 = g_reader_basic_error_label;
      pcVar2 = (c2_fe_symbol *)this_mode;
    }
    else {
      pcVar19 = top->tail->src;
      reader_binary_op(&top,0x16d);
      node = top->tail;
      cVar18 = (c2_tuple_u14)dlp_pack_site_id(0,(uint32_t)pcVar19,id);
      node->u14 = cVar18;
      fn = fn_saved;
      list = list_saved;
      pcVar16 = g_reader_basic_error_label;
      pcVar2 = (c2_fe_symbol *)this_mode;
    }
    goto switchD_1072fb80_caseD_1;
  case 0x28:
    reader_pop_convert_append(top,0x1004);
switchD_1072fb80_caseD_2:
    reader_binary_op(&top,0x16d);
    pcVar16 = g_reader_basic_error_label;
    pcVar2 = (c2_fe_symbol *)this_mode;
    goto switchD_1072fb80_caseD_1;
  case 0x29:
    node = ((op.sym)->u32).label_tuple;
    if (node == zero) {
      node = tuple_new_label(op.sym);
    }
    if (asm_block == zero) break;
    *(byte *)((int)&((c2_fe_symbol *)node)->storage_sym + 1) =
         *(byte *)((int)&((c2_fe_symbol *)node)->storage_sym + 1) | 2;
    if (asm_last != zero) goto LAB_10785053;
    (asm_block->u20).default_label = node;
    pcVar16 = g_reader_basic_error_label;
    asm_last = node;
    pcVar2 = (c2_fe_symbol *)this_mode;
    goto switchD_1072fb80_caseD_1;
  case 0x2c:
  case 0x34:
    node = top->tail;
    if (((node->kind != '\x11') && ((1 << (byte)(op.type >> 0xc) & 0xeU) != 0)) &&
       ((op.type & 0xf000) != 0x3000)) {
      reader_check_array_index(node);
    }
    reader_pop_convert_append(top,op.type);
    pcVar16 = g_reader_basic_error_label;
    pcVar2 = (c2_fe_symbol *)this_mode;
    goto switchD_1072fb80_caseD_1;
  case 0x30:
  case 0x5a:
    reader_load_value(top,op.type,CONCAT22(op.size._2_2_,(ushort)op.size),op.qualifiers & 0x800);
    if (op.op == 0x5a) {
      node = top->tail;
      pcVar19 = (c2_operand *)node;
      if ((1 << (((c2_operand *)node)->kind & 0x1f) & 0xffeU) == 0) {
        pcVar19 = (c2_operand *)((c2_operand *)node)->tag;
      }
      pcVar19->flags = (byte)*(uint16_t *)&pcVar19->flags | 0x80;
    }
    pcVar16 = g_reader_basic_error_label;
    pcVar2 = (c2_fe_symbol *)this_mode;
    if ((op.type & 0xf000) == 0x5000) {
      g_reader_aggregate_size = CONCAT22(op.size._2_2_,(ushort)op.size);
    }
    goto switchD_1072fb80_caseD_1;
  case 0x32:
    reader_emit_store(&top,&op);
    pcVar16 = g_reader_basic_error_label;
    pcVar2 = (c2_fe_symbol *)this_mode;
    goto switchD_1072fb80_caseD_1;
  case 0x33:
    if ((op.type & 0xf000) == 0x4000) {
      node = (c2_tuple *)operand_new_fconst(op.type,(c2_float_const *)op.value);
    }
    else {
      node = (c2_tuple *)operand_new_intconst(op.type,op.value,op.value_hi);
    }
    break;
  case 0x35:
  case 0x36:
    bVar22 = op.op != 0x35;
    node = reader_pop(&top);
    pcVar19 = reader_duplicate_operand(top);
    reader_push(&top->after,(c2_node *)pcVar19);
    if ((top->flags & 4) != 0) {
      top->after->flags = top->flags;
      if ((c2_fe_symbol *)(top->u10).bitfield != zero) {
        pcVar19 = operand_list_clone((top->u10).bitfield);
        (top->after->u10).bitfield = pcVar19;
      }
    }
    reader_push(&top->after,(c2_node *)node);
    reader_assign_op(&top->after,bVar22 + 0x16d,&op);
    reader_load_value(top,op.type,CONCAT22(op.size._2_2_,(ushort)op.size),op.qualifiers & 0x800);
    top->flags = top->flags | 0x20;
    pcVar16 = g_reader_basic_error_label;
    pcVar2 = (c2_fe_symbol *)this_mode;
    goto switchD_1072fb80_caseD_1;
  case 0x37:
    opnd = (c2_operand *)reader_pop(&top);
    opnd->type = 0x1001;
    opnd2 = (c2_operand *)reader_pop(&top);
    opnd2->type = 0x1001;
    (top->u10).bitfield = opnd;
    tuple_splice_after((c2_tuple *)opnd,(c2_tuple *)opnd2);
    top->flags = top->flags | 4;
    pcVar16 = g_reader_basic_error_label;
    pcVar2 = (c2_fe_symbol *)this_mode;
    goto switchD_1072fb80_caseD_1;
  case 0x38:
  case 0x39:
    opnd = (c2_operand *)((op.sym)->u32).label_tuple;
    if (opnd == zero) {
      opnd = (c2_operand *)tuple_new_label(op.sym);
    }
    bVar6 = reader_test_value(&top);
    _cond = CONCAT31(in_stack_0000003d,bVar6);
    if (op.op == 0x39) {
      bVar6 = g_cond_inverse[bVar6];
    }
    g_reader_popping_tested_value = 1;
    opnd2 = reader_pop_operand(top);
    g_reader_popping_tested_value = (int)zero;
    opnd2->flags11 = opnd2->flags11 & 0xf;
    node = tuple_new_branch(0x185,bVar6,(c2_node *)opnd,opnd2,opnd2->sym->def,tuple_splice_after,
                            top->tail);
    top->tail = node;
    fn = fn_saved;
    pcVar16 = g_reader_basic_error_label;
    pcVar2 = (c2_fe_symbol *)this_mode;
    goto switchD_1072fb80_caseD_1;
  case 0x3a:
    opnd = (c2_operand *)((op.sym)->u32).label_tuple;
    if (opnd == zero) {
      opnd = (c2_operand *)tuple_new_label(op.sym);
    }
    node = tuple_new_branch(0x186,'\0',(c2_node *)opnd,zero,zero,zero,zero);
    break;
  case 0x3b:
    opnd = reader_pop_operand(top);
    opnd2 = operand_new_temp_sym(opnd->type);
    pcVar7 = tuple_new(0x15b,opnd->type,opnd2,opnd,tuple_splice_after,top->tail);
    uVar3 = g_cur_line;
    top->tail = pcVar7;
    pcVar8 = tuple_new_block_boundary();
    cells = (c2_reader_cell *)0x0;
    pcVar9 = il_read_tree(fn_saved,&cells,pcVar8,depth,0);
    pcVar7 = pcVar8->next;
    node_free((c2_node *)pcVar8);
    uVar4 = g_cur_line;
    pcVar7->prev = (c2_tuple *)0x0;
    g_cur_line = uVar3;
    pcVar8 = lower_switch_statement(g_il_switch_case_list,top->tail);
    top->tail = pcVar8;
    tuple_splice_after(top->tail,pcVar7);
    case_tail = (c2_switch_case_range *)0x0;
    g_cur_line = uVar4;
    top->tail = pcVar9;
    g_il_switch_case_list = (c2_switch_case_range *)0x0;
    goto LAB_1072efe5;
  case 0x3c:
    node = reader_pop(&top);
    node_free((c2_node *)node);
    case_tail = arena_alloc(4,0x20);
    g_il_switch_case_list = case_tail;
    case_tail->label = (c2_tuple *)(op.sym)->u32;
    pcVar16 = g_reader_basic_error_label;
    pcVar2 = (c2_fe_symbol *)this_mode;
    goto switchD_1072fb80_caseD_1;
  case 0x3d:
    node = reader_pop(&top);
    pcVar10 = arena_alloc(4,0x20);
    case_tail->next = pcVar10;
    pcVar10->last = (uint32_t)node->src;
    pcVar19 = node->dst;
    pcVar10->last_high = (int32_t)pcVar19;
    pcVar10->first = pcVar10->last;
    pcVar10->first_high = (int32_t)pcVar19;
    pcVar10->label = (c2_tuple *)(op.sym)->u32;
    node_free((c2_node *)node);
    pcVar16 = g_reader_basic_error_label;
    case_tail = pcVar10;
    pcVar2 = (c2_fe_symbol *)this_mode;
    goto switchD_1072fb80_caseD_1;
  case 0x3e:
    goto switchD_1072fb80_caseD_3e;
  case 0x40:
    node = top->tail;
    pcVar19 = node->src;
    if ((pcVar19 == (c2_operand *)0xdb) || (pcVar19 == (c2_operand *)0x11e)) {
      fn->flags = fn->flags | 0x40;
    }
    if (pcVar19 == (c2_operand *)0xd8) {
      fn->flags = fn->flags | 0x80;
    }
switchD_1072fb80_caseD_3e:
    reader_read_call(&top,&op,depth,fn,this_mode);
    pcVar16 = g_reader_basic_error_label;
    pcVar2 = zero;
    goto switchD_1072fb80_caseD_1;
  case 0x41:
    opnd = reader_pop_operand(top);
    uVar3 = op.type;
    pcVar5 = fn_saved;
    pcVar16 = fn_saved->fsym;
    if (((opnd->kind == '\x01') && (opnd->sym->cls == '\x03')) &&
       ((pcVar2 = (c2_fe_symbol *)opnd->sym->def, pcVar2 != zero &&
        (pcVar2 != (c2_fe_symbol *)top->tail)))) {
      anchor = &node;
      node = (c2_tuple *)pcVar2;
    }
    else {
      anchor = &top->tail;
    }
    convert_operand(&opnd,op.type,anchor);
    uVar15 = pcVar16->refcount;
    uVar12 = il_type_to_c2_type((byte)pcVar16->storage & 0xf,uVar15);
    iVar13 = reader_type_is_simple_scalar(pcVar16->attrs & 0x1c,(uint16_t)uVar12,uVar15);
    if (iVar13 == 0) {
      pcVar7 = tuple_new_exit(0x16c,uVar3,zero,opnd,tuple_splice_after,top->tail);
      top->tail = pcVar7;
    }
    else {
      pcVar16 = pcVar5->struct_return;
      if (pcVar16 == zero) {
        ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\reader.c",0x515);
      }
      pcVar16->storage = pcVar16->storage & 0xfffffff3 | 3;
      node = (c2_tuple *)operand_for_fe_symbol(pcVar16);
      if (CONCAT22(op.size._2_2_,(ushort)op.size) < 0x1000) {
        uVar21 = (ushort)op.size | 0x5000;
        opnd2 = operand_new_mem(0x14c,uVar21,zero,(int32_t)zero,(c2_operand *)node,zero,
                                (uint32_t)zero);
        pcVar7 = top->tail;
        insert_fn_00 = tuple_splice_after;
        pcVar17 = operand_new_intconst(0x1004,CONCAT22(op.size._2_2_,(ushort)op.size),(int32_t)zero)
        ;
        pcVar7 = tuple_new_blockop(0x16b,uVar21,opnd2,opnd,pcVar17,insert_fn_00,pcVar7);
        top->tail = pcVar7;
      }
      else {
        tuple_splice_after(top->tail,(c2_tuple *)opnd);
        top->tail = (c2_tuple *)opnd;
        reader_push(&top,(c2_node *)node);
        reader_swap_top(&top);
        reader_struct_copy(&top,&op);
        reader_pop_operand(top);
      }
      g_reader_aggregate_size = CONCAT22(op.size._2_2_,(ushort)op.size);
      opnd = (c2_operand *)node_clone((c2_node *)node);
      pcVar7 = tuple_new_exit(0x16c,0x3004,zero,opnd,tuple_splice_after,top->tail);
      top->tail = pcVar7;
    }
    if ((void *)g_inlining_active != zero) goto LAB_1072efe5;
    zero = (c2_fe_symbol *)0x0;
    g_no_missing_return_warning = 0;
    fn = fn_saved;
    list = list_saved;
    pcVar16 = g_reader_basic_error_label;
    pcVar2 = (c2_fe_symbol *)this_mode;
    goto switchD_1072fb80_caseD_1;
  case 0x42:
    goto code_r0x1072fd8b;
  case 0x44:
    if ((int)zero < this_mode) {
      pcVar1 = top->next->next;
      top->next->next = pcVar1->next;
      pcVar1->next = top;
      top = pcVar1;
    }
    else {
      reader_swap_top(&top);
    }
    reader_flush_and_fold_copy(top);
    if ((c2_fe_symbol *)top->before != zero) {
      reader_flush_cells_to_head(top);
    }
    pcVar7 = tuple_new_block_boundary();
    opnd = (c2_operand *)reader_flush_cell_tuples(top,pcVar7);
    node = pcVar7->next;
    if (node == zero) {
      top->tail = top->head;
    }
    else {
      tuple_splice_after(top->head,node);
      top->tail = (c2_tuple *)opnd;
    }
    node_free((c2_node *)pcVar7);
    if ((c2_fe_symbol *)top->after != zero) {
      reader_flush_all_cells(top);
    }
    node = reader_pop(&top);
    if (node == zero) goto LAB_1072efe5;
    reader_push(&top->before,(c2_node *)node);
    zero = (c2_fe_symbol *)0x0;
    fn = fn_saved;
    list = list_saved;
    pcVar16 = g_reader_basic_error_label;
    pcVar2 = (c2_fe_symbol *)this_mode;
    goto switchD_1072fb80_caseD_1;
  case 0x46:
    if ((((void *)g_pdb_il_mode != zero) && ((void *)g_reader_file_record_seen != zero)) &&
       (pcVar16 = (c2_fe_symbol *)(fn->fsym->u4a).function.exp_offset, pcVar16 != zero)) {
      g_current_line_abs = line_number_map((uint32_t)pcVar16);
      g_il_line_base = (int)pcVar16;
      if (g_current_line_abs < fn->line_base + 0x10000) {
        g_cur_line = (short)g_current_line_abs - (short)fn->line_base;
      }
      else {
        g_cur_line = 0xffff;
      }
    }
    if ((void *)this_mode == zero) {
      opnd = (c2_operand *)reader_pop(&top);
      this_arg = (c2_operand *)0x0;
    }
    else {
      this_arg = (c2_operand *)reader_pop(&top);
      operand_to_memory_form(this_arg);
      opnd = (c2_operand *)reader_pop(&top);
    }
    pcVar5 = fn_saved;
    node = tuple_new_func_entry(fn_saved);
    node_free((c2_node *)opnd);
    reader_push(&top,(c2_node *)node);
    pcVar11 = il_read_op(pcVar5,&op);
    while ((pcVar11 != (c2_reader_op *)0x0 && (op.op != 0x4c))) {
      node = top->tail;
      if ((c2_fe_symbol *)node->src == zero) {
        pcVar19 = operand_for_fe_symbol(op.sym);
        node->src = pcVar19;
      }
      else {
        opnd2 = operand_for_fe_symbol(op.sym);
        tuple_splice_after((c2_tuple *)opnd2,(c2_tuple *)node->src);
        node->src = opnd2;
      }
      node->src->flags = node->src->flags | 0x10;
      pcVar11 = il_read_op(pcVar5,&op);
    }
    pcVar16 = pcVar5->fsym;
    uVar15 = pcVar16->refcount;
    uVar12 = il_type_to_c2_type((byte)pcVar16->storage & 0xf,uVar15);
    iVar13 = reader_type_is_simple_scalar(pcVar16->attrs & 0x1c,(uint16_t)uVar12,uVar15);
    if (iVar13 != 0) {
      pcVar16 = fe_symbol_new_local(pcVar5->scope,3,g_ptr_type & 0xfff,3,1,'\x04',0x100);
      *(undefined1 *)((int)&pcVar16->refcount + 2) = 1;
      pcVar16->name = zero;
      pcVar5->struct_return = pcVar16;
    }
    fn = fn_saved;
    list = list_saved;
    pcVar16 = g_reader_basic_error_label;
    pcVar2 = zero;
    if (this_arg != zero) {
      node = top->tail;
      if ((c2_fe_symbol *)node->src == zero) {
        node->src = this_arg;
        *(byte *)&((c2_fe_symbol *)this_arg)->size = (byte)((c2_fe_symbol *)this_arg)->size | 0x10;
        pcVar16 = g_reader_basic_error_label;
        pcVar2 = zero;
      }
      else {
        tuple_splice_after((c2_tuple *)this_arg,(c2_tuple *)node->src);
        part_offset = ((c2_fe_symbol *)this_arg)->size;
        node->src = this_arg;
        *(byte *)&((c2_fe_symbol *)this_arg)->size = (byte)part_offset | 0x10;
        fn = fn_saved;
        pcVar16 = g_reader_basic_error_label;
        pcVar2 = zero;
      }
    }
    goto switchD_1072fb80_caseD_1;
  case 0x47:
    node = tuple_new_func_exit(fn);
    reader_push(&top,(c2_node *)node);
    if (g_return_label_used == '\0') {
      node_free((c2_node *)g_return_label);
      g_return_label = zero;
      pcVar16 = g_reader_basic_error_label;
      pcVar2 = (c2_fe_symbol *)this_mode;
    }
    else {
      tuple_insert_before(top->tail,g_return_label);
      pcVar16 = g_reader_basic_error_label;
      pcVar2 = (c2_fe_symbol *)this_mode;
    }
    goto switchD_1072fb80_caseD_1;
  case 0x4b:
    reader_flush_and_fold_copy(top);
    pcVar16 = g_reader_basic_error_label;
    pcVar2 = (c2_fe_symbol *)this_mode;
    goto switchD_1072fb80_caseD_1;
  case 0x4c:
    done = 1;
    goto switchD_1072fb80_caseD_1;
  case 0x4f:
    switch((undefined2)op.arg) {
    case 1:
    case 0x24:
      if ((void *)op.value != zero) {
        g_current_line_abs = line_number_map(op.value);
        pcVar16 = g_reader_basic_error_label;
        pcVar2 = (c2_fe_symbol *)this_mode;
        if (g_current_line_abs < fn->line_base + 0x10000) {
          g_cur_line = (short)g_current_line_abs - (short)fn->line_base;
        }
        else {
          g_cur_line = 0xffff;
        }
      }
      goto switchD_1072fb80_caseD_1;
    default:
      ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\reader.c",0x6ae);
    case 0xf:
      part_offset = 0x1b4;
      break;
    case 0x10:
      part_offset = 0x1b5;
      break;
    case 0x11:
      if ((void *)g_opt_debug_info == zero) goto switchD_1072fb80_caseD_1;
      part_offset = 0x1b6;
      break;
    case 0x12:
      if ((void *)g_opt_debug_info == zero) goto switchD_1072fb80_caseD_1;
      part_offset = 0x1b7;
      break;
    case 0x16:
      node = inasm_read_instruction((uint8_t *)op.value,fn->scope);
      goto LAB_1078501c;
    case 0x18:
      node = tuple_new_marker(0x1ba);
      (node->u14).arg = (void *)(op.value & 0xffff);
LAB_1078501c:
      node->flags = node->flags | 2;
      if (asm_last == zero) {
        (asm_block->u20).default_label = node;
        pcVar16 = g_reader_basic_error_label;
        asm_last = node;
        pcVar2 = (c2_fe_symbol *)this_mode;
      }
      else {
LAB_10785053:
        asm_last->next = node;
        node->prev = asm_last;
        asm_last = node;
        pcVar16 = g_reader_basic_error_label;
        pcVar2 = (c2_fe_symbol *)this_mode;
      }
      goto switchD_1072fb80_caseD_1;
    case 0x19:
      if ((list == zero) ||
         (iVar13._0_1_ = ((c2_fe_symbol *)list)->cls, iVar13._1_1_ = ((c2_fe_symbol *)list)->x05,
         iVar13._2_1_ = ((c2_fe_symbol *)list)->x06, iVar13._3_1_ = ((c2_fe_symbol *)list)->x07,
         iVar13 != 0x191)) {
        asm_block = tuple_new_asm_block(0x191,0x1004);
        fn->flags = fn->flags | 1;
        pcVar16 = g_reader_basic_error_label;
        pcVar2 = (c2_fe_symbol *)this_mode;
      }
      else {
        pcVar16 = ((c2_fe_symbol *)list)->last_referrer;
        list_saved = (c2_tuple *)((c2_fe_symbol *)list)->offset;
        asm_block = list;
        tuple_unlink(list);
        asm_last = (c2_tuple *)pcVar16;
        for (pcVar16 = pcVar16->next; pcVar16 != zero; pcVar16 = pcVar16->next) {
          asm_last = (c2_tuple *)pcVar16;
        }
        fn->flags = fn->flags | 1;
        list = list_saved;
        pcVar16 = g_reader_basic_error_label;
        pcVar2 = (c2_fe_symbol *)this_mode;
      }
      goto switchD_1072fb80_caseD_1;
    case 0x1a:
      if (asm_last == zero) {
        node_free((c2_node *)asm_block);
        pcVar16 = g_reader_basic_error_label;
        asm_last = zero;
        asm_block = zero;
        pcVar2 = (c2_fe_symbol *)this_mode;
      }
      else {
        reader_push(&top,(c2_node *)asm_block);
        pcVar16 = g_reader_basic_error_label;
        asm_last = zero;
        asm_block = zero;
        pcVar2 = (c2_fe_symbol *)this_mode;
      }
      goto switchD_1072fb80_caseD_1;
    case 0x1f:
      bVar22 = (void *)g_inlining_active == zero;
      fn->options = op.value;
      pcVar16 = g_reader_basic_error_label;
      if (bVar22) {
        apply_function_optimize_flags(op.value);
        g_label_merge_class1 = g_opt_global;
        pcVar16 = g_reader_basic_error_label;
        pcVar2 = (c2_fe_symbol *)this_mode;
      }
      goto switchD_1072fb80_caseD_1;
    case 0x20:
      node = tuple_new_marker(0x1b8);
      node->u14 = (c2_tuple_u14)op.value;
      reader_push(&top,(c2_node *)node);
      pcVar16 = g_reader_basic_error_label;
      pcVar2 = (c2_fe_symbol *)this_mode;
      goto switchD_1072fb80_caseD_1;
    case 0x23:
      bVar22 = (void *)g_inlining_active == zero;
      fn->warning_states = (c2_warning_state *)op.sym;
      pcVar16 = g_reader_basic_error_label;
      if (bVar22) {
        apply_warning_state_list((short *)op.sym);
        pcVar16 = g_reader_basic_error_label;
        pcVar2 = (c2_fe_symbol *)this_mode;
      }
      goto switchD_1072fb80_caseD_1;
    case 0x25:
      if ((void *)op.value == zero) {
        if ((fn->fsym->attrs & 0x1000) != 0) {
          node = tuple_new_pseudo(0x19b,0x1004);
          goto LAB_1072ebad;
        }
        goto switchD_1072fb80_caseD_1;
      }
      pcVar16 = fe_scope_lookup_id(fn->scope,op.value);
      pcVar2 = (c2_fe_symbol *)this_mode;
      if ((*(byte *)&pcVar16->u3e & 1) == 0) goto switchD_1072fb80_caseD_1;
      opnd = (c2_operand *)(pcVar16->u32).label_tuple;
      pcVar16->role = 'X';
      if (opnd == zero) {
        opnd = (c2_operand *)tuple_new_label(pcVar16);
      }
      node = tuple_new_branch(0x18b,'\0',(c2_node *)opnd,zero,zero,zero,zero);
      goto LAB_1072ebad;
    }
    node = tuple_new_marker(part_offset);
    break;
  case 0x53:
    depth = depth + 1;
    if (1 < depth) {
      g_reader_block_cursor = g_reader_block_cursor->next;
      node = tuple_new_marker(0x1b4);
      node->u14 = (c2_tuple_u14)g_reader_block_cursor->locals;
      reader_push(&top,(c2_node *)node);
      pcVar16 = g_reader_basic_error_label;
      pcVar2 = (c2_fe_symbol *)this_mode;
    }
    goto switchD_1072fb80_caseD_1;
  case 0x54:
    if (1 < depth) {
      node = tuple_new_marker(0x1b5);
      node->u14 = (c2_tuple_u14)g_reader_block_cursor->locals;
      reader_push(&top,(c2_node *)node);
      pcVar14 = (c2_symbol *)g_reader_block_cursor->prev;
      pcVar16 = *(c2_fe_symbol **)(*(int *)&pcVar14->cls + 4);
      g_reader_block_cursor = (c2_reader_block *)pcVar14;
      *(c2_fe_symbol **)&pcVar14->cls = pcVar16;
      if (pcVar16 != zero) {
        pcVar16->storage_sym = pcVar14;
      }
    }
    if (op.value == 0 && op.value_hi == 0) {
      done = 1;
    }
    depth = depth + -1;
    pcVar16 = g_reader_basic_error_label;
    pcVar2 = (c2_fe_symbol *)this_mode;
    goto switchD_1072fb80_caseD_1;
  case 0x55:
    reader_read_argument(top,&op);
    pcVar16 = g_reader_basic_error_label;
    pcVar2 = (c2_fe_symbol *)this_mode;
    goto switchD_1072fb80_caseD_1;
  case 0x56:
    reader_set_source_file((char *)op.sym);
    g_cur_line = (uint16_t)zero;
    g_reader_file_record_seen = 1;
    g_current_line_abs = (uint32_t)zero;
    pcVar16 = g_reader_basic_error_label;
    pcVar2 = (c2_fe_symbol *)this_mode;
    goto switchD_1072fb80_caseD_1;
  case 0x59:
    node = (c2_tuple *)reader_pop_operand(top);
    if ((c2_fe_symbol *)top->head->next == zero) {
      tuple_splice_after(top->tail,node);
      top->tail = node;
      pcVar16 = g_reader_basic_error_label;
      pcVar2 = (c2_fe_symbol *)this_mode;
    }
    else {
      node = tuple_new_unary_temp
                       (0x162,((c2_operand *)node)->type,(c2_operand *)node,tuple_splice_after,
                        top->tail);
      if (((void *)g_opt_basic != zero) && ((node->type & 0xf000) != 0x4000)) {
        pcVar19 = operand_new_codeaddr(0x154,g_reader_basic_error_label);
        tuple_append_src(node,pcVar19);
        node->op = 0x178;
      }
      top->tail = node;
      pcVar16 = g_reader_basic_error_label;
      pcVar2 = (c2_fe_symbol *)this_mode;
    }
    goto switchD_1072fb80_caseD_1;
  case 0x5c:
    node = tuple_new_pseudo(0x1a0,0x1004);
    pcVar20 = arena_alloc(1,0x10);
    (node->u20).cond_cells = pcVar20;
    ((node->u20).eh_construct)->flags = CONCAT22(op.arg._2_2_,(undefined2)op.arg);
    opnd = (c2_operand *)tuple_new_block_boundary();
    cells = top->before;
    opnd2 = opnd;
    if (cells != zero) {
      do {
        opnd = (c2_operand *)reader_flush_cell_tuples(cells,(c2_tuple *)opnd);
        reader_pop(&cells);
      } while (cells != (c2_reader_cell *)0x0);
    }
    top->before = (c2_reader_cell *)0x0;
    opnd = (c2_operand *)reader_flush_cell_tuples(top,(c2_tuple *)opnd);
    cells = top->after;
    while (cells != (c2_reader_cell *)0x0) {
      opnd = (c2_operand *)reader_flush_cell_tuples(cells,(c2_tuple *)opnd);
      reader_pop(&cells);
    }
    top->after = (c2_reader_cell *)0x0;
    reader_pop(&top);
    ((node->u20).cond_cells)->next = (c2_cond_cell *)opnd2->next;
    node_free((c2_node *)opnd2);
    pcVar20 = ((node->u20).cond_cells)->next;
    if (pcVar20 != (c2_cond_cell *)0x0) {
      pcVar20->cc = 0;
    }
    opnd = reader_pop_operand(top);
    if ((opnd->flags & 0x10) != 0) {
      opnd = (c2_operand *)node_clone((c2_node *)opnd);
    }
    if (opnd->kind == '\x06') {
      pcVar19 = tuple_append_src(node,opnd->base);
      node->src = pcVar19;
    }
    else {
      pcVar19 = tuple_append_src(node,opnd);
      node->src = pcVar19;
    }
    node->type = node->src->type;
    pcVar19 = operand_new_temp(node->src->type);
    node->dst = pcVar19;
    node->dst->flags = node->dst->flags | 0x10;
    symbol_mark_overlapping_parts(node->dst->sym,node);
    tuple_splice_after(top->tail,node);
    top->tail = node;
    if (opnd->kind == '\x06') {
      reader_load_value(top,opnd->type,g_reader_aggregate_size,0);
      opnd->base = (c2_operand *)0x0;
      node_free((c2_node *)opnd);
    }
LAB_1072efe5:
    zero = (c2_fe_symbol *)0x0;
    fn = fn_saved;
    list = list_saved;
    pcVar16 = g_reader_basic_error_label;
    pcVar2 = (c2_fe_symbol *)this_mode;
    goto switchD_1072fb80_caseD_1;
  case 0x5d:
  case 0x5e:
    node = tuple_new_pseudo((op.op != 0x5d) + 0x1a1,0x1004);
    pcVar20 = arena_alloc(1,0x10);
    (node->u20).cond_cells = pcVar20;
    ((node->u20).eh_region)->count = op.value;
    ((node->u20).eh_construct)->flags = CONCAT22(op.arg._2_2_,(undefined2)op.arg);
    reader_push(&top,(c2_node *)node);
    pcVar16 = g_reader_basic_error_label;
    pcVar2 = (c2_fe_symbol *)this_mode;
    goto switchD_1072fb80_caseD_1;
  case 0x60:
  case 0x62:
    node = tuple_new_pseudo((-(uint)(op.op != 0x60) & 2) + 0x1a4,0x1004);
    pcVar20 = arena_alloc(1,0x10);
    (node->u20).cond_cells = pcVar20;
    reader_push(&top,(c2_node *)node);
    pcVar16 = g_reader_basic_error_label;
    pcVar2 = (c2_fe_symbol *)this_mode;
    goto switchD_1072fb80_caseD_1;
  case 0x61:
    node = tuple_new_pseudo(0x1a5,0x1004);
    pcVar20 = arena_alloc(1,0x10);
    (node->u20).cond_cells = pcVar20;
    ((node->u20).eh_region)->count = op.value;
    ((node->u20).eh_construct)->object = (c2_eh_state *)op.sym;
    ((node->u20).eh_construct)->flags = CONCAT22(op.arg._2_2_,(undefined2)op.arg);
    reader_push(&top,(c2_node *)node);
    pcVar16 = g_reader_basic_error_label;
    pcVar2 = (c2_fe_symbol *)this_mode;
    goto switchD_1072fb80_caseD_1;
  case 0x68:
    g_reader_pointer_arith = 1;
    reader_binary_op(&top,0x16d);
    opnd = top->tail->dst;
    g_reader_pointer_arith = (int)zero;
    pcVar16 = g_reader_basic_error_label;
    pcVar2 = (c2_fe_symbol *)this_mode;
    if (((1 << (opnd->kind & 0x1f) & 6U) != 0) &&
       (pcVar14 = opnd->sym, (c2_fe_symbol *)pcVar14->def != zero)) {
      (pcVar14->u30).local_number = (pcVar14->u30).local_number | 1;
      opnd->sym->def->type = 0x3004;
      operand_set_type(opnd,0x3004);
      pcVar16 = g_reader_basic_error_label;
      pcVar2 = (c2_fe_symbol *)this_mode;
    }
    goto switchD_1072fb80_caseD_1;
  case 0x77:
    opnd = (c2_operand *)reader_pop(&top);
    if ((c2_fe_symbol *)(opnd->u18).reg != zero) {
      pcVar19 = reader_duplicate_operand(top);
      reader_push(&top,(c2_node *)pcVar19);
      reader_swap_top(&top);
      pcVar17 = operand_new_intconst(0x3004,(uint32_t)zero,(int32_t)zero);
      reader_push(&top,(c2_node *)pcVar17);
      reader_binary_op(&top,0x17d);
      pcVar19 = top->tail->dst;
      pcVar19->flags11 = pcVar19->flags11 & 0xf | 0x10;
      reader_swap_top(&top);
      reader_push(&top,(c2_node *)opnd);
      reader_binary_op(&top,0x16d);
      pcVar17 = operand_new_intconst(0x1004,(uint32_t)zero,(int32_t)zero);
      reader_push(&top,(c2_node *)pcVar17);
      op_00.type = op.type;
      op_00.op = op.op;
      op_00.qualifiers = op.qualifiers;
      op_00.size._0_2_ = (ushort)op.size;
      op_00.size._2_2_ = op.size._2_2_;
      op_00.x0c = op.x0c;
      op_00.value = op.value;
      op_00.value_hi = op.value_hi;
      op_00.sym = op.sym;
      op_00.arg._0_2_ = (undefined2)op.arg;
      op_00.arg._2_2_ = op.arg._2_2_;
      pcVar7 = il_read_tree_case_42
                         (fn,list,zero,case_tail,top,node,opnd,opnd2,cells,fn_saved,asm_last,
                          asm_block,this_mode,done,cond,stack,op_00,list_saved,depth,top_level);
      return pcVar7;
    }
    node_free((c2_node *)opnd);
    pcVar16 = g_reader_basic_error_label;
    pcVar2 = (c2_fe_symbol *)this_mode;
    goto switchD_1072fb80_caseD_1;
  case 0x8b:
    g_reader_pointer_arith = 1;
    reader_binary_op(&top,0x16e);
    pcVar19 = (c2_operand *)top->tail;
    g_reader_pointer_arith = (int)zero;
    pcVar16 = g_reader_basic_error_label;
    pcVar2 = (c2_fe_symbol *)this_mode;
    if ((pcVar19->op == 0x16e) && (opnd = pcVar19, ((pcVar19->u18).children)->kind == '\a')) {
      reader_discard_value((c2_tuple *)pcVar19);
      pcVar16 = g_reader_basic_error_label;
      pcVar2 = (c2_fe_symbol *)this_mode;
    }
    goto switchD_1072fb80_caseD_1;
  case 0x8d:
    pcVar7 = tuple_new_pseudo(0x198,0x1004);
    reader_push_tuple_list(top,pcVar7);
    opnd = reader_pop_operand(top);
    convert_operand(&opnd,0x1004,&top->tail);
    node = tuple_new_pseudo(0x199,0x1004);
    tuple_append_src(node,opnd);
    tuple_splice_after(top->tail,node);
    top->tail = node;
    pcVar16 = g_reader_basic_error_label;
    pcVar2 = (c2_fe_symbol *)this_mode;
    goto switchD_1072fb80_caseD_1;
  case 0x8e:
    node = tuple_new_pseudo(0x194,0x1004);
    break;
  case 0x8f:
    node = tuple_new_pseudo(0x192,0x1004);
    break;
  case 0x90:
    node = tuple_new_pseudo(0x193,0x1004);
    break;
  case 0x99:
    reader_address_of_top(top,0x3004);
    this_mode = 1;
    pcVar16 = g_reader_basic_error_label;
    pcVar2 = (c2_fe_symbol *)this_mode;
    goto switchD_1072fb80_caseD_1;
  case 0x9a:
    reader_address_of_top(top,0x3004);
    reader_address_of_top(top,0x3004);
    this_mode = 2;
    pcVar16 = g_reader_basic_error_label;
    pcVar2 = (c2_fe_symbol *)this_mode;
    goto switchD_1072fb80_caseD_1;
  case 0x9b:
    if ((op.type & 0xf000) == 0x5000) {
      uVar15 = CONCAT22(op.size._2_2_,(ushort)op.size);
    }
    else {
      uVar15 = op.type & 0xfff;
    }
    part_offset = type_class_to_symbol_class(op.type);
    pcVar16 = reader_eh_object_local
                        (fn,CONCAT22(op.arg._2_2_,(undefined2)op.arg),part_offset,uVar15);
    node = (c2_tuple *)operand_for_symbol_ref(pcVar16);
    break;
  case 0x9d:
    reader_build_thunk_body(&top,depth,fn);
    pcVar16 = g_reader_basic_error_label;
    pcVar2 = (c2_fe_symbol *)this_mode;
    goto switchD_1072fb80_caseD_1;
  case 0xa0:
    opnd = reader_pop_operand(top);
    if ((c2_fe_symbol *)top->before != zero) {
      reader_flush_cells_to_head(top);
    }
    node = tuple_new_pseudo(0x1ac,op.type);
    tuple_append_src(node,opnd);
    tuple_splice_after(top->tail,node);
    top->tail = node;
    if ((c2_fe_symbol *)top->after != zero) {
      reader_flush_all_cells(top);
    }
    node = tuple_new_pseudo(0x1ab,0x1004);
    opnd2 = (c2_operand *)tuple_new_block_boundary();
    (node->u20).default_label = (c2_tuple *)opnd2;
    tuple_splice_after((c2_tuple *)opnd2,top->head->next);
    top->head->next = node;
    node->prev = top->head;
    top->tail = node;
    pcVar16 = g_reader_basic_error_label;
    pcVar2 = (c2_fe_symbol *)this_mode;
    if ((opnd->kind == '\a') && ((opnd->u18).reg == (c2_symbol *)0x0 && opnd->tag == 0)) {
      pcVar7 = tuple_new_branch(0x18c,'\0',(c2_node *)g_return_label,zero,zero,tuple_splice_after,
                                top->tail);
      g_return_label_used = '\x01';
      top->tail = pcVar7;
      pcVar16 = g_reader_basic_error_label;
      pcVar2 = (c2_fe_symbol *)this_mode;
    }
    goto switchD_1072fb80_caseD_1;
  }
LAB_1072ebad:
  reader_push(&top,(c2_node *)node);
  pcVar16 = g_reader_basic_error_label;
  pcVar2 = (c2_fe_symbol *)this_mode;
  goto switchD_1072fb80_caseD_1;
switchD_1072fb80_caseD_7:
  ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\reader.c",0x7cb);
}

