void __fastcall delete_identity_alu_op(c2_tuple *t,int flags_live)

{
  uint uVar1;
  c2_operand *k;
  uint32_t v;
  int iVar2;
  
  uVar1 = t->op;
  if ((((uVar1 != 0) && (uVar1 < 0x144)) && (g_x86_op_operand_count[uVar1] == 2)) &&
     (((g_x86_op_flags[uVar1] & 0x40) != 0 && (k = t->src->next, k->kind == '\a')))) {
    switch(uVar1) {
    case 0x2d:
    case 0x30:
    case 0x32:
      v = 0;
      break;
    case 0x2e:
      v = 0xffffffff;
      break;
    default:
      goto switchD_10738b78_caseD_2f;
    }
    iVar2 = const_compare(k,v,(int)v >> 0x1f);
    if ((iVar2 == 0) && (flags_live == 0)) {
      tuple_unlink_free(t);
    }
  }
switchD_10738b78_caseD_2f:
  return;
}

