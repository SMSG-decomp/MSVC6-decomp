void reset_eh_state_numbering(void)

{
  int iVar1;
  c2_eh_state **bucket;
  
  bucket = g_eh_state_hash;
  for (iVar1 = 0x20; iVar1 != 0; iVar1 = iVar1 + -1) {
    *bucket = (c2_eh_state *)0x0;
    bucket = bucket + 1;
  }
  g_eh_state_counter = 0;
  g_eh_current_state = (c2_eh_state *)0x0;
  return;
}

