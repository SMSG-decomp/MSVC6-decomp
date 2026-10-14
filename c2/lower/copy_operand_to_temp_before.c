c2_operand * __fastcall copy_operand_to_temp_before(c2_operand *op,c2_tuple *t)

{
  uint8_t kind;
  byte bVar1;
  uint16_t type;
  c2_node *pcVar2;
  c2_operand *pcVar3;
  c2_tuple *pcVar4;
  c2_operand *clone;
  c2_operand *pcVar5;
  c2_operand *pcVar6;
  c2_operand *pcVar7;
  uint uVar8;
  uint uVar9;
  undefined4 unaff_EBX;
  uint32_t uVar10;
  int iVar11;
  
  type = op->type;
  pcVar3 = operand_new_temp_sym(type);
  pcVar4 = tuple_new(1,type,pcVar3,op,tuple_insert_before,t);
  if (4 < (op->type & 0xfff)) {
    lower_int64_tuple(pcVar4);
  }
  tuple_replace_src(t,op,pcVar3);
  kind = pcVar3->kind;
  uVar10 = CONCAT31((int3)((uint)unaff_EBX >> 8),kind);
  clone = (c2_operand *)node_alloc(kind);
  uVar9 = g_node_kind_sizes[uVar10 & 0xff];
  pcVar6 = pcVar3;
  pcVar7 = clone;
  for (uVar8 = uVar9 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
    pcVar7->next = pcVar6->next;
    pcVar6 = (c2_operand *)&pcVar6->op;
    pcVar7 = (c2_operand *)&pcVar7->op;
  }
  for (uVar9 = uVar9 & 3; uVar9 != 0; uVar9 = uVar9 - 1) {
    *(undefined1 *)&pcVar7->next = *(undefined1 *)&pcVar6->next;
    pcVar6 = (c2_operand *)((int)&pcVar6->next + 1);
    pcVar7 = (c2_operand *)((int)&pcVar7->next + 1);
  }
  clone->next = (c2_operand *)0x0;
  switch(g_node_clone_case_by_kind[uVar10 & 0xff]) {
  case 0:
    clone->flags = (byte)*(uint16_t *)&clone->flags & 0xcf;
    clone->flags11 = clone->flags11 & 0xef;
    return clone;
  case 2:
    if (pcVar3->base != (c2_operand *)0x0) {
      pcVar6 = (c2_operand *)node_clone((c2_node *)pcVar3->base);
      bVar1 = pcVar6->flags;
      clone->base = pcVar6;
      pcVar6->flags = bVar1 | 0x30;
    }
    if (pcVar3->index != (c2_operand *)0x0) {
      pcVar3 = (c2_operand *)node_clone((c2_node *)pcVar3->index);
      bVar1 = pcVar3->flags;
      clone->index = pcVar3;
      pcVar3->flags = bVar1 | 0x30;
    }
  case 1:
    clone->flags = (byte)*(uint16_t *)&clone->flags & 0xef;
    return clone;
  case 3:
    uVar10 = pcVar3->op;
    pcVar6 = clone;
    if (kind == '\x14') {
      if (uVar10 == 0x1a0) {
        cxx_eh_copy_object_record((c2_node *)pcVar3,(c2_node *)clone);
      }
      else if ((uVar10 == 0x1ab) && (pcVar3->base_sym != (c2_symbol *)0x0)) {
        pcVar4 = clone_tuple_list((c2_tuple *)pcVar3->base_sym);
        ((c2_tuple_u20 *)&clone->base_sym)->default_label = pcVar4;
      }
    }
    else if (uVar10 == 0x188) {
      seh_register_finally_call_clone((c2_tuple *)pcVar3,(c2_tuple *)clone);
    }
    pcVar7 = (pcVar3->u18).children;
    iVar11 = 0;
    if (pcVar7 != (c2_operand *)0x0) {
      pcVar5 = (c2_operand *)node_clone((c2_node *)pcVar7);
      bVar1 = pcVar5->kind;
      (pcVar6->u18).children = pcVar5;
      if ((1 << (bVar1 & 0x1f) & 0xffeU) != 0) {
        pcVar5->flags = pcVar5->flags | 0x10;
      }
      clone = pcVar6;
      for (pcVar7 = pcVar7->next; pcVar6 = clone, pcVar7 != (c2_operand *)0x0; pcVar7 = pcVar7->next
          ) {
        if (((1 << (pcVar7->kind & 0x1f) & 0xffeU) == 0) || ((pcVar7->flags & 0x20) == 0)) {
          pcVar6 = (c2_operand *)node_clone((c2_node *)pcVar7);
          pcVar5->next = pcVar6;
          pcVar5 = pcVar6;
          if ((1 << (pcVar6->kind & 0x1f) & 0xffeU) != 0) {
            pcVar6->flags = pcVar6->flags | 0x10;
          }
        }
        else {
          iVar11 = 1;
        }
      }
    }
    pcVar2 = (c2_node *)pcVar3->tag;
    if (pcVar2 != (c2_node *)0x0) {
      pcVar3 = (c2_operand *)node_clone(pcVar2);
      pcVar6->tag = (uint32_t)pcVar3;
      if ((1 << (pcVar3->kind & 0x1f) & 0xffeU) != 0) {
        pcVar3->flags = pcVar3->flags | 0x10;
      }
      clone = pcVar6;
      for (pcVar2 = pcVar2->next; pcVar2 != (c2_node *)0x0; pcVar2 = pcVar2->next) {
        pcVar6 = (c2_operand *)node_clone(pcVar2);
        pcVar3->next = pcVar6;
        if ((1 << (pcVar6->kind & 0x1f) & 0xffeU) != 0) {
          pcVar6->flags = pcVar6->flags | 0x10;
        }
        pcVar3 = pcVar6;
      }
    }
    if (iVar11 != 0) {
      tuple_link_mem_subops((c2_tuple *)clone);
    }
  case 5:
    clone->rank = 0;
    return clone;
  case 4:
    pcVar6 = clone;
    pcVar7 = operand_list_clone((c2_operand *)pcVar3->base_sym);
    ((c2_tuple_u20 *)&clone->base_sym)->cond_cells = (c2_cond_cell *)pcVar7;
    pcVar3 = (c2_operand *)
             node_clone_case_3((c2_tuple *)pcVar3,kind,(c2_tuple *)clone,(c2_tuple *)pcVar6,uVar10);
    return pcVar3;
  }
}

