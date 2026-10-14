void __fastcall operand_to_address_form(c2_operand *op)

{
  op->kind = ((op->kind != '\x02') - 1U & 0xfe) + 5;
  return;
}

