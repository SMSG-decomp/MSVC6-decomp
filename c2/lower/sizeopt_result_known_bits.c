uint32_t __fastcall sizeopt_result_known_bits(c2_tuple *t)

{
  int iVar1;
  uint32_t uVar2;
  
  if (((t->op != 0x177) && (t->op != 0x171)) && (iVar1 = op_is_0x29_to_0x2b(t), iVar1 == 0)) {
    if ((t->op == 0x172) && (t->src->kind == '\a')) {
      uVar2 = operand_known_leading_zero_bits(t->src);
      return uVar2;
    }
    return 0;
  }
  return (t->type & 0xfff) * 8 - 8;
}

