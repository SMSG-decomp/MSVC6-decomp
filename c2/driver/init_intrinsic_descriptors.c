void init_intrinsic_descriptors(void)

{
  short sVar1;
  uint8_t *puVar2;
  
  sVar1 = 0;
  puVar2 = &g_intrinsic_init_table[0].x87_flags;
  do {
    g_intrinsic_desc[sVar1].flags = puVar2[-1];
    g_intrinsic_desc[sVar1].x87_flags = *puVar2;
    g_intrinsic_desc[sVar1].arg_codes = *(char **)(puVar2 + -9);
    g_intrinsic_desc[sVar1].helper_name = *(char **)(puVar2 + -5);
    g_intrinsic_desc[sVar1].param_type = *(uint16_t *)(puVar2 + -0xb);
    sVar1 = *(short *)(puVar2 + 3);
    puVar2 = puVar2 + 0x10;
  } while (sVar1 < 0x18a);
  return;
}

