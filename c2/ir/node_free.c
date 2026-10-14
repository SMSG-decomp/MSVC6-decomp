uint32_t __fastcall node_free(c2_node *node)

{
  c2_node *pcVar1;
  uint uVar2;
  uint32_t kind;
  c2_node *src_opnd;
  c2_node *src_next;
  c2_node *dst_opnd;
  c2_node *dst_next;
  c2_tuple *label;
  uint32_t size;
  
  kind = (uint32_t)node->kind;
  switch(*(undefined1 *)((int)node_free_jump_table + kind + 0x2b)) {
  case 1:
    if (*(c2_node **)&node[2].kind != (c2_node *)0x0) {
      node_free(*(c2_node **)&node[2].kind);
    }
    if ((c2_node *)node[2].rank_or_prev != (c2_node *)0x0) {
      node_free((c2_node *)node[2].rank_or_prev);
    }
    break;
  case 2:
    goto switchD_10701bc6_caseD_2;
  case 3:
    if (node->op == 0x188) {
      seh_forget_finally_call((c2_tuple *)node);
    }
    else if (node->op == 0x189) {
      seh_forget_finally_ret((c2_tuple *)node);
    }
    if ((*(char *)(*(int *)&node[1].kind + 8) == '\x04') &&
       (label = *(c2_tuple **)(*(int *)(*(int *)&node[1].kind + 0x14) + 0x32),
       label != (c2_tuple *)0x0)) {
      label_remove_ref(label,node);
    }
  case 6:
switchD_10701bc6_caseD_6:
    pcVar1 = node[2].next;
LAB_10701ab5:
    node_list_free(pcVar1);
switchD_10701bc6_caseD_2:
    src_opnd = *(c2_node **)&node[1].kind;
    while (src_opnd != (c2_node *)0x0) {
      src_next = src_opnd->next;
      uVar2 = 1 << (src_opnd->kind & 0x1f);
      if ((((uVar2 & 0xffe) != 0) && ((uVar2 & 0x60) != 0)) &&
         (((uint)src_opnd[1].next & 0x2000) == 0)) {
        src_opnd[2].kind = '\0';
        src_opnd[2].flags = '\0';
        src_opnd[2].type = 0;
        src_opnd[2].rank_or_prev = 0;
      }
      node_free(src_opnd);
      src_opnd = src_next;
    }
    dst_opnd = (c2_node *)node[1].rank_or_prev;
    while (dst_opnd != (c2_node *)0x0) {
      dst_next = dst_opnd->next;
      uVar2 = 1 << (dst_opnd->kind & 0x1f);
      if ((((uVar2 & 0xffe) != 0) && ((uVar2 & 0x60) != 0)) &&
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
    if (node->op != 0x18e) {
      label_remove_ref((c2_tuple *)node[2].next,node);
    }
    pcVar1 = (c2_node *)node[2].op;
    goto LAB_10701ab5;
  case 5:
    size = node->op;
    if (size == 0x1a0) {
      cxx_eh_funclet_ref_released((c2_tuple *)node);
    }
    else if (size == 0x1a4) {
      eh_object_release((c2_tuple *)node);
    }
    else if (size == 0x1ab) goto switchD_10701bc6_caseD_6;
    goto switchD_10701bc6_caseD_2;
  case 7:
    node_list_free(*(c2_node **)&node[1].kind);
    break;
  case 8:
    node_list_free((c2_node *)node[1].rank_or_prev);
    *(undefined4 *)(*(int *)&node[1].kind + 0x32) = 0;
    break;
  case 9:
    if ((c2_bitset *)node[1].op != (c2_bitset *)0x0) {
      bitset_free((c2_bitset *)node[1].op);
    }
    break;
  case 10:
    label_remove_ref((c2_tuple *)node[1].op,node);
  }
  size = g_node_kind_sizes[kind];
  pcVar1 = g_node_free_lists[size];
  g_node_free_lists[size] = node;
  node->next = pcVar1;
  return size;
}

