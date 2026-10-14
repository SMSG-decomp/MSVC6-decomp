int __fastcall sched_adjust_memory_operand(c2_sched_edge *edge)

{
  uint8_t *puVar1;
  uint8_t uVar2;
  c2_tuple *t;
  c2_symbol *pcVar3;
  c2_operand *pcVar4;
  c2_operand_u18 cVar5;
  byte bVar6;
  c2_operand *pcVar7;
  int32_t iVar8;
  int iVar9;
  c2_operand *pcVar10;
  byte bVar11;
  c2_tuple *pcVar12;
  uint32_t uVar13;
  c2_tuple *producer;
  c2_operand *pcVar14;
  c2_sched_node *from;
  
  from = edge->from;
  t = edge->to->tuple;
  producer = from->tuple;
  pcVar12 = t;
  if (0xf < (edge->soft & 0x1f)) {
    pcVar12 = producer;
  }
  for (pcVar14 = pcVar12->src; pcVar14 != (c2_operand *)0x0; pcVar14 = pcVar14->next) {
    if (pcVar14->kind == '\x06') {
      if (pcVar14 != (c2_operand *)0x0) goto LAB_1074db22;
      break;
    }
  }
  for (pcVar14 = pcVar12->dst; (pcVar14 != (c2_operand *)0x0 && (pcVar14->kind != '\x06'));
      pcVar14 = pcVar14->next) {
  }
LAB_1074db22:
  switch(edge->soft & 0x1f) {
  case 1:
    uVar13 = (producer->src->next->u18).lo;
    pcVar10 = pcVar14->base;
    if (pcVar10 != (c2_operand *)0x0) {
      pcVar7 = producer->dst;
LAB_1074db68:
      if ((pcVar7->u18).reg == (pcVar10->u18).reg) {
        pcVar14->disp = pcVar14->disp + uVar13;
        break;
      }
    }
    goto LAB_1077a7d9;
  case 2:
    pcVar10 = (c2_operand *)node_clone((c2_node *)producer->src->next);
    pcVar12 = t;
    goto LAB_1077a62b;
  case 3:
    uVar13 = (producer->src->next->u18).lo;
    pcVar10 = pcVar14->base;
    if (pcVar10 != (c2_operand *)0x0) {
      pcVar7 = producer->dst;
LAB_1074dcdc:
      if ((pcVar7->u18).reg == (pcVar10->u18).reg) {
        pcVar14->disp = pcVar14->disp - uVar13;
        break;
      }
    }
    goto LAB_1077a7c6;
  case 4:
    uVar13 = (producer->src->next->u18).lo;
    if (pcVar14->index == (c2_operand *)0x0) {
      pcVar14->index = pcVar14->base;
      if (uVar13 == 1) {
        bVar6 = 0;
      }
      else if (uVar13 == 2) {
        bVar6 = 1;
      }
      else {
        bVar6 = (uVar13 != 4) + 2;
      }
      pcVar14->base = (c2_operand *)0x0;
      pcVar14->flags = (pcVar14->flags ^ bVar6) & 0xf ^ pcVar14->flags;
      iVar9 = sched_adjust_memory_operand_case_5(producer,pcVar14,t,producer,from,edge);
      return iVar9;
    }
    bVar6 = pcVar14->flags;
    iVar9 = (1 << (bVar6 & 0xf)) * uVar13;
    if (iVar9 == 1) {
      bVar11 = 0;
    }
    else if (iVar9 == 2) {
      bVar11 = 1;
    }
    else {
      bVar11 = (iVar9 != 4) + 2;
    }
    pcVar14->flags = (bVar6 ^ bVar11) & 0xf ^ bVar6;
    iVar9 = sched_adjust_memory_operand_case_5(producer,pcVar14,t,producer,from,edge);
    return iVar9;
  case 5:
  case 6:
    for (pcVar10 = producer->src; (pcVar10 != (c2_operand *)0x0 && (pcVar10->kind != '\x05'));
        pcVar10 = pcVar10->next) {
    }
    pcVar7 = pcVar14->base;
    if (pcVar7 != (c2_operand *)0x0) {
      pcVar7->flags = pcVar7->flags & 0xdf;
      tuple_detach_src((c2_node *)t,pcVar7);
      node_free((c2_node *)pcVar14->base);
      pcVar14->base = (c2_operand *)0x0;
    }
    pcVar7 = pcVar14->index;
    if (pcVar7 != (c2_operand *)0x0) {
      pcVar7->flags = pcVar7->flags & 0xdf;
      tuple_detach_src((c2_node *)t,pcVar7);
      node_free((c2_node *)pcVar14->index);
      pcVar14->index = (c2_operand *)0x0;
    }
    if (pcVar10->base != (c2_operand *)0x0) {
      pcVar7 = (c2_operand *)node_clone((c2_node *)pcVar10->base);
      pcVar14->base = pcVar7;
      tuple_append_src(t,pcVar7);
      puVar1 = &pcVar14->base->flags;
      *puVar1 = *puVar1 | 0x10;
    }
    if (pcVar10->index != (c2_operand *)0x0) {
      pcVar7 = (c2_operand *)node_clone((c2_node *)pcVar10->index);
      pcVar14->index = pcVar7;
      tuple_append_src(t,pcVar7);
      puVar1 = &pcVar14->index->flags;
      *puVar1 = *puVar1 | 0x10;
    }
    bVar6 = pcVar10->flags;
    pcVar3 = pcVar10->base_sym;
    pcVar14->op = pcVar10->op;
    iVar9 = pcVar10->disp;
    pcVar14->base_sym = pcVar3;
    pcVar14->flags = (bVar6 ^ pcVar14->flags) & 0xf ^ pcVar14->flags;
    pcVar14->disp = pcVar14->disp + iVar9;
    break;
  case 7:
  case 8:
    for (pcVar10 = producer->src; (pcVar10 != (c2_operand *)0x0 && (pcVar10->kind != '\x05'));
        pcVar10 = pcVar10->next) {
    }
    pcVar7 = pcVar10->base;
    if (pcVar7 == (c2_operand *)0x0) {
      pcVar7 = pcVar10->index;
    }
    pcVar4 = pcVar14->base;
    cVar5 = pcVar7->u18;
    pcVar4->sym = pcVar7->sym;
    pcVar4->u18 = cVar5;
    iVar8 = pcVar10->disp;
    pcVar14->base_sym = pcVar10->base_sym;
    goto LAB_1074dd34;
  case 9:
  case 10:
    for (pcVar10 = producer->src; (pcVar10 != (c2_operand *)0x0 && (pcVar10->kind != '\x05'));
        pcVar10 = pcVar10->next) {
    }
    bVar6 = pcVar14->flags;
    pcVar14->base_sym = pcVar10->base_sym;
    pcVar14->disp = pcVar14->disp + (1 << (bVar6 & 0xf)) * pcVar10->disp;
    pcVar7 = pcVar10->base;
    if (pcVar7 == (c2_operand *)0x0) {
      uVar2 = pcVar10->flags;
      pcVar7 = pcVar14->index;
      cVar5 = pcVar10->index->u18;
      pcVar7->sym = pcVar10->index->sym;
      pcVar7->u18 = cVar5;
      pcVar14->flags = (uVar2 + bVar6 ^ bVar6) & 0xf ^ bVar6;
    }
    else {
      pcVar14 = pcVar14->index;
      cVar5 = pcVar7->u18;
      pcVar14->sym = pcVar7->sym;
      pcVar14->u18 = cVar5;
    }
    break;
  case 0xb:
    if ((pcVar14->base != (c2_operand *)0x0) &&
       ((producer->dst->u18).reg == (pcVar14->base->u18).reg)) {
      pcVar14->disp = pcVar14->disp + 1;
      break;
    }
    goto LAB_1074dd58;
  case 0xc:
    pcVar10 = pcVar14->base;
    if (pcVar10 != (c2_operand *)0x0) {
      pcVar7 = producer->dst;
LAB_1074dd17:
      if ((pcVar7->u18).reg == (pcVar10->u18).reg) {
        pcVar14->disp = pcVar14->disp + -1;
        break;
      }
    }
    goto LAB_1074dd29;
  default:
    ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\x86\\schedmd.c",0x72c);
  case 0x10:
    pcVar10 = pcVar14->base;
    uVar13 = (t->src->next->u18).lo;
    if (pcVar10 != (c2_operand *)0x0) {
      pcVar7 = t->dst;
      goto LAB_1074dcdc;
    }
LAB_1077a7c6:
    iVar8 = (-1 << (pcVar14->flags & 0xf)) * uVar13;
    goto LAB_1074dd34;
  case 0x11:
    pcVar10 = pcVar14->base;
    uVar13 = (t->src->next->u18).lo;
    if (pcVar10 != (c2_operand *)0x0) {
      pcVar7 = t->dst;
      goto LAB_1074db68;
    }
LAB_1077a7d9:
    iVar8 = (1 << (pcVar14->flags & 0xf)) * uVar13;
LAB_1074dd34:
    pcVar14->disp = pcVar14->disp + iVar8;
    break;
  case 0x12:
    pcVar10 = (c2_operand *)node_clone((c2_node *)t->src->next);
    pcVar12 = producer;
LAB_1077a62b:
    tuple_append_src(pcVar12,pcVar10);
    if (pcVar14->index == (c2_operand *)0x0) {
      pcVar14->index = pcVar10;
      pcVar14->op = 0x14d;
      pcVar14->flags = pcVar14->flags & 0xf0;
    }
    else {
      pcVar14->base = pcVar10;
      pcVar14->op = 0x14d;
    }
    break;
  case 0x13:
    for (pcVar10 = t->src; (pcVar10 != (c2_operand *)0x0 && (pcVar10->kind != '\x05'));
        pcVar10 = pcVar10->next) {
    }
    pcVar14->disp = pcVar14->disp - pcVar10->disp;
    break;
  case 0x14:
    for (pcVar10 = t->src; (pcVar10 != (c2_operand *)0x0 && (pcVar10->kind != '\x05'));
        pcVar10 = pcVar10->next) {
    }
    pcVar14->disp = pcVar14->disp + (-1 << (pcVar14->flags & 0xf)) * pcVar10->disp;
    break;
  case 0x15:
    pcVar10 = pcVar14->base;
    if (pcVar10 != (c2_operand *)0x0) {
      pcVar7 = t->dst;
      goto LAB_1074dd17;
    }
LAB_1074dd29:
    bVar6 = pcVar14->flags;
    iVar9 = -1;
    goto LAB_1074dd32;
  case 0x16:
    if ((pcVar14->base != (c2_operand *)0x0) && ((t->dst->u18).reg == (pcVar14->base->u18).reg)) {
      pcVar14->disp = pcVar14->disp + 1;
      break;
    }
LAB_1074dd58:
    bVar6 = pcVar14->flags;
    iVar9 = 1;
LAB_1074dd32:
    iVar8 = iVar9 << (bVar6 & 0xf);
    goto LAB_1074dd34;
  }
  sched_remove_edge(edge);
  if ((edge->soft & 0x20) == 0) {
    if (from->nsucc == 0) {
      sched_link_to_next_barrier(from);
    }
  }
  else {
    sched_retire_node(from);
  }
  bVar6 = producer->flags;
  t->flags = t->flags & 0xfb;
  producer->flags = bVar6 & 0xfb;
  return 1;
}

