c2_tuple * __fastcall
il_read_tree(c2_function *fn,c2_reader_cell **stack,c2_tuple *list,int depth,int top_level)

{
  c2_reader_cell *pcVar1;
  c2_reader_block *pcVar2;
  c2_reader_block *pcVar3;
  c2_reader_op op_00;
  uint16_t uVar4;
  uint16_t uVar5;
  int32_t id;
  byte bVar6;
  c2_tuple *pcVar7;
  c2_tuple *pcVar8;
  c2_tuple *cursor;
  c2_switch_case_range *pcVar9;
  c2_reader_op *pcVar10;
  uint uVar11;
  int iVar12;
  c2_operand *pcVar13;
  c2_symbol *pcVar14;
  uint uVar15;
  uint32_t uVar16;
  c2_tuple *pcVar17;
  c2_fe_symbol *pcVar18;
  c2_const_operand *pcVar19;
  c2_tuple_u14 cVar20;
  c2_operand *pcVar21;
  c2_cond_cell *pcVar22;
  ushort uVar23;
  c2_tuple **anchor;
  int32_t part_offset;
  bool bVar24;
  code *insert_fn_00;
  c2_switch_case_range *case_tail;
  c2_reader_cell *top;
  c2_tuple *node;
  c2_operand *opnd;
  c2_operand *opnd2;
  c2_reader_cell *cells;
  c2_function *fn_saved;
  c2_tuple *asm_last;
  c2_tuple *asm_block;
  int this_mode;
  int done;
  uint8_t cond;
  c2_reader_op op;
  c2_insert_fn *insert_fn;
  
  top = *stack;
  done = 0;
  asm_block = (c2_tuple *)0x0;
  asm_last = (c2_tuple *)0x0;
  this_mode = 0;
  cursor = list;
  fn_saved = fn;
LAB_1072fb3d:
  il_read_op(fn,&op);
  if (&stack0x00000000 == (undefined1 *)0x20) {
    ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\reader.c",0x2a8);
  }
  if (((((&g_il_op_attr_high)[op.op * 2] & 0x80) != 0) && (top != (c2_reader_cell *)0x0)) &&
     (top->after != (c2_reader_cell *)0x0)) {
    if ((op.op == 0x38) || (op.op == 0x39)) {
      reader_test_value(&top);
      g_reader_popping_tested_value = 1;
    }
    opnd = reader_pop_operand(top);
    g_reader_popping_tested_value = 0;
    if ((((op.op == 0x3b) || (op.op == 0x3e)) || (op.op == 0x40)) &&
       ((((1 << (opnd->kind & 0x1f) & 6U) == 0 || (opnd->sym->cls != '\x03')) ||
        (opnd->sym->def != (c2_tuple *)0x0)))) {
      opnd2 = operand_new_temp_sym(opnd->type);
      opnd2->sym->flags7 = opnd2->sym->flags7 | 2;
      pcVar7 = tuple_new(0x15b,opnd->type,opnd2,opnd,tuple_splice_after,top->tail);
      top->tail = pcVar7;
      opnd = opnd2;
    }
    if (((1 << (opnd->kind & 0x1f) & 6U) == 0) || (opnd->sym->cls != '\x03')) {
      uVar23 = opnd->type;
      if ((uVar23 & 0xf000) == 0x5000) {
        if (((uVar23 == 0x5001) || (uVar23 == 0x5002)) || ((uVar23 == 0x5004 || (uVar23 == 0x5008)))
           ) {
          node = (c2_tuple *)operand_new_temp(uVar23);
        }
        else {
          pcVar18 = fe_symbol_new_local(g_reading_function->scope,6,uVar23 & 0xfff,1,1,'\x04',0);
          node = (c2_tuple *)operand_for_fe_symbol(pcVar18);
        }
        pcVar7 = top->tail;
        insert_fn = tuple_splice_after;
        pcVar19 = operand_new_intconst(0x1004,opnd->type & 0xfff,0);
        node = tuple_new_blockop(0x16b,uVar23,(c2_operand *)node,opnd,pcVar19,insert_fn,pcVar7);
        top->tail = node;
        opnd = top->tail->dst;
        if (((1 << (opnd->kind & 0x1f) & 6U) != 0) && (opnd->sym->def != (c2_tuple *)0x0)) {
          opnd->sym->def = top->tail;
        }
      }
      else {
        pcVar7 = tuple_new_unary_temp(0x15b,uVar23,opnd,tuple_splice_after,top->tail);
        top->tail = pcVar7;
        opnd = top->tail->dst;
      }
    }
    reader_flush_all_cells(top);
    tuple_splice_after(top->tail,(c2_tuple *)opnd);
    top->tail = (c2_tuple *)opnd;
  }
  pcVar7 = cursor;
  pcVar18 = g_reader_basic_error_label;
  switch(op.op) {
  case 1:
  case 0x2a:
  case 0x2b:
  case 0x43:
    break;
  case 2:
    goto switchD_1072fb80_caseD_2;
  case 3:
    reader_binary_op(&top,0x16e);
    pcVar18 = g_reader_basic_error_label;
    break;
  case 4:
    reader_binary_op(&top,0x16f);
    pcVar18 = g_reader_basic_error_label;
    break;
  case 5:
    reader_binary_op(&top,0x175);
    pcVar18 = g_reader_basic_error_label;
    break;
  case 6:
    reader_binary_op(&top,0x176);
    pcVar18 = g_reader_basic_error_label;
    break;
  default:
    ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\reader.c",0x7cb);
  case 8:
    reader_unary_op(&top,0x161);
    pcVar18 = g_reader_basic_error_label;
    break;
  case 9:
    reader_binary_op(&top,0x171);
    pcVar18 = g_reader_basic_error_label;
    break;
  case 10:
    reader_binary_op(&top,0x177);
    pcVar18 = g_reader_basic_error_label;
    break;
  case 0xb:
    reader_binary_op(&top,0x172);
    pcVar18 = g_reader_basic_error_label;
    break;
  case 0xc:
    reader_binary_op(&top,0x173);
    pcVar18 = g_reader_basic_error_label;
    break;
  case 0xd:
    reader_binary_op(&top,0x174);
    pcVar18 = g_reader_basic_error_label;
    break;
  case 0xe:
    reader_unary_op(&top,0x160);
    pcVar18 = g_reader_basic_error_label;
    break;
  case 0xf:
    reader_assign_op(&top,0x16d,&op);
    pcVar18 = g_reader_basic_error_label;
    break;
  case 0x10:
    reader_assign_op(&top,0x16e,&op);
    pcVar18 = g_reader_basic_error_label;
    break;
  case 0x11:
    reader_assign_op(&top,0x16f,&op);
    pcVar18 = g_reader_basic_error_label;
    break;
  case 0x12:
    reader_assign_op(&top,0x175,&op);
    pcVar18 = g_reader_basic_error_label;
    break;
  case 0x13:
    reader_assign_op(&top,0x176,&op);
    pcVar18 = g_reader_basic_error_label;
    break;
  case 0x15:
    reader_assign_op(&top,0x171,&op);
    pcVar18 = g_reader_basic_error_label;
    break;
  case 0x16:
    reader_assign_op(&top,0x177,&op);
    pcVar18 = g_reader_basic_error_label;
    break;
  case 0x17:
    reader_assign_op(&top,0x172,&op);
    pcVar18 = g_reader_basic_error_label;
    break;
  case 0x18:
    reader_assign_op(&top,0x174,&op);
    pcVar18 = g_reader_basic_error_label;
    break;
  case 0x19:
    reader_assign_op(&top,0x173,&op);
    pcVar18 = g_reader_basic_error_label;
    break;
  case 0x1a:
    if ((top->flags & 1) == 0) {
      cond = reader_test_value(&top);
      pcVar21 = top->tail->dst;
      pcVar21->flags11 = g_cond_inverse[cond] << 4 | pcVar21->flags11 & 0xf;
      pcVar18 = g_reader_basic_error_label;
    }
    else {
      top->flags = top->flags ^ 2;
      pcVar18 = g_reader_basic_error_label;
    }
    break;
  case 0x1b:
  case 0x1c:
    if (((top->flags & 1) == 0) ||
       (((bVar6 = top->flags & 2, bVar6 == 0 || (op.op != 0x1b)) &&
        ((bVar6 != 0 || (op.op != 0x1c)))))) {
      node = (c2_tuple *)0x0;
    }
    else {
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
    (top->u10).bitfield = (c2_operand *)0x0;
    reader_pop_two_merge(&top,&opnd,&opnd2,1);
    (top->u10).label = node;
    pcVar18 = g_reader_basic_error_label;
    break;
  case 0x1f:
    reader_binary_op(&top,0x17d);
    pcVar21 = top->tail->dst;
    pcVar21->flags11 = pcVar21->flags11 & 0xf | 0x20;
    pcVar18 = g_reader_basic_error_label;
    break;
  case 0x20:
    reader_binary_op(&top,0x17d);
    pcVar21 = top->tail->dst;
    pcVar21->flags11 = pcVar21->flags11 & 0xf | 0x10;
    pcVar18 = g_reader_basic_error_label;
    break;
  case 0x21:
    reader_binary_op(&top,0x17d);
    pcVar21 = top->tail->dst;
    pcVar21->flags11 = pcVar21->flags11 & 0xf | 0x40;
    pcVar18 = g_reader_basic_error_label;
    break;
  case 0x22:
    reader_binary_op(&top,0x17d);
    pcVar21 = top->tail->dst;
    pcVar21->flags11 = pcVar21->flags11 & 0xf | 0x60;
    pcVar18 = g_reader_basic_error_label;
    break;
  case 0x23:
    reader_binary_op(&top,0x17d);
    pcVar21 = top->tail->dst;
    pcVar21->flags11 = pcVar21->flags11 & 0xf | 0x30;
    pcVar18 = g_reader_basic_error_label;
    break;
  case 0x24:
    reader_binary_op(&top,0x17d);
    pcVar21 = top->tail->dst;
    pcVar21->flags11 = pcVar21->flags11 & 0xf | 0x50;
    pcVar18 = g_reader_basic_error_label;
    break;
  case 0x26:
    node = (c2_tuple *)operand_for_symbol_ref(op.sym);
    reader_push(&top,(c2_node *)node);
    if (((op.sym)->storage & 0x1000) != 0) {
      reader_load_value(top,g_ptr_type,0,0);
    }
    pcVar18 = g_reader_basic_error_label;
    if (((op.sym)->cls == '\x01') && (((op.sym)->attrs & 0x1000) != 0)) {
      reader_tls_address(top);
      pcVar18 = g_reader_basic_error_label;
    }
    break;
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
    if (g_opt_dlp == 0) {
      if (node->kind != '\x03') goto switchD_1072fb80_caseD_2;
      reader_pop_two_merge(&top,&opnd,&opnd2,0);
      pcVar14 = opnd->sym;
      node_free((c2_node *)opnd);
      uVar16 = (opnd2->u18).lo;
      node_free((c2_node *)opnd2);
      pcVar14 = symbol_get_part(pcVar14,0x5000,0,uVar16);
      node = (c2_tuple *)operand_new_symaddr(g_symbol_class_address_op[pcVar14->cls],pcVar14);
      ((c2_operand *)node)->type = g_ptr_type;
      fn = fn_saved;
      tuple_splice_after(top->tail,node);
      top->tail = node;
      pcVar7 = list;
      pcVar18 = g_reader_basic_error_label;
      fn_saved = fn;
    }
    else {
      pcVar21 = top->tail->src;
      reader_binary_op(&top,0x16d);
      node = top->tail;
      fn = fn_saved;
      cVar20 = (c2_tuple_u14)dlp_pack_site_id(0,(uint32_t)pcVar21,id);
      node->u14 = cVar20;
      pcVar7 = list;
      pcVar18 = g_reader_basic_error_label;
      fn_saved = fn;
    }
    break;
  case 0x28:
    reader_pop_convert_append(top,0x1004);
    goto switchD_1072fb80_caseD_2;
  case 0x29:
    node = ((op.sym)->u32).label_tuple;
    if (node == (c2_tuple *)0x0) {
      node = tuple_new_label(op.sym);
    }
    if (asm_block == (c2_tuple *)0x0) goto LAB_1072ebad;
    node->flags = node->flags | 2;
    if (asm_last == (c2_tuple *)0x0) {
      (asm_block->u20).default_label = node;
      pcVar18 = g_reader_basic_error_label;
      asm_last = node;
      break;
    }
    goto LAB_10785053;
  case 0x2c:
  case 0x34:
    node = top->tail;
    if (((node->kind != '\x11') && ((1 << (byte)(op.type >> 0xc) & 0xeU) != 0)) &&
       ((op.type & 0xf000) != 0x3000)) {
      reader_check_array_index(node);
    }
    reader_pop_convert_append(top,op.type);
    pcVar18 = g_reader_basic_error_label;
    break;
  case 0x30:
  case 0x5a:
    reader_load_value(top,op.type,CONCAT22(op.size._2_2_,(ushort)op.size),op.qualifiers & 0x800);
    if (op.op == 0x5a) {
      node = top->tail;
      pcVar21 = (c2_operand *)node;
      if ((1 << (((c2_operand *)node)->kind & 0x1f) & 0xffeU) == 0) {
        pcVar21 = (c2_operand *)((c2_operand *)node)->tag;
      }
      pcVar21->flags = (byte)*(uint16_t *)&pcVar21->flags | 0x80;
    }
    pcVar18 = g_reader_basic_error_label;
    if ((op.type & 0xf000) == 0x5000) {
      g_reader_aggregate_size = CONCAT22(op.size._2_2_,(ushort)op.size);
    }
    break;
  case 0x32:
    reader_emit_store(&top,&op);
    pcVar18 = g_reader_basic_error_label;
    break;
  case 0x33:
    if ((op.type & 0xf000) == 0x4000) {
      node = (c2_tuple *)operand_new_fconst(op.type,(c2_float_const *)op.value);
    }
    else {
      node = (c2_tuple *)operand_new_intconst(op.type,op.value,op.value_hi);
    }
    goto LAB_1072ebad;
  case 0x35:
  case 0x36:
    bVar24 = op.op != 0x35;
    node = reader_pop(&top);
    pcVar21 = reader_duplicate_operand(top);
    reader_push(&top->after,(c2_node *)pcVar21);
    if ((top->flags & 4) != 0) {
      top->after->flags = top->flags;
      if ((top->u10).bitfield != (c2_operand *)0x0) {
        pcVar21 = operand_list_clone((top->u10).bitfield);
        (top->after->u10).bitfield = pcVar21;
      }
    }
    reader_push(&top->after,(c2_node *)node);
    reader_assign_op(&top->after,bVar24 + 0x16d,&op);
    reader_load_value(top,op.type,CONCAT22(op.size._2_2_,(ushort)op.size),op.qualifiers & 0x800);
    top->flags = top->flags | 0x20;
    pcVar18 = g_reader_basic_error_label;
    break;
  case 0x37:
    opnd = (c2_operand *)reader_pop(&top);
    opnd->type = 0x1001;
    opnd2 = (c2_operand *)reader_pop(&top);
    opnd2->type = 0x1001;
    (top->u10).bitfield = opnd;
    tuple_splice_after((c2_tuple *)opnd,(c2_tuple *)opnd2);
    top->flags = top->flags | 4;
    pcVar18 = g_reader_basic_error_label;
    break;
  case 0x38:
  case 0x39:
    opnd = (c2_operand *)((op.sym)->u32).label_tuple;
    fn = fn_saved;
    if (opnd == (c2_operand *)0x0) {
      opnd = (c2_operand *)tuple_new_label(op.sym);
      fn = fn_saved;
    }
    cond = reader_test_value(&top);
    bVar6 = cond;
    if (op.op == 0x39) {
      bVar6 = g_cond_inverse[cond];
    }
    g_reader_popping_tested_value = 1;
    opnd2 = reader_pop_operand(top);
    g_reader_popping_tested_value = 0;
    opnd2->flags11 = opnd2->flags11 & 0xf;
    node = tuple_new_branch(0x185,bVar6,(c2_node *)opnd,opnd2,opnd2->sym->def,tuple_splice_after,
                            top->tail);
    top->tail = node;
    pcVar18 = g_reader_basic_error_label;
    fn_saved = fn;
    break;
  case 0x3a:
    opnd = (c2_operand *)((op.sym)->u32).label_tuple;
    if (opnd == (c2_operand *)0x0) {
      opnd = (c2_operand *)tuple_new_label(op.sym);
    }
    node = tuple_new_branch(0x186,'\0',(c2_node *)opnd,(c2_operand *)0x0,(c2_tuple *)0x0,
                            (c2_insert_fn *)0x0,(c2_tuple *)0x0);
    goto LAB_1072ebad;
  case 0x3b:
    opnd = reader_pop_operand(top);
    opnd2 = operand_new_temp_sym(opnd->type);
    pcVar7 = tuple_new(0x15b,opnd->type,opnd2,opnd,tuple_splice_after,top->tail);
    uVar4 = g_cur_line;
    top->tail = pcVar7;
    pcVar17 = tuple_new_block_boundary();
    cells = (c2_reader_cell *)0x0;
    pcVar8 = il_read_tree(fn_saved,&cells,pcVar17,depth,0);
    pcVar7 = pcVar17->next;
    node_free((c2_node *)pcVar17);
    uVar5 = g_cur_line;
    pcVar7->prev = (c2_tuple *)0x0;
    g_cur_line = uVar4;
    pcVar17 = lower_switch_statement(g_il_switch_case_list,top->tail);
    top->tail = pcVar17;
    fn = fn_saved;
    tuple_splice_after(top->tail,pcVar7);
    case_tail = (c2_switch_case_range *)0x0;
    g_cur_line = uVar5;
    top->tail = pcVar8;
    g_il_switch_case_list = (c2_switch_case_range *)0x0;
    pcVar7 = list;
    pcVar18 = g_reader_basic_error_label;
    fn_saved = fn;
    break;
  case 0x3c:
    node = reader_pop(&top);
    node_free((c2_node *)node);
    case_tail = arena_alloc(4,0x20);
    g_il_switch_case_list = case_tail;
    case_tail->label = (c2_tuple *)(op.sym)->u32;
    pcVar18 = g_reader_basic_error_label;
    break;
  case 0x3d:
    node = reader_pop(&top);
    pcVar9 = arena_alloc(4,0x20);
    case_tail->next = pcVar9;
    pcVar9->last = (uint32_t)node->src;
    pcVar21 = node->dst;
    pcVar9->last_high = (int32_t)pcVar21;
    pcVar9->first = pcVar9->last;
    pcVar9->first_high = (int32_t)pcVar21;
    pcVar9->label = (c2_tuple *)(op.sym)->u32;
    node_free((c2_node *)node);
    pcVar18 = g_reader_basic_error_label;
    case_tail = pcVar9;
    break;
  case 0x3e:
    goto switchD_1072fb80_caseD_3e;
  case 0x40:
    node = top->tail;
    pcVar21 = node->src;
    if ((pcVar21 == (c2_operand *)0xdb) || (pcVar21 == (c2_operand *)0x11e)) {
      fn->flags = fn->flags | 0x40;
    }
    if (pcVar21 == (c2_operand *)0xd8) {
      fn->flags = fn->flags | 0x80;
    }
    goto switchD_1072fb80_caseD_3e;
  case 0x41:
    opnd = reader_pop_operand(top);
    uVar4 = op.type;
    pcVar18 = fn_saved->fsym;
    if (((opnd->kind == '\x01') && (opnd->sym->cls == '\x03')) &&
       ((pcVar7 = opnd->sym->def, pcVar7 != (c2_tuple *)0x0 && (pcVar7 != top->tail)))) {
      anchor = &node;
      node = pcVar7;
    }
    else {
      anchor = &top->tail;
    }
    fn = fn_saved;
    convert_operand(&opnd,op.type,anchor);
    uVar15 = pcVar18->refcount;
    uVar11 = il_type_to_c2_type((byte)pcVar18->storage & 0xf,uVar15);
    iVar12 = reader_type_is_simple_scalar(pcVar18->attrs & 0x1c,(uint16_t)uVar11,uVar15);
    if (iVar12 == 0) {
      pcVar7 = tuple_new_exit(0x16c,uVar4,(c2_operand *)0x0,opnd,tuple_splice_after,top->tail);
      top->tail = pcVar7;
    }
    else {
      pcVar18 = fn_saved->struct_return;
      if (pcVar18 == (c2_fe_symbol *)0x0) {
        ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\reader.c",0x515);
      }
      pcVar18->storage = pcVar18->storage & 0xfffffff3 | 3;
      node = (c2_tuple *)operand_for_fe_symbol(pcVar18);
      if (CONCAT22(op.size._2_2_,(ushort)op.size) < 0x1000) {
        uVar23 = (ushort)op.size | 0x5000;
        opnd2 = operand_new_mem(0x14c,uVar23,(c2_symbol *)0x0,0,(c2_operand *)node,(c2_operand *)0x0
                                ,0);
        pcVar7 = top->tail;
        insert_fn_00 = tuple_splice_after;
        pcVar19 = operand_new_intconst(0x1004,CONCAT22(op.size._2_2_,(ushort)op.size),0);
        pcVar7 = tuple_new_blockop(0x16b,uVar23,opnd2,opnd,pcVar19,insert_fn_00,pcVar7);
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
      pcVar7 = tuple_new_exit(0x16c,0x3004,(c2_operand *)0x0,opnd,tuple_splice_after,top->tail);
      top->tail = pcVar7;
    }
    pcVar7 = list;
    pcVar18 = g_reader_basic_error_label;
    fn_saved = fn;
    if (g_inlining_active == 0) {
      g_no_missing_return_warning = 0;
    }
    break;
  case 0x42:
    reader_read_conditional(&top);
    pcVar18 = g_reader_basic_error_label;
    break;
  case 0x44:
    if (this_mode == 0) {
      reader_swap_top(&top);
      fn = fn_saved;
    }
    else {
      pcVar1 = top->next->next;
      top->next->next = pcVar1->next;
      pcVar1->next = top;
      top = pcVar1;
      fn = fn_saved;
    }
    reader_flush_and_fold_copy(top);
    if (top->before != (c2_reader_cell *)0x0) {
      reader_flush_cells_to_head(top);
    }
    pcVar7 = tuple_new_block_boundary();
    opnd = (c2_operand *)reader_flush_cell_tuples(top,pcVar7);
    node = pcVar7->next;
    if (node == (c2_tuple *)0x0) {
      top->tail = top->head;
    }
    else {
      tuple_splice_after(top->head,node);
      top->tail = (c2_tuple *)opnd;
    }
    node_free((c2_node *)pcVar7);
    if (top->after != (c2_reader_cell *)0x0) {
      reader_flush_all_cells(top);
    }
    node = reader_pop(&top);
    pcVar7 = list;
    pcVar18 = g_reader_basic_error_label;
    fn_saved = fn;
    if (node != (c2_tuple *)0x0) {
      reader_push(&top->before,(c2_node *)node);
      pcVar18 = g_reader_basic_error_label;
      fn_saved = fn;
    }
    break;
  case 0x46:
    if (((g_pdb_il_mode != 0) && (g_reader_file_record_seen != 0)) &&
       (uVar16 = (fn->fsym->u4a).function.exp_offset, uVar16 != 0)) {
      g_current_line_abs = line_number_map(uVar16);
      g_il_line_base = uVar16;
      if (g_current_line_abs < fn->line_base + 0x10000) {
        g_cur_line = (short)g_current_line_abs - (short)fn->line_base;
      }
      else {
        g_cur_line = 0xffff;
      }
    }
    if (this_mode == 0) {
      opnd = (c2_operand *)reader_pop(&top);
      pcVar21 = (c2_operand *)0x0;
    }
    else {
      pcVar21 = (c2_operand *)reader_pop(&top);
      operand_to_memory_form(pcVar21);
      opnd = (c2_operand *)reader_pop(&top);
    }
    fn = fn_saved;
    node = tuple_new_func_entry(fn_saved);
    node_free((c2_node *)opnd);
    reader_push(&top,(c2_node *)node);
    pcVar10 = il_read_op(fn_saved,&op);
    while ((pcVar10 != (c2_reader_op *)0x0 && (op.op != 0x4c))) {
      node = top->tail;
      if (node->src == (c2_operand *)0x0) {
        pcVar13 = operand_for_fe_symbol(op.sym);
        node->src = pcVar13;
      }
      else {
        opnd2 = operand_for_fe_symbol(op.sym);
        tuple_splice_after((c2_tuple *)opnd2,(c2_tuple *)node->src);
        node->src = opnd2;
      }
      node->src->flags = node->src->flags | 0x10;
      pcVar10 = il_read_op(fn_saved,&op);
    }
    pcVar18 = fn_saved->fsym;
    uVar15 = pcVar18->refcount;
    uVar11 = il_type_to_c2_type((byte)pcVar18->storage & 0xf,uVar15);
    iVar12 = reader_type_is_simple_scalar(pcVar18->attrs & 0x1c,(uint16_t)uVar11,uVar15);
    if (iVar12 != 0) {
      pcVar18 = fe_symbol_new_local(fn_saved->scope,3,g_ptr_type & 0xfff,3,1,'\x04',0x100);
      *(undefined1 *)((int)&pcVar18->refcount + 2) = 1;
      pcVar18->name = (char *)0x0;
      fn_saved->struct_return = pcVar18;
    }
    if (pcVar21 != (c2_operand *)0x0) {
      node = top->tail;
      if (node->src != (c2_operand *)0x0) {
        tuple_splice_after((c2_tuple *)pcVar21,(c2_tuple *)node->src);
        bVar6 = pcVar21->flags;
        this_mode = 0;
        node->src = pcVar21;
        pcVar21->flags = bVar6 | 0x10;
        pcVar7 = list;
        pcVar18 = g_reader_basic_error_label;
        fn_saved = fn;
        break;
      }
      node->src = pcVar21;
      pcVar21->flags = pcVar21->flags | 0x10;
    }
    this_mode = 0;
    pcVar7 = list;
    pcVar18 = g_reader_basic_error_label;
    fn_saved = fn;
    break;
  case 0x47:
    node = tuple_new_func_exit(fn);
    reader_push(&top,(c2_node *)node);
    if (g_return_label_used == '\0') {
      node_free((c2_node *)g_return_label);
      g_return_label = (c2_tuple *)0x0;
      pcVar18 = g_reader_basic_error_label;
    }
    else {
      tuple_insert_before(top->tail,g_return_label);
      pcVar18 = g_reader_basic_error_label;
    }
    break;
  case 0x4b:
    reader_flush_and_fold_copy(top);
    pcVar18 = g_reader_basic_error_label;
    break;
  case 0x4c:
    done = 1;
    break;
  case 0x4f:
    switch((undefined2)op.arg) {
    case 1:
    case 0x24:
      if (op.value != 0) {
        g_current_line_abs = line_number_map(op.value);
        pcVar18 = g_reader_basic_error_label;
        if (g_current_line_abs < fn->line_base + 0x10000) {
          g_cur_line = (short)g_current_line_abs - (short)fn->line_base;
        }
        else {
          g_cur_line = 0xffff;
        }
      }
      break;
    default:
      ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\reader.c",0x6ae);
    case 0xf:
      part_offset = 0x1b4;
      goto LAB_1072fbed;
    case 0x10:
      part_offset = 0x1b5;
LAB_1072fbed:
      node = tuple_new_marker(part_offset);
      goto LAB_1072ebad;
    case 0x11:
      if (g_opt_debug_info != 0) {
        part_offset = 0x1b6;
        goto LAB_1072fbed;
      }
      break;
    case 0x12:
      if (g_opt_debug_info != 0) {
        part_offset = 0x1b7;
        goto LAB_1072fbed;
      }
      break;
    case 0x16:
      node = inasm_read_instruction((uint8_t *)op.value,fn->scope);
      goto LAB_1078501c;
    case 0x18:
      node = tuple_new_marker(0x1ba);
      (node->u14).arg = (void *)(op.value & 0xffff);
LAB_1078501c:
      node->flags = node->flags | 2;
      if (asm_last == (c2_tuple *)0x0) {
        (asm_block->u20).default_label = node;
        pcVar18 = g_reader_basic_error_label;
        asm_last = node;
      }
      else {
LAB_10785053:
        asm_last->next = node;
        node->prev = asm_last;
        asm_last = node;
        pcVar18 = g_reader_basic_error_label;
      }
      break;
    case 0x19:
      if ((cursor == (c2_tuple *)0x0) || (cursor->op != 0x191)) {
        asm_block = tuple_new_asm_block(0x191,0x1004);
        fn->flags = fn->flags | 1;
        pcVar18 = g_reader_basic_error_label;
      }
      else {
        asm_last = (cursor->u20).default_label;
        list = cursor->prev;
        tuple_unlink(cursor);
        for (pcVar7 = asm_last->next; pcVar7 != (c2_tuple *)0x0; pcVar7 = pcVar7->next) {
          asm_last = pcVar7;
        }
        fn->flags = fn->flags | 1;
        pcVar7 = list;
        pcVar18 = g_reader_basic_error_label;
        asm_block = cursor;
      }
      break;
    case 0x1a:
      if (asm_last == (c2_tuple *)0x0) {
        node_free((c2_node *)asm_block);
        asm_block = (c2_tuple *)0x0;
        asm_last = (c2_tuple *)0x0;
        pcVar18 = g_reader_basic_error_label;
      }
      else {
        reader_push(&top,(c2_node *)asm_block);
        asm_block = (c2_tuple *)0x0;
        asm_last = (c2_tuple *)0x0;
        pcVar18 = g_reader_basic_error_label;
      }
      break;
    case 0x1f:
      bVar24 = g_inlining_active == 0;
      fn->options = op.value;
      pcVar18 = g_reader_basic_error_label;
      if (bVar24) {
        apply_function_optimize_flags(op.value);
        g_label_merge_class1 = g_opt_global;
        pcVar18 = g_reader_basic_error_label;
      }
      break;
    case 0x20:
      node = tuple_new_marker(0x1b8);
      node->u14 = (c2_tuple_u14)op.value;
      reader_push(&top,(c2_node *)node);
      pcVar18 = g_reader_basic_error_label;
      break;
    case 0x23:
      bVar24 = g_inlining_active == 0;
      fn->warning_states = (c2_warning_state *)op.sym;
      pcVar18 = g_reader_basic_error_label;
      if (bVar24) {
        apply_warning_state_list((short *)op.sym);
        pcVar18 = g_reader_basic_error_label;
      }
      break;
    case 0x25:
      if (op.value == 0) {
        if ((fn->fsym->attrs & 0x1000) != 0) {
          node = tuple_new_pseudo(0x19b,0x1004);
          goto LAB_1072ebad;
        }
      }
      else {
        pcVar18 = fe_scope_lookup_id(fn->scope,op.value);
        if ((*(byte *)&pcVar18->u3e & 1) != 0) {
          opnd = (c2_operand *)(pcVar18->u32).label_tuple;
          pcVar18->role = 'X';
          if (opnd == (c2_operand *)0x0) {
            opnd = (c2_operand *)tuple_new_label(pcVar18);
          }
          node = tuple_new_branch(0x18b,'\0',(c2_node *)opnd,(c2_operand *)0x0,(c2_tuple *)0x0,
                                  (c2_insert_fn *)0x0,(c2_tuple *)0x0);
          goto LAB_1072ebad;
        }
      }
    }
    break;
  case 0x53:
    depth = depth + 1;
    if (1 < depth) {
      g_reader_block_cursor = g_reader_block_cursor->next;
      node = tuple_new_marker(0x1b4);
      node->u14 = (c2_tuple_u14)g_reader_block_cursor->locals;
      reader_push(&top,(c2_node *)node);
      pcVar18 = g_reader_basic_error_label;
    }
    break;
  case 0x54:
    if (1 < depth) {
      node = tuple_new_marker(0x1b5);
      node->u14 = (c2_tuple_u14)g_reader_block_cursor->locals;
      reader_push(&top,(c2_node *)node);
      pcVar2 = g_reader_block_cursor->prev;
      pcVar3 = pcVar2->next->next;
      g_reader_block_cursor = pcVar2;
      pcVar2->next = pcVar3;
      if (pcVar3 != (c2_reader_block *)0x0) {
        pcVar3->prev = pcVar2;
      }
    }
    if (op.value == 0 && op.value_hi == 0) {
      done = 1;
    }
    depth = depth + -1;
    pcVar18 = g_reader_basic_error_label;
    break;
  case 0x55:
    reader_read_argument(top,&op);
    pcVar18 = g_reader_basic_error_label;
    break;
  case 0x56:
    reader_set_source_file((char *)op.sym);
    g_current_line_abs = 0;
    g_cur_line = 0;
    g_reader_file_record_seen = 1;
    pcVar18 = g_reader_basic_error_label;
    break;
  case 0x59:
    node = (c2_tuple *)reader_pop_operand(top);
    if (top->head->next == (c2_tuple *)0x0) {
      tuple_splice_after(top->tail,node);
      top->tail = node;
      pcVar18 = g_reader_basic_error_label;
    }
    else {
      node = tuple_new_unary_temp
                       (0x162,((c2_operand *)node)->type,(c2_operand *)node,tuple_splice_after,
                        top->tail);
      if ((g_opt_basic != 0) && ((node->type & 0xf000) != 0x4000)) {
        pcVar21 = operand_new_codeaddr(0x154,g_reader_basic_error_label);
        tuple_append_src(node,pcVar21);
        node->op = 0x178;
      }
      top->tail = node;
      pcVar18 = g_reader_basic_error_label;
    }
    break;
  case 0x5c:
    node = tuple_new_pseudo(0x1a0,0x1004);
    pcVar22 = arena_alloc(1,0x10);
    (node->u20).cond_cells = pcVar22;
    ((node->u20).eh_construct)->flags = CONCAT22(op.arg._2_2_,(undefined2)op.arg);
    opnd = (c2_operand *)tuple_new_block_boundary();
    cells = top->before;
    opnd2 = opnd;
    while (cells != (c2_reader_cell *)0x0) {
      opnd = (c2_operand *)reader_flush_cell_tuples(cells,(c2_tuple *)opnd);
      reader_pop(&cells);
    }
    top->before = (c2_reader_cell *)0x0;
    opnd = (c2_operand *)reader_flush_cell_tuples(top,(c2_tuple *)opnd);
    cells = top->after;
    fn = fn_saved;
    while (cells != (c2_reader_cell *)0x0) {
      opnd = (c2_operand *)reader_flush_cell_tuples(cells,(c2_tuple *)opnd);
      reader_pop(&cells);
    }
    top->after = (c2_reader_cell *)0x0;
    reader_pop(&top);
    ((node->u20).cond_cells)->next = (c2_cond_cell *)opnd2->next;
    node_free((c2_node *)opnd2);
    pcVar22 = ((node->u20).cond_cells)->next;
    if (pcVar22 != (c2_cond_cell *)0x0) {
      pcVar22->cc = 0;
    }
    opnd = reader_pop_operand(top);
    if ((opnd->flags & 0x10) != 0) {
      opnd = (c2_operand *)node_clone((c2_node *)opnd);
    }
    if (opnd->kind == '\x06') {
      pcVar21 = tuple_append_src(node,opnd->base);
      node->src = pcVar21;
    }
    else {
      pcVar21 = tuple_append_src(node,opnd);
      node->src = pcVar21;
    }
    node->type = node->src->type;
    pcVar21 = operand_new_temp(node->src->type);
    node->dst = pcVar21;
    node->dst->flags = node->dst->flags | 0x10;
    symbol_mark_overlapping_parts(node->dst->sym,node);
    tuple_splice_after(top->tail,node);
    top->tail = node;
    pcVar7 = list;
    pcVar18 = g_reader_basic_error_label;
    fn_saved = fn;
    if (opnd->kind == '\x06') {
      reader_load_value(top,opnd->type,g_reader_aggregate_size,0);
      opnd->base = (c2_operand *)0x0;
      node_free((c2_node *)opnd);
      pcVar18 = g_reader_basic_error_label;
      fn_saved = fn;
    }
    break;
  case 0x5d:
  case 0x5e:
    node = tuple_new_pseudo((op.op != 0x5d) + 0x1a1,0x1004);
    pcVar22 = arena_alloc(1,0x10);
    (node->u20).cond_cells = pcVar22;
    ((node->u20).eh_region)->count = op.value;
    ((node->u20).eh_construct)->flags = CONCAT22(op.arg._2_2_,(undefined2)op.arg);
    reader_push(&top,(c2_node *)node);
    pcVar18 = g_reader_basic_error_label;
    break;
  case 0x60:
  case 0x62:
    node = tuple_new_pseudo((-(uint)(op.op != 0x60) & 2) + 0x1a4,0x1004);
    pcVar22 = arena_alloc(1,0x10);
    (node->u20).cond_cells = pcVar22;
    reader_push(&top,(c2_node *)node);
    pcVar18 = g_reader_basic_error_label;
    break;
  case 0x61:
    node = tuple_new_pseudo(0x1a5,0x1004);
    pcVar22 = arena_alloc(1,0x10);
    (node->u20).cond_cells = pcVar22;
    ((node->u20).eh_region)->count = op.value;
    ((node->u20).eh_construct)->object = (c2_eh_state *)op.sym;
    ((node->u20).eh_construct)->flags = CONCAT22(op.arg._2_2_,(undefined2)op.arg);
    reader_push(&top,(c2_node *)node);
    pcVar18 = g_reader_basic_error_label;
    break;
  case 0x68:
    g_reader_pointer_arith = 1;
    reader_binary_op(&top,0x16d);
    g_reader_pointer_arith = 0;
    opnd = top->tail->dst;
    pcVar18 = g_reader_basic_error_label;
    if (((1 << (opnd->kind & 0x1f) & 6U) != 0) &&
       (pcVar14 = opnd->sym, pcVar14->def != (c2_tuple *)0x0)) {
      (pcVar14->u30).local_number = (pcVar14->u30).local_number | 1;
      opnd->sym->def->type = 0x3004;
      operand_set_type(opnd,0x3004);
      pcVar18 = g_reader_basic_error_label;
    }
    break;
  case 0x77:
    opnd = (c2_operand *)reader_pop(&top);
    if ((opnd->u18).reg != (c2_symbol *)0x0) {
      pcVar21 = reader_duplicate_operand(top);
      reader_push(&top,(c2_node *)pcVar21);
      reader_swap_top(&top);
      pcVar19 = operand_new_intconst(0x3004,0,0);
      reader_push(&top,(c2_node *)pcVar19);
      reader_binary_op(&top,0x17d);
      pcVar21 = top->tail->dst;
      pcVar21->flags11 = pcVar21->flags11 & 0xf | 0x10;
      reader_swap_top(&top);
      reader_push(&top,(c2_node *)opnd);
      reader_binary_op(&top,0x16d);
      pcVar19 = operand_new_intconst(0x1004,0,0);
      reader_push(&top,(c2_node *)pcVar19);
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
                         (fn,cursor,(void *)0x0,case_tail,top,node,opnd,opnd2,cells,fn_saved,
                          asm_last,asm_block,this_mode,done,cond,stack,op_00,list,depth,top_level);
      return pcVar7;
    }
    node_free((c2_node *)opnd);
    pcVar18 = g_reader_basic_error_label;
    break;
  case 0x8b:
    g_reader_pointer_arith = 1;
    reader_binary_op(&top,0x16e);
    g_reader_pointer_arith = 0;
    pcVar21 = (c2_operand *)top->tail;
    pcVar18 = g_reader_basic_error_label;
    if ((pcVar21->op == 0x16e) && (opnd = pcVar21, ((pcVar21->u18).children)->kind == '\a')) {
      reader_discard_value((c2_tuple *)pcVar21);
      pcVar18 = g_reader_basic_error_label;
    }
    break;
  case 0x8d:
    pcVar17 = tuple_new_pseudo(0x198,0x1004);
    reader_push_tuple_list(top,pcVar17);
    opnd = reader_pop_operand(top);
    convert_operand(&opnd,0x1004,&top->tail);
    node = tuple_new_pseudo(0x199,0x1004);
    tuple_append_src(node,opnd);
    tuple_splice_after(top->tail,node);
    top->tail = node;
    pcVar18 = g_reader_basic_error_label;
    break;
  case 0x8e:
    node = tuple_new_pseudo(0x194,0x1004);
    goto LAB_1072ebad;
  case 0x8f:
    node = tuple_new_pseudo(0x192,0x1004);
    goto LAB_1072ebad;
  case 0x90:
    node = tuple_new_pseudo(0x193,0x1004);
    goto LAB_1072ebad;
  case 0x99:
    reader_address_of_top(top,0x3004);
    this_mode = 1;
    pcVar18 = g_reader_basic_error_label;
    break;
  case 0x9a:
    reader_address_of_top(top,0x3004);
    reader_address_of_top(top,0x3004);
    this_mode = 2;
    pcVar18 = g_reader_basic_error_label;
    break;
  case 0x9b:
    if ((op.type & 0xf000) == 0x5000) {
      uVar15 = CONCAT22(op.size._2_2_,(ushort)op.size);
    }
    else {
      uVar15 = op.type & 0xfff;
    }
    uVar16 = type_class_to_symbol_class(op.type);
    pcVar18 = reader_eh_object_local(fn,CONCAT22(op.arg._2_2_,(undefined2)op.arg),uVar16,uVar15);
    node = (c2_tuple *)operand_for_symbol_ref(pcVar18);
LAB_1072ebad:
    reader_push(&top,(c2_node *)node);
    pcVar18 = g_reader_basic_error_label;
    break;
  case 0x9d:
    reader_build_thunk_body(&top,depth,fn);
    pcVar18 = g_reader_basic_error_label;
    break;
  case 0xa0:
    opnd = reader_pop_operand(top);
    if (top->before != (c2_reader_cell *)0x0) {
      reader_flush_cells_to_head(top);
    }
    node = tuple_new_pseudo(0x1ac,op.type);
    tuple_append_src(node,opnd);
    tuple_splice_after(top->tail,node);
    top->tail = node;
    if (top->after != (c2_reader_cell *)0x0) {
      reader_flush_all_cells(top);
    }
    node = tuple_new_pseudo(0x1ab,0x1004);
    opnd2 = (c2_operand *)tuple_new_block_boundary();
    (node->u20).default_label = (c2_tuple *)opnd2;
    tuple_splice_after((c2_tuple *)opnd2,top->head->next);
    top->head->next = node;
    node->prev = top->head;
    top->tail = node;
    pcVar18 = g_reader_basic_error_label;
    if ((opnd->kind == '\a') && ((opnd->u18).reg == (c2_symbol *)0x0 && opnd->tag == 0)) {
      pcVar17 = tuple_new_branch(0x18c,'\0',(c2_node *)g_return_label,(c2_operand *)0x0,
                                 (c2_tuple *)0x0,tuple_splice_after,top->tail);
      g_return_label_used = '\x01';
      top->tail = pcVar17;
      pcVar18 = g_reader_basic_error_label;
    }
  }
switchD_1072fb80_caseD_1:
  g_reader_basic_error_label = pcVar18;
  cursor = pcVar7;
  if ((op.op == 0x4b) || (((&g_il_op_attr_high)[op.op * 2] & 0x10) != 0)) {
    if (done != 0) goto LAB_107300d8;
    if (top != (c2_reader_cell *)0x0) {
      if ((g_reader_new_locals != (c2_list_cell *)0x0) && (top_level != 0)) {
        node = tuple_new_marker(0x1b4);
        (node->u14).scope_locals = g_reader_new_locals;
        node->flags12 = '\x01';
        tuple_splice_after(cursor,node);
        cursor = node;
      }
      cells = top->before;
      while (cells != (c2_reader_cell *)0x0) {
        cursor = reader_flush_cell_tuples(cells,cursor);
        reader_pop(&cells);
      }
      top->before = (c2_reader_cell *)0x0;
      cursor = reader_flush_cell_tuples(top,cursor);
      cells = top->after;
      while (cells != (c2_reader_cell *)0x0) {
        cursor = reader_flush_cell_tuples(cells,cursor);
        reader_pop(&cells);
      }
      top->after = (c2_reader_cell *)0x0;
      reader_pop(&top);
      list = cursor;
      if ((g_reader_new_locals != (c2_list_cell *)0x0) && (top_level != 0)) {
        node = tuple_new_marker(0x1b5);
        (node->u14).scope_locals = g_reader_new_locals;
        node->flags12 = '\x01';
        tuple_splice_after(cursor,node);
        g_reader_new_locals = (c2_list_cell *)0x0;
        list = node;
        cursor = node;
      }
    }
  }
  else if (done != 0) {
LAB_107300d8:
    *stack = top;
    return cursor;
  }
  goto LAB_1072fb3d;
switchD_1072fb80_caseD_3e:
  reader_read_call(&top,&op,depth,fn,this_mode);
  this_mode = 0;
  pcVar18 = g_reader_basic_error_label;
  goto switchD_1072fb80_caseD_1;
switchD_1072fb80_caseD_2:
  reader_binary_op(&top,0x16d);
  pcVar18 = g_reader_basic_error_label;
  goto switchD_1072fb80_caseD_1;
}

