void __cdecl pch_relocate_token_records(void)

{
  uint *slot;
  
  slot = &g_token_static_records;
  do {
    if ((c1_u8 *)*slot != (c1_u8 *)0x0) {
      pch_relocate_token((c1_u8 *)*slot);
    }
    slot = slot + 1;
  } while ((int)slot < 0x104d1b00);
  return;
}

