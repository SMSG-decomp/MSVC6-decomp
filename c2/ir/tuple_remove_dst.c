uint32_t __fastcall tuple_remove_dst(c2_tuple *t,c2_operand *op)

{
  c2_tuple *label;
  uint32_t uVar1;
  c2_operand *pcVar2;
  c2_operand *cur;
  c2_node *sublist;
  c2_operand *prev;
  uint uVar3;
  c2_operand *src_opnd;
  c2_node *dst_opnd;
  c2_node *dst_next;
  c2_node *free_head;
  uint8_t kind;
  c2_operand *src_next;
  
  prev = (c2_operand *)0x0;
  pcVar2 = t->dst;
  if (t->dst == (c2_operand *)0x0) {
LAB_10701b81:
    t->dst = op->next;
  }
  else {
    do {
      cur = pcVar2;
      if (cur == op) break;
      pcVar2 = cur->next;
      prev = cur;
    } while (cur->next != (c2_operand *)0x0);
    if (prev == (c2_operand *)0x0) goto LAB_10701b81;
    prev->next = op->next;
  }
  if ((1 << (op->kind & 0x1f) & 0x60U) != 0) {
    tuple_remove_mem_subops(t,op);
  }
  kind = op->kind;
  switch(*(undefined1 *)((int)node_free_jump_table + kind + 0x2b)) {
  case 1:
    if (op->base != (c2_operand *)0x0) {
      node_free((c2_node *)op->base);
    }
    if (op->index != (c2_operand *)0x0) {
      node_free((c2_node *)op->index);
    }
    break;
  case 2:
    goto switchD_10701bc6_caseD_2;
  case 3:
    if (op->op == 0x188) {
      seh_forget_finally_call((c2_tuple *)op);
    }
    else if (op->op == 0x189) {
      seh_forget_finally_ret((c2_tuple *)op);
    }
    if ((((op->u18).children)->kind == '\x04') &&
       (label = *(c2_tuple **)((int)&((op->u18).children)->sym->u30 + 2), label != (c2_tuple *)0x0))
    {
      label_remove_ref(label,(c2_node *)op);
    }
  case 6:
switchD_10701bc6_caseD_6:
    sublist = (c2_node *)op->base_sym;
LAB_10701ab5:
    node_list_free(sublist);
switchD_10701bc6_caseD_2:
    src_opnd = (op->u18).children;
    while (src_opnd != (c2_operand *)0x0) {
      src_next = src_opnd->next;
      uVar3 = 1 << (src_opnd->kind & 0x1f);
      if ((((uVar3 & 0xffe) != 0) && ((uVar3 & 0x60) != 0)) && ((src_opnd->flags11 & 0x20) == 0)) {
        src_opnd->base = (c2_operand *)0x0;
        src_opnd->index = (c2_operand *)0x0;
      }
      node_free((c2_node *)src_opnd);
      src_opnd = src_next;
    }
    dst_opnd = (c2_node *)op->tag;
    while (dst_opnd != (c2_node *)0x0) {
      dst_next = dst_opnd->next;
      uVar3 = 1 << (dst_opnd->kind & 0x1f);
      if ((((uVar3 & 0xffe) != 0) && ((uVar3 & 0x60) != 0)) &&
         (((uint)dst_opnd[1].next & 0x2000) == 0)) {
        dst_opnd[2].kind = '\0';
        dst_opnd[2].flags = '\0';
        dst_opnd[2].type = 0;
        dst_opnd[2].rank_or_prev = 0;
      }
      node_free(dst_opnd);
      dst_opnd = dst_next;
    }
    break;
  case 4:
    if (op->op != 0x18e) {
      label_remove_ref((c2_tuple *)op->base_sym,(c2_node *)op);
    }
    sublist = (c2_node *)op->disp;
    goto LAB_10701ab5;
  case 5:
    uVar1 = op->op;
    if (uVar1 == 0x1a0) {
      cxx_eh_funclet_ref_released((c2_tuple *)op);
    }
    else if (uVar1 == 0x1a4) {
      eh_object_release((c2_tuple *)op);
    }
    else if (uVar1 == 0x1ab) goto switchD_10701bc6_caseD_6;
    goto switchD_10701bc6_caseD_2;
  case 7:
    node_list_free((c2_node *)(op->u18).reg);
    break;
  case 8:
    node_list_free((c2_node *)op->tag);
    *(undefined4 *)((int)&((op->u18).range)->last_block + 2) = 0;
    break;
  case 9:
    if (op->sym != (c2_symbol *)0x0) {
      bitset_free((c2_bitset *)op->sym);
    }
    break;
  case 10:
    label_remove_ref((c2_tuple *)op->sym,(c2_node *)op);
  }
  uVar1 = g_node_kind_sizes[kind];
  free_head = g_node_free_lists[uVar1];
  g_node_free_lists[uVar1] = (c2_node *)op;
  op->next = (c2_operand *)free_head;
  return uVar1;
}

