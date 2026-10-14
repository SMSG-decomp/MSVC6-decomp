void __fastcall asm_print_mnemonic(c2_tuple *t)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  uint size;
  char *pcVar5;
  
  uVar1 = t->op;
  pcVar5 = (char *)0x0;
  if (uVar1 < 0xb7) {
    if (uVar1 == 0xb6) {
      pcVar4 = "lock";
      goto LAB_10774bf9;
    }
    switch(uVar1) {
    case 0xf:
      goto switchD_10774bed_caseD_f;
    case 0x35:
    case 0x36:
    case 0x37:
    case 0x38:
    case 0x39:
    case 0x3a:
    case 0x3b:
      goto switchD_10774bed_caseD_35;
    case 0xa3:
      goto switchD_10774bed_caseD_a3;
    case 0xa5:
    case 0xaa:
    case 0xab:
    case 0xac:
    case 0xad:
      if ((t->type & 0xfff) == 4) {
        size = 4;
        goto LAB_10774c7f;
      }
      break;
    case 0xa9:
      pcVar4 = "npad";
      goto LAB_10774bf9;
    }
    goto switchD_10774bed_caseD_10;
  }
  switch(uVar1) {
  case 0xbb:
    pcVar4 = asm_data_directive_for_size(t->type & 0xfff);
    break;
  case 0xc1:
switchD_10774bed_caseD_a3:
    pcVar4 = "imul";
    break;
  case 0xc3:
    pcVar4 = "movzx";
    break;
  case 0xc5:
    pcVar4 = "movsx";
    break;
  case 0xd0:
    pcVar4 = "mov";
    break;
  case 0x10e:
  case 0x10f:
  case 0x110:
  case 0x111:
  case 0x112:
switchD_10774bed_caseD_35:
    size = t->type & 0xfff;
LAB_10774c7f:
    pcVar5 = asm_size_suffix_letter(size);
  default:
switchD_10774bed_caseD_10:
    pcVar4 = g_x86_mnemonics[uVar1];
    break;
  case 0x113:
switchD_10774bed_caseD_f:
    pcVar4 = "j";
    pcVar5 = g_x86_cc_suffix_table[(byte)t->type];
  }
LAB_10774bf9:
  iVar2 = g_asm_column;
  iVar3 = asm_printf("%s",pcVar4);
  g_asm_column = g_asm_column + iVar3;
  if (pcVar5 != (char *)0x0) {
    iVar3 = asm_printf("%s",pcVar5);
    g_asm_column = g_asm_column + iVar3;
  }
  if (((0 < g_x86_op_operand_count[uVar1]) || ((g_x86_op_flags[uVar1] & 0x100) != 0)) ||
     (uVar1 == 0xa9)) {
    asm_pad_by((iVar2 - g_asm_column) + 8);
  }
  return;
}

