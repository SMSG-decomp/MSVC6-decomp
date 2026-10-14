void __fastcall narrow_and_or_constant(c2_tuple *t,uint32_t size,uint32_t shift)

{
  c2_operand_u18 *pcVar1;
  c2_operand *pcVar2;
  c2_operand *pcVar3;
  c2_operand *op;
  uint uVar4;
  int iVar5;
  ushort type;
  uint64_t uVar6;
  
  uVar4 = t->type & 0xfff;
  if (uVar4 != size) {
    if ((int)size < (int)uVar4) {
      pcVar1 = &t->src->next->u18;
      pcVar1->reg = (c2_symbol *)((int)pcVar1->reg >> ((byte)(shift << 3) & 0x1f));
    }
    else if ((int)uVar4 < (int)size) {
      pcVar2 = t->src;
      iVar5 = ((pcVar2->u18).reg)->offset;
      iVar5 = (int)(iVar5 + (iVar5 >> 0x1f & 7U)) >> 3;
      if (t->op == 0x2e) {
        if ((pcVar2->type & 0xfff) == 1) {
          if (iVar5 == 0) {
            uVar4 = 0xffffff00;
          }
          else {
            uVar4 = shift;
            if (iVar5 == 1) {
              uVar4 = 0xffff00ff;
            }
          }
        }
        else {
          uVar4 = 0xffff0000;
        }
        if (size == 2) {
          uVar4 = uVar4 & 0xffff;
        }
      }
      else {
        uVar4 = 0;
      }
      pcVar1 = &pcVar2->next->u18;
      pcVar1->lo = pcVar1->lo | uVar4;
    }
    pcVar2 = t->src;
    type = (ushort)size | 0x1000;
    pcVar3 = pcVar2->next;
    pcVar3->type = type;
    uVar6 = const_normalize(type,(pcVar3->u18).lo,pcVar3->tag);
    op = t->dst;
    pcVar3->u18 = (c2_operand_u18)(int)uVar6;
    pcVar3->tag = (int)(uVar6 >> 0x20);
    if (op->type != 0x8000) {
      operand_retype(op,type,shift);
    }
    operand_retype(pcVar2,type,shift);
    t->type = type;
  }
  return;
}

