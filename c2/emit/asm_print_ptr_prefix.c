void __fastcall asm_print_ptr_prefix(c2_tuple *t,c2_operand *op,int size)

{
  byte bVar1;
  char *pcVar2;
  int iVar3;
  
  switch(op->op) {
  case 0x14a:
  case 0x14c:
  case 0x14d:
  case 0x14e:
  case 0x14f:
  case 0x152:
    goto switchD_10774e61_caseD_14a;
  case 0x14b:
    break;
  default:
    return;
  }
  if (op->kind != '\x02') {
    return;
  }
switchD_10774e61_caseD_14a:
  pcVar2 = asm_size_keyword(size);
  iVar3 = asm_printf("%s PTR ",pcVar2);
  g_asm_column = g_asm_column + iVar3;
  bVar1 = op->flags11 & 7;
  if (bVar1 == 0) {
    return;
  }
  iVar3 = asm_printf("%s:",g_register_names[bVar1 + 0x18]);
  g_asm_column = g_asm_column + iVar3;
  return;
}

