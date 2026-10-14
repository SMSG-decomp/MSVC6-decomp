void __fastcall set_op_width(c2_tuple *t,uint32_t width)

{
  uint16_t uVar1;
  c2_tuple *pcVar2;
  c2_operand *pcVar3;
  ushort uVar4;
  ushort uVar5;
  int iVar6;
  c2_operand *pcVar7;
  ushort type;
  
  pcVar7 = t->dst;
  uVar4 = t->type & 0xf000;
  uVar5 = (ushort)width;
  type = uVar4 | uVar5;
  uVar1 = pcVar7->type;
  t->type = type;
  if ((uVar1 != 0x8000) &&
     (pcVar2 = pcVar7->sym->def, operand_retype(pcVar7,uVar4 | uVar5 & 0xf000 | uVar5,0),
     pcVar2 != (c2_tuple *)0x0)) {
    t->dst->sym->def = t;
  }
  if ((t->kind != '\x0e') && (pcVar7 = t->src, t->src != (c2_operand *)0x0)) {
    while ((pcVar3 = pcVar7->next, (pcVar7->flags & 0x20) == 0 && ((pcVar7->type & 0xfff) != width))
          ) {
      operand_retype(pcVar7,type,0);
      if (t->op == 0x177) {
        return;
      }
      if (t->op == 0x171) {
        return;
      }
      iVar6 = op_is_0x29_to_0x2b(t);
      if (iVar6 != 0) {
        return;
      }
      pcVar7 = pcVar3;
      if (pcVar3 == (c2_operand *)0x0) {
        return;
      }
    }
  }
  return;
}

