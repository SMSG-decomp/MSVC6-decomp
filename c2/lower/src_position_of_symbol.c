int __fastcall src_position_of_symbol(c2_tuple *t,c2_symbol *s)

{
  uint uVar1;
  c2_operand *pcVar2;
  c2_operand *pcVar3;
  
  pcVar2 = find_src_symbol_ref(t,s);
  if (((pcVar2 == (c2_operand *)0x0) || (uVar1 = t->op, uVar1 == 0)) || (0x143 < uVar1)) {
    return 0;
  }
  if (((g_x86_op_flags[uVar1] & 0x800) == 0) && (g_x86_op_operand_count[uVar1] == 2)) {
    pcVar3 = t->src->next;
  }
  else {
    pcVar3 = (c2_operand *)0x0;
  }
  if (pcVar2 == t->src) {
    return 1;
  }
  return (pcVar2 != pcVar3) - 1 & 2;
}

