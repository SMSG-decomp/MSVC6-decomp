c2_operand * tls_array_operand(void)

{
  uint8_t *puVar1;
  c2_fe_symbol *fs;
  c2_operand *pcVar2;
  
  fs = extern_symbol_lookup_or_create((uint8_t *)"__tls_array");
  pcVar2 = operand_for_fe_symbol(fs);
  pcVar2->flags11 = pcVar2->flags11 & 0xfd | 5;
  pcVar2->flags = pcVar2->flags | 0x80;
  puVar1 = &pcVar2->sym->flags5;
  *puVar1 = *puVar1 | 4;
  return pcVar2;
}

