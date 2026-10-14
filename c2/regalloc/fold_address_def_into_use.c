void __fastcall fold_address_def_into_use(c2_tuple *t,c2_operand *op,c2_tuple *def)

{
  uint8_t *puVar1;
  byte bVar2;
  uint8_t uVar3;
  c2_operand *node;
  c2_symbol *pcVar4;
  uint32_t uVar5;
  c2_tuple *pcVar6;
  uint32_t uVar7;
  c2_live_range *pcVar8;
  c2_operand *pcVar9;
  c2_operand *pcVar10;
  c2_operand *local_4;
  
  local_4 = (c2_operand *)t;
  pcVar9 = find_mem_operand_using(t,op,&local_4);
  op->flags = op->flags & 0xdf;
  tuple_remove_src(t,op);
  pcVar10 = def->src->base;
  if (pcVar10 == (c2_operand *)0x0) {
    if (pcVar9->base == op) {
      pcVar9->base = (c2_operand *)0x0;
    }
  }
  else if (pcVar9->base == op) {
    pcVar10 = (c2_operand *)node_clone((c2_node *)pcVar10);
    bVar2 = pcVar10->flags;
    pcVar9->base = pcVar10;
    pcVar10->flags = bVar2 & 0xef | 0x20;
    tuple_append_src(t,pcVar10);
  }
  else {
    if ((pcVar9->flags & 0xf) != 0) {
      pcVar9->disp = pcVar9->disp + ((1 << (pcVar9->flags & 0xf)) + -1) * def->src->disp;
    }
    pcVar10 = (c2_operand *)node_clone((c2_node *)pcVar10);
    bVar2 = pcVar10->flags;
    pcVar9->index = pcVar10;
    pcVar10->flags = bVar2 & 0xef | 0x20;
    tuple_append_src(t,pcVar10);
  }
  pcVar10 = def->src;
  node = pcVar10->index;
  if (node != (c2_operand *)0x0) {
    pcVar10 = pcVar9->index;
    if ((pcVar10 != (c2_operand *)0x0) && (pcVar10 != op)) {
      pcVar9->base = pcVar10;
    }
    pcVar10 = (c2_operand *)node_clone((c2_node *)node);
    bVar2 = pcVar10->flags;
    pcVar9->index = pcVar10;
    pcVar10->flags = bVar2 & 0xef | 0x20;
    tuple_append_src(t,pcVar10);
    pcVar10 = def->src;
    pcVar9->flags = (pcVar10->flags ^ pcVar9->flags) & 0xf ^ pcVar9->flags;
  }
  pcVar4 = pcVar10->base_sym;
  pcVar9->disp = pcVar9->disp + pcVar10->disp;
  if (pcVar4 != (c2_symbol *)0x0) {
    pcVar9->base_sym = pcVar4;
  }
  uVar5 = pcVar9->op;
  if (pcVar9->base == (c2_operand *)0x0) {
    if ((pcVar9->base_sym == (c2_symbol *)0x0) ||
       ((((uVar3 = pcVar9->base_sym->cls, uVar3 != '\x03' && (uVar3 != '\x04')) && (uVar3 != '\x05')
         ) && (uVar3 != '\x06')))) {
      pcVar9->op = 0x14f;
    }
    else {
      pcVar9->op = 0x14e;
    }
    pcVar8 = (pcVar9->index->u18).range;
    pcVar6 = (pcVar8->u38).def;
    if ((pcVar6 == (c2_tuple *)0x0) || (pcVar6->op != 0x12)) goto LAB_107230c7;
    uVar7 = pcVar6->src->op;
  }
  else {
    pcVar10 = pcVar9->index;
    if (pcVar10 == (c2_operand *)0x0) {
      pcVar9->op = 0x14c;
      goto LAB_107230c7;
    }
    pcVar8 = (pcVar9->base->u18).range;
    pcVar9->op = 0x14d;
    pcVar6 = (pcVar8->u38).def;
    if (((pcVar6 != (c2_tuple *)0x0) && (pcVar6->op == 0x12)) && (pcVar6->src->op != 0x14c)) {
      puVar1 = &pcVar8->flags5;
      *puVar1 = *puVar1 | 4;
    }
    pcVar8 = (pcVar10->u18).range;
    pcVar6 = (pcVar8->u38).def;
    if ((pcVar6 == (c2_tuple *)0x0) || (pcVar6->op != 0x12)) goto LAB_107230c7;
    uVar7 = pcVar6->src->op;
  }
  if (uVar7 != 0x14c) {
    pcVar8->flags5 = pcVar8->flags5 | 4;
  }
LAB_107230c7:
  if (((t->op == 0x12) && (pcVar8 = (t->dst->u18).range, pcVar8->kind == '\x02')) &&
     (pcVar9->op != uVar5)) {
    puVar1 = &pcVar8->flags5;
    *puVar1 = *puVar1 | 4;
  }
  return;
}

