void __fastcall pch_relocate_tagged_list(uint *link)

{
  uint uVar1;
  char cVar2;
  
  uVar1 = *link;
  *link = *link & 0xfffffffe;
  cVar2 = pch_relocate_slot_once(&g_pch_image,(uint)link);
  if (cVar2 != '\0') {
    pch_relocate_tagged_list((uint *)*link);
  }
  if ((uVar1 & 1) != 0) {
    *link = *link | 1;
  }
  return;
}

