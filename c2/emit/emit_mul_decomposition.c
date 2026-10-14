int32_t __fastcall emit_mul_decomposition(c2_mul_decomp *step,c2_operand **value,c2_tuple *anchor)

{
  uint32_t uVar1;
  int32_t iVar2;
  c2_tuple *pcVar3;
  c2_const_operand *src2;
  uint32_t uVar4;
  uint16_t uVar5;
  int iVar6;
  c2_operand *pcVar7;
  c2_operand *pcStack_8;
  uint32_t local_4;
  c2_insert_fn *insert_fn;
  
  uVar1 = step->value;
  uVar4 = step->op;
  pcVar3 = anchor;
  local_4 = uVar1;
  switch(uVar4) {
  case 0:
    goto override_jmp_1074fb89_case_0;
  case 1:
    emit_mul_decomposition(step->from,value,anchor);
    pcVar3 = tuple_new_unary_temp(0x161,anchor->type,*value,tuple_insert_before,anchor);
    *value = pcVar3->dst;
    return uVar1;
  case 2:
    copy_mul_operand_to_temp(value,&pcStack_8,1);
    iVar2 = emit_mul_decomposition(step->from,value,anchor);
    emit_mul_by_pow2(uVar1 - 1,iVar2,value,anchor);
    pcVar7 = *value;
    uVar5 = anchor->type;
    uVar4 = 0x16d;
    insert_fn = tuple_insert_before;
    break;
  case 3:
    copy_mul_operand_to_temp(value,&pcStack_8,1);
    iVar2 = emit_mul_decomposition(step->from,value,anchor);
    emit_mul_by_pow2(uVar1 + 1,iVar2,value,anchor);
    pcVar7 = *value;
    uVar5 = anchor->type;
    insert_fn = tuple_insert_before;
    uVar4 = 0x16e;
    break;
  case 4:
    copy_mul_operand_to_temp(value,&pcStack_8,1);
    iVar2 = emit_mul_decomposition(step->from,value,anchor);
    emit_mul_by_pow2(1 - uVar1,iVar2,value,anchor);
    pcVar3 = tuple_new_binary_temp(0x16e,anchor->type,*value,pcStack_8,tuple_insert_before,anchor);
    pcVar7 = pcVar3->dst;
    uVar5 = anchor->type;
    *value = pcVar7;
    pcVar3 = tuple_new_unary_temp(0x161,uVar5,pcVar7,tuple_insert_before,anchor);
    *value = pcVar3->dst;
    return uVar1;
  case 8:
    switch(uVar4) {
    case 8:
      local_4 = 2;
      break;
    case 9:
      local_4 = 3;
      break;
    case 10:
      local_4 = 4;
      break;
    case 0xb:
      local_4 = 5;
      break;
    case 0xc:
      local_4 = 8;
      break;
    case 0xd:
      local_4 = 9;
    }
    emit_mul_decomposition(step->from,value,anchor);
    insert_fn = tuple_insert_before;
    pcStack_8 = operand_new_intconst(0x1004,local_4,(int)local_4 >> 0x1f);
    pcVar7 = *value;
    uVar5 = anchor->type;
    uVar4 = 0x16f;
    break;
  case 9:
    switch(uVar4) {
    case 8:
      iVar6 = 2;
      break;
    case 9:
      iVar6 = 3;
      break;
    case 10:
      iVar6 = 4;
      break;
    case 0xb:
      iVar6 = 5;
      break;
    case 0xc:
      iVar6 = 8;
      break;
    case 0xd:
      iVar6 = 9;
    }
    emit_mul_decomposition(step->from,value,anchor);
    copy_mul_operand_to_temp(value,&pcStack_8,1);
    insert_fn = tuple_insert_before;
    src2 = operand_new_intconst(0x1004,iVar6 - 1U,(int)(iVar6 - 1U) >> 0x1f);
    pcVar3 = tuple_new_binary_temp(0x16f,anchor->type,*value,src2,insert_fn,pcVar3);
    pcVar3 = tuple_new_binary_temp
                       (0x16d,anchor->type,pcStack_8,pcVar3->dst,tuple_insert_before,anchor);
    *value = pcVar3->dst;
    return local_4;
  }
  pcVar3 = tuple_new_binary_temp(uVar4,uVar5,pcVar7,pcStack_8,insert_fn,pcVar3);
  *value = pcVar3->dst;
override_jmp_1074fb89_case_0:
  return uVar1;
}

