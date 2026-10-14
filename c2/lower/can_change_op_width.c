int __fastcall can_change_op_width(c2_tuple *t,int width)

{
  uint8_t uVar1;
  c2_operand *pcVar2;
  c2_symbol *pcVar3;
  c2_symbol *pcVar4;
  c2_fe_symbol *pcVar5;
  c2_operand *pcVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  
  pcVar2 = t->dst;
  if (pcVar2 != (c2_operand *)0x0) {
    uVar7 = t->type & 0xfff;
    if (width < (int)uVar7) {
      uVar7 = width;
    }
    iVar9 = (4 - uVar7) * 8;
    if (((1 << (pcVar2->kind & 0x1f) & 6U) == 0) || (pcVar2->sym->def == (c2_tuple *)0x0)) {
      if ((1 << (pcVar2->kind & 0x1f) & 6U) == 0) {
        return 0;
      }
      pcVar3 = pcVar2->sym;
      if (pcVar3 == (c2_symbol *)0x0) {
        return 0;
      }
      pcVar4 = pcVar3->storage;
      if (pcVar4 == (c2_symbol *)0x0) {
        return 0;
      }
      if (4 < pcVar4->size) {
        return 0;
      }
      uVar1 = pcVar4->cls;
      if ((((uVar1 != '\x03') && (uVar1 != '\x04')) && (uVar1 != '\x05')) && (uVar1 != '\x06')) {
        return 0;
      }
      pcVar5 = pcVar4->fe;
      if (pcVar5 != (c2_fe_symbol *)0x0) {
        if (((byte)pcVar5->storage & 0xf) == 6) {
          return 0;
        }
        if (pcVar3->size < (int)pcVar5->size) {
          return 0;
        }
      }
    }
    else {
      iVar8 = operand_readable_as_dword(pcVar2);
      if (iVar8 == 0) {
        return 0;
      }
      if ((int)(uint)(pcVar2->sym->u30).globopt.killed < iVar9) {
        return 0;
      }
    }
    switch(t->op) {
    case 0x15b:
    case 0x160:
    case 0x161:
    case 0x171:
      iVar9 = operand_readable_at_width(t->src,width);
      return (uint)(iVar9 != 0);
    case 0x16d:
    case 0x16e:
    case 0x16f:
    case 0x172:
    case 0x173:
    case 0x174:
      pcVar2 = t->src;
      iVar9 = operand_readable_at_width(pcVar2,width);
      if ((iVar9 != 0) && (iVar9 = operand_readable_at_width(pcVar2->next,width), iVar9 != 0)) {
        return 1;
      }
      break;
    case 0x177:
      pcVar6 = t->src;
      iVar8 = operand_readable_at_width(pcVar6,width);
      if ((iVar8 != 0) && (pcVar6 = pcVar6->next, pcVar6->kind == '\a')) {
        return (uint)((int)(pcVar6->u18).reg + iVar9 <= (int)(uint)(pcVar2->sym->u30).globopt.killed
                     );
      }
    }
  }
  return 0;
}

