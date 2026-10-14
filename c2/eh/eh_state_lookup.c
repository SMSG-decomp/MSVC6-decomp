c2_eh_state * __fastcall eh_state_lookup(int32_t state)

{
  c2_eh_state *pcVar1;
  uint uVar2;
  
  uVar2 = state & 0x8000001f;
  if ((int)uVar2 < 0) {
    uVar2 = (uVar2 - 1 | 0xffffffe0) + 1;
  }
  for (pcVar1 = g_eh_state_hash[uVar2]; (pcVar1 != (c2_eh_state *)0x0 && (pcVar1->state != state));
      pcVar1 = pcVar1->hash_next) {
  }
  return pcVar1;
}

