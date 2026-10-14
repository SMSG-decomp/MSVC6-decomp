void __fastcall asm_print_instruction(c2_tuple *t)

{
  sbyte sVar1;
  int iVar2;
  c2_operand *pcVar3;
  
  asm_pad_to_column(8);
  iVar2 = asm_print_special_operands(t);
  if (iVar2 == 0) {
    asm_print_mnemonic(t);
    sVar1 = g_x86_op_operand_count[t->op];
    if (0 < sVar1) {
      if ((g_x86_op_flags[t->op] & 0x800) == 0) {
        pcVar3 = t->src;
      }
      else {
        pcVar3 = t->dst;
      }
      asm_print_memory_operand(t,pcVar3,pcVar3->type & 0xfff);
      if (1 < sVar1) {
        iVar2 = asm_printf(", ");
        g_asm_column = g_asm_column + iVar2;
        if (pcVar3 == t->dst) {
          pcVar3 = t->src;
        }
        else {
          pcVar3 = pcVar3->next;
        }
        asm_print_memory_operand(t,pcVar3,pcVar3->type & 0xfff);
      }
    }
  }
  return;
}

