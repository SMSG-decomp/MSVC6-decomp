uint32_t __fastcall classify_byte_lane_shift(c2_tuple *t,int *lane,c2_tuple **src)

{
  ushort uVar1;
  c2_operand *pcVar2;
  uint uVar3;
  c2_tuple *pcVar4;
  c2_operand *pcVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint32_t uVar9;
  uint uVar10;
  uint local_c;
  
  pcVar2 = t->src;
  uVar9 = local_c & 0xffff0000;
  if ((pcVar2->next->kind == '\a') && (uVar3 = (pcVar2->next->u18).lo, (uVar3 & 7) == 0)) {
    if ((uVar3 == 8) && (((t->type & 0xfff) == 2 && ((t->type & 0xf000) == 0x2000)))) {
      *lane = 1;
      uVar9 = uVar9 | 0xff00;
      *src = t;
    }
    else {
      uVar1 = t->type;
      if (((uVar1 & 0xfff) == 4) &&
         ((((1 << (pcVar2->kind & 0x1f) & 6U) != 0 &&
           (pcVar4 = pcVar2->sym->def, pcVar4 != (c2_tuple *)0x0)) && (pcVar4->op == 0x172)))) {
        pcVar2 = pcVar4->src;
        pcVar5 = pcVar2->next;
        if (pcVar5->kind == '\a') {
          uVar6 = (pcVar5->u18).lo;
          uVar8 = 0;
          uVar10 = uVar6 >> ((byte)uVar3 & 0x1f);
          if (uVar10 == 0xff) {
            uVar8 = 0xffffffff;
          }
          else if (uVar10 == 0xff00) {
            uVar8 = 1;
          }
          *src = pcVar4;
          iVar7 = ((int)(uVar8 + 1) >> 1) + (uVar3 >> 3);
          *lane = iVar7;
          if (((1 < iVar7) && (pcVar2->kind == '\x01')) ||
             (((uVar1 & 0xf000) != 0x2000 && ((uVar6 & 0x80000000) != 0)))) {
            uVar8 = 0;
          }
          return local_c & 0xffff0000 | (uVar8 & 0xff) << 8;
        }
      }
    }
  }
  return uVar9;
}

