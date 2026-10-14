void __fastcall hash_live_range(c2_live_range *lr)

{
  c2_live_range *pcVar1;
  uint uVar2;
  
  uVar2 = lr->id & 0x3ff;
  pcVar1 = g_live_range_hash[uVar2];
  g_live_range_hash[uVar2] = lr;
  lr->hash_next = pcVar1;
  return;
}

