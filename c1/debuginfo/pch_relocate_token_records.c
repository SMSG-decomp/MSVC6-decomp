void __cdecl pch_relocate_token_records(void)

{
  c1_u8 **slot;
  
  slot = (c1_u8 **)&g_token_static_records;
  do {
    if ((c1_token *)*slot != (c1_token *)0x0) {
      pch_relocate_token((c1_token *)*slot);
    }
    slot = slot + 1;
  } while ((int)slot < 0x1065d9ac);
  return;
}

