void __fastcall operand_to_memory_form(c2_operand *op)

{
  op->kind = ((op->kind != '\x03') - 1U & 0xfc) + 6;
  return;
}

