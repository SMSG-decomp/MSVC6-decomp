uint32_t __fastcall classify_byte_lane_source(c2_operand *op,uint32_t strip_flags,uint32_t lane_in)

{
  ushort uVar1;
  c2_operand *pcVar2;
  uint32_t *puVar3;
  int iVar4;
  uint32_t uVar5;
  c2_tuple *local_c;
  int local_8;
  c2_tuple *local_4;
  
  uVar5 = lane_in & 0xffff0000;
  if ((1 << (op->kind & 0x1f) & 6U) == 0) {
    return uVar5;
  }
  if (op->sym->def == (c2_tuple *)0x0) {
    return uVar5;
  }
  pcVar2 = strip_widening_converts(op,strip_flags);
  if ((lane_in == 0) && (puVar3 = get_byte_masked_source(pcVar2), puVar3 != (uint32_t *)0x0)) {
    iVar4 = classify_masked_shift_source(pcVar2,&local_8,&local_c);
    if (iVar4 != 0) {
      return 0xff00;
    }
    if ((pcVar2->type & 0xfff) != 1) {
      return 0xff00;
    }
    return 0xff01;
  }
  if ((1 << (pcVar2->kind & 0x1f) & 6U) == 0) {
    return uVar5;
  }
  local_c = pcVar2->sym->def;
  if (local_c == (c2_tuple *)0x0) {
    return uVar5;
  }
  switch(local_c->op) {
  case 0x146:
    if ((char)local_c->src == '\0') {
      return uVar5 | 0x100;
    }
    if ((char)((uint)local_c->src >> 8) != '\0') {
      return uVar5;
    }
    break;
  default:
    goto switchD_107228dc_caseD_147;
  case 0x171:
    iVar4 = operand_is_const_value(local_c->src->next,8);
    if (iVar4 == 0) {
      return uVar5;
    }
    uVar1 = local_c->type & 0xfff;
    if (uVar1 == 2) {
      return uVar5 | 0x100;
    }
    if (uVar1 != 4) {
      return uVar5;
    }
    pcVar2 = local_c->src;
    if ((1 << (pcVar2->kind & 0x1f) & 6U) == 0) {
      return uVar5;
    }
    if (pcVar2->sym->def == (c2_tuple *)0x0) {
      return uVar5;
    }
    pcVar2 = strip_widening_converts(pcVar2,0);
    puVar3 = get_byte_masked_source(pcVar2);
    if (puVar3 == (uint32_t *)0x0) {
      return uVar5;
    }
    return uVar5 | 0x100;
  case 0x172:
    pcVar2 = local_c->src->next;
    if (pcVar2->kind != '\a') {
      return uVar5;
    }
    iVar4 = const_compare(pcVar2,0xff,0);
    if (iVar4 != 0) {
      iVar4 = const_compare(local_c->src->next,0xff00,0);
      if (iVar4 != 0) {
        return uVar5;
      }
      return uVar5 | 0x100;
    }
    break;
  case 0x177:
    uVar5 = classify_byte_lane_shift(local_c,&local_8,&local_4);
    return uVar5;
  }
  uVar5 = uVar5 | 0xff00;
switchD_107228dc_caseD_147:
  return uVar5;
}

