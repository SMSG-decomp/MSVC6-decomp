void clear_live_range_hash(void)

{
  int iVar1;
  c2_live_range **bucket;
  
  bucket = g_live_range_hash;
  for (iVar1 = 0x400; iVar1 != 0; iVar1 = iVar1 + -1) {
    *bucket = (c2_live_range *)0x0;
    bucket = bucket + 1;
  }
  return;
}

