void __fastcall pch_relocate_record_chain(void *record)

{
  char cVar1;
  
  while( true ) {
    pch_relocate_slot_once(&g_pch_image,(uint)record);
    pch_relocate_slot_once(&g_pch_image,(int)record + 0x10);
    cVar1 = pch_relocate_slot_once(&g_pch_image,(uint)((int)record + 0x14));
    if (cVar1 == '\0') break;
    record = *(void **)((int)record + 0x14);
  }
  return;
}

