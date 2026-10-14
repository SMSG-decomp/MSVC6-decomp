void __fastcall reader_binary_op(c2_reader_cell **stack,uint32_t op)

{
  byte bVar1;
  c2_symbol *pcVar2;
  uint32_t uVar3;
  uint16_t uVar4;
  undefined2 extraout_var;
  c2_tuple *pcVar5;
  c2_operand *left_00;
  undefined4 unaff_EBX;
  uint32_t const_lo;
  c2_tuple **ppcVar6;
  c2_operand *pcVar7;
  uint64_t uVar8;
  c2_operand *right_home;
  c2_operand *left;
  c2_tuple **tail;
  uint32_t op_saved;
  uint32_t type;
  int both_pointers;
  uint32_t right_lo;
  
  both_pointers = 0;
  op_saved = op;
  reader_pop_two_merge(stack,&left,&right_home,0);
  if ((op == 0x177) || (op == 0x171)) {
    uVar4 = left->type;
    const_lo._2_2_ = (undefined2)((uint)unaff_EBX >> 0x10);
    const_lo = CONCAT22(const_lo._2_2_,uVar4);
    type = const_lo;
    if ((right_home->type & 0xfff) < 5) {
      tail = &(*stack)->tail;
      convert_operand(&right_home,uVar4,tail);
      ppcVar6 = tail;
    }
    else {
      ppcVar6 = &(*stack)->tail;
      tail = ppcVar6;
      convert_operand(&right_home,0x1004,ppcVar6);
    }
    convert_operand(&left,uVar4,ppcVar6);
    ppcVar6 = tail;
  }
  else {
    uVar4 = usual_arithmetic_type(left->type,right_home->type);
    type = CONCAT22(extraout_var,uVar4);
    if (((left->type & 0xf000) != 0x3000) ||
       (both_pointers = 1, (right_home->type & 0xf000) != 0x3000)) {
      both_pointers = 0;
    }
    if ((op == 0x17d) && (((uVar4 & 0xf000) == 0x3000 || (both_pointers != 0)))) {
      type = (uint32_t)(uVar4 & 0xfff | 0x2000);
    }
    const_lo = type;
    ppcVar6 = &(*stack)->tail;
    uVar4 = (uint16_t)type;
    tail = ppcVar6;
    convert_operand(&left,uVar4,ppcVar6);
    convert_operand(&right_home,uVar4,ppcVar6);
    if (((left->type ^ right_home->type) & 0xfff) != 0) {
      ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\reader.c",0x85b);
    }
  }
  pcVar7 = left;
  uVar4 = (uint16_t)const_lo;
  if ((left->kind == '\a') &&
     (((((op_saved == 0x16d || (op_saved == 0x16f)) || (op_saved == 0x172)) ||
       ((op_saved == 0x173 || (op_saved == 0x174)))) && (g_reader_pointer_arith == 0)))) {
    left = right_home;
    right_home = pcVar7;
  }
  left_00 = left;
  pcVar7 = right_home;
  if ((right_home->kind != '\a') || (g_reader_pointer_arith != 0)) goto switchD_10730bd7_caseD_170;
  switch(op_saved) {
  case 0x16d:
    if (g_opt_dlp != 0) break;
    bVar1 = left->kind;
    while (((((1 << (bVar1 & 0x1f) & 6U) != 0 &&
             (pcVar5 = left->sym->def, ppcVar6 = tail, pcVar5 != (c2_tuple *)0x0)) &&
            (pcVar5->op == 0x16d)) && (pcVar5->src->next->kind == '\a'))) {
      if ((left->flags & 0x10) == 0) {
        node_free((c2_node *)left);
      }
      left = (c2_operand *)node_clone((c2_node *)pcVar5->src);
      pcVar7 = pcVar5->src->next;
      pcVar2 = (pcVar7->u18).reg;
      right_lo = (right_home->u18).lo;
      uVar3 = pcVar7->tag;
      (right_home->u18).reg = (c2_symbol *)((int)&pcVar2->fe + right_lo);
      right_home->tag = right_home->tag + uVar3 + (uint)CARRY4(right_lo,(uint)pcVar2);
      if (left->type != uVar4) {
        left->type = uVar4;
        uVar8 = const_normalize(uVar4,(right_home->u18).lo,right_home->tag);
        right_home->u18 = (c2_operand_u18)(int)uVar8;
        right_home->tag = (int)(uVar8 >> 0x20);
      }
      if (*tail == pcVar5) {
        *tail = pcVar5->prev;
      }
      tuple_unlink(pcVar5);
      node_free((c2_node *)pcVar5);
      bVar1 = left->kind;
      ppcVar6 = tail;
    }
  case 0x16e:
  case 0x171:
  case 0x174:
  case 0x177:
    left_00 = left;
    pcVar7 = right_home;
    if ((right_home->u18).reg == (c2_symbol *)0x0 && right_home->tag == 0) {
LAB_10730dd5:
      if ((pcVar7->flags & 0x10) == 0) {
        node_free((c2_node *)pcVar7);
        left_00 = left;
      }
      if ((*(uint16_t *)&left_00->flags & 0x10) != 0) {
        left_00 = (c2_operand *)node_clone((c2_node *)left_00);
        left = left_00;
      }
      tuple_splice_after(*ppcVar6,(c2_tuple *)left_00);
      *ppcVar6 = (c2_tuple *)left;
      return;
    }
    break;
  case 0x16f:
    if ((right_home->u18).reg == (c2_symbol *)0x0 && right_home->tag == 0) {
code_r0x10730eed:
      if ((left->flags & 0x10) == 0) {
        node_free((c2_node *)left);
      }
      if ((right_home->flags & 0x10) != 0) {
        right_home = (c2_operand *)node_clone((c2_node *)right_home);
      }
      pcVar5 = (c2_tuple *)tuple_delete_if_dead((c2_node *)*ppcVar6,0);
      *ppcVar6 = pcVar5;
      tuple_splice_after(pcVar5,(c2_tuple *)right_home);
      *ppcVar6 = (c2_tuple *)right_home;
      return;
    }
  case 0x175:
    if (((right_home->u18).reg == (c2_symbol *)0x1) && (right_home->tag == 0)) goto LAB_10730dd5;
    break;
  default:
    break;
  case 0x172:
    const_lo = (right_home->u18).lo;
    if (const_lo == 0 && right_home->tag == 0) goto code_r0x10730eed;
    uVar8 = aullshr(('\b' - (char)right_home->type) * '\b',0xffffffff,0xffffffff);
    ppcVar6 = tail;
    if (uVar8 == CONCAT44((uint)(uVar8 >> 0x20) & pcVar7->tag,(uint)uVar8 & const_lo))
    goto LAB_10730dd5;
    goto LAB_10730e45;
  case 0x173:
    const_lo = (right_home->u18).lo;
    if (const_lo == 0 && right_home->tag == 0) goto LAB_10730dd5;
    uVar8 = aullshr(('\b' - (char)right_home->type) * '\b',0xffffffff,0xffffffff);
    if (uVar8 == CONCAT44((uint)(uVar8 >> 0x20) & pcVar7->tag,(uint)uVar8 & const_lo)) {
      reader_binary_op_part(left_00,pcVar7,tail,right_home);
      return;
    }
LAB_10730e45:
    uVar4 = (uint16_t)type;
    ppcVar6 = tail;
  }
switchD_10730bd7_caseD_170:
  if (op_saved != 0x17d) {
    pcVar5 = tuple_new_binary_temp(op_saved,uVar4,left_00,pcVar7,tuple_splice_after,*ppcVar6);
    *tail = pcVar5;
    return;
  }
  pcVar5 = tuple_new_compare(0x17d,uVar4,left_00,pcVar7,tuple_splice_after,*ppcVar6);
  reader_check_binary_index((c2_tuple *)pcVar5->src,(c2_tuple *)pcVar5->src->next,both_pointers);
  *tail = pcVar5;
  return;
}

