c2_operand * __fastcall operand_cse_key(c2_operand *op)

{
  if (op != (c2_operand *)0x0) {
    switch(*(undefined1 *)((int)operand_cse_key_jump_table + op->kind + 0xb)) {
    case 0:
      if ((op->flags & 0x20) == 0) {
        return op;
      }
      break;
    case 1:
      goto switchD_1070f94c_caseD_1;
    }
  }
  op = (c2_operand *)0x0;
switchD_1070f94c_caseD_1:
  return op;
}

