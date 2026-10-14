c2_node * __fastcall node_clone(c2_node *node)

{
  uint8_t kind;
  byte bVar1;
  c2_operand *pcVar2;
  uint16_t uVar3;
  c2_tuple *clone;
  c2_tuple *pcVar4;
  c2_tuple *pcVar5;
  c2_operand *pcVar6;
  c2_operand *pcVar7;
  c2_node *pcVar8;
  uint uVar9;
  uint uVar10;
  undefined4 in_stack_fffffffc;
  uint32_t uVar11;
  c2_operand *dst_opnd;
  int saw_linked_subop;
  c2_operand *src_opnd;
  
  kind = node->kind;
  uVar11 = CONCAT31((int3)((uint)in_stack_fffffffc >> 8),kind);
  clone = (c2_tuple *)node_alloc(kind);
  uVar10 = g_node_kind_sizes[uVar11 & 0xff];
  pcVar8 = node;
  pcVar4 = clone;
  for (uVar9 = uVar10 >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {
    pcVar4->next = (c2_tuple *)pcVar8->next;
    pcVar8 = (c2_node *)&pcVar8->op;
    pcVar4 = (c2_tuple *)&pcVar4->op;
  }
  for (uVar10 = uVar10 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {
    *(undefined1 *)&pcVar4->next = *(undefined1 *)&pcVar8->next;
    pcVar8 = (c2_node *)((int)&pcVar8->next + 1);
    pcVar4 = (c2_tuple *)((int)&pcVar4->next + 1);
  }
  clone->next = (c2_tuple *)0x0;
  switch(g_node_clone_case_by_kind[uVar11 & 0xff]) {
  case 0:
    bVar1 = *(byte *)((int)&clone->line + 1);
    *(byte *)&clone->line = (byte)clone->line & 0xcf;
    *(byte *)((int)&clone->line + 1) = bVar1 & 0xef;
    return (c2_node *)clone;
  case 2:
    if (*(c2_node **)&node[2].kind != (c2_node *)0x0) {
      pcVar8 = node_clone(*(c2_node **)&node[2].kind);
      bVar1 = *(byte *)&pcVar8[1].next;
      clone->switch_flags = (uint32_t)pcVar8;
      *(byte *)&pcVar8[1].next = bVar1 | 0x30;
    }
    if ((c2_node *)node[2].rank_or_prev != (c2_node *)0x0) {
      pcVar4 = (c2_tuple *)node_clone((c2_node *)node[2].rank_or_prev);
      uVar3 = pcVar4->line;
      clone[1].next = pcVar4;
      *(byte *)&pcVar4->line = (byte)uVar3 | 0x30;
    }
  case 1:
    *(byte *)&clone->line = (byte)clone->line & 0xef;
    return (c2_node *)clone;
  case 3:
    uVar11 = node->op;
    pcVar4 = clone;
    if (kind == '\x14') {
      if (uVar11 == 0x1a0) {
        cxx_eh_copy_object_record(node,(c2_node *)clone);
      }
      else if ((uVar11 == 0x1ab) && ((c2_tuple *)node[2].next != (c2_tuple *)0x0)) {
        pcVar5 = clone_tuple_list((c2_tuple *)node[2].next);
        (clone->u20).tuples = pcVar5;
      }
    }
    else if (uVar11 == 0x188) {
      seh_register_finally_call_clone((c2_tuple *)node,clone);
    }
    src_opnd = *(c2_operand **)&node[1].kind;
    saw_linked_subop = 0;
    if (src_opnd != (c2_operand *)0x0) {
      pcVar7 = (c2_operand *)node_clone((c2_node *)src_opnd);
      bVar1 = pcVar7->kind;
      pcVar4->src = pcVar7;
      if ((1 << (bVar1 & 0x1f) & 0xffeU) != 0) {
        pcVar7->flags = pcVar7->flags | 0x10;
      }
      clone = pcVar4;
      for (pcVar2 = src_opnd->next; pcVar4 = clone, pcVar2 != (c2_operand *)0x0;
          pcVar2 = pcVar2->next) {
        if (((1 << (pcVar2->kind & 0x1f) & 0xffeU) == 0) || ((pcVar2->flags & 0x20) == 0)) {
          pcVar6 = (c2_operand *)node_clone((c2_node *)pcVar2);
          pcVar7->next = pcVar6;
          pcVar7 = pcVar6;
          if ((1 << (pcVar6->kind & 0x1f) & 0xffeU) != 0) {
            pcVar6->flags = pcVar6->flags | 0x10;
          }
        }
        else {
          saw_linked_subop = 1;
        }
      }
    }
    dst_opnd = (c2_operand *)node[1].rank_or_prev;
    if (dst_opnd != (c2_operand *)0x0) {
      pcVar7 = (c2_operand *)node_clone((c2_node *)dst_opnd);
      pcVar4->dst = pcVar7;
      if ((1 << (pcVar7->kind & 0x1f) & 0xffeU) != 0) {
        pcVar7->flags = pcVar7->flags | 0x10;
      }
      clone = pcVar4;
      for (pcVar2 = dst_opnd->next; pcVar2 != (c2_operand *)0x0; pcVar2 = pcVar2->next) {
        pcVar6 = (c2_operand *)node_clone((c2_node *)pcVar2);
        pcVar7->next = pcVar6;
        if ((1 << (pcVar6->kind & 0x1f) & 0xffeU) != 0) {
          pcVar6->flags = pcVar6->flags | 0x10;
        }
        pcVar7 = pcVar6;
      }
    }
    if (saw_linked_subop != 0) {
      tuple_link_mem_subops(clone);
    }
  case 5:
    clone->prev = (c2_tuple *)0x0;
    return (c2_node *)clone;
  case 4:
    pcVar4 = clone;
    pcVar7 = operand_list_clone((c2_operand *)node[2].next);
    (clone->u20).cond_cells = (c2_cond_cell *)pcVar7;
    pcVar8 = node_clone_case_3((c2_tuple *)node,kind,clone,pcVar4,uVar11);
    return pcVar8;
  }
}

