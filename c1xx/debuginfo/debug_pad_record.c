void __cdecl debug_pad_record(int length,c1_u16 *record)

{
  uint uVar1;
  char cVar2;
  char *pcVar3;
  uint uVar4;
  
  uVar1 = -length - 2U & 3;
  pcVar3 = (char *)(length + 2 + (int)record);
  cVar2 = (char)uVar1 + -0x10;
  for (uVar4 = uVar1; uVar4 != 0; uVar4 = uVar4 - 1) {
    *pcVar3 = cVar2;
    pcVar3 = pcVar3 + 1;
    cVar2 = cVar2 + -1;
  }
  *record = (c1_u16)(length + uVar1);
  if (g_pch_precomp_types != 0) {
    g_cv_precomp_signature = crc16_update((byte *)record,3,g_cv_precomp_signature);
  }
  il_emit_debug_record(0xb);
  g_cv_type_stream_size = g_cv_type_stream_size + 2 + length + uVar1;
  return;
}

