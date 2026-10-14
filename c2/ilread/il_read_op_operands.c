c2_reader_op * __fastcall il_read_op_operands(uint32_t op,c2_function *fn,c2_reader_op *out)

{
  c2_scope_table *pcVar1;
  c2_reader_op *op_00;
  ushort uVar2;
  int16_t iVar3;
  uint32_t *puVar4;
  int iVar5;
  int32_t iVar6;
  uint uVar7;
  c2_fe_symbol *pcVar8;
  bool bVar9;
  longlong lVar10;
  double as_double;
  c2_float_const real_const;
  uint32_t raw_bytes [3];
  byte format;
  
  op_00 = out;
  format = g_il_op_format_table[op];
  out->op = op;
  switch(format) {
  case 0:
  case 0x10:
    goto switchD_10730176_caseD_0;
  case 1:
    il_read_type_operand(out);
    if (g_opt_dlp == 0) {
      return op_00;
    }
    bVar9 = op == 0x27;
    break;
  case 2:
    uVar7 = il_read_id();
    pcVar8 = fe_scope_lookup_id(fn->scope,uVar7);
    op_00->sym = pcVar8;
    if (g_opt_dlp == 0) {
      return op_00;
    }
    bVar9 = op == 0x28;
    break;
  case 3:
    uVar7 = il_read_id();
    pcVar8 = fe_scope_lookup_id(fn->scope,uVar7);
    op_00->sym = pcVar8;
    il_read_type_operand(op_00);
    il_read_byte();
    il_read_byte();
    return op_00;
  case 4:
    uVar7 = il_read_id();
    pcVar8 = fe_scope_lookup_id(fn->scope,uVar7);
    op_00->sym = pcVar8;
    il_read_byte();
    return op_00;
  case 5:
    il_read_type_operand(out);
    il_read_byte();
    return op_00;
  case 6:
    il_read_type_operand(out);
    uVar2 = op_00->type;
    if ((uVar2 & 0xf000) == 0x4000) {
      if (uVar2 != 0x400a) {
        ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\getattr.c",0xfd);
      }
    }
    else if (uVar2 != 0x400a) {
      if ((uVar2 & 0xfff) == 8) {
        lVar10 = il_read_quad();
        op_00->value = (int)lVar10;
        op_00->value_hi = (int)((ulonglong)lVar10 >> 0x20);
        return op_00;
      }
      goto switchD_10730176_caseD_d;
    }
    puVar4 = il_read_12_bytes(raw_bytes);
    real_const.mantissa_low = *puVar4;
    real_const.mantissa_high = puVar4[1];
    real_const._8_4_ = puVar4[2];
    iVar5 = type_word_at_0a(&real_const);
    if (iVar5 == 10) {
      uVar2 = 0x400a;
    }
    else {
      uVar2 = (ushort)iVar5 | 0x4000;
    }
    op_00->type = uVar2;
    if (uVar2 == 0x4004) {
      iVar5 = fpu_store_float(&real_const,(float *)&out);
      if (iVar5 != 0) {
        warning(2,0x2f4);
      }
      fe_set_type4_store_st0_b((float *)&out,&real_const);
    }
    else {
      iVar5 = fpu_store_double(&real_const,&as_double);
      if (iVar5 != 0) {
        warning(2,0x2f4);
      }
      fe_set_type8_store_st0(&as_double,&real_const);
    }
    puVar4 = arena_alloc(0,0xc);
    op_00->value = (int32_t)puVar4;
    *puVar4 = real_const.mantissa_low;
    puVar4[1] = real_const.mantissa_high;
    puVar4[2] = real_const._8_4_;
    return op_00;
  case 7:
    il_read_type_operand(out);
  case 8:
    uVar7 = il_read_id();
    pcVar8 = fe_scope_lookup_id(fn->scope,uVar7);
    op_00->sym = pcVar8;
    return op_00;
  case 9:
    il_read_type_operand(out);
  case 10:
    iVar5 = il_read_byte();
    *(char *)&op_00->arg = (char)iVar5;
    return op_00;
  case 0xb:
    ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\getattr.c",0x16b);
  case 0xc:
    iVar3 = il_read_short();
    *(int16_t *)&op_00->arg = iVar3;
    il_read_pragma_operands(op_00);
    return op_00;
  case 0xd:
  case 0x11:
    goto switchD_10730176_caseD_d;
  case 0xe:
    il_read_type_operand(out);
    uVar7 = il_read_id();
    pcVar1 = fn->scope;
    pcVar8 = fe_scope_lookup_id(pcVar1,uVar7);
    op_00->sym = pcVar8;
    uVar7 = il_read_id();
    pcVar8 = fe_scope_lookup_id(pcVar1,uVar7);
    op_00->arg = (int32_t)pcVar8;
    return op_00;
  case 0xf:
    il_read_short();
    return op_00;
  case 0x12:
    il_read_type_operand(out);
    uVar7 = il_read_id();
    op_00->arg = uVar7;
    return op_00;
  case 0x13:
    il_read_type_operand(out);
    iVar6 = il_read_long();
    op_00->arg = iVar6;
    return op_00;
  case 0x14:
    iVar6 = il_read_long();
    op_00->value = iVar6;
    iVar6 = il_read_long();
    op_00->arg = iVar6;
    return op_00;
  case 0x15:
    uVar7 = il_read_id();
    pcVar1 = fn->scope;
    pcVar8 = fe_scope_lookup_id(pcVar1,uVar7);
    op_00->value = (int32_t)pcVar8;
    uVar7 = il_read_id();
    pcVar8 = fe_scope_lookup_id(pcVar1,uVar7);
    op_00->sym = pcVar8;
    iVar3 = il_read_short();
    op_00->arg = (int)iVar3;
    return op_00;
  default:
    fatal_error(1,"E:\\8168\\vc98\\p2\\src\\P2\\getattr.c",0x1d5);
  }
  if (bVar9) {
switchD_10730176_caseD_d:
    iVar6 = il_read_long();
    op_00->value = iVar6;
    op_00->value_hi = iVar6 >> 0x1f;
    return op_00;
  }
switchD_10730176_caseD_0:
  return op_00;
}

