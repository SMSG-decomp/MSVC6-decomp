c2_operand * __fastcall
operand_new_mem(uint32_t op,uint16_t type,c2_symbol *base_sym,int32_t disp,c2_operand *base,
               c2_operand *index,uint32_t alias_tag)

{
  byte bVar1;
  c2_operand *pcVar2;
  
  pcVar2 = (c2_operand *)node_alloc('\x06');
  pcVar2->base_sym = base_sym;
  pcVar2->op = op;
  pcVar2->type = type;
  pcVar2->disp = disp;
  pcVar2->tag = alias_tag;
  if (base != (c2_operand *)0x0) {
    if ((1 << (base->kind & 0x1f) & 0xffeU) != 0) {
      if ((base->flags & 0x10) != 0) {
        base = (c2_operand *)node_clone((c2_node *)base);
      }
      base->flags = base->flags | 0x10;
    }
    bVar1 = base->flags;
    pcVar2->base = base;
    base->flags = bVar1 | 0x20;
  }
  if (index != (c2_operand *)0x0) {
    if ((1 << (index->kind & 0x1f) & 0xffeU) != 0) {
      if ((index->flags & 0x10) != 0) {
        index = (c2_operand *)node_clone((c2_node *)index);
      }
      index->flags = index->flags | 0x10;
    }
    bVar1 = index->flags;
    pcVar2->index = index;
    index->flags = bVar1 | 0x20;
  }
  return pcVar2;
}

