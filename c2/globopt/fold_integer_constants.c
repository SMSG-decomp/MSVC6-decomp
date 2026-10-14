c2_operand * __fastcall
fold_integer_constants(c2_tuple *user,uint16_t type,c2_operand *k,c2_operand *opnd)

{
  uint32_t uVar1;
  c2_symbol *pcVar2;
  c2_operand *pcVar3;
  uint8_t count;
  uint64_t uVar4;
  c2_symbol *local_8;
  uint local_4;
  
  if ((((1 << (byte)(type >> 0xc) & 0xeU) == 0) && (user->op != 0x15f)) || (k->kind != '\a')) {
switchD_10705b3c_caseD_0:
    return (c2_operand *)0x0;
  }
  if (opnd != (c2_operand *)0x0) {
    if (opnd->kind != '\a') {
      return (c2_operand *)0x0;
    }
    local_8 = (c2_symbol *)(opnd->u18).lo;
    local_4 = opnd->tag;
  }
  count = (uint8_t)local_8;
  switch((&fold_integer_constants_case_index_base)[user->op]) {
  case 0:
    goto switchD_10705b3c_caseD_0;
  case 1:
    goto switchD_10705b3c_caseD_1;
  case 2:
    (k->u18).lo = ~(k->u18).lo;
    k->tag = ~k->tag;
    pcVar3 = constant_convert_to(k,type,user);
    return pcVar3;
  case 3:
    uVar1 = (k->u18).lo;
    (k->u18).lo = -uVar1;
    k->tag = -(k->tag + (uint)(uVar1 != 0));
    pcVar3 = constant_convert_to(k,type,user);
    return pcVar3;
  case 4:
    pcVar2 = (k->u18).reg;
    (k->u18).reg = (c2_symbol *)((int)&local_8->fe + (int)&pcVar2->fe);
    k->tag = k->tag + local_4 + (uint)CARRY4((uint)pcVar2,(uint)local_8);
    pcVar3 = constant_convert_to(k,type,user);
    return pcVar3;
  case 5:
    pcVar2 = (k->u18).reg;
    (k->u18).reg = (c2_symbol *)((int)pcVar2 - (int)local_8);
    k->tag = (k->tag - local_4) - (uint)(pcVar2 < local_8);
    pcVar3 = constant_convert_to(k,type,user);
    return pcVar3;
  case 6:
    uVar4 = __allmul((k->u18).lo,k->tag,(uint32_t)local_8,local_4);
    break;
  case 7:
    uVar4 = allshl(count,k->tag,(k->u18).lo);
    break;
  case 8:
    (k->u18).lo = (k->u18).lo & (uint)local_8;
    k->tag = k->tag & local_4;
    pcVar3 = constant_convert_to(k,type,user);
    return pcVar3;
  case 9:
    (k->u18).lo = (k->u18).lo | (uint)local_8;
    k->tag = k->tag | local_4;
    pcVar3 = constant_convert_to(k,type,user);
    return pcVar3;
  case 10:
    (k->u18).lo = (k->u18).lo ^ (uint)local_8;
    k->tag = k->tag ^ local_4;
    pcVar3 = constant_convert_to(k,type,user);
    return pcVar3;
  case 0xb:
    if (local_8 == (c2_symbol *)0x0 && local_4 == 0) {
      return (c2_operand *)0x0;
    }
    if ((type & 0xf000) == 0x2000) {
      uVar4 = ulldiv_helper((k->u18).lo,k->tag,(uint32_t)local_8,local_4);
    }
    else {
      uVar4 = lldiv_helper((k->u18).lo,k->tag,(uint32_t)local_8,local_4);
    }
    break;
  case 0xc:
    if (local_8 == (c2_symbol *)0x0 && local_4 == 0) {
      return (c2_operand *)0x0;
    }
    if ((type & 0xf000) == 0x2000) {
      uVar4 = ullrem_helper((k->u18).lo,k->tag,(uint32_t)local_8,local_4);
    }
    else {
      uVar4 = llrem_helper((k->u18).lo,k->tag,(uint32_t)local_8,local_4);
    }
    break;
  case 0xd:
    if ((type & 0xf000) == 0x2000) {
      uVar4 = aullshr(count,k->tag,(k->u18).lo);
    }
    else {
      uVar4 = allshr((k->u18).lo,k->tag,count);
    }
  }
  k->u18 = (c2_operand_u18)(int)uVar4;
  k->tag = (int)(uVar4 >> 0x20);
switchD_10705b3c_caseD_1:
  pcVar3 = constant_convert_to(k,type,user);
  return pcVar3;
}

