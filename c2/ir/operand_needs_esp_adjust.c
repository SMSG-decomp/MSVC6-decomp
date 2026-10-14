int __fastcall operand_needs_esp_adjust(c2_operand *op)

{
  c2_symbol *pcVar1;
  
  if (op->op == 0x14a) {
    pcVar1 = op->sym;
  }
  else {
    if (op->op != 0x14e) {
      return 0;
    }
    pcVar1 = op->base_sym;
  }
  if (((g_esp_adjust_params == 0) || (pcVar1->cls != '\x05')) &&
     ((g_esp_adjust_locals == 0 || (pcVar1->cls == '\x05')))) {
    return 0;
  }
  return 1;
}

