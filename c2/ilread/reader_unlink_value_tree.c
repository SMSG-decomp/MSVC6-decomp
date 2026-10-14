void __fastcall reader_unlink_value_tree(c2_tuple *t)

{
  byte bVar1;
  c2_operand *pcVar2;
  c2_tuple *pcVar3;
  uint32_t uVar4;
  c2_operand *pcVar5;
  uint uVar6;
  c2_node *list;
  
  uVar6 = 1 << (t->kind & 0x1f);
  if ((uVar6 & 0xffe) == 0) {
    for (pcVar5 = t->src; pcVar5 != (c2_operand *)0x0; pcVar5 = pcVar5->next) {
      if (((1 << (pcVar5->kind & 0x1f) & 6U) != 0) &&
         (pcVar3 = pcVar5->sym->def, pcVar3 != (c2_tuple *)0x0)) {
        reader_unlink_value_tree(pcVar3);
      }
    }
  }
  else {
    if (((uVar6 & 6) != 0) && (pcVar3 = ((t->u14).expr)->def, pcVar3 != (c2_tuple *)0x0)) {
      reader_unlink_value_tree(pcVar3);
      tuple_unlink(t);
      node_free((c2_node *)t);
      return;
    }
    if (((t->kind == 6) &&
        ((uVar4 = t->switch_flags, uVar4 == 0 ||
         (((1 << (*(byte *)(uVar4 + 8) & 0x1f) & 6U) != 0 &&
          (*(int *)(*(int *)(uVar4 + 0x14) + 0x14) != 0)))))) &&
       ((pcVar3 = t[1].next, pcVar3 == (c2_tuple *)0x0 ||
        (((1 << (pcVar3->kind & 0x1f) & 6U) != 0 &&
         (((pcVar3->u14).block)->rpo_next != (c2_block *)0x0)))))) {
      reader_unlink_value_tree(*(c2_tuple **)(*(int *)(uVar4 + 0x14) + 0x14));
      tuple_unlink(t);
      node_free((c2_node *)t);
      return;
    }
  }
  tuple_unlink(t);
  bVar1 = t->kind;
  switch(*(undefined1 *)((int)node_free_jump_table + bVar1 + 0x2b)) {
  case 1:
    if ((c2_node *)t->switch_flags != (c2_node *)0x0) {
      node_free((c2_node *)t->switch_flags);
    }
    if (t[1].next != (c2_tuple *)0x0) {
      node_free((c2_node *)t[1].next);
    }
    break;
  case 2:
    goto switchD_10701bc6_caseD_2;
  case 3:
    if (t->op == 0x188) {
      seh_forget_finally_call(t);
    }
    else if (t->op == 0x189) {
      seh_forget_finally_ret(t);
    }
    if ((t->src->kind == '\x04') &&
       (pcVar3 = *(c2_tuple **)((int)&t->src->sym->u30 + 2), pcVar3 != (c2_tuple *)0x0)) {
      label_remove_ref(pcVar3,(c2_node *)t);
    }
  case 6:
switchD_10701bc6_caseD_6:
    list = (c2_node *)(t->u20).cond_cells;
LAB_10701ab5:
    node_list_free(list);
switchD_10701bc6_caseD_2:
    pcVar5 = t->src;
    while (pcVar5 != (c2_operand *)0x0) {
      pcVar2 = pcVar5->next;
      uVar6 = 1 << (pcVar5->kind & 0x1f);
      if ((((uVar6 & 0xffe) != 0) && ((uVar6 & 0x60) != 0)) && ((pcVar5->flags11 & 0x20) == 0)) {
        pcVar5->base = (c2_operand *)0x0;
        pcVar5->index = (c2_operand *)0x0;
      }
      node_free((c2_node *)pcVar5);
      pcVar5 = pcVar2;
    }
    pcVar5 = t->dst;
    while (pcVar5 != (c2_operand *)0x0) {
      pcVar2 = pcVar5->next;
      uVar6 = 1 << (pcVar5->kind & 0x1f);
      if ((((uVar6 & 0xffe) != 0) && ((uVar6 & 0x60) != 0)) && ((pcVar5->flags11 & 0x20) == 0)) {
        pcVar5->base = (c2_operand *)0x0;
        pcVar5->index = (c2_operand *)0x0;
      }
      node_free((c2_node *)pcVar5);
      pcVar5 = pcVar2;
    }
    break;
  case 4:
    if (t->op != 0x18e) {
      label_remove_ref((t->u20).default_label,(c2_node *)t);
    }
    list = (c2_node *)(t->u24).cases;
    goto LAB_10701ab5;
  case 5:
    uVar4 = t->op;
    if (uVar4 == 0x1a0) {
      cxx_eh_funclet_ref_released(t);
    }
    else if (uVar4 == 0x1a4) {
      eh_object_release(t);
    }
    else if (uVar4 == 0x1ab) goto switchD_10701bc6_caseD_6;
    goto switchD_10701bc6_caseD_2;
  case 7:
    node_list_free((c2_node *)t->src);
    break;
  case 8:
    node_list_free((c2_node *)t->dst);
    *(undefined4 *)((int)&t->src[1].next + 2) = 0;
    break;
  case 9:
    if ((t->u14).regs != (c2_bitset *)0x0) {
      bitset_free((t->u14).regs);
    }
    break;
  case 10:
    label_remove_ref((c2_tuple *)(t->u14).scope_locals,(c2_node *)t);
  }
  pcVar3 = (c2_tuple *)g_node_free_lists[g_node_kind_sizes[bVar1]];
  g_node_free_lists[g_node_kind_sizes[bVar1]] = (c2_node *)t;
  t->next = pcVar3;
  return;
}

