void __cdecl browse_record_finish_kind11(byte *rec)

{
  uint uVar1;
  
  uVar1 = *(uint *)(rec + 8);
  *rec = 3;
  rec[2] = 0x12;
  rec[0x14] = 0;
  rec[0x15] = 0;
  if ((byte)(uVar1 >> 0x18) != g_browse_id_module_byte) {
    *(uint *)(rec + 8) = uVar1 & 0xff000000;
  }
  return;
}

