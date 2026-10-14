void __fastcall switch_narrow_to_byte_compares(c2_switch_case_range *cases,c2_tuple *sw,int ncases)

{
  uint16_t type;
  c2_symbol *pcVar1;
  c2_tuple *pcVar2;
  c2_tuple *pcVar3;
  bool bVar4;
  uint32_t uVar5;
  int32_t iVar6;
  bool bVar7;
  
  bVar4 = false;
  if ((((((sw->op == 0x15b) && ((1 << (sw->dst->kind & 0x1f) & 6U) != 0)) &&
        (sw->dst->sym->cls == '\x03')) &&
       ((sw->src->kind == '\x01' && (pcVar1 = sw->src->sym, pcVar1->cls == '\x03')))) &&
      ((pcVar2 = pcVar1->def, pcVar2 != (c2_tuple *)0x0 &&
       ((pcVar3 = sw->prev, pcVar3 == pcVar2 && (pcVar3->op == 0x15f)))))) &&
     (type = pcVar3->src->type, (type & 0xfff) == 1)) {
    if (ncases != 0) {
      do {
        ncases = ncases + -1;
        if (bVar4) {
          return;
        }
        uVar5 = cases->first;
        iVar6 = cases->first_high;
        do {
          if ((cases->last_high < iVar6) || ((cases->last_high <= iVar6 && (cases->last < uVar5))))
          break;
          if ((type & 0xf000) == 0x1000) {
            if ((uVar5 != (int)(char)uVar5) || (iVar6 != (int)(char)uVar5 >> 0x1f))
            goto LAB_1077610f;
          }
          else if ((uVar5 != (uVar5 & 0xff)) || (iVar6 != 0)) {
LAB_1077610f:
            bVar4 = true;
          }
          bVar7 = 0xfffffffe < uVar5;
          uVar5 = uVar5 + 1;
          iVar6 = iVar6 + (uint)bVar7;
        } while (!bVar4);
        cases = cases->next;
      } while (ncases != 0);
      if (bVar4) {
        return;
      }
    }
    pcVar2 = sw->prev;
    pcVar2->op = 0x15b;
    pcVar2->type = type;
    operand_retype(pcVar2->dst,type,0);
    operand_retype(sw->dst,type,0);
    operand_retype(sw->src,type,0);
    sw->type = type;
  }
  return;
}

