void __fastcall pch_relocate_token_chunks(void *stream)

{
  uint *slot;
  uint *slot_00;
  int iVar1;
  
  slot = *(uint **)stream;
  do {
    iVar1 = 4;
    slot_00 = slot + 5;
    do {
      if (*slot_00 == 0) break;
      pch_relocate_slot_once(&g_pch_image,slot_00);
      pch_relocate_token((c1_u8 *)*slot_00);
      iVar1 = iVar1 + 1;
      slot_00 = slot_00 + 1;
    } while (iVar1 < 0x1f);
    if (*slot == 0) {
      return;
    }
    pch_relocate_slot_once(&g_pch_image,slot);
    slot = (uint *)*slot;
  } while( true );
}

