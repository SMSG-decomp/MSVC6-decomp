int __fastcall asm_print_special_operands(c2_tuple *t)

{
  uint32_t uVar1;
  int iVar2;
  
  uVar1 = t->op;
  switch(uVar1) {
  case 0x21:
    goto switchD_10774859_caseD_21;
  default:
    if ((((g_x86_op_flags[uVar1] & 1) != 0) && (g_x86_op_operand_count[uVar1] == 2)) &&
       (t->src->next->op != 0x149)) {
      asm_print_mnemonic(t);
      asm_print_memory_operand(t,t->src->next,t->type & 0xfff);
      return 1;
    }
switchD_10774859_caseD_21:
    return 0;
  case 0x52:
  case 0x53:
  case 0x5c:
  case 0x5d:
  case 0xd1:
  case 0xd2:
    asm_print_mnemonic(t);
    asm_print_memory_operand(t,t->src->next,t->type & 0xfff);
    return 1;
  case 0x56:
    asm_print_mnemonic(t);
    asm_print_memory_operand(t,t->src,t->src->type & 0xfff);
    return 1;
  case 0x5a:
  case 0x5b:
  case 0x62:
  case 99:
    asm_print_mnemonic(t);
    asm_print_memory_operand(t,t->dst,t->type & 0xfff);
    return 1;
  case 0x60:
    asm_print_mnemonic(t);
    asm_print_memory_operand(t,t->src,t->type & 0xfff);
    return 1;
  case 0xa3:
    asm_print_mnemonic(t);
    iVar2 = asm_printf("%s, ",g_register_names[((t->dst->u18).reg)->id]);
    g_asm_column = g_asm_column + iVar2;
    asm_print_memory_operand(t,t->src,t->type & 0xfff);
    iVar2 = asm_printf(", ");
    g_asm_column = g_asm_column + iVar2;
    asm_print_memory_operand(t,t->src->next,t->type & 0xfff);
    return 1;
  case 0xa9:
    asm_print_mnemonic(t);
    iVar2 = asm_printf("%d",(uint)t->flags12);
    g_asm_column = g_asm_column + iVar2;
    return 1;
  case 0xca:
  case 0xcb:
    asm_print_mnemonic(t);
    asm_print_memory_operand(t,t->src,t->type & 0xfff);
    iVar2 = asm_printf(", ");
    g_asm_column = g_asm_column + iVar2;
    asm_print_memory_operand(t,t->src->next,t->type & 0xfff);
    iVar2 = asm_printf(", ");
    g_asm_column = g_asm_column + iVar2;
    asm_print_memory_operand(t,t->src->next->next,1);
    return 1;
  case 0x113:
  case 0x115:
    asm_print_mnemonic(t);
    iVar2 = asm_printf("SHORT ");
    g_asm_column = g_asm_column + iVar2;
    asm_print_memory_operand(t,t->src,4);
    return 1;
  }
}

