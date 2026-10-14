int __fastcall classify_masked_shift_source(c2_operand *opnd,int *lane,c2_tuple **src)

{
  c2_tuple *pcVar1;
  c2_operand *pcVar2;
  uint uVar3;
  c2_operand *pcVar4;
  int iVar5;
  int iVar6;
  uint32_t uVar7;
  
  if ((1 << (opnd->kind & 0x1f) & 6U) == 0) {
    return 0;
  }
  if (opnd->sym->def == (c2_tuple *)0x0) {
    return 0;
  }
  pcVar4 = (c2_operand *)get_byte_masked_source(opnd);
  if (pcVar4 == (c2_operand *)0x0) {
    pcVar1 = opnd->sym->def;
    if (pcVar1->op != 0x172) {
      return 0;
    }
    if ((pcVar1->type & 0xfff) != 4) {
      return 0;
    }
    pcVar4 = pcVar1->src;
    if (pcVar4->next->kind != '\a') {
      return 0;
    }
    uVar7 = (pcVar4->next->u18).lo;
    if (uVar7 != 0xff) {
      if (uVar7 != 0xff00) {
        return 0;
      }
      iVar5 = 1;
      goto LAB_107234d3;
    }
  }
  else {
    if (((((1 << (opnd->kind & 0x1f) & 6U) != 0) &&
         (pcVar1 = opnd->sym->def, pcVar1 != (c2_tuple *)0x0)) && (pcVar1->op == 0x177)) &&
       (uVar7 = classify_byte_lane_shift(pcVar4->sym->def,lane,src), (uVar7 & 0xff00) == 0xff00)) {
      return -1;
    }
    uVar7 = 0xff;
  }
  iVar5 = -1;
LAB_107234d3:
  if ((((1 << (pcVar4->kind & 0x1f) & 6U) != 0) &&
      (pcVar1 = pcVar4->sym->def, pcVar1 != (c2_tuple *)0x0)) && (pcVar1->op == 0x177)) {
    pcVar4 = pcVar1->src;
    pcVar2 = pcVar4->next;
    if (pcVar2->kind == '\a') {
      uVar3 = (pcVar2->u18).lo;
      if (((uVar3 & 7) == 0) && (uVar7 << ((byte)uVar3 & 0x1f) != 0)) {
        *src = pcVar1;
        iVar6 = (uVar3 >> 3) + (iVar5 + 1 >> 1);
        *lane = iVar6;
        if (iVar6 < 2) {
          return iVar5;
        }
        if (pcVar4->kind != '\x01') {
          return iVar5;
        }
      }
    }
  }
  return 0;
}

